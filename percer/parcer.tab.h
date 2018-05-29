/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARCER_TAB_H_INCLUDED
# define YY_YY_PARCER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    INT = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    RETURN = 263,
    VOID = 264,
    SYB = 265,
    ERROR = 266,
    KEY = 267,
    ID = 268,
    LE = 269,
    GE = 270,
    EQUAL = 271,
    DIF = 272,
    EQ = 273,
    LESS = 274,
    GRT = 275,
    PLUS = 276,
    MINUS = 277,
    MUL = 278,
    DIV = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 15 "parcer.y" /* yacc.c:1909  */

	Program *program;
	Declaration *declaration;
	Var_declaration * var_declaration;
	Param *param;
	Statement *statement;
	Var *var;
	Simple_expression *simple_expression;
	Expression *expression;
	Call *call;
	Factor *factor;
	Relop * relop;
	Mulop *mulop;
	Term  *term;
	Addop *addop;
	Addtive_expression *addtive_expression;
	Expression_stmt *expression_stmt;
	Selection_stmt *selection_stmt;
	Iteration_stmt *iteration_stmt;
	Return_stmt *return_stmt;
	Compound_stmt *compound_stmt;
	Type_specifier *type_specifier;
	Func_declaration *func_declaration;
	std::list<Declaration *> *declaration_list;
	std::list<Expression *> *args_list;
	Arg  *args;
	std::list<Param *> *params;
	std::list<Var_declaration *> *local_declarations;
	std::list<Statement *> *statement_list;

	std::string *string;
	int token;

#line 113 "parcer.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARCER_TAB_H_INCLUDED  */
