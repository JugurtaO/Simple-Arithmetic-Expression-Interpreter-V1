#include "analyse_lexicale.h"
#include "lecture_caracteres.h"
typedef enum {C_INIT, C_ENTIER, C_FIN, C_ERROR, C_OPARATEUR} Etat_Automate_Ana ;




// -- e.i : indifferent 
// --e.f : une Expression Arithmetique a ete lue dans fichier
// -- si elle ne contient pas d’erreur de syntaxe un message est affiche
// -- sinon le pgm termine sur un message d’erreur

void lecture_fichier(char *fichier,Lexeme tab[]);

void analyser(char *fichier,int *resultat);
