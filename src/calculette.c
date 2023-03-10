// #include "analyse_lexicale.h"
#include "../headers/analyse_syntaxique.h"
// #include "lecture_caracteres.h"
#include <stdio.h>



int main(int argc,char**argv){

    int res = -1;

    if (argc!=2){
        return -1;
    }
    else{
        analyser(argv[1],&res);
       
    
    }
    return 0;
}




