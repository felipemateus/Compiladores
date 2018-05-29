%{
		#include <stdio.h>
		#include <stdlib.h>
		#include "class/node.h"

		int yylex();
		int yyparse();
		void yyerror(const char* s);

		int countLines = 1;

		//using namespace std;

%}
%union {
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
}

%token<token> NUM
%token<token> INT IF ELSE WHILE RETURN VOID
%token<token> SYB ERROR
%token<string> KEY ID

/*  tokens de operadores com mais de character:
		GRT		">"						PLUS 	"+"
		LESS	"<"						MINUS	"-"
		LE  	"<="					MUL		"*"
		GE  	">="          DIV		"/"
		EQUAL "=="
		EQ     "="
		DIF   "!="*/
%token<string> LE GE EQUAL DIF EQ LESS GRT
%token<token>PLUS MINUS MUL DIV

%type <program> program
%type <declaration_list> declaration_list
%type <declaration> declaration
%type	<var_declaration> var_declaration
%type	<param> param
%type	<params> params param_list
%type <compound_stmt> compound_stmt
%type <local_declarations> local_declarations
%type <statement_list> statement_list
%type	<statement> statement
%type	<var> var
%type <simple_expression> simple_expression
%type	<expression> expression
%type <args> args
%type <args_list> arg-list
%type <call> call
%type <factor> factor
%type <relop> relop
%type <mulop> mulop
%type <term> term
%type <addop> addop
%type <addtive_expression> addtive_expression
%type <expression_stmt> expression_stmt
%type <selection_stmt> selection_stmt
%type <iteration_stmt> iteration_stmt
%type <return_stmt> return_stmt
%type <type_specifier> type_specifier
%type <func_declaration> func_declaration


%left '+' '-'
%left '*' '/'

%start program

%%

program :							 	declaration_list																	{$$ = new Program($1);     printf("Program [\n");}
											;
declaration_list:  		 	declaration declaration_list											{$$->push_back($1);printf("declaration_list1 ;\n");}
											| declaration																				{$$ = new list<Declaration*>();$$->push_back($1); printf("declaration_list2 ;\n");}
											;
declaration:				 	 	var_declaration																		{$$ = $1; printf("declaration1 ;\n");}
											|	func_declaration																	{$$ = $1; printf("declaration2 ;\n");}
											;

var_declaration : 			type_specifier ID	';'															{$$ = new Var_declaration($1,$2);    printf("var_declaration1 ;\n");}
											| type_specifier ID '[' NUM ']' ';'									{$$ = new Var_declaration($1,$2); 	printf("var_declaration2 ;\n");}
											;

type_specifier 	: 			INT																								{$$ =  new Type_specifier(new string("int"));}
											| VOID																							{$$ =  new Type_specifier(new string("void"));}
											;


func_declaration: 				type_specifier ID '('params ')' compound_stmt		{$$ = new Func_declaration($1, $2,$4,$6 ); printf("fUNC \n");}
											;

params: 								param_list																				{$$ =  $1;}
											| VOID																							{$$ =  NULL;}
											;

param_list: 						param_list ',' param															{$1->push_back($3); $$ = $1;}
											| param																							{$$ =  new list<Param*>(); $$->push_back($1);}
											;

param:									type_specifier ID																	{$$ = new Param($1,$2); }
											| type_specifier ID '['']'													{$$ = new Param($1,$2); }
											;

compound_stmt:				 '{' local_declarations statement_list '}'					{ $$ = new Compound_stmt($2,$3);  printf("fUNC \n");}
											;


local_declarations : 		local_declarations var_declaration								{$1->push_back($2); $$=$1;}
											| %empty																						{$$ = new list<Var_declaration*>();}
											;

statement_list : 				statement_list statement													{$1->push_back($2); $$ = $1;}
											| %empty																						{$$ = new list<Statement*>();}
											;

statement :							expression_stmt																		{$$ = $1;}
											| compound_stmt																			{$$ = $1;}
											| selection_stmt																		{$$ = $1;}
              				| iteration_stmt																		{$$ = $1;}
											| return_stmt																				{$$ = $1;}
											;

expression_stmt :				expression ';'																		{$$ = new Expression_stmt($1);}
											| ';'																								{$$ = NULL;}
											;

selection_stmt:				 	IF '(' expression ')' statement										{$$ = new Selection_stmt($3,$5);}
                  		| IF '(' expression ')' statement ELSE statement		{$$ = new Selection_stmt($3,$5,$7);}

iteration_stmt:	  			WHILE '(' expression ')' statement								{$$ =  new Iteration_stmt($3,$5);}
											;

return_stmt :				 		RETURN ';'																				{$$ = NULL;}
											| RETURN expression ';'															{$$ = new Return_stmt($2);}
											;

expression :				 		var '=' expression																{$$ = new Expression($1,$3);}
											| simple_expression																	{$$ = new Expression($1);}
											;

var :				 						ID																								{$$ = new Var($1);}
											| ID '[' expression ']'															{$$ = new Var($1,$3);}
											;

simple_expression :			addtive_expression relop addtive_expression				{$$ = new Simple_expression($1,$2,$3);}
                      | addtive_expression																{$$ = new Simple_expression($1);}
											;

relop :							 		LE																								{new Relop($1);}
											| LESS																							{new Relop($1);}
											| GRT																								{new Relop($1);}
											| GE																								{new Relop($1);}
											| EQUAL																							{new Relop($1);}
											| DIF																								{new Relop($1);}
											;

addtive_expression :		addtive_expression addop term											{$$ = new Addtive_expression($1,$2,$3);}
											| term																							{$$ = new Addtive_expression($1);}
											;

addop :				 					PLUS                                               {$$ = new Addop(new char('+'));}
											| MINUS																							 {$$ = new Addop(new char('-'));}
											;

term :				 					term mulop factor																	{$$ = new Term($1,$2,$3); }
											| factor																						{$$ = new Term($1);}
											;


mulop :									MUL																								{$$ = new Mulop(new char('*'));}
											| DIV																								{$$ = new Mulop(new char('/'));}
											;

factor :							 '(' expression ')'																	{$$ = new Factor($2); }
											| var																								{$$ = new Factor($1); }
											| call																							{$$ = new Factor($1); }
											| NUM																								{$$ = new Factor($1); printf("NUM \n");}
											;

call :				 					ID '(' args ')'																		{$$ = new Call($1,$3);}
											;


args :				 					arg-list																					{$$ = new Arg($1);}
											| %empty																						{$$ = NULL;}
											;

arg-list :					 		arg-list ',' expression													{$1->push_back($3); $$ = $1;}
											| expression																			{$$ = new list<Expression*>(); $$->push_back($1);}
											;






%%

int main(){
	//number_node NUMBER(2);
	//NUMBER.print();
	Type_specifier *tipe = new Type_specifier(new string("VOID"));
  tipe->evaluate();

	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	fprintf(stderr, "Linha %d\n", countLines);
	exit(1);
}
