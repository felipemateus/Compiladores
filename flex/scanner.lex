
%{
  int isKeyWord(char*);
  int countLines = 1;
%}

letter  [a-zA-Z]
digit   [0-9]
symb    "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|"("|")"|"{"|"}"|","|";"

/* KEY */
/* SYM */
/* ERROR */



%%

\n                                { countLines++;}

{digit}+                          { printf("(%d,NUM,\"%s\")\n", countLines,yytext);}

{letter}({letter}|{digit})*       { if(isKeyWord(yytext))
                                      printf("(%d,KEY,\"%s\")\n", countLines,yytext);
                                    else
                                      printf("(%d,ID,\"%s\")\n", countLines,yytext);
                                  }

{symb}                            { printf("(%d,SYM,\"%s\")\n", countLines,yytext);}

.

%%

int main(int argc,char* argv[]){
    if(argc > 1){
      printf("\nNome do  arquivo: %s\n",argv[1]);
      yyin = fopen(argv[1],"r");
    }

    printf("Passeia aqui\n");
    yylex();
    printf("Numero de linhas : %d \n",countLines);
    return 0;

}

int isKeyWord(char* palavra){

    /* if(strcmp == "else"||
      palavra == "if"   ||
      palavra == "int"  ||
      palavra == "return"||
      palavra == "void"||
      palavra =="while"){
        printf("Passeia aqui KEY\n");

        return 1;

      } */

      if(strcmp(palavra,"else") == 0  ||
         strcmp(palavra,"if") == 0    ||
         strcmp(palavra,"int") == 0   ||
         strcmp(palavra,"return") == 0||
         strcmp(palavra,"void") == 0  ||
         strcmp(palavra,"while") == 0 ){
          return 1;

      }



      return 0;


  return 0;
}
