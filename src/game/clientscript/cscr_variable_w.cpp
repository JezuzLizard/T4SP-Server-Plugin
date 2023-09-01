#include <stdinc.hpp>
#include "codsrc/clientscript/cscr_variable.hpp"

namespace game
{
	// void __usercall Scr_InitVariableRange(unsigned int a1@<edi>, unsigned int a2@<esi>, scriptInstance_t a3)
	void Scr_InitVariableRange(unsigned int a1, unsigned int a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov edi, a1;
			mov esi, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_InitClassMap(scriptInstance_t a1@<eax>)
	void Scr_InitClassMap(scriptInstance_t a1, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			call call_addr;
		}
	}

	// unsigned int __usercall GetNewVariableIndexInternal2@<eax>(unsigned int name@<ecx>, scriptInstance_t inst, unsigned int parentId, unsigned int index)
	unsigned int GetNewVariableIndexInternal2(unsigned int name, scriptInstance_t inst, unsigned int parentId, unsigned int index, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push index;
			push parentId;
			push inst;
			mov ecx, name;
			call call_addr;
			mov answer, eax;
			add esp, 0xC;
		}

		return answer;
	}

	// unsigned int __usercall GetNewVariableIndexReverseInternal2@<eax>(unsigned int name@<ecx>, scriptInstance_t inst, unsigned int parentId, unsigned int index)
	unsigned int GetNewVariableIndexReverseInternal2(unsigned int name, scriptInstance_t inst, unsigned int parentId, unsigned int index, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push index;
			push parentId;
			push inst;
			mov ecx, name;
			call call_addr;
			mov answer, eax;
			add esp, 0xC;
		}

		return answer;
	}

	// void __usercall MakeVariableExternal(VariableValueInternal *parentValue@<eax>, scriptInstance_t inst, unsigned int index)
	void MakeVariableExternal(VariableValueInternal* parentValue, scriptInstance_t inst, unsigned int index, void* call_addr)
	{
		__asm
		{
			push index;
			push inst;
			mov eax, parentValue;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall FreeChildValue(unsigned int id@<eax>, scriptInstance_t inst, unsigned int parentId)
	void FreeChildValue(unsigned int id, scriptInstance_t inst, unsigned int parentId, void* call_addr)
	{
		__asm
		{
			push parentId;
			push inst;
			mov eax, id;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall ClearObject(unsigned int a1@<edi>, scriptInstance_t a2)
	void ClearObject(unsigned int a1, scriptInstance_t a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_StopThread(scriptInstance_t inst@<ecx>, unsigned int a2@<eax>)
	void Scr_StopThread(scriptInstance_t inst, unsigned int a2, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			mov eax, a2;
			call call_addr;
		}
	}

	// unsigned int __usercall GetSafeParentLocalId@<eax>(scriptInstance_t a1@<eax>, unsigned int a2)
	unsigned int GetSafeParentLocalId(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push a2;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}

		return answer;
	}

	// unsigned int __usercall GetStartLocalId@<eax>(unsigned int result@<eax>, scriptInstance_t a2@<ecx>)
	unsigned int GetStartLocalId(unsigned int result, scriptInstance_t a2, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall Scr_KillThread(scriptInstance_t inst@<ecx>, unsigned int parentId_1@<eax>)
	void Scr_KillThread(scriptInstance_t inst, unsigned int parentId_1, void* call_addr)
	{
		__asm
		{
			mov ecx, inst;
			mov eax, parentId_1;
			call call_addr;
		}
	}

	// unsigned __int16 __usercall AllocVariable@<ax>(scriptInstance_t inst@<eax>)
	unsigned __int16 AllocVariable(scriptInstance_t inst, void* call_addr)
	{
		unsigned __int16 answer;
		
		__asm
		{
			mov eax, inst;
			call call_addr;
			mov answer, ax;
		}
		
		return answer;
	}

	// int __usercall FreeVariable@<eax>(int a1@<eax>, scriptInstance_t a2@<edx>)
	void FreeVariable(unsigned int a1, scriptInstance_t a2, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			mov edx, a2;
			call call_addr;
		}
	}

	// unsigned int __usercall AllocValue@<eax>(scriptInstance_t inst@<eax>)
	unsigned int AllocValue(scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, inst;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// unsigned int __usercall AllocEntity@<eax>(unsigned int classnum@<eax>, scriptInstance_t inst@<ecx>, int entnum, int clientnum)
	unsigned int AllocEntity(unsigned int classnum, scriptInstance_t inst, int entnum, int clientnum, void* call_addr)
	{
		unsigned int answer;

		__asm
		{
			push clientnum;
			push entnum;
			mov eax, classnum;
			mov ecx, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}

		return answer;
	}

	// unsigned int __usercall Scr_AllocArray@<eax>(scriptInstance_t a1@<eax>)
	unsigned int Scr_AllocArray(scriptInstance_t a1, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// unsigned int __usercall AllocChildThread@<eax>(scriptInstance_t inst@<ecx>, unsigned int a2@<eax>, unsigned int a3)
	unsigned int AllocChildThread(scriptInstance_t inst, unsigned int a2, unsigned int a3, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push a3;
			mov ecx, inst;
			mov eax, a2;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// void __usercall FreeValue(unsigned int id@<eax>, scriptInstance_t inst)
	void FreeValue(unsigned int id, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			push inst;
			mov eax, id;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall RemoveRefToObject(unsigned int id@<eax>, scriptInstance_t inst@<ecx>)
	void RemoveRefToObject(unsigned int id, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov eax, id;
			mov ecx, inst;
			call call_addr;
		}
	}

	// float *__usercall Scr_AllocVector@<eax>(scriptInstance_t a1@<eax>)
	float * Scr_AllocVector(scriptInstance_t a1, void* call_addr)
	{
		float * answer;
		
		__asm
		{
			mov eax, a1;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall RemoveRefToVector(int vecVal@<eax>, scriptInstance_t inst)
	void RemoveRefToVector(const float* vecVal, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			push inst;
			mov eax, vecVal;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall AddRefToValue(scriptInstance_t inst@<eax>, VariableType type@<ecx>, VariableUnion u)
	void AddRefToValue(scriptInstance_t inst, VariableType type_, VariableUnion u, void* call_addr)
	{
		__asm
		{
			push u;
			mov eax, inst;
			mov ecx, type_;
			call call_addr;
			add esp, 0x4;
		}
	}

	// int __usercall FindArrayVariable@<eax>(unsigned int id@<eax>, unsigned int intvalue@<ecx>, scriptInstance_t inst)
	int FindArrayVariable(unsigned int id, unsigned int intvalue, scriptInstance_t inst, void* call_addr)
	{
		int answer;
		
		__asm
		{
			push inst;
			mov eax, id;
			mov ecx, intvalue;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// int __usercall FindVariable@<eax>(int name@<ecx>, int a2@<eax>, scriptInstance_t inst)
	unsigned int FindVariable(unsigned int unsignedValue, unsigned int parentId, scriptInstance_t inst, void* call_addr)
	{
		int answer;
		
		__asm
		{
			push inst;
			mov ecx, unsignedValue;
			mov eax, parentId;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// unsigned int __usercall GetArrayVariableIndex@<eax>(unsigned int unsignedValue@<eax>, scriptInstance_t inst, unsigned int parentId)
	unsigned int GetArrayVariableIndex(unsigned int unsignedValue, scriptInstance_t inst, unsigned int parentId, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push parentId;
			push inst;
			mov eax, unsignedValue;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// unsigned int __usercall Scr_GetVariableFieldIndex@<eax>(scriptInstance_t a1@<eax>, unsigned int name@<esi>, unsigned int parentId)
	unsigned int Scr_GetVariableFieldIndex(scriptInstance_t a1, unsigned int name, unsigned int parentId, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push parentId;
			mov eax, a1;
			mov esi, name;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// VariableValue __usercall Scr_FindVariableField@<edx:eax>(scriptInstance_t inst@<edi>, unsigned int parentId, unsigned int name)
	//Custom made do not replace!
	VariableValue Scr_FindVariableField(scriptInstance_t inst, unsigned int parentId, unsigned int name, void* call_addr)
	{
		VariableValue answer;
		VariableUnion u;
		VariableType typ;

		__asm
		{
			push name;
			push parentId;
			mov edi, inst;
			call call_addr;

			mov u, eax;
			mov typ, edx;

			add esp, 0x8;
		}

		answer.u = u;
		answer.type = typ;
		return answer;
	}

	// void __usercall ClearVariableField(scriptInstance_t inst@<ecx>, unsigned int id@<eax>, unsigned int name, VariableValue *value)
	void ClearVariableField(scriptInstance_t inst, unsigned int id, unsigned int name, VariableValue * value, void* call_addr)
	{
		__asm
		{
			push value;
			push name;
			mov ecx, inst;
			mov eax, id;
			call call_addr;
			add esp, 0x8;
		}
	}

	// unsigned int __usercall GetVariable@<eax>(scriptInstance_t a1@<eax>, unsigned int parentId, unsigned int name)
	unsigned int GetVariable(scriptInstance_t a1, unsigned int parentId, unsigned int name, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push name;
			push parentId;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// unsigned int __usercall GetNewVariable@<eax>(scriptInstance_t a1@<eax>, unsigned int a2@<ecx>, unsigned int a3@<edi>)
	unsigned int GetNewVariable(scriptInstance_t a1, unsigned int a2, unsigned int a3, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			mov edi, a3;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// unsigned int __usercall GetObjectVariable@<eax>(unsigned int a1@<eax>, scriptInstance_t inst, unsigned int parentId)
	unsigned int GetObjectVariable(unsigned int a1, scriptInstance_t inst, unsigned int parentId, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push parentId;
			push inst;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// unsigned int __usercall GetNewObjectVariable@<eax>(scriptInstance_t inst@<eax>, unsigned int name@<ecx>, unsigned int parentId@<edi>)
	unsigned int GetNewObjectVariable(scriptInstance_t inst, unsigned int name, unsigned int parentId, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, inst;
			mov ecx, name;
			mov edi, parentId;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall RemoveVariable(unsigned int name@<ecx>, unsigned int parentId@<edi>, scriptInstance_t inst@<esi>)
	void RemoveVariable(unsigned int name, unsigned int parentId, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov ecx, name;
			mov edi, parentId;
			mov esi, inst;
			call call_addr;
		}
	}

	// void __usercall RemoveNextVariable(scriptInstance_t a1@<edi>, unsigned int parentId)
	void RemoveNextVariable(scriptInstance_t a1, unsigned int parentId, void* call_addr)
	{
		__asm
		{
			push parentId;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall SafeRemoveVariable(unsigned int unsignedValue@<ecx>, unsigned int parentId@<edi>, scriptInstance_t inst@<esi>)
	void SafeRemoveVariable(unsigned int unsignedValue, unsigned int parentId, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			mov ecx, unsignedValue;
			mov edi, parentId;
			mov esi, inst;
			call call_addr;
		}
	}

	// void __usercall SetVariableValue(scriptInstance_t a1@<eax>, VariableValue *a2@<edi>, unsigned int a3)
	void SetVariableValue(scriptInstance_t a1, VariableValue * a2, unsigned int a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov edi, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// VariableValue __usercall Scr_EvalVariable@<edx:eax>(scriptInstance_t a1@<eax>, unsigned int a2)
	//Custom made Do not touch!
	VariableValue Scr_EvalVariable(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		VariableValue answer;
		VariableUnion u;
		VariableType typ;

		__asm
		{
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;

			mov u, eax;
			mov typ, edx;
		}

		answer.u = u;
		answer.type = typ;
		return answer;
	}

	// unsigned int __usercall Scr_EvalVariableObject@<eax>(scriptInstance_t inst@<ecx>, int a2@<eax>)
	unsigned int Scr_EvalVariableObject(scriptInstance_t inst, int a2, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov ecx, inst;
			mov eax, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// VariableValue __usercall Scr_EvalVariableEntityField@<edx:eax>(unsigned int entId@<ecx>, scriptInstance_t inst, unsigned int name)
	//Custom made Do not touch
	VariableValue Scr_EvalVariableEntityField(unsigned int entId, scriptInstance_t inst, unsigned int name, void* call_addr)
	{
		VariableValue answer;
		VariableUnion u;
		VariableType typ;

		__asm
		{
			push name;
			push inst;
			mov ecx, entId;
			call call_addr;
			mov u, eax;
			mov typ, edx;
			add esp, 0x8;
		}
		
		answer.u = u;
		answer.type = typ;
		return answer;
	}

	// VariableValue __usercall Scr_EvalVariableField@<edx:eax>(scriptInstance_t inst@<eax>, unsigned int id@<edx>)
	//Custom made do not touch
	VariableValue Scr_EvalVariableField(scriptInstance_t inst, unsigned int id, void* call_addr)
	{
		VariableValue answer;
		VariableUnion u;
		VariableType typ;

		__asm
		{
			mov eax, inst;
			mov edx, id;
			call call_addr;
			mov u, eax;
			mov typ, edx;
		}

		answer.u = u;
		answer.type = typ;
		return answer;
	}

	// void __usercall Scr_EvalSizeValue(scriptInstance_t a1@<eax>, VariableValue *value)
	void Scr_EvalSizeValue(scriptInstance_t a1, VariableValue * value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// VariableValueInternal_u __usercall GetObject@<eax>(scriptInstance_t a1@<eax>, unsigned int a2@<ecx>)
	unsigned int GetObject(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// unsigned int __usercall GetArray@<eax>(scriptInstance_t inst@<eax>, unsigned int a2@<ecx>)
	unsigned int GetArray(scriptInstance_t inst, unsigned int a2, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, inst;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall Scr_EvalBoolComplement(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>)
	void Scr_EvalBoolComplement(scriptInstance_t a1, VariableValue * a2, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			mov esi, a2;
			call call_addr;
		}
	}

	// void __usercall Scr_CastBool(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>)
	void Scr_CastBool(scriptInstance_t a1, VariableValue * a2, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			mov esi, a2;
			call call_addr;
		}
	}

	// char __usercall Scr_CastString@<al>(scriptInstance_t a1@<edi>, VariableValue *a2@<esi>)
	char Scr_CastString(scriptInstance_t a1, VariableValue * a2, void* call_addr)
	{
		char answer;
		
		__asm
		{
			mov edi, a1;
			mov esi, a2;
			call call_addr;
			mov answer, al;
		}
		
		return answer;
	}

	// void __usercall Scr_CastDebugString(scriptInstance_t a1@<ecx>, VariableValue *a2@<eax>)
	void Scr_CastDebugString(scriptInstance_t a1, VariableValue * a2, void* call_addr)
	{
		__asm
		{
			mov ecx, a1;
			mov eax, a2;
			call call_addr;
		}
	}

	// void __usercall Scr_CastVector(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>)
	void Scr_CastVector(scriptInstance_t a1, VariableValue * a2, void* call_addr)
	{
		__asm
		{
			mov eax, a1;
			mov esi, a2;
			call call_addr;
		}
	}

	// VariableUnion __usercall Scr_EvalFieldObject@<eax>(VariableValue *a1@<eax>, scriptInstance_t inst, int a3)
	VariableUnion Scr_EvalFieldObject(VariableValue * a1, scriptInstance_t inst, int a3, void* call_addr)
	{
		VariableUnion answer;
		
		__asm
		{
			push a3;
			push inst;
			mov eax, a1;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// void __usercall Scr_UnmatchingTypesError(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>, VariableValue *value)
	void Scr_UnmatchingTypesError(scriptInstance_t a1, VariableValue * a2, VariableValue * value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, a1;
			mov esi, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_CastWeakerPair(VariableValue *a1@<ecx>, VariableValue *a2@<edi>, scriptInstance_t a3@<eax>)
	void Scr_CastWeakerPair(VariableValue * a1, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			mov ecx, a1;
			mov edi, a2;
			mov eax, a3;
			call call_addr;
		}
	}

	// void __usercall Scr_CastWeakerStringPair(VariableValue *a1@<eax>, VariableValue *a2@<ecx>, scriptInstance_t inst)
	void Scr_CastWeakerStringPair(VariableValue * a1, VariableValue * a2, scriptInstance_t inst, void* call_addr)
	{
		__asm
		{
			push inst;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalOr(VariableValue *result@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalOr(VariableValue * result, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalExOr(VariableValue *result@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalExOr(VariableValue * result, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalAnd(VariableValue *result@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalAnd(VariableValue * result, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalEquality(VariableValue *a1@<eax>, scriptInstance_t inst, VariableValue *a4)
	void Scr_EvalEquality(VariableValue * a1, scriptInstance_t inst, VariableValue * a4, void* call_addr)
	{
		__asm
		{
			push a4;
			push inst;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_EvalLess(VariableValue *a1@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalLess(VariableValue * a1, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalGreaterEqual(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>, VariableValue *a3)
	void Scr_EvalGreaterEqual(scriptInstance_t a1, VariableValue * a2, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov esi, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalGreater(VariableValue *a1@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalGreater(VariableValue * a1, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalLessEqual(scriptInstance_t a1@<eax>, VariableValue *a2@<esi>, VariableValue *a3)
	void Scr_EvalLessEqual(scriptInstance_t a1, VariableValue * a2, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov esi, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalShiftLeft(VariableValue *result@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalShiftLeft(VariableValue * result, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalShiftRight(VariableValue *result@<eax>, VariableValue *a2@<ecx>, scriptInstance_t a3)
	void Scr_EvalShiftRight(VariableValue * result, VariableValue * a2, scriptInstance_t a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalPlus(scriptInstance_t a@<ecx>, VariableValue *a1, VariableValue *a2)
	void Scr_EvalPlus(scriptInstance_t a, VariableValue * a1, VariableValue * a2, void* call_addr)
	{
		__asm
		{
			push a2;
			push a1;
			mov ecx, a;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_EvalMinus(VariableValue *a1@<eax>, scriptInstance_t a2, VariableValue *a3)
	void Scr_EvalMinus(VariableValue * a1, scriptInstance_t a2, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_EvalMultiply(VariableValue *a1@<eax>, scriptInstance_t a2, VariableValue *a3)
	void Scr_EvalMultiply(VariableValue * a1, scriptInstance_t a2, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push a2;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_EvalDivide(VariableValue *a1@<eax>, scriptInstance_t inst, VariableValue *a3)
	void Scr_EvalDivide(VariableValue * a1, scriptInstance_t inst, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			push inst;
			mov eax, a1;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_EvalMod(scriptInstance_t a1@<eax>, VariableValue *a2@<ecx>, VariableValue *a3)
	void Scr_EvalMod(scriptInstance_t a1, VariableValue * a2, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_EvalBinaryOperator(scriptInstance_t a1@<eax>, VariableValue *a2@<ecx>, OpcodeVM a4, VariableValue *a5)
	void Scr_EvalBinaryOperator(scriptInstance_t a1, VariableValue * a2, OpcodeVM a4, VariableValue * a5, void* call_addr)
	{
		__asm
		{
			push a5;
			push a4;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			add esp, 0x8;
		}
	}

	// void __usercall Scr_FreeEntityNum(scriptInstance_t inst@<ecx>, unsigned int result@<eax>, unsigned int a3)
	void Scr_FreeEntityNum(scriptInstance_t inst, unsigned int classnum, unsigned int entnum, void* call_addr)
	{
		__asm
		{
			push entnum;
			mov ecx, inst;
			mov eax, classnum;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_SetClassMap(scriptInstance_t a1@<esi>, unsigned int a2)
	void Scr_SetClassMap(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov esi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// void __usercall Scr_RemoveClassMap(unsigned int result@<eax>, scriptInstance_t a2@<edi>)
	void Scr_RemoveClassMap(unsigned int result, scriptInstance_t a2, void* call_addr)
	{
		__asm
		{
			mov eax, result;
			mov edi, a2;
			call call_addr;
		}
	}

	// void __usercall Scr_AddClassField(scriptInstance_t inst@<ecx>, unsigned int a2@<eax>, char *name, unsigned int a4)
	void Scr_AddClassField(scriptInstance_t inst, unsigned int classnum, const char * name, unsigned int offset_, void* call_addr)
	{
		__asm
		{
			push offset_;
			push name;
			mov ecx, inst;
			mov eax, classnum;
			call call_addr;
			add esp, 0x8;
		}
	}

	// int __usercall Scr_GetOffset@<eax>(char *name@<eax>, scriptInstance_t inst@<edi>, classNum_e classNum)
	VariableUnion Scr_GetOffset(const char * name, scriptInstance_t inst, classNum_e classNum, void* call_addr)
	{
		VariableUnion answer;
		
		__asm
		{
			push classNum;
			mov eax, name;
			mov edi, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// unsigned int __usercall FindEntityId@<eax>(unsigned int entClass@<eax>, int entNum@<ecx>, scriptInstance_t inst@<edi>)
	unsigned int FindEntityId(unsigned int entClass, int entNum, scriptInstance_t inst, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov eax, entClass;
			mov ecx, entNum;
			mov edi, inst;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// unsigned int __usercall Scr_GetEntityId@<eax>(int entNum@<eax>, scriptInstance_t inst, classNum_e classnum, int clientnum)
	unsigned int Scr_GetEntityId(int entNum, scriptInstance_t inst, classNum_e classnum, int clientnum, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push clientnum;
			push classnum;
			push inst;
			mov eax, entNum;
			call call_addr;
			mov answer, eax;
			add esp, 0xC;
		}
		
		return answer;
	}

	// unsigned int __usercall Scr_FindArrayIndex@<eax>(scriptInstance_t a1@<eax>, VariableValue *a2@<ecx>, int a3)
	unsigned int Scr_FindArrayIndex(scriptInstance_t a1, VariableValue * a2, unsigned int a3, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// void __usercall Scr_EvalArray(scriptInstance_t a2@<ecx>, VariableValue *eax0@<eax>, VariableValue *a3)
	void Scr_EvalArray(scriptInstance_t a2, VariableValue * eax0, VariableValue * a3, void* call_addr)
	{
		__asm
		{
			push a3;
			mov ecx, a2;
			mov eax, eax0;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall Scr_EvalArrayRef@<eax>(scriptInstance_t a2@<ecx>, unsigned int eax0@<eax>)
	unsigned int Scr_EvalArrayRef(scriptInstance_t a2, unsigned int eax0, void* call_addr)
	{
		unsigned int answer;
		
		__asm
		{
			mov ecx, a2;
			mov eax, eax0;
			call call_addr;
			mov answer, eax;
		}
		
		return answer;
	}

	// void __usercall ClearArray(unsigned int parentId@<eax>, scriptInstance_t inst@<ecx>, VariableValue *value)
	void ClearArray(unsigned int parentId, scriptInstance_t inst, VariableValue * value, void* call_addr)
	{
		__asm
		{
			push value;
			mov eax, parentId;
			mov ecx, inst;
			call call_addr;
			add esp, 0x4;
		}
	}

	// unsigned int __usercall SetEmptyArray@<eax>(scriptInstance_t a1@<edi>, unsigned int a2)
	void SetEmptyArray(scriptInstance_t a1, unsigned int a2, void* call_addr)
	{
		__asm
		{
			push a2;
			mov edi, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// scr_entref_t *__usercall Scr_GetEntityIdRef@<eax>(scr_entref_t *result@<eax>, scriptInstance_t a2@<ecx>, unsigned int a3)
	scr_entref_t * Scr_GetEntityIdRef(scr_entref_t * result, scriptInstance_t a2, unsigned int a3, void* call_addr)
	{
		scr_entref_t * answer;
		
		__asm
		{
			push a3;
			mov eax, result;
			mov ecx, a2;
			call call_addr;
			mov answer, eax;
			add esp, 0x4;
		}
		
		return answer;
	}

	// void __usercall Scr_CopyEntityNum(unsigned int a1@<eax>, unsigned int parentId)
	void CopyEntity(unsigned int parentId, unsigned int newParentId, void* call_addr)
	{
		__asm
		{
			push newParentId;
			mov eax, parentId;
			call call_addr;
			add esp, 0x4;
		}
	}

	// float __usercall Scr_GetEndonUsage@<st0>(unsigned int a1@<ecx>, scriptInstance_t a2@<edi>)
	float Scr_GetEndonUsage(unsigned int a1, scriptInstance_t a2, void* call_addr)
	{
		float answer;

		__asm
		{
			mov ecx, a1;
			mov edi, a2;
			call call_addr;
			fstp answer;
		}

		return answer;
	}

	// float __usercall Scr_GetThreadUsage@<xmm0>(VariableStackBuffer *a1@<eax>, scriptInstance_t a2@<ecx>, float *a3)
	float Scr_GetThreadUsage(VariableStackBuffer * a1, scriptInstance_t a2, float * a3, void* call_addr)
	{
		float answer;
		
		__asm
		{
			push a3;
			mov eax, a1;
			mov ecx, a2;
			call call_addr;
			movss answer, xmm0;
			add esp, 0x4;
		}
		
		return answer;
	}

	// int __usercall Scr_FindField@<eax>(scriptInstance_t a1@<eax>, unsigned __int8 *a2, int *a3)
	unsigned int Scr_FindField(scriptInstance_t inst, const char * name, int * type_, void* call_addr)
	{
		int answer;
		
		__asm
		{
			push type_;
			push name;
			mov eax, inst;
			call call_addr;
			mov answer, eax;
			add esp, 0x8;
		}
		
		return answer;
	}

	// void __usercall Scr_FreeGameVariable(scriptInstance_t a1@<eax>, int bComplete)
	void Scr_FreeGameVariable(scriptInstance_t a1, int bComplete, void* call_addr)
	{
		__asm
		{
			push bComplete;
			mov eax, a1;
			call call_addr;
			add esp, 0x4;
		}
	}

	// char __usercall Scr_CreateLowercaseString@<al>(int a1@<eax>, const char *a2@<edx>)
	bool Scr_SLHasLowercaseString(unsigned int a1, const char * a2, void* call_addr)
	{
		char answer;
		
		__asm
		{
			mov eax, a1;
			mov edx, a2;
			call call_addr;
			mov answer, al;
		}
		
		return answer;
	}

	unsigned int FindObject(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::FindObject(inst, id);
	}

	float Scr_GetEntryUsageInternal(scriptInstance_t inst, unsigned int type, VariableUnion u)
	{
		return codsrc::Scr_GetEntryUsageInternal(inst, type, u);
	}

	float Scr_GetEntryUsage(scriptInstance_t inst, VariableValueInternal* entryValue)
	{
		return codsrc::Scr_GetEntryUsage(inst, entryValue);
	}

	unsigned int FindFirstSibling(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::FindFirstSibling(inst, id);
	}

	unsigned int FindNextSibling(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::FindNextSibling(inst, id);
	}

	VariableValue Scr_GetArrayIndexValue(scriptInstance_t inst, unsigned int name)
	{
		return codsrc::Scr_GetArrayIndexValue(inst, name);
	}

	void AddRefToObject(scriptInstance_t inst, unsigned int id)
	{
		codsrc::AddRefToObject(inst, id);
	}

	void RemoveRefToEmptyObject(scriptInstance_t inst, unsigned int id)
	{
		codsrc::RemoveRefToEmptyObject(inst, id);
	}

	void Scr_ClearThread(scriptInstance_t inst, unsigned int parentId)
	{
		codsrc::Scr_ClearThread(inst, parentId);
	}

	unsigned int FindObjectVariable(scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		return codsrc::FindObjectVariable(inst, parentId, id);
	}

	void RemoveObjectVariable(scriptInstance_t inst, unsigned int parentId, unsigned int id)
	{
		codsrc::RemoveObjectVariable(inst, parentId, id);
	}

	VariableValueInternal_u* GetVariableValueAddress(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::GetVariableValueAddress(inst, id);
	}

	void Scr_KillEndonThread(scriptInstance_t inst, unsigned int threadId)
	{
		codsrc::Scr_KillEndonThread(inst, threadId);
	}

	BOOL IsValidArrayIndex(scriptInstance_t inst, unsigned int unsignedValue)
	{
		return codsrc::IsValidArrayIndex(inst, unsignedValue);
	}

	void RemoveArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		codsrc::RemoveArrayVariable(inst, parentId, unsignedValue);
	}

	void SafeRemoveArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		codsrc::SafeRemoveArrayVariable(inst, parentId, unsignedValue);
	}

	void AddRefToVector(scriptInstance_t inst, const float* floatVal)
	{
		codsrc::AddRefToVector(inst, floatVal);
	}

	unsigned int FindArrayVariableIndex(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return codsrc::FindArrayVariableIndex(inst, parentId, unsignedValue);
	}

	unsigned int GetVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		return codsrc::GetVariableIndexInternal(inst, parentId, name);
	}

	unsigned int GetNewVariableIndexInternal(scriptInstance_t inst, unsigned int parentId, unsigned int name)
	{
		return codsrc::GetNewVariableIndexInternal(inst, parentId, name);
	}

	unsigned int AllocObject(scriptInstance_t inst)
	{
		return codsrc::AllocObject(inst);
	}

	VariableType GetValueType(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::GetValueType(inst, id);
	}

	VariableType GetObjectType(scriptInstance_t inst, unsigned int id)
	{
		return codsrc::GetObjectType(inst, id);
	}

	float* Scr_AllocVector_(scriptInstance_t inst, const float* v)
	{
		return codsrc::Scr_AllocVector_(inst, v);
	}

	void Scr_EvalInequality(scriptInstance_t inst, VariableValue* value1, VariableValue* value2)
	{
		codsrc::Scr_EvalInequality(inst, value1, value2);
	}

	unsigned int Scr_EvalArrayRefInternal(scriptInstance_t inst, VariableValue* varValue, VariableValueInternal* parentValue)
	{
		return codsrc::Scr_EvalArrayRefInternal(inst, varValue, parentValue);
	}

	unsigned int GetNewArrayVariableIndex(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return codsrc::GetNewArrayVariableIndex(inst, parentId, unsignedValue);
	}

	unsigned int GetNewArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return codsrc::GetNewArrayVariable(inst, parentId, unsignedValue);
	}

	unsigned int GetArrayVariable(scriptInstance_t inst, unsigned int parentId, unsigned int unsignedValue)
	{
		return codsrc::GetArrayVariable(inst, parentId, unsignedValue);
	}

	unsigned int AllocThread(scriptInstance_t inst, unsigned int self)
	{
		return codsrc::AllocThread(inst, self);
	}
}
