#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
#include "exp.h"

using namespace std;

operator_node::operator_node(exp_node *L, exp_node *R){
  left =  L;
  right = R;
}


/********************/
/*    number_node   */
/********************/
number_node::number_node(int value){
  num =value;
}
int number_node::evaluate(){
  cout<<"number_node: operando = "<< num <<endl;
  return num;
}

void number_node::print(){
  cout<<"Felipe é lindo "<<num<< endl;
}


/********************/
/*    plus_node     */
/********************/
void plus_node:: print(){
  cout<< "(";
  left->print();
  cout<<" + ";
  right->print();
  cout<<")";
}

int plus_node::evaluate(){
  int left_num, right_num;

  left_num  = left->evaluate();
  right_num = right->evaluate();

  num = left_num + right_num;
  cout << "plus_node: " << left_num << " + " << right_num << " = " << num << "\n";
  return (num);
}
