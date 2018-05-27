%option noyywrap
%{
  #include <iostream>
  #include  <string>

  #include <stdio.h>
  #define YY_DECL int yylex()
  #include "parcer.tab.h"



  int isKeyWord(char*);
  extern int countLines;


%}

letter  [a-zA-Z]
digit   [0-9]
symb    "+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"=="|"!="|"="|"("|")"|"["|"]"|"{"|"}"|","|";"





%%

\n                                { printf("Linha \n"); countLines++;}


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
                                          //printf("(%d,Comentário,\"%s\")\n", countLines,yytext);
                                          break;
                                        }


                                      }
                                      if(c == EOF){
                                        //printf("(%d,ERROR,\"%s\")\n", countLines,yytext);
                                        //fprintf(fileWrite,"(%d,ERROR,\"/*\")\n", linha);
                                        //yyerror()
                                        return ERROR;
                                        //break;
                                      }

                                  }

                                  }

{digit}+                          {
                                    printf("(%d,NUM,\"%s\")\n", countLines,yytext);
                                    //fprintf(fileWrite,"(%d,NUM,\"%s\")\n", countLines,yytext);
                                    yylval = atoi(yytext);
                                    return NUM;
                                  }

{digit}+({letter}+|{digit}+)+      {
                                    //fprintf(fileWrite,"(%d,ERROR,\"%s\")\n", countLines,yytext);
                                    return 0;
                                  }

{letter}({letter}|{digit})*       {
                                      if(isKeyWord(yytext)){
                                        printf("(%d,KEY,\"%s\")\n", countLines,yytext);
                                      }

                                      if(strcmp(yytext,"else")== 0)     {return ELSE;}
                                      if(strcmp(yytext,"if") == 0)      {return IF ;}
                                      if(strcmp(yytext,"int") == 0 )     {return INT; }
                                      if(strcmp(yytext,"return") == 0)   {return RETURN; }
                                      if(strcmp(yytext,"void") == 0)     {return  VOID; }
                                      if(strcmp(yytext,"while") == 0)    {return  WHILE;}


                                      printf("scan ID %s\n",yytext);

                                      return ID;

                                  }

{symb}                            {
                                      if(strcmp(yytext,"<=")== 0)     {return LE;}
                                      if(strcmp(yytext,">=") == 0)      {return GE ;}
                                      if(strcmp(yytext,"==") == 0 )     {return EQUAL; }
                                      if(strcmp(yytext,"!=") == 0)   {return DIF; }


                                    return yytext[0];
                                  }

[" "|\t]+                             /* alooo */

.                                {
                                    //fprintf(fileWrite,"(%d,ERROR,\"%s\")\n", countLines,yytext);
                                    printf("(%d,ERROR,\"%s\")\n", countLines,yytext);

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
