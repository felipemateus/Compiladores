#include <iostream>
#include <list>
#include "node.h"
using namespace std;





int main(){
  Declaration *um = new Declaration(2);
  Declaration *dois = new Declaration(2);

  list<Declaration *> *declra = new list<Declaration *>() ;

  declra->push_back(um);
  declra->push_back(dois);

  Declaration_list *declis = new Declaration_list(declra);

  Program *prog = new Program(declis);

  prog->evaluate();
}
