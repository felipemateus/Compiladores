#include <string>
#include <fstream>

using namespace std;

class Scanner
{


public:
  Scanner(string fileName ){

    file = new ifstream(fileName.c_str());

    //buffer = new char[bufferSize];
    //currentChar = 0;
  }

  char getChar(){
    while (file->get(buffer)) {
      cout << buffer;
    }
    cout<<"\n";
  }

  //Corrigir isso dps
  int currentChar;
  char buffer;
  string lexema;
  ifstream* file;



};
