#include <iostream>
#include <string>
#include "node.h"

using std::cout;


/*********************
      Program
*********************/
Program::Program(Declaration_list *declarations){
  dec_list = declarations;
}
void Program::evaluate(){
  cout << "Program name:"<<'\n';
  dec_list->evaluate();
}


/*********************
    Declaration_list
*********************/
Declaration_list::Declaration_list(list<Declaration *> *declarations){
  this->declarations = declarations;
}
void Declaration_list::evaluate(){
  cout << "Declaration List name:"<<'\n';
  for (it = declarations->begin() ; it !=declarations->end() ; it++)  {
    (*it)->evaluate();
  }

}
/*********************
    Declaration
*********************/
Declaration::Declaration(int t){
  type =t;
}
void Declaration::evaluate(){
  cout << "Declaratio name:"<< '\n';

}
