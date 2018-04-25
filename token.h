#include <string>
using std::string;
using namespace std;

class Token
{
public:
  Token()
  {
      numLiha = 0;
      tipoToken ="";
      lexema = "";
  }
  int numLiha;
  string tipoToken;
  string lexema;

void imprimeValues(){
  cout<< "Linha: "<<numLiha<<" Tipo : "<<tipoToken<<" Lexema:" <<lexema<<endl;
}
};
