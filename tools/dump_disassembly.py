import idautils
import idc
import idaapi
import ida_funcs
import ida_idaapi
import ida_typeinf
import os

# Operand types returned by get_operand_Type
# o_void = cvar.o_void
# o_reg = cvar.o_reg
# o_mem = cvar.o_mem
# o_phrase = cvar.o_phrase
# o_displ = cvar.o_displ
# o_imm = cvar.o_imm
# o_far = cvar.o_far # Jump
# o_near = cvar.o_near # Jump
# o_idpspec0 = cvar.o_idpspec0
# o_idpspec1 = cvar.o_idpspec1
# o_idpspec2 = cvar.o_idpspec2
# o_idpspec3 = cvar.o_idpspec3
# o_idpspec4 = cvar.o_idpspec4
# o_idpspec5 = cvar.o_idpspec5

# Output file to write function code
output_file_c = "function_code.c"

# Output file to write function declarations
output_file_h = "function_declarations.h"

dumpable_funcs_searched = 0

max_functions_to_dump = 50

dumped_func_addr_array = []

dumpable_func_calls = []

dumpable_func_names = []

global_objects_list = {}

debug_dump_extra_data = True

# array indexed by func names of pairs of a start addr
jump_locs = {}

jump_loc_names = {}

def is_integer(n):
    try:
        int(n)
    except ValueError:
        return False
    else:
        return True

def item_in_array(array, item):
    try:
        array.index(item)
    except ValueError:
        return False
    else:
        return True

def is_ida_hex_str(str):
    for char in str:
        if not is_integer(char) and char != "h":
            return False
    return True

def convert_ida_hex_str_to_true_hex(str):
    int_str = ""
    for char in str:
        if is_integer(char):
            int_str += char
    return hex(int(int_str))

def clean_func_name(func_name):
    has_colon = item_in_array(func_name, ":")
    has_semicolon = item_in_array(func_name, ";")
    new_name = ""
    if has_colon:
        new_name = func_name.split(":")[1]
    elif has_semicolon:
        new_name = func_name.split(";")[0]
    else:
        new_name = func_name
    # index = 0
    # for char in func_name:
    #     if char == ";":
    #         continue
    #     new_name += char
    return new_name

def get_func_name_in_register(insn):
    tokens = insn.split()
    index = 0
    for token in tokens:
        if token == ";":
            fwd_index = index + 1
            if fwd_index > len(tokens):
                return ""
            else:
                return tokens[index + 1]
    return ""

def funct_is_dumpable(func_name, addr):
    called_func = idaapi.get_func(addr)
    called_func_flags = idc.get_func_flags(addr)
    # data_segment_for_addr = idaapi.get_segm_by_name(".idata")
    if not idaapi.is_func_entry(called_func):
        return False
    if idc.get_segm_name(addr) != ".text":
        return False
    if called_func_flags & ida_funcs.FUNC_LIB:
        return False
    # if not data_segment_for_addr:
    #     return False
    # if data_segment_for_addr.contains(called_ea):
    #     return False
    return True

# def parse_addr_from_loc_name(loc_name):
#     index = 0
#     array_size = len(loc_name)
#     for char in loc_name:
#         while not is_integer(char) and 

