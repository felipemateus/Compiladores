#include <iostream>
#include <string>
#include "node.h"

using std::cout;



/*********************
    Type_specifier
*********************/
Type_specifier::Type_specifier(string *type){
  this->type = type;
};
void Type_specifier::evaluate(){
  cout << "Type name:" << *(this->type) <<'\n';
};

/*********************
      Program
*********************/
Program::Program(list<Declaration *> *declarations){
  this->declarations = declarations;
}
void Program::evaluate(){
  cout << "Program name:"<<'\n';

  cout << "Declaration List name:"<<'\n';
  for (it = declarations->begin() ; it !=declarations->end() ; it++)  {
    cout << "Declaration 2 List name:"<<'\n';

    (*it)->evaluate();
  }
}



/*********************
    Var_declaration
*********************/
Var_declaration::Var_declaration(Type_specifier *type, string *id){
  this->type = type;
  this->id = id;
}
void Var_declaration::print(){
  cout<<"Var_declaration"<<endl;
}
void Var_declaration::evaluate(){
  cout << "Var_declaration name:"<< '\n';

}

/*********************
        Param
*********************/
Param::Param(Type_specifier *tipo, string *id){
  this->tipo = tipo;
  this->id = id;
}
void Param::print(){
  cout<<"Param"<<endl;
}
void Param::evaluate(){
  cout << "Param"<< '\n';

}

/*********************
        Var
*********************/
Var::Var(string *id, Expression *expression){
  this->id = id;
  this->expression = expression;
}
Var::Var(string *id){
  this->id = id;
}
void Var::print(){
  cout<<"Var"<<endl;
}
void Var::evaluate(){
  cout << "Var"<< '\n';

}

/*********************
  Simple_expression
*********************/
Simple_expression::Simple_expression(Addtive_expression *addtive_expressionUm, Relop *relop, Addtive_expression *addtive_expressionDois){
  this->addtive_expressionUm = addtive_expressionUm;
  this->relop = relop;
  this->addtive_expressionDois = addtive_expressionDois;
}
Simple_expression::Simple_expression(Addtive_expression *addtive_expressionUm){
  this->addtive_expressionUm = addtive_expressionUm;
}
void Simple_expression::print(){
  cout<<"Simple_expression"<<endl;
}
void Simple_expression::evaluate(){
  cout << "Simple_expression"<< '\n';

}

/*********************
  Expression
*********************/
Expression::Expression(Var *var,Expression *expression){
  this->var = var;
  this->expression = expression;
}
Expression::Expression(Simple_expression *simple_expression){
  this->simple_expression = simple_expression;

}
void Expression::print(){
  cout<<"Expression"<<endl;
}
void Expression::evaluate(){
  cout << "Expression"<< '\n';

}

/*********************
        Arg
*********************/
Arg::Arg(list<Expression* > *args){
  this->args = args;
}
void Arg::print(){
  cout<<"Arg"<<endl;
}
void Arg::evaluate(){
  cout << "Arg"<< '\n';

}
/*********************
        Call
*********************/
Call::Call(string *id, Arg *args ){
  this->id = id;
  this->args = args;
}
void Call::print(){
  cout<<"Call"<<endl;
}
void Call::evaluate(){
  cout << "Call"<< '\n';

}

/*********************
      Factor
*********************/
Factor::Factor(Expression *expression){
  this->expression = expression;
}
Factor::Factor(Var *var){
  this->var = var;
}
Factor::Factor(Call *call){
  this->call = call;
}
Factor::Factor(int num){
  this->num = num;
}
void Factor::print(){
  cout<<"Factor"<<endl;
}
void Factor::evaluate(){
  cout << "Factor"<< '\n';

}
/*********************
        Relop
*********************/
Relop::Relop(string *symbol ){
  this->symbol = symbol;
}
void Relop::print(){
  cout<<"Relop"<<endl;
}
void Relop::evaluate(){
  cout << "Relop"<< '\n';

}

