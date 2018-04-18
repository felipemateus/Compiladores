#include <iostream>
#include <string>

using namespace std;

class GradeDeNotas
{


public:

	void setNomeCurso(string nome){
		nomeCurso = nome;
	}

	string getNomeCurso()const{
		return nomeCurso;
	}

	void mostraMensagem(string nome)const
	{
		cout<<"Bem vindo a Grade de Notas do Curso "<< getNomeCurso() <<endl;
	}

private:

	string nomeCurso;



};


int main()
{
	string nomeDoCurso;
	GradeDeNotas grade;

	cout<<"Nome do Curso:"<< grade.getNomeCurso()<<endl;
	getline(cin,nomeDoCurso);
	cout<<endl;

	grade.setNomeCurso(nomeDoCurso);

	grade.mostraMensagem(nomeDoCurso);
}