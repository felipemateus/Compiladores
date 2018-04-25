#include <iostream>
#include <string>
#include "token.h"
#include "scanner.h"



using namespace std;
int main(){
  Scanner scann("main.c");

  //scann.getChar();


  Token token =  scann.getToken();

  token.imprimeValues();
  //Token tok;
  //tok.numLiha = 20;
  //cout<<tok.numLiha;


}
