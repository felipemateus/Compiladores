%{
  #include <stdio.h>
  #include <stdlib.h>
%}

%token NUM KEY ID SYB ERROR


%left PLUS MINUS
%left TIMES DIV

%start inicio


%%

inicio  : program                               {printf("[program")};



program : declarationList
        ;

declarationList :  declarationList  declaration
                 | declaration
                 ;

declaration      : varDeclaration
                 ;

varDeclaration  :  typeSpecifier ID ;
                 |  typeSpecifier ID [ NUM ] ;
                 ;

typeSpecifier    : int
                 | void
                 ;
