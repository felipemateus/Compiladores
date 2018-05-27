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
enum type{
  INT,
  VOID,
};

class Declaration{
protected:
  int type;
public:
  Declaration(int t);
  /*virtual void print(){}*/
  /*virtual*/ void evaluate(); /*= 0*/;
};

class Declaration_list{
  list<Declaration *> *declarations;
  list<Declaration *>::iterator it ;

public:
  Declaration_list(list<Declaration *> *declarations);
  void evaluate();
};

class Program{
protected:
  Declaration_list *dec_list;

public:
  Program(Declaration_list *declarations);

  void evaluate();
};





/*
class Var_declaration: public Declaration{
protected:
  string type;
  string id:
public:
  var_declaration(string type,string id);
  void print(){}
  void evaluate() = 0;
}

class func_declaration:public declaration{
protected:
  type *tipo;
  string id;
  params *params;
  compound_stmt *compound_st
public:
  func_declaration()(type *tipo,string id,params *params, compound_stmt *comp_st);
  void print(){}
  void evaluate() = 0;
}

class params{
protected:
  list<param *> *params;
public:
  parans(list<param *> *params);
  void print(){}
  void evaluate();
}

class param: public Declaration{
protected:
  type tipo;
  string id;
public:
  param(type *tipo, string id)
  void print(){}
  void evaluate() = 0;
}

class compound_stmt: public  Declaration{
protected:
  local_declarations * local_dec;
  list<statement *> *statement_list;
public:
   compound_stmt(local_declarations *local,list<statement *> *statements)
   void print(){}
   void evaluate()
}



class local_declarations: public Declaration{

}



class statement: public Declaration{
public:
  virtual void print();
  virtual void evaluate();
}



class expression_stmt: public statement{
public:
  virtual void print();
  virtual void evaluate();
}

class selection_stmt: public statement{
public:
  virtual void print();
  virtual void evaluate();
}
class iteration_stmt: public statement{
public:
  virtual void print();
  virtual void evaluate();
}
class return_stmt: public statement{
public:
  virtual void print();
  virtual void evaluate();
}
*/