def parse_assembly_for_func_calls(func_addr):
    global dumpable_funcs_searched
    if dumpable_funcs_searched >= max_functions_to_dump:
        print("Hit func search limit {}".format(dumpable_funcs_searched))
        return
    dumpable_funcs_searched += 1
    func = idaapi.get_func(func_addr)
    if not func:
        print("Couldn't find func at addr {}".format(hex(func_addr)))
        return
    primary_func_name = idc.get_func_name(func_addr)
    # Iterate over the function's basic blocks
    print("Searching function {}".format(primary_func_name))
    # Iterate over the instructions in the basic block
    for insn in idautils.FuncItems(func_addr):
        insn2 = idaapi.insn_t()
        idaapi.decode_insn(insn2, insn)
        # Write the instruction to the .c file
        first_operand_type = idc.get_operand_type(insn, 0)
        second_operand_type = idc.get_operand_type(insn, 1)
        operand_name = insn2.get_canon_mnem()
        insn_as_string = idc.GetDisasm(insn)
        insn_tokens = insn_as_string.split()
        if operand_name == "call":
            called_func_name = insn_tokens[1]
            cleaned_func_name = clean_func_name(called_func_name)
            called_ea = idc.get_name_ea_simple(cleaned_func_name)
            
            if called_ea == ida_idaapi.BADADDR:
                continue

            # Handle functions stored in registers
            if cleaned_func_name == "eax":
                # if get_func_name_in_register(insn_tokens) == "":
                #     print("Couldn't resolve function name for {} in primary func {}".format(insn_as_string, primary_func_name))
                #     continue
                continue
            
            if item_in_array(dumpable_func_calls, called_ea):
                continue
            
            if not funct_is_dumpable(clean_func_name, called_ea):
                continue

            dumpable_func_calls.append(called_ea)
            dumpable_func_names.append(cleaned_func_name)
            
            parse_assembly_for_func_calls(called_ea)
        elif first_operand_type == idaapi.o_near: # TODO: Handle idaapi.o_far jump type
            if insn_tokens[1] == "short":
                start_loc_name = insn_tokens[2]
            else:
                start_loc_name = insn_tokens[1]
            
            if not primary_func_name in jump_locs:
                jump_locs[primary_func_name] = []
                jump_loc_names[primary_func_name] = {}

            loc_addr = idc.get_name_ea_simple(start_loc_name)
            if loc_addr == ida_idaapi.BADADDR:
                # TODO: Add logging for this
                continue
            if loc_addr in jump_locs[primary_func_name]:
                continue
            jump_locs[primary_func_name].append(loc_addr)
            jump_loc_names[primary_func_name]["{}".format(loc_addr)] = start_loc_name
        # if first_operand_type == idaapi.o_void:
        #     continue
        # if first_operand_type == idaapi.o_mem:
        #     # get_operand_value # Returns the offset added to the operand
        #     # TODO: Get the base address of the object too so the offset isn't lost ida_name.get_name_base_ea
        #     global_object_addr = idc.get_operand_value(insn, 0)
        #     global_object_name = idc.get_name(global_object_addr) # This function can take in flags that determine what name it returns
        #     object_addr_as_str = "{}".format(global_object_addr)
        #     if global_object_addr == ida_idaapi.BADADDR:
        #         # Add logging warning here
        #         print("Failed to add global object to list")
        #     elif not (object_addr_as_str in global_objects_list):
        #         print("Object is not in list {}".format(hex(global_object_addr)))
        #         global_objects_list[object_addr_as_str] = global_object_name
        # if (second_operand_type == idaapi.o_mem):
        #     global_object_addr = idc.get_operand_value(insn, 1)
        #     global_object_name = idc.get_name(global_object_addr)
        #     object_addr_as_str = "{}".format(global_object_addr)
        #     if global_object_addr == ida_idaapi.BADADDR:
        #         # Add logging warning here
        #         print("Failed to add global object to list")
        #     elif not (object_addr_as_str in global_objects_list):
        #         print("Object is not in list {}".format(hex(global_object_addr)))
        #         global_objects_list[object_addr_as_str] = global_object_name

def addr_is_end_loc(func_name, addr):
    for jump_loc in jump_locs[func_name]:
        # print("addr_is_end_loc: {} {} {}".format(func_name, addr, jump_loc))
        if jump_loc == addr:
            return True
    return False

def pre_parse_instruction(insn_str):
    index = 0
    pre_string = ""
    string_len = len(insn_str)
    for char in insn_str:
        if (index + 1) < string_len:
            fwd_char = insn_str[index + 1]
            if fwd_char == "+" or fwd_char == "-" or fwd_char == "*" or fwd_char == "/":
                pre_string += char + " "
                index += 1
                continue
            if char == "+" or char == "-" or char == "*" or char == "/":
                pre_string += char + " "
                index += 1
                continue
            if char == ";":
                index += 1
                continue
            pre_string += char
            index += 1
    return pre_string

def post_parse_instruction_as_tokens(insn_str):
    final_string = ""
    index = 0
    tokens = insn_str.split()
    max_index = len(tokens)
    for token in tokens:
        if token == "short" or token == "offset":
            index += 1
            continue
        if is_ida_hex_str(token):
            token = convert_ida_hex_str_to_true_hex(token)
        if index != max_index:
            final_string += token + " "
        else:
            final_string += token
        index += 1    
    return final_string

