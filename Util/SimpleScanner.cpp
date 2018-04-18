#include <iostream>
#include <string.h>
#include <iomanip>


using namespace std;

void initLexame(char* palavra);
void compareLexema(char*);	

//char lexema[100];
int state;

int main(){

	char palavra[6] =  {'w','h','i','l','e',' '};

	//cout << palavra; 

	
	initLexame(palavra);

}


void initLexame(char* palavra){

	char currentChar;
	int indexChar = 0;
	char lexema[100] ="" ;
	state=0;



	//while(true)
	//{
		
		switch(state)
		{

			case 0:

			do{
				currentChar = palavra[indexChar];
				strncat(lexema,&currentChar,1);
				//strcpy(lexema,currentChar);
				//lexema += currentChar;
				indexChar++;
				cout<<lexema<<endl;
			


			}while(palavra[indexChar] != ' ');
							
				
			state = 2;
			

			case 2:
			compareLexema(lexema);
				

		} 

	//}

	cout<<lexema<<endl;
}

void compareLexema(char* lexema){

	if(strcmp(lexema,"while") == 0){
		cout<<"igual"<<endl;
	}else{
		cout<<"diferente"<<endl;
	}
}
