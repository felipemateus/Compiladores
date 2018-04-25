#include <iostream>
#include <string>
#include <fstream>

//#include "token.h"

using namespace std;


class Scanner
{


public:

  //Corrigir isso dps


  ifstream* file;
  int linhaAtual;


  Scanner(string fileName ){

    file = new ifstream(fileName.c_str());
    linhaAtual = 1;


  }

  bool getChar(char *currentChar){
    if(file->get(*currentChar)){
      if(*currentChar == '\n'){
        linhaAtual++;
      }

      return true;
    }else{
      return false;
    }



  }

  Token getToken(){
    Token token;
    token.numLiha =linhaAtual;

    string lexema = "";
    char currentChar;

    while (getChar(&currentChar)) {

      //Caso inicie com letra(letra | Digito)*
      if(isalpha(currentChar) ){
        lexema.append(1,currentChar);
        getChar(&currentChar);
        while(isalpha(currentChar) || isdigit(currentChar)){
          lexema.append(1,currentChar);
          getChar(&currentChar);

        }
        file->putback(currentChar);
        token.lexema =  lexema;
        break;
      }

      if(currentChar != ' ' && currentChar!='\n'){
        lexema.append(1,currentChar);
        //std::cout << currentChar << '\n';
        //std::cout << lexema << '\n';
      }else{
        break;
      }
    }


    token.lexema = lexema;

    return token;
  }






};
