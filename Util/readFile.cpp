#include <iostream>
#include <fstream>
#include <string>


using namespace std;


int main(){

	int bufferSize = 256;
	char buffer[bufferSize];

	ifstream file ("main.c");

	if(!file){
		cerr<<"Não foi possivel abrir o arquivo"<<endl;
	}
	int i =0;
	while(!file.eof()){
		file.get(buffer[i]);
		i++;
	}

	cout<<buffer;//<<endl;


}