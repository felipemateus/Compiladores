#include <iostream>
#include <list>
#include "node.h"
using namespace std;





int main(){

  Type_specifier *tipe = new Type_specifier(new string("VOID"));
  tipe->evaluate();
  /*
  Var_declaration *um = new Var_declaration(Type_specifier.INT,"ID");
  Var_declaration *dois = new Var_declaration(&INT,"ID");

  list<Declaration *> *declra = new list<Declaration *>() ;

  declra->push_back(um);
  declra->push_back(dois);


  Program *prog = new Program(declra);

  prog->evaluate();
  */
}
