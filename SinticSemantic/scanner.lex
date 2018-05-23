
%{
  #include "y.tab.h"

  extern "C" int yylex();
  //extern "C" FILE *yyin;

  int isKeyWord(char*);
  int countLines = 1;
%}

letter  [a-zA-Z]
digit   [0-9]
symb    "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|"("|")"|"["|"]"|"{"|"}"|","|";"

/* KEY */
/* SYM */
/* ERROR */



%%

\n                                { countLines++;}


"/*"                              {
                                    int c= 0;
                                    int linha = countLines;
                                    while(true){
                                      do{
                                        if(c =='\n'){countLines++;}
                                      }while((c=yyinput()) != '*' && c != EOF);


                                      if(c == '*'){
                                        while( (c=yyinput()) == '*' ){}

                                        if( c == '/'){
                                          break;
                                        }


                                      }
                                      if(c == EOF){
                                        fprintf(fileWrite,"(%d,ERROR,\"/*\")\n", linha);
                                        break;
                                      }

                                  }

                                  }

{digit}+                          {
                                    fprintf(fileWrite,"(%d,NUM,\"%s\")\n", countLines,yytext);

                                  }

{digit}+({letter}+|{digit}+)+      {
                                    fprintf(fileWrite,"(%d,ERROR,\"%s\")\n", countLines,yytext);
                                    return 0;
                                  }

{letter}({letter}|{digit})*       { if(isKeyWord(yytext)){
                                      fprintf(fileWrite,"(%d,KEY,\"%s\")\n", countLines,yytext);
                                    }
                                    else{
                                      fprintf(fileWrite,"(%d,ID,\"%s\")\n", countLines,yytext);

                                    }
                                  }

{symb}                            {
                                    fprintf(fileWrite,"(%d,SYM,\"%s\")\n", countLines,yytext);
                                  }

[" "|\t]+                             /* alooo */

.                                {
                                    fprintf(fileWrite,"(%d,ERROR,\"%s\")\n", countLines,yytext);
                                    return 0;
                                  }


%%


int isKeyWord(char* palavra){


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
