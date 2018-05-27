%{
		#include <stdio.h>
		#include <stdlib.h>
		#include "exp.h"

		int yylex();
		int yyparse();
		void yyerror(const char* s);

		using namespace std;

%}

%token NUM
%token ERRO KEY ID SYB ERROR
%left '+' '-'
%left '*' '/'

%start program

%%

program :							 	declaration_list
											;
declaration_list:  		 	declaration_list declaration
											|	declaration
											;
declaration:				 	 	var_declaration
											|	fun_declaration
											;

/* ---------------------------------------------------*/
var_declaration : 			type_specifier ID ';'
											| type_specifier ID '[' NUM ']' ';'
											;
type_specifier 	: 			"int"
											| "void"
											;

/* ---------------------------------------------------*/

fun_declaration: 				type_specifier ID '('params ')' compound_stmt
											;
params: 								param_list
											| "void"
											;
param_list: 						param_list ',' param
											| param
											;
param:									type_specifier ID
											| type_specifier ID '[' ']'
											;
/* ---------------------------------------------------*/

compound_stmt:				 '{' local_declarations statement_list '}'
											;

/* ---------------------------------------------------*/

local_declarations : 		local_declarations var_declaration
											| %empty
											;
statement_list : 				statement_list statement
											| %empty
											;
/* ---------------------------------------------------*/

statement :							expression_stmt
											| compound_stmt
											| selection_stmt
              				| iteration_stmt
											| return_stmt
											;
expression_stmt :				expression ';'
											| ';'
											;
selection_stmt:				 	"if" '(' expression ')' statement
                  		| "if" '(' expression ')' statement "else" statement

iteration_stmt:	  			"while" '(' expression ')' statement
											;

return_stmt :				 		"return" ';'
											| "return" expression ';'
											;

expression :				 		var '=' expression
											| simple_expression
											;
var :				 						ID
											| ID '[' expression ']'
											;

simple_expression :			additive_expression relop additive_expression
                      | additive_expression
											;
relop :							 		"<="
											| "<"
											| ">"
											| ">="
											| "=="
											| "!="
											;

additive_expression :		additive_expression addop term
											| term
											;
addop :				 					'+'
											| '-'
											;
term :				 					term mulop factor
											| factor
											;
mulop :									'*'
											| '/'
											;

factor :							 '(' expression ')'
											| var
											| call
											| NUM
											;

call :				 					ID '(' args ')'
											;
args :				 					arg-list
											| %empty
											;
arg-list :					 		arg-list ',' expression
											| expression
											;







%%

int main(){
	number_node NUMBER(2);
	NUMBER.print();
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
