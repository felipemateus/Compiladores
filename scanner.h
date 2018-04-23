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


  Scanner(string fileName ){

    file = new ifstream(fileName.c_str());


  }

  char getChar(){
    //while (file->get(buffer)) {
      //cout << buffer;
  //  }
    cout<<"\n";
  }

  Token getToken(){
    Token token;
    string lexema = "";

    char currentChar;

    while (file->get(currentChar)) {
      /* code */


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