def dump_function_code(func_ea, mangled_name, f_c, f_h):
    global debug_dump_extra_data
    # Try to demangle the name
    # demangled_name = idc.demangle_name(mangled_name, idc.INF_SHORT_DN)
    func_name = mangled_name
    # if demangled_name != "None":
    #    func_name = demangled_name
    f_c.write("\n/*{}*/\n".format(hex(func_ea)))
    cfunc_ptr = idaapi.decompile(func_ea)
    arguments = cfunc_ptr.arguments
    f_c.write("{}".format(func_name))
    # lvar_t info
    # type method on arguments index returns a tinfo_t
	# name class var on arguments index
    if arguments:
        f_c.write(" /*(")
        # arg is a tinfo_t object
        index = 0
        args_len = len(arguments)
        # TODO: Dump arg registers too
        for arg in arguments:
            if index + 1 >= args_len:
                f_c.write(" {} {}".format(arg.type().dstr(), arg.name))
                continue
            f_c.write(" {} {},".format(arg.type().dstr(), arg.name))
            index += 1
        f_c.write(" )*/\n")
    else:
        f_c.write("/*( )*/\n")
    
    # Write the function declaration to the .h file
    f_h.write("void {}();\n".format(func_name))
    func_has_jump_locs = mangled_name in jump_locs
    # func_object = idaapi.get_func(func_ea)

    # Iterate over the instructions in the function
    for insn in idautils.FuncItems(func_ea):
        # Write the instruction to the .c file
        insn_as_string = idc.GetDisasm(insn)
        insn2 = idaapi.insn_t()
        idaapi.decode_insn(insn2, insn)
        instruction_name = insn2.get_canon_mnem()
        if func_has_jump_locs:

            if addr_is_end_loc(mangled_name, insn2.ea):
                func_addr_as_str = "{}".format(insn2.ea)
                if func_addr_as_str in jump_loc_names[func_name]:
                    f_c.write("{}:\n".format(jump_loc_names[func_name][func_addr_as_str]))
        f_c.write("\t")
        # pre_string = pre_parse_instruction(insn_as_string)
        # final_string = post_parse_instruction_as_tokens(pre_string)
        # f_c.write(final_string + "\n")
        first_operand_type = idc.get_operand_type(insn, 0)
        second_operand_type = idc.get_operand_type(insn, 1)
        wrote_first_operand_addrs = False
        wrote_second_operand_addrs = False
        f_c.write(" {}".format(insn_as_string))
        if not debug_dump_extra_data:
            f_c.write("\n")
            continue
        if first_operand_type == idaapi.o_mem:
            # get_operand_value # Returns the offset added to the operand
            # TODO: Get the base address of the object too so the offset isn't lost
            global_object_addr = idc.get_operand_value(insn, 0)
            # object_addr_as_str = "{}".format(global_object_addr)
            f_c.write(" //:Type: <{}> :Addr: <{}>".format(first_operand_type, hex(global_object_addr)))
            wrote_first_operand_addrs = True
        if second_operand_type == idaapi.o_mem:
            global_object_addr = idc.get_operand_value(insn, 1)
            # object_addr_as_str = "{}".format(global_object_addr)
            if wrote_first_operand_addrs:
                f_c.write(" {} {}".format(second_operand_type, hex(global_object_addr)))
            else:
                f_c.write(" //:Type: <{}> :Addr: <{}>".format(second_operand_type, hex(global_object_addr)))
            wrote_second_operand_addrs = True
        if instruction_name == "call":
            # get_operand_value # Returns the offset added to the operand
            # TODO: Get the base address of the object too so the offset isn't lost
            call_addr = idc.get_operand_value(insn, 0)
            # object_addr_as_str = "{}".format(global_object_addr)
            f_c.write(" //:Type: <{}> :Addr: <{}>".format(first_operand_type, hex(call_addr)))
            wrote_first_operand_addrs = True
        if wrote_first_operand_addrs and not wrote_second_operand_addrs:
            f_c.write(" {}".format(second_operand_type))
        elif not wrote_first_operand_addrs and not wrote_second_operand_addrs:
            f_c.write(" //:Type: <{}> :Type: <{}>".format(first_operand_type, second_operand_type))
            
        f_c.write("\n")
    f_c.write("\n")

# Open the output files in write mode
with open(output_file_c, "w") as f_c, open(output_file_h, "w") as f_h:

    # Write the header guard for the .h file
    f_h.write("#ifndef FUNCTION_DECLARATIONS_H\n#define FUNCTION_DECLARATIONS_H\n\n")

    # Name of the input function to dump
    # input_func_ea = 0x699E90 # Scr_GetFloat

    input_func_ea = 0x40FAA0 # G_FindItem

    # Get the address of the input function
    input_func_name = idc.get_func_name(input_func_ea)
    # Define a function to dump the code for a given function
    dumpable_func_calls.append(input_func_ea)
    dumpable_func_names.append(input_func_name)
                # f_c.write(" //op: {}\n".format(insn2.get_canon_mnem()))
    # Dump the code for the input function

    print("Starting search for functions recursively")	
    parse_assembly_for_func_calls(input_func_ea)
    
    index = 0
    function_count = len(dumpable_func_names)
    print("Dumping {} functions max {}". format(function_count, max_functions_to_dump))
    for func_addr in dumpable_func_calls:
        if index >= max_functions_to_dump:
            break
        func_name = dumpable_func_names[index]
        print("Now dumping {} at address {} count {}".format(func_name, hex(func_addr), index))
        dump_function_code(func_addr, func_name, f_c, f_h)
        index += 1
    print("Successfully dumped {} of {} total functions".format(function_count, max_functions_to_dump))
    # Write the footer guard for the .h file
    f_h.write("\n#endif")
    print("Function code written to {} and function declarations written to {}".format(output_file_c, output_file_h))