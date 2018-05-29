#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
using namespace std;
/*
    program         -> Possui uma lista de declarações
    declaration     -> var_declaration | fun_declaration

    var_declaration -> type_specifier ID ;
    type_specifier  -> int |void

    fun_declaration: 				type_specifier ID '('params ')' compound_stmt
    											;
    params: 								param_list
    											| VOID
    											;
    param_list: 						param_list ',' param
    											| param
    											;
    param:									type_specifier ID

    compound_stmt:				 '{' local_declarations statement_list '}'


    local_declarations : 		local_declarations var_declaration
    											| %empty
    											;

    statement_list : 				statement_list statement
    											| %empty
    											;

*/

/*********************
    Type_specifier
*********************/
class Type_specifier{
protected:
  string *type;
public:
  Type_specifier(string *type);
  void evaluate();

};

/*********************
      Declaration
*********************/

class Declaration{

public:
  virtual void print(){}
  virtual void evaluate() = 0;
};

/*********************
      Program
*********************/
class Program{
protected:
  list<Declaration *> *declarations;
  list<Declaration *>::iterator it ;


public:
  Program(list<Declaration *> *declarations);

  void evaluate();
};

/*********************
    Var_declaration
*********************/

class Var_declaration: public Declaration{
protected:
  Type_specifier *type;
  string *id;
public:
  Var_declaration(Type_specifier *type,string *id);
  void print();
  void evaluate();
};

/*********************
        Param
*********************/

class Param: public Declaration{
protected:
  Type_specifier *tipo;
  string *id;
public:
  Param(Type_specifier *tipo, string *id);
  void print();
  void evaluate();
};


/*********************
        Statement
*********************/
class Statement: public Declaration{
public:
  virtual void print(){};
  virtual void evaluate()=0;
};

class Expression;
/*********************
        Var
*********************/
class Var: public Statement{
protected:
  string *id;
  Expression *expression;
public:
  Var(string *id);
  Var(string *id,Expression * expression );
  void print();
  void evaluate();
};

/*********************
  Simple_expression
*********************/
class Relop;
class Addtive_expression;
class Simple_expression: public Statement{
protected:
  Addtive_expression *addtive_expressionUm;
  Relop *relop;
  Addtive_expression *addtive_expressionDois;
public:
  Simple_expression(Addtive_expression *addtive_expressionUm, Relop *relop, Addtive_expression *addtive_expressionDois);
  Simple_expression(Addtive_expression *addtive_expressionUm);

  void print();
  void evaluate();
};



/*********************
      Expression
*********************/
class Expression: public Statement{
protected:
  Var *var;
  Expression *expression;
  Simple_expression *simple_expression;
public:
  Expression(Var *var,Expression *expression);
  Expression(Simple_expression *simple_expression);
  void print();
  void evaluate();
};


/*********************
        Arg
*********************/
class Arg: public Statement{
protected:
  list<Expression*> *args;

public:
  Arg(list<Expression* > *args);
  void print();
  void evaluate();
};
/*********************
        Call
*********************/
class Call: public Statement{
protected:
  string *id;
  Arg *args;
public:
  Call(string * id, Arg *args );


  void print();
  void evaluate();
};





/*********************
        Factor
*********************/
class Factor: public Statement{
protected:
  Expression *expression;
  Var *var;
  Call *call;
  int num;
public:
  Factor(Expression *expression );
  Factor(Var *var);
  Factor(Call *call);
  Factor(int num);

  void print();
  void evaluate();
};

/*********************
        Relop
*********************/
class Relop: public Statement{
protected:
  string *symbol;
public:
  Relop(string *symbol);
  void print();
  void evaluate();
};

/*********************
        Mulop
*********************/
class Mulop: public Statement{
protected:
  char *op;

public:
  Mulop(char *op);
  void print();
  void evaluate();
};

/*********************
        Term
*********************/
class Term: public Statement{
protected:
  Term *term ;
  Mulop *mulop;
  Factor *factor;

public:
  Term(Term *term, Mulop *mulop, Factor *factor);
  Term(Factor *factor);
  void print();
  void evaluate();
};
/*********************
        Addop
*********************/
class Addop: public Statement{
protected:
  char *op;
public:
  Addop(char *op);
  void print();
  void evaluate();
};

/*********************
  Addtive_expression
*********************/
class Addtive_expression: public Statement{
protected:
  Addtive_expression *addtive_expression;
  Addop *addop;
  Term *term;
public:
  Addtive_expression(Addtive_expression * addtive_expression,Addop *addop, Term *term);
  Addtive_expression(Term *term);

  void print();
  void evaluate();
};



/*********************
    Expression_stmt
*********************/
class Expression_stmt: public Statement{
protected:
  Expression *expression;
public:
  Expression_stmt(Expression* expression);
  void print();
  void evaluate();
};


/*********************
    Selection_stmt
*********************/
class Selection_stmt: public Statement{
protected:
  Expression *ifExpression;
  Statement *ifStatement;
  Statement *elseStatement;

public:
  Selection_stmt(Expression *ifExpression,Statement *ifStatement);
  Selection_stmt(Expression *ifExpression, Statement *ifStatement, Statement *elseStatement);
  void print();
  void evaluate();
};


/*********************
    Iteration_stmt
*********************/

class Iteration_stmt: public Statement{
protected:
  Expression *expression;
  Statement *statement;
public:
  Iteration_stmt(Expression *expression, Statement *statement);
  void print();
  void evaluate();
};



/*********************
      Return_stmt
*********************/

class Return_stmt: public Statement{
protected:
  Expression *expression;
public:
  Return_stmt(Expression *expression);
  void print();
  void evaluate();
};

/*********************
      Compound_stmt
*********************/
class Compound_stmt: public  Statement{
protected:
  list<Var_declaration *> *local_declarations;
  list<Statement *> *statement_list;
public:
   Compound_stmt(list<Var_declaration *> *local_declarations, list<Statement *> *statements);
   void print();
   void evaluate();
};

/*********************
    Func_declaration
*********************/

class Func_declaration: public Declaration{
protected:
  Type_specifier *tipo;
  string *id;
  list<Param *> *params;
  Compound_stmt *compound_st;
public:
  Func_declaration(Type_specifier *tipo, string *id, list<Param*> *params, Compound_stmt *comp_st);
  void print();
  void evaluate();
};
