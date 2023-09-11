#include <stdinc.hpp>
#include "clientscript_public.hpp"

#pragma warning(push)
#pragma warning(disable: 4102)
#pragma warning(disable: 4244)
namespace codsrc
{
	// Decomp Status: Completed
	unsigned int LowerCase(unsigned int strVal)
	{
	  return game::SL_ConvertToLowercase(*game::gInst, strVal, *game::g_parse_user);
	}

	// Decomp Status: Completed
	int yyparse()
	{
		/*-------------------------.
		| yyparse or yypush_parse.  |
		`-------------------------*/

		int yystate;
		/* Number of tokens to shift before error messages enabled.  */
		int yyerrorstatus;

		/* The semantic value stack.  */
		game::stype_t yyvsa[200]; // YYINITDEPTH
		game::stype_t *yyvsp;
		game::stype_t *yyvs;

		/* The stacks and their tools:
		`yyss': related to states.
		`yyvs': related to semantic values.

		Refer to the stacks thru separate pointers, to allow yyoverflow
		to reallocate them elsewhere.  */

		/* The state stack.  */
		__int16 yyssa[200]; // YYINITDEPTH
		__int16 *yyss;
		__int16 *yyssp;

		int yystacksize;

		int yyn;
		/* Lookahead token as an internal (translated) token number.  */
		int yytoken; // yychar1
		/* The variables used to return semantic value and location from the
		action routines.  */
		game::stype_t yyval;

		__int16 *yyss1;
		int yysize;
		game::stype_t *yyvs1;

		game::sval_u valstack[6];
		unsigned int s;

		/* The number of symbols on the RHS of the reduced rule.
		Keep to zero when no symbol should be popped.  */
		int yylen = 0;

		yytoken = 0;
		yyss = yyssa;
		yyvs = yyvsa;
		yystacksize = 200; // YYINITDEPTH

		// YYDPRINTF ((stderr, "Starting parse\n"));

		yystate = 0;
		yyerrorstatus = 0;
		*game::yynerrs = 0;
		*game::yychar = -2; // YYEMPTY /* Cause a token to be read.  */

		/* Initialize stack pointers.
		Waste one element of value and location stack
		so that they stay on the same level as the state stack.
		The wasted elements are never initialized.  */
		yyssp = yyss;
		yyvsp = yyvs;

		goto yysetstate;

		while ( 1 )
		{
		/*------------------------------------------------------------.
		| yynewstate -- Push a new state, which is found in yystate.  |
		`------------------------------------------------------------*/
		yynewstate:
			/* In all cases, when you get here, the value and location stacks
			have just been pushed.  So pushing a state here evens the stacks.  */
			yyssp++;

		yysetstate:
			*yyssp = (short)yystate;

			if ( yyssp >= &yyss[yystacksize - 1] )
			{
				/* Get the current used size of the three stacks, in elements.  */
				yysize = yyssp - yyss + 1;

				yyvs1 = yyvs;
				yyss1 = yyss;

				/* Extend the stack our own way.  */
				if ( yystacksize >= 10000 ) // YYMAXDEPTH
				{
					if ( !*game::yychar ) // yyerror yyexhaustedlab
					{
						game::CompileError(*game::gInst, *game::g_sourcePos, "unexpected end of file found");
					}

					if ( *game::yychar != 257 )
					{
						game::CompileError(*game::gInst, *game::g_sourcePos, "bad syntax");
					}

					return 0;
				}

				yystacksize *= 2;
				if ( yystacksize > 10000 ) // YYMAXDEPTH
				{
					yystacksize = 10000; // YYMAXDEPTH
				}

				// YYSTACK_RELOCATE (yyss_alloc, yyss);
				s = sizeof(__int16) * yystacksize;
				yyss = (__int16 *)alloca(s);
				memcpy(yyss, yyss1, s);

				// YYSTACK_RELOCATE (yyvs_alloc, yyvs);
				s = sizeof(game::stype_t) * yystacksize;
				yyvs = (game::stype_t *)alloca(s);
				memcpy(yyss, yyvs1, s);

				yyvsp = &yyvs[yysize - 1];
				yyssp = &yyss[yysize - 1];

				// YYDPRINTF ((stderr, "Stack size increased to %lu\n", (unsigned long int) yystacksize));

				if ( yyssp >= &yyss[yystacksize - 1] )
				{
					return 1;                               // yyabortlab  YYABORT
				}
			}

			goto yybackup;

		/*-----------.
		| yybackup.  |
		`-----------*/
		yybackup:

			/* Do appropriate processing given the current state.  Read a
			lookahead token if we need one and don't already have one.  */

			/* First try to decide what to do without reference to lookahead token.  */
			yyn = game::yypact[yystate];

			if ( yyn == -32768 ) // YYPACT_NINF
			{
				break; // yydefault
			}

			/* Not known => get a lookahead token if don't already have one.  */

			/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
			if ( *game::yychar == -2 )
			{
				// YYDPRINTF ((stderr, "Reading a token: "));
				*game::yychar = game::yylex();
			}

			if ( *game::yychar > 0 ) // YYEOF
			{
				yytoken = (unsigned int)*game::yychar > 0x158 ? 119 : game::yytranslate[*game::yychar];// t5 is 0x159 and 120  YYTRANSLATE 
				// YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
			}
			else
			{
				yytoken = 0;
				*game::yychar = 0;
				// YYDPRINTF ((stderr, "Now at end of input.\n"));
			}

			/* If the proper action on seeing token YYTOKEN is to reduce or to
			detect an error, take that action.  */
			yyn += yytoken;

			if ( yyn < 0 || yyn > 0x543 || game::yycheck[yyn] != yytoken ) // 0x59B on t5  YYLAST
			{
				break; // yydefault
			}

			yyn = game::yytable[yyn];

			if ( yyn >= 0 )
			{
				if ( !yyn )
				{
					goto yyerrlab;
				}

				if ( yyn == 261 )                         // 267 on t5   YYFINAL
				{
					return 0;                               // yyacceptlab
				}

				if ( *game::yychar )
				{
					/* Shift the lookahead token.  */
					//YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

					/* Discard the shifted token.  */
					*game::yychar = -2;
				}

				*++yyvsp = *game::yylval;

				/* Count tokens shifted since error; after three, turn off error
				status.  */
				if ( yyerrorstatus )
				{
					--yyerrorstatus;
				}

				yystate = yyn;
				continue; // yynewstate
			}
			else
			{
				if ( yyn == -32768 ) // YYTABLE_NINF
				{
					goto yyerrlab;
				}

				yyn = -yyn;

			/*-----------------------------.
			| yyreduce -- Do a reduction.  |
			`-----------------------------*/
			yyreduce:
				/* yyn is the number of a rule to reduce with.  */
				yylen = game::yyr2[yyn];

				/* If YYLEN is nonzero, implement the default value of the action:
				`$$ = $1'.

				Otherwise, the following line sets YYVAL to garbage.
				This behavior is undocumented and Bison
				users should not rely upon it.  Assigning to YYVAL
				unconditionally makes the parser a bit smaller, and it avoids a
				GCC warning that YYVAL may be used uninitialized.  */
				// if ( yylen > 0 )
				{
					yyval = yyvsp[1 - yylen];
				}

				// YY_REDUCE_PRINT (yyn);
				switch ( yyn )
				{
				case 1u:
					*game::yaccResult = game::node1((game::scr_enum_t)yyvsp[-1].val.stringValue, yyvsp->val);// node2_
					break;
				case 2u:
					*game::yaccResult = game::node1(game::ENUM_expression, yyvsp->val);// node1
					break;
				case 3u:
				case 4u:
					*game::yaccResult = game::node1(game::ENUM_statement, yyvsp->val);
					break;
				case 5u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_primitive_expression, yyvsp->val, valstack[5]);
					break;
				case 6u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].stringValue = yyvsp->pos;
					valstack[3].stringValue = yyvsp[-2].pos;
					valstack[2] = yyvsp->val;
					valstack[1] = yyvsp[-2].val;

					yyval.val = game::node5(
						game::ENUM_bool_or,
						valstack[1],
						valstack[2],
						valstack[3],
						valstack[4],
						valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 7u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].stringValue = yyvsp->pos;
					valstack[3].stringValue = yyvsp[-2].pos;
					valstack[2] = yyvsp->val;
					valstack[1] = yyvsp[-2].val;

					yyval.val = game::node5(
						game::ENUM_bool_and,
						valstack[1],
						valstack[2],
						valstack[3],
						valstack[4],
						valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 8u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_or;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 9u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_ex_or;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xAu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_and;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xBu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_equality;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xCu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_inequality;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xDu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_less;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xEu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_greater;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0xFu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_less_equal;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x10u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_greater_equal;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x11u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_shift_left;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x12u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_shift_right;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x13u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_plus;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x14u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_minus;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x15u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_multiply;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x16u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_divide;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x17u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_mod;
					yyval.val = game::node4(game::ENUM_binary, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					break;
				case 0x18u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_bool_not, yyvsp->val, valstack[5]);
					break;
				case 0x19u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_bool_complement, yyvsp->val, valstack[5]);
					break;
				case 0x1Au:
					yyval.val = game::node1(game::ENUM_expression, yyvsp->val);
					break;
				case 0x1Bu:
				case 0x5Fu:
				case 0x69u:
				case 0x72u:
					yyval.val = game::node0();
					break;
				case 0x1Cu:
				case 0x1Du:
					yyvsp->val.stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyval.val = yyvsp->val;
					break;
				case 0x1Eu:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					valstack[3] = yyvsp[-2].val;
					yyvsp->val = valstack[4];

					yyval.val = game::node3(game::ENUM_far_function, valstack[3], valstack[4], valstack[5]);
					++game::gScrCompilePub[*game::gInst].far_function_count;
					break;
				case 0x1Fu:
					valstack[5].sourcePosValue = yyvsp->pos; // node_pos
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node2(game::ENUM_local_function, valstack[4], valstack[5]);
					break;
				case 0x20u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					valstack[3] = yyvsp[-2].val;
					yyvsp->val = valstack[4];

					yyval.val = game::node3(game::ENUM_far_function, valstack[3], valstack[4], valstack[5]);
					yyval.pos = yyvsp[-1].pos;
					++game::gScrCompilePub[*game::gInst].far_function_count;
					break;
				case 0x21u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node2(game::ENUM_local_function, valstack[4], valstack[5]);
					break;
				case 0x22u:
				case 0x37u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_function, yyvsp->val, valstack[5]);
					break;
				case 0x23u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node2(game::ENUM_function_pointer, yyvsp[-2].val, valstack[5]);
					break;
				case 0x24u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_script_call, yyvsp->val, valstack[5]);
					break;
				case 0x25u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node3(game::ENUM_script_thread_call, yyvsp->val, valstack[4], valstack[5]);
					yyval.pos = yyvsp->pos;
					break;
				case 0x26u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node3(game::ENUM_call, yyvsp[-3].val, yyvsp[-1].val, valstack[5]);
					yyval.pos = yyvsp[-2].pos;
					break;
				case 0x27u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node5(
						game::ENUM_method,
						yyvsp[-4].val,
						yyvsp[-3].val,
						yyvsp[-1].val,
						valstack[4],
						valstack[5]);
					yyval.pos = yyvsp[-2].pos;
					break;
				case 0x28u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node2(game::ENUM_expression_list, yyvsp[-1].val, valstack[5]);
					break;
				case 0x29u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_integer, yyvsp->val, valstack[5]);
					break;
				case 0x2Au:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_float, yyvsp->val, valstack[5]);
					break;
				case 0x2Bu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_minus_integer, yyvsp->val, valstack[5]);
					break;
				case 0x2Cu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_minus_float, yyvsp->val, valstack[5]);
					break;
				case 0x2Du:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_string, yyvsp->val, valstack[5]);
					break;
				case 0x2Eu:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_istring, yyvsp->val, valstack[5]);
					break;
				case 0x2Fu:
					yyval.val = game::node1(game::ENUM_call_expression, yyvsp->val);
					break;
				case 0x30u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node2(game::ENUM_variable, yyvsp->val, valstack[5]);
					break;
				case 0x31u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_undefined, valstack[5]);
					break;
				case 0x32u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_self, valstack[5]);
					break;
				case 0x33u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_level, valstack[5]);
					break;
				case 0x34u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_game, valstack[5]);
					break;
				case 0x35u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_anim, valstack[5]);
					break;
				case 0x36u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_size_field, yyvsp[-1].val, valstack[5]);
					yyval.pos = yyvsp->pos;
					break;
				case 0x38u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node1(game::ENUM_empty_array, valstack[5]);
					break;
				case 0x39u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node2(game::ENUM_animation, valstack[4], valstack[5]);
					break;
				case 0x3Au:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_false, valstack[5]);
					break;
				case 0x3Bu:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_true, valstack[5]);
					break;
				case 0x3Cu:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_animtree, valstack[5]);
					break;
				case 0x3Du:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					yyval.val = game::node3(game::ENUM_breakon, yyvsp[-4].val, yyvsp[-1].val, valstack[5]);
					break;
				case 0x3Eu:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node3(game::ENUM_field_variable, yyvsp[-2].val, valstack[4], valstack[5]);
					yyval.pos = yyvsp->pos;
					break;
				case 0x3Fu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].sourcePosValue = yyvsp[-3].pos;
					yyval.val = game::node4(game::ENUM_array_variable, yyvsp[-3].val, yyvsp[-1].val, valstack[4], valstack[5]);
					yyval.pos = yyvsp[-2].pos;
					break;
				case 0x40u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node2(game::ENUM_local_variable, valstack[4], valstack[5]);
					break;
				case 0x41u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					yyval.val = game::node2(game::ENUM_object, valstack[4], valstack[5]);
					break;
				case 0x42u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node2(game::ENUM_self_field, yyvsp[-2].val, valstack[5]);
					yyval.pos = yyvsp->pos;
					break;
				case 0x43u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node4(game::ENUM_assignment, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x44u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_return, yyvsp->val, valstack[5]);
					break;
				case 0x45u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_return2, valstack[5]);
					break;
				case 0x46u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].sourcePosValue = yyvsp->pos;
					yyval.val = game::node3(game::ENUM_wait, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x47u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_inc, yyvsp[-1].val, valstack[5]);
					break;
				case 0x48u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_dec, yyvsp[-1].val, valstack[5]);
					break;
				case 0x49u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_or;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Au:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_ex_or;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Bu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_bit_and;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Cu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_shift_left;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Du:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_shift_right;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Eu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_plus;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x4Fu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_minus;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x50u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_multiply;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x51u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_divide;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x52u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].intValue = game::OP_mod;
					yyval.val = game::node4(game::ENUM_binary_equals, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5]);
					break;
				case 0x53u:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node4(game::ENUM_waittill, yyvsp[-4].val, yyvsp[-1].val, valstack[4], valstack[5]);
					break;
				case 0x54u:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node4(game::ENUM_waittillmatch, yyvsp[-4].val, yyvsp[-1].val, valstack[4], valstack[5]);
					break;
				case 0x55u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_waittillFrameEnd, valstack[5]);
					break;
				case 0x56u:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node4(game::ENUM_notify, yyvsp[-4].val, yyvsp[-1].val, valstack[4], valstack[5]);
					break;
				case 0x57u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node4(game::ENUM_endon, yyvsp[-4].val, yyvsp[-1].val, valstack[4], valstack[5]);
					break;
				case 0x58u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_break, valstack[5]);
					break;
				case 0x59u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_continue, valstack[5]);
					break;
				case 0x5Au:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_breakpoint, valstack[5]);
					break;
				case 0x5Bu:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					yyval.val = game::node2(game::ENUM_prof_begin, yyvsp[-1].val, valstack[5]);
					break;
				case 0x5Cu:
					valstack[5].sourcePosValue = yyvsp[-3].pos;
					yyval.val = game::node2(game::ENUM_prof_end, yyvsp[-1].val, valstack[5]);
					break;
				case 0x5Du:
					yyval.val = game::node1(game::ENUM_call_expression_statement, yyvsp->val);
					break;
				case 0x62u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node3(game::ENUM_statement_list, yyvsp[-1].val, valstack[4], valstack[5]);
					break;
				case 0x63u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node4(game::ENUM_if, yyvsp[-2].val, yyvsp->val, valstack[5], *game::g_dummyVal);
					break;
				case 0x64u: // this 0x65 on t5
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node7( // game::ENUM_if_else inlined opti arg
						yyvsp[-4].val,
						yyvsp[-2].val,
						yyvsp->val,
						valstack[4],
						valstack[5],
						*game::g_dummyVal,
						*game::g_dummyVal);
					break;
				case 0x65u:
					valstack[5].sourcePosValue = yyvsp[-4].pos;
					valstack[4].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node5(game::ENUM_while, yyvsp[-2].val, yyvsp->val, valstack[4], valstack[5], *game::g_dummyVal);
					break;
				case 0x66u:
					valstack[5].sourcePosValue = yyvsp[-7].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node8( // game::ENUM_for inlined
						yyvsp[-5].val,
						yyvsp[-4].val,
						yyvsp[-2].val,
						yyvsp->val,
						valstack[4],
						valstack[5],
						*game::g_dummyVal,
						*game::g_dummyVal);
					break;
				case 0x67u:
					valstack[5].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node3(game::ENUM_switch, yyvsp[-4].val, yyvsp[-1].val, valstack[5]);
					break;
				case 0x68u:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node3(game::ENUM_developer_statement_list, yyvsp[-1].val, valstack[5], *game::g_dummyVal);
					break;
				case 0x6Au:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					yyval.val = game::node3(game::ENUM_case, yyvsp[-1].val, valstack[5], *game::g_dummyVal);
					break;
				case 0x6Bu:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_default, valstack[5], *game::g_dummyVal);
					break;
				case 0x6Du:
				case 0x81u:
					yyval.val = game::append_node(yyvsp[-1].val, yyvsp->val);
					break;
				case 0x6Eu:
				case 0x76u:
				case 0x82u:
				case 0x85u:
					valstack[5] = game::node0();
					yyval.val = game::linked_list_end(valstack[5]);
					break;
				case 0x6Fu:
				case 0x7Bu:
					valstack[4].sourcePosValue = yyvsp->pos;
					valstack[5] = game::node1((game::scr_enum_t)yyvsp->val.stringValue, valstack[4]);
					yyval.val = game::prepend_node(valstack[5], yyvsp[-2].val);
					break;
				case 0x70u:
				case 0x7Cu:
					valstack[3].sourcePosValue = yyvsp->pos;
					valstack[5] = game::node0();
					valstack[4] = game::node1((game::scr_enum_t)yyvsp->val.stringValue, valstack[3]);
					yyval.val = game::prepend_node(valstack[4], valstack[5]);
					break;
				case 0x73u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					valstack[3] = game::node1((game::scr_enum_t)valstack[4].stringValue, valstack[5]);
					yyval.val = game::append_node(yyvsp[-2].val, valstack[3]);
					break;
				case 0x74u:
					yyvsp->val.stringValue = game::LowerCase(yyvsp->val.stringValue);
					valstack[5].stringValue = yyvsp->pos;
					valstack[4] = game::node1((game::scr_enum_t)yyvsp->val.stringValue, valstack[5]);
					valstack[3] = game::node0();
					valstack[2] = game::linked_list_end(valstack[3]);
					yyval.val = game::append_node(valstack[2], valstack[4]);
					break;
				case 0x77u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4].stringValue = game::LowerCase(yyvsp->val.stringValue);
					yyvsp->val = valstack[4];
					valstack[3] = game::node1((game::scr_enum_t)valstack[4].stringValue, valstack[5]);
					yyval.val = game::append_node(yyvsp[-2].val, valstack[3]);
					break;
				case 0x78u:
				case 0x7Au:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4] = yyvsp->val;
					valstack[3] = game::node1((game::scr_enum_t)valstack[4].stringValue, valstack[5]);
					valstack[2] = game::node0();
					valstack[1] = game::linked_list_end(valstack[2]);
					yyval.val = game::append_node(valstack[1], valstack[3]);
					break;
				case 0x79u:
					valstack[5].sourcePosValue = yyvsp->pos;
					valstack[4] = yyvsp->val;
					valstack[3] = game::node1((game::scr_enum_t)valstack[4].stringValue, valstack[5]);
					yyval.val = game::append_node(yyvsp[-2].val, valstack[3]);
					break;
				case 0x7Du:
					valstack[5] = *game::g_dummyVal;
					valstack[4].stringValue = yyvsp->pos;
					valstack[3].stringValue = yyvsp[-6].pos;
					valstack[2] = yyvsp[-1].val;
					valstack[1] = yyvsp[-4].val;
					valstack[0].stringValue = game::LowerCase(yyvsp[-6].val.stringValue);
					yyvsp[-6].val = valstack[0];
					yyval.val = game::node6(valstack[0], valstack[1], valstack[2], valstack[3], valstack[4], valstack[5]); // game::ENUM_thread inlined
					break;
				case 0x7Eu:
					valstack[5].sourcePosValue = yyvsp[-2].pos;
					valstack[4].sourcePosValue = yyvsp[-4].pos;
					yyval.val = game::node3(game::ENUM_usingtree, yyvsp[-2].val, valstack[4], valstack[5]);
					break;
				case 0x7Fu:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_begin_developer_thread, valstack[5]);
					break;
				case 0x80u:
					valstack[5].sourcePosValue = yyvsp->pos;
					yyval.val = game::node1(game::ENUM_end_developer_thread, valstack[5]);
					break;
				case 0x83u:
					valstack[5].sourcePosValue = yyvsp[-1].pos;
					yyval.val = game::node2(game::ENUM_include, yyvsp->val, valstack[5]);
					++game::gScrCompilePub[*game::gInst].far_function_count;
					break;
				case 0x84u:
					yyval.val = game::append_node(yyvsp[-2].val, yyvsp[-1].val);
					break;
				default:
					break;
				}
				
				// YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

				yyvsp -= yylen;
				yyssp -= yylen;
				yylen = 0;

				// YY_STACK_PRINT (yyss, yyssp);

				*++yyvsp = yyval;

				/* Now `shift' the result of the reduction.  Determine what state
				that goes to, based on the state we popped back to and the rule
				number reduced by.  */
				yyn = game::yyr1[yyn];

				yystate = *yyssp + game::yypgoto[yyn]; // yystate = yypgoto[yyn - YYNTOKENS] + *yyssp; ?

				if ( yystate >= 0 && yystate <= 0x543 && game::yycheck[yystate] == *yyssp ) // 0x59B on t5  YYLAST
				{
					yystate = game::yytable[yystate];
				}
				else
				{
					yystate = game::yydefgoto[yyn]; // yystate = yydefgoto[yyn - YYNTOKENS]; ?
				}

				continue; // yynewstate
			}
		}

	/*-----------------------------------------------------------.
	| yydefault -- do the default action for the current state.  |
	`-----------------------------------------------------------*/
	yydefault:
		yyn = game::yydefact[yystate];
		if ( yyn )
		{
			goto yyreduce;
		}

		goto yyerrlab;

	/*------------------------------------.
	| yyerrlab -- here on detecting error |
	`------------------------------------*/
	yyerrlab:
		/* If not already recovering from an error, report this error.  */
		if (!yyerrorstatus)
		{
			++*game::yynerrs;
			if ( !*game::yychar ) // yyerror
			{
				game::CompileError(*game::gInst, *game::g_sourcePos, "unexpected end of file found");
			}

			if ( *game::yychar != 257 )
			{
				game::CompileError(*game::gInst, *game::g_sourcePos, "bad syntax");
			}

			return 0;
		}


		if ( yyerrorstatus == 3 )
		{
			/* If just tried and failed to reuse lookahead token after an
			error, discard it.  */

			/* Return failure if at end of input.  */
			if ( !*game::yychar )
			{
				return 1; // YYABORT
			}

			// yydestruct ("Error: discarding", yytoken, &yylval);

			*game::yychar = -2;
		}

	/*-------------------------------------------------------------.
	| yyerrlab1 -- common code for both syntax error and YYERROR.  |
	`-------------------------------------------------------------*/
	yyerrlab1:
		yyerrorstatus = 3; /* Each real token shifted decrements this.  */

		while ( 2 )
		{
			yyn = game::yypact[yystate];
			if ( yyn == -32768 ) // YYPACT_NINF
			{
				goto yyerrpop;
			}

			if ( ++yyn < 0 || yyn > 0x543 || game::yycheck[yyn] != 1 ) // 0x59B on t5
			{
				goto yyerrpop;
			}

			yyn = game::yytable[yyn];
			if ( yyn < 0 )
			{
				if ( yyn != -32768 )
				{
					yyn = -yyn;
					goto yyreduce;
				}

				goto yyerrpop;
			}

			if ( !yyn )
			{
				/* Pop the current state because it cannot handle the error token.  */
			yyerrpop:
				if ( yyssp == yyss )
				{
					return 1;                               // yyabortlab
				}

				// yydestruct ("Error: popping", yystos[yystate], yyvsp);
				--yyvsp;
				yystate = *--yyssp;
				// YY_STACK_PRINT (yyss, yyssp);
				continue;
			}

			break;
		}

		if ( yyn == 261 )
		{
			return 0;
		}

		/* Shift the error token.  */
		*++yyvsp = *game::yylval;

		// YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

		yystate = yyn;
		goto yynewstate;
	}

	// Completed
	int StringValue(int len, const char *str)
	{
		int result;
		char v3;
		char stra[8192];
		char *v5;
		const char *v6;
		int v7;

		if ( len < 0x2000 )
		{
			v5 = stra;
			while ( len )
			{
				if ( *str == '\\' )
				{
					v7 = len - 1;
					if ( !v7 )
					{
						break;
					}

					v6 = str + 1;
					v3 = *v6;
					if ( *v6 == 'n' )
					{
						*v5++ = '\n';
					}
					else if ( v3 == 'r' )
					{
						*v5++ = '\r';
					}
					else
					{
						if ( v3 == 't' )
						{
							*v5 = '\t';
						}
						else
						{
							*v5 = *v6;
						}

						++v5;
					}
					len = v7 - 1;
					str = v6 + 1;
				}
				else
				{
					--len;
					*v5++ = *str++;
				}
			}

			*v5 = 0;
			game::yylval->val.stringValue = game::SL_GetString_(stra, *game::gInst, *game::g_parse_user);
			result = 1;
		}
		else
		{
			game::CompileError(*game::gInst, *game::g_sourcePos, "max string length exceeded: \"%s\"", str); // wouldn't this trigger va error?
			result = 0;
		}
		return result;
	}

	// Restored
	FILE* yy_load_buffer_state()
	{
		FILE *result;
		
		*game::yy_n_chars = (*game::yy_current_buffer)->yy_n_chars;
		*game::yy_c_buf_p = (*game::yy_current_buffer)->yy_buf_pos;
		*game::yytext = *game::yy_c_buf_p;
		result = (*game::yy_current_buffer)->yy_input_file;
		*game::yyin = (*game::yy_current_buffer)->yy_input_file;
		*game::yy_hold_char = *(*game::yy_c_buf_p);
		return result;
	}

	// Completed
	int yylex()
	{
		/** The main scanner function which does all the work.
		*/
		int yy_next_state;
		int yy_amount_of_matched_text;
		unsigned __int8 yy_c;
		char *yy_bp;
		int yy_current_state;
		int yy_act;
		char *yy_cp;
		int yy_next_buffer;

		if ( *game::yy_init )
		{
			*game::yy_init = 0;
			if ( !*game::yy_start )
			{
				*game::yy_start = 1; /* first start state */
			}

			if ( !*game::yyin )
			{
				*game::yyin = game::__iob_func();
			}

			if ( !*game::yyout )
			{
				*game::yyout = game::__iob_func() + 1;
			}

			if ( !*game::yy_current_buffer )
			{
				*game::yy_current_buffer = game::yy_create_buffer(); // optimized args
			}

			game::yy_load_buffer_state();
		}

		while ( 1 ) /* loops until end-of-file is reached */
		{
			yy_cp = *game::yy_c_buf_p;

			/* Support of yytext. */
			*(*game::yy_c_buf_p) = *game::yy_hold_char;

			/* yy_bp points to the position in yy_ch_buf of the start of
			* the current run.
			*/
			yy_bp = yy_cp;

			yy_current_state = *game::yy_start;

		yy_match:
			do
			{
				yy_c = game::yy_ec[(unsigned __int8)*yy_cp];
				if ( game::yy_accept[yy_current_state] )
				{
					*game::yy_last_accepting_state = yy_current_state;
					*game::yy_last_accepting_cpos = yy_cp;
				}
				while ( game::yy_chk[yy_c + game::yy_base[yy_current_state]] != yy_current_state )
				{
					yy_current_state = game::yy_def[yy_current_state];

					if ( yy_current_state >= 258 ) // 262 on t5
					{
						yy_c = game::yy_meta[yy_c];
					}
				}
				yy_current_state = game::yy_nxt[yy_c + game::yy_base[yy_current_state]];
				++yy_cp;
			}
			while ( game::yy_base[yy_current_state] != 435 ); // 443 on t5

		yy_find_action:

			yy_act = game::yy_accept[yy_current_state];
			if ( !game::yy_accept[yy_current_state] )
			{
				/* have to back up */
				yy_cp = *game::yy_last_accepting_cpos;
				yy_act = game::yy_accept[*game::yy_last_accepting_state];
			}

			*game::yytext = yy_bp;
			*game::yyleng = yy_cp - yy_bp;
			*game::yy_hold_char = *yy_cp;
			*yy_cp = 0;
			*game::yy_c_buf_p = yy_cp;

		do_action: /* This label is used only to access EOF actions. */
			switch ( yy_act )
			{ /* beginning of action switch */
			case 0: /* must back up */
				/* undo the effects of YY_DO_BEFORE_ACTION */
				*yy_cp = *game::yy_hold_char;
				yy_cp = *game::yy_last_accepting_cpos;
				yy_current_state = *game::yy_last_accepting_state;
				goto yy_find_action;
			case 1:
			case 3:
			case 4:
			case 5:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				break;
			case 2:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::yy_start = 3;
				*game::g_out_pos += *game::yyleng;
				break;
			case 6:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::yy_start = 5;
				*game::g_out_pos += *game::yyleng;
				break;
			case 7:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return game::StringValue(*game::yyleng - 2, *game::yytext + 1) != 0 ? 259 : 257; // t5 is equal
			case 8:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return game::StringValue(*game::yyleng - 3, *game::yytext + 2) != 0 ? 260 : 257;
			case 9:                                 // t5 has HashValue added
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 261;
			case 10:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 262;
			case 11:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 263;
			case 12:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 264;
			case 13:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 265;
			case 14:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 266;
			case 15:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 267;
			case 16:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 268;
			case 17:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 269;
			case 18:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 270;
			case 19:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 271;
			case 20:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 272;
			case 21:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 273;
			case 22:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 274;
			case 23:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 275;
			case 24:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 276;
			case 25:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 277;
			case 26:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 278;
			case 27:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 279;
			case 28:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 280;
			case 29:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 281;
			case 30:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 282;
			case 31:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 283;
			case 32:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 284;
			case 33:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 285;
			case 34:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 286;
			case 35:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				game::_sscanf(*game::yytext, "%d", game::yylval.get());       // IntegerValue
				return 287;
			case 36:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				game::_sscanf(*game::yytext, "%f", game::yylval.get());       // FloatValue
				return 288;
			case 37:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 290;
			case 38:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 289;
			case 39:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 294;
			case 40:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 291;
			case 41:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 293;
			case 42:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 292;
			case 43:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 295;
			case 44:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 296;
			case 45:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 297;
			case 46:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 298;
			case 47:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 299;
			case 48:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 300;
			case 49:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 301;
			case 50:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 302;
			case 51:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 303;
			case 52:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 304;
			case 53:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 305;
			case 54:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 306;
			case 55:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 307;
			case 56:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 308;
			case 57:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 309;
			case 58:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 310;
			case 59:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 311;
			case 60:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 312;
			case 61:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 313;
			case 62:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 314;
			case 63:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 315;
			case 64:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 316;
			case 65:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 317;
			case 66:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 318;
			case 67:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 319;
			case 68:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 320;
			case 69:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 321;
			case 70:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 322;
			case 71:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 323;
			case 72:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 325;
			case 73:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 326;
			case 74:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 327;
			case 75:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 328;
			case 76:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 329;
			case 77:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 330;
			case 78:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 331;
			case 79:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 332;
			case 80:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 333;
			case 81:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 334;
			case 82:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 335;
			case 83:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 336;
			case 84:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 337;
			case 85:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 338;
			case 86:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 339;
			case 87:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 340;
			case 88:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 341;
			case 89:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 342;
			case 90:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				return 343;
			case 91:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;                  // TextValue
				game::yylval->val.stringValue = game::SL_GetStringOfSize(*game::gInst, *game::yytext, 0, *game::yyleng + 1);
				return 258;
			case 92:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				game::yylval->val.stringValue = game::SL_GetStringOfSize(*game::gInst, *game::yytext, 0, *game::yyleng + 1);
				return 324;
			case 93:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				game::CompileError(*game::gInst, *game::g_sourcePos, "bad token '%s'", *game::yytext);
				break;
			case 94:
				game::yylval->pos = *game::g_out_pos;
				*game::g_sourcePos = *game::g_out_pos;
				*game::g_out_pos += *game::yyleng;
				game::_fwrite(*game::yytext, *game::yyleng, 1u, *game::yyout);
				break;
			case 95: // YY_END_OF_BUFFER
				/* Amount of text matched not including the EOB char. */
				yy_amount_of_matched_text = yy_cp - *game::yytext - 1;

				/* Undo the effects of YY_DO_BEFORE_ACTION. */
				*yy_cp = *game::yy_hold_char;

				if ( !(*game::yy_current_buffer)->yy_buffer_status ) // YY_BUFFER_NEW
				{
					/* We're scanning a new file or input source.  It's
					* possible that this happened because the user
					* just pointed yyin at a new source and called
					* yylex().  If so, then we have to assure
					* consistency between YY_CURRENT_BUFFER and our
					* globals.  Here is the right place to do so, because
					* this is the first action (other than possibly a
					* back-up) that will match for the new input source.
					*/
					*game::yy_n_chars = (*game::yy_current_buffer)->yy_n_chars;
					(*game::yy_current_buffer)->yy_input_file = *game::yyin;
					(*game::yy_current_buffer)->yy_buffer_status = 1;
				}

				/* Note that here we test for yy_c_buf_p "<=" to the position
				* of the first EOB in the buffer, since yy_c_buf_p will
				* already have been incremented past the NUL character
				* (since all states make transitions on EOB to the
				* end-of-buffer state).  Contrast this with the test
				* in input().
				*/
				if ( *game::yy_c_buf_p <= &((*game::yy_current_buffer)->yy_ch_buf[*game::yy_n_chars]) )
				{
					/* This was really a NUL. */

					*game::yy_c_buf_p = &((*game::yytext)[yy_amount_of_matched_text]);
					yy_current_state = game::yy_get_previous_state();

					/* Okay, we're now positioned to make the NUL
					* transition.  We couldn't have
					* yy_get_previous_state() go ahead and do it
					* for us because it doesn't know how to deal
					* with the possibility of jamming (and we don't
					* want to build jamming into it because then it
					* will run more slowly).
					*/

					yy_next_state = game::yy_try_NUL_trans(yy_current_state);
					yy_bp = *game::yytext; // YY_MORE_ADJ

					if ( yy_next_state )
					{
						yy_cp = ++*game::yy_c_buf_p;
						yy_current_state = yy_next_state;
						goto yy_match;
					}

					yy_cp = *game::yy_c_buf_p;
					goto yy_find_action;
				}

				yy_next_buffer = game::yy_get_next_buffer();
				if ( yy_next_buffer == 0 ) // EOB_ACT_CONTINUE_SCAN
				{
					*game::yy_c_buf_p = &((*game::yytext)[yy_amount_of_matched_text]);
					yy_current_state = game::yy_get_previous_state();
					yy_cp = *game::yy_c_buf_p;
					yy_bp = *game::yytext;
					goto yy_match;
				}

				if ( yy_next_buffer == 1 ) // EOB_ACT_END_OF_FILE
				{
					// yywrap() yy_did_buffer_switch_on_eof
					/* Note: because we've taken care in
					* yy_get_next_buffer() to have set up
					* yytext, we can now set up
					* yy_c_buf_p so that if some total
					* hoser (like flex itself) wants to
					* call the scanner after we return the
					* YY_NULL, it'll still work - another
					* YY_NULL will get returned.
					*/
					*game::yy_c_buf_p = *game::yytext;
					yy_act = (*game::yy_start - 1) / 2 + 96; // 97 on t5
					goto do_action;
				}

				if ( yy_next_buffer == 2 ) // EOB_ACT_LAST_MATCH
				{
					*game::yy_c_buf_p = &((*game::yy_current_buffer)->yy_ch_buf[*game::yy_n_chars]);
					yy_current_state = game::yy_get_previous_state();
					yy_cp = *game::yy_c_buf_p;
					yy_bp = *game::yytext;
					goto yy_find_action;
				}

				break;
			case 96: // YY_STATE_EOF(...)
			case 97:
			case 98:
				return 0; // YYNULL
			default:
				game::yy_fatal_error("fatal flex scanner internal error--no action found");
				break;
			}
		}
	}

	// Restored
	void yy_fatal_error(const char* err)
	{
		game::_fprintf(game::__iob_func() + 2, "%s\n", err);
		game::_exit(2);
	}

	// Restored
	void * yy_flex_realloc(void *ptr, unsigned int size)
	{
		return game::_realloc(ptr, size);
	}

	// Completed
	int yy_get_next_buffer()
	{
		int result;
		int yy_c_buf_p_offset;
		game::yy_buffer_state *b;
		signed int num_to_read;
		char *source;
		int ret_val;
		char *dest;
		int number_to_move;
		int i;

		dest = (*game::yy_current_buffer)->yy_ch_buf;
		source = *game::yytext;
		if ( *game::yy_c_buf_p > &dest[*game::yy_n_chars + 1] )
		{
			game::yy_fatal_error("fatal flex scanner internal error--end of buffer missed");
		}

		if ( (*game::yy_current_buffer)->yy_fill_buffer)
		{
			number_to_move = *game::yy_c_buf_p - *game::yytext - 1;
			for ( i = 0;
				i < number_to_move;
				++i )
			{
				*dest++ = *source++;
			}
			if ( (*game::yy_current_buffer)->yy_buffer_status == 2 )
			{
				*game::yy_n_chars = 0;
				(*game::yy_current_buffer)->yy_n_chars = 0;
			}
			else
			{
				for ( num_to_read = (*game::yy_current_buffer)->yy_buf_size - number_to_move - 1;
					num_to_read <= 0;
					num_to_read = (*game::yy_current_buffer)->yy_buf_size - number_to_move - 1 )
				{
					b = *game::yy_current_buffer;
					yy_c_buf_p_offset = *game::yy_c_buf_p - (*game::yy_current_buffer)->yy_ch_buf;

					if ( (*game::yy_current_buffer)->yy_is_our_buffer )
					{
						if ( (signed int)(2 * (*game::yy_current_buffer)->yy_buf_size) > 0 )
						{
							(*game::yy_current_buffer)->yy_buf_size *= 2;
						}
						else
						{
							(*game::yy_current_buffer)->yy_buf_size += (*game::yy_current_buffer)->yy_buf_size >> 3;
						}

						b->yy_ch_buf = (char *)game::yy_flex_realloc(b->yy_ch_buf, b->yy_buf_size + 2);
					}
					else
					{
						(*game::yy_current_buffer)->yy_ch_buf = 0;
					}
					if ( !b->yy_ch_buf )
					{
						game::yy_fatal_error("fatal error - scanner input buffer overflow");
					}

					*game::yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];
				}

				if ( num_to_read > 0x2000 )
				{
					num_to_read = 0x2000;
				}

				*game::yy_n_chars = game::Scr_ScanFile(num_to_read, &((*game::yy_current_buffer)->yy_ch_buf[number_to_move]));
				(*game::yy_current_buffer)->yy_n_chars = *game::yy_n_chars;
			}
			if ( *game::yy_n_chars )
			{
				ret_val = 0;
			}
			else if ( number_to_move )
			{
				ret_val = 2;
				(*game::yy_current_buffer)->yy_buffer_status = 2;
			}
			else
			{
				ret_val = 1;
				game::yyrestart();
			}
			*game::yy_n_chars += number_to_move;
			(*game::yy_current_buffer)->yy_ch_buf[*game::yy_n_chars] = 0;
			(*game::yy_current_buffer)->yy_ch_buf[*game::yy_n_chars + 1] = 0;
			*game::yytext = (*game::yy_current_buffer)->yy_ch_buf;
			result = ret_val;
		}
		else if ( *game::yy_c_buf_p - *game::yytext == 1 )
		{
			result = 1;
		}
		else
		{
			result = 2;
		}

		return result;
	}

	// Completed
	int yy_get_previous_state()
	{
		unsigned __int8 yy_c;
		int yy_current_state;
		char *yy_cp;

		yy_current_state = *game::yy_start;
		for ( yy_cp = *game::yytext;
			yy_cp < *game::yy_c_buf_p;
			++yy_cp )
		{
			if ( *yy_cp )
			{
				yy_c = game::yy_ec[(unsigned __int8)*yy_cp];
			}
			else
			{
				yy_c = 1;
			}

			if ( game::yy_accept[yy_current_state] )
			{
				*game::yy_last_accepting_state = yy_current_state;
				*game::yy_last_accepting_cpos = yy_cp;
			}

			while ( game::yy_chk[yy_c + game::yy_base[yy_current_state]] != yy_current_state )
			{
				yy_current_state = game::yy_def[yy_current_state];
				if ( yy_current_state >= 258 ) // 262 on t5
				{
					yy_c = game::yy_meta[yy_c];
				}
			}
			yy_current_state = game::yy_nxt[yy_c + game::yy_base[yy_current_state]];
		}
		return yy_current_state;
	}

	// Completed, untested, code doesn't hit
	int yy_try_NUL_trans(int yy_current_state)
	{
		unsigned __int8 yy_c;
		int yy_current_statea;

		yy_c = 1;
		if ( game::yy_accept[yy_current_state] )
		{
			*game::yy_last_accepting_state = yy_current_state;
			*game::yy_last_accepting_cpos = *game::yy_c_buf_p;
		}
		while ( game::yy_chk[yy_c + game::yy_base[yy_current_state]] != yy_current_state )
		{
			yy_current_state = game::yy_def[yy_current_state];
			if ( yy_current_state >= 258 ) // 262 on t5
			{
				yy_c = game::yy_meta[yy_c];
			}
		}
		yy_current_statea = game::yy_nxt[yy_c + game::yy_base[yy_current_state]];
		return yy_current_statea != 257 ? yy_current_statea : 0; // 261 on t5
	}

	// Restored
	void yy_init_buffer(game::yy_buffer_state *b, FILE *file)
	{
		game::yy_flush_buffer(b);
		b->yy_input_file = file;
		b->yy_fill_buffer = 1;
		b->yy_is_interactive = 0;
	}

	// Completed
	void yyrestart()
	{
		if ( !*game::yy_current_buffer )
		{
			*game::yy_current_buffer = game::yy_create_buffer();
		}

		game::yy_init_buffer(*game::yy_current_buffer, *game::yyin);
		game::yy_load_buffer_state();
	}

	// Decomp Status: Completed, untested, code doesn't hit
	game::yy_buffer_state * yy_create_buffer()
	{
		game::yy_buffer_state *b;

		b = (game::yy_buffer_state *)game::Z_TryMalloc(sizeof(game::yy_buffer_state));
		if ( !b )
		{
			game::yy_fatal_error("out of dynamic memory in yy_create_buffer()");
		}

		b->yy_buf_size = 0x4000;
		b->yy_ch_buf = (char *)game::Z_TryMalloc(b->yy_buf_size + 2);
		if ( !b->yy_ch_buf )
		{
			game::yy_fatal_error("out of dynamic memory in yy_create_buffer()");
		}

		b->yy_is_our_buffer = 1;
		game::yy_init_buffer(b, *game::yyin);
		return b;
	}

	// Decomp Status: Completed
	void yy_flush_buffer(game::yy_buffer_state *b)
	{
		if ( b )
		{
			b->yy_n_chars = 0;
			*b->yy_ch_buf = 0;
			b->yy_ch_buf[1] = 0;
			b->yy_buf_pos = b->yy_ch_buf;
			b->yy_at_bol = 1;
			b->yy_buffer_status = 0;

			if ( b == *game::yy_current_buffer )
			{
				game::yy_load_buffer_state();
			}
		}
	}

	// Decomp Status: Completed
	void ScriptParse(game::scriptInstance_t inst, game::sval_u *parseData)
	{
		game::yy_buffer_state buffer_state;

		*game::g_out_pos = 0xFFFFFFFF;
		*game::g_sourcePos = 0;
		*game::g_parse_user = 0;
		game::g_dummyVal->stringValue = 0;
		*game::gInst = inst;
		*game::yy_init = 1;
		buffer_state.yy_buf_size = 0x4000;
		buffer_state.yy_ch_buf = game::ch_buf.get();
		buffer_state.yy_is_our_buffer = 0;

		game::yy_init_buffer(&buffer_state, 0);

		*game::yy_current_buffer = &buffer_state;
		*game::yy_start = 3;
		game::yyparse();

		*parseData = *game::yaccResult;
	}
}
#pragma warning(pop)