/*********************
        Mulop
*********************/
Mulop::Mulop(char *op ){
  this->op = op;
}
void Mulop::print(){
  cout<<"Mulop"<<endl;
}
void Mulop::evaluate(){
  cout << "Mulop"<< '\n';

}

/*********************
        Term
*********************/
Term::Term(Term *term, Mulop *mulop, Factor *factor){
  this->term = term;
  this->mulop = mulop;
  this->factor = factor;
}
Term::Term(Factor *factor){
  this->factor = factor;
}
void Term::print(){
  cout<<"Term"<<endl;
}
void Term::evaluate(){
  cout << "Term"<< '\n';

}

/*********************
        Addop
*********************/
Addop::Addop(char *op ){
  this->op = op;
}
void Addop::print(){
  cout<<"Addop"<<endl;
}
void Addop::evaluate(){
  cout << "Addop"<< '\n';

}

/*********************
  Addtive_expression
*********************/
Addtive_expression::Addtive_expression(Addtive_expression * addtive_expression,Addop *addop, Term *term){
  this->addtive_expression = addtive_expression;
  this->addop= addop;
  this->term = term;
}
Addtive_expression::Addtive_expression(Term *term){
  this->term = term;
}
void Addtive_expression::print(){
  cout<<"Addtive_expression"<<endl;
}
void Addtive_expression::evaluate(){
  cout << "Addtive_expression"<< '\n';
}

/*********************
  Expression_stmt
*********************/
Expression_stmt::Expression_stmt(Expression *expression){
  this->expression = expression;
}
void Expression_stmt::print(){
  cout<<"Expression_stmt"<<endl;
}
void Expression_stmt::evaluate(){
  cout << "Expression_stmt"<< '\n';
}

/*********************
  Selection_stmt
*********************/
Selection_stmt::Selection_stmt(Expression *ifExpression,Statement *ifStatement){
  this->ifExpression= ifExpression;
  this->ifStatement = ifStatement;
}
Selection_stmt::Selection_stmt(Expression *ifExpression,Statement *ifStatement,Statement *elseStatement){
  this->ifExpression= ifExpression;
  this->ifStatement = ifStatement;
  this->elseStatement = elseStatement;
}

void Selection_stmt::print(){
  cout<<"Selection_stmt"<<endl;
}
void Selection_stmt::evaluate(){
  cout << "Selection_stmt"<< '\n';
}

/*********************
  Iteration_stmt
*********************/
Iteration_stmt::Iteration_stmt(Expression *expression, Statement *statement){
  this->expression = expression;
  this->statement = statement;
}
void Iteration_stmt::print(){
  cout<<"Iteration_stmt"<<endl;
}
void Iteration_stmt::evaluate(){
  cout << "Iteration_stmt"<< '\n';
}

/*********************
  Return_stmt
*********************/
Return_stmt::Return_stmt(Expression *expression){
  this->expression = expression;
}
void Return_stmt::print(){
  cout<<"Return_stmt"<<endl;
}
void Return_stmt::evaluate(){
  cout << "Return_stmt"<< '\n';
}


/*********************
    Compound_stmt
*********************/
Compound_stmt::Compound_stmt(list<Var_declaration *> *local_declarations, list<Statement *> *statements){
  this->local_declarations = local_declarations;
  this->statement_list = statements;
}
void Compound_stmt::print(){
  cout<<"Compound_stmt"<<endl;
}
void Compound_stmt::evaluate(){
  cout<<"Compound_stmt"<<endl;
}


/*********************
    Func_declaration
*********************/
Func_declaration::Func_declaration(Type_specifier *tipo, string *id, list<Param *> *params, Compound_stmt *comp_st){
  this->tipo = tipo;
  this->id = id;
  this->params = params;
  this->compound_st = comp_st;
}
void Func_declaration::print(){
    cout<<"Func_declaration"<<endl;
  }
void Func_declaration::evaluate(){
    cout<<"Func_declaration"<<endl;
    //eval na lista de Params
    //eval em comp_st
}
