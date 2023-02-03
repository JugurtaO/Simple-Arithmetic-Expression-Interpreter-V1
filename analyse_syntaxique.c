#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "analyse_syntaxique.h"

void analyser(char *fichier, int *resultat)
{
    Lexeme tab[256];
    lecture_fichier(fichier, tab);
    

    Etat_Automate_Ana etat = C_INIT;
    Nature_Lexeme Lex;
    int currentIndex = 0;
    int res = 0;
    Nature_Lexeme op_prec = ENTIER;
    printf("------Les lexèmes de l'expressions :------\n");
    printf("*********************************************\n");
    while (etat != C_FIN && etat != C_ERROR)
    {
        
        Lex = tab[currentIndex].nature;
      
        afficher(tab[currentIndex]);
        printf("\n");

        

        switch (etat)
        {
        case C_INIT:
          
            switch (Lex)
            {
            case ENTIER:
                
                etat = C_ENTIER;
                switch (op_prec)
                {
                case ENTIER:
                    res = tab[currentIndex].valeur;
                    break;
                case PLUS:
                    res = res + tab[currentIndex].valeur;
                    break;
                case MOINS:
                    res = res - tab[currentIndex].valeur;
                    break;
                case MUL:
                    res = res * tab[currentIndex].valeur;
                    break;
                case DIV:
                    if (tab[currentIndex].valeur != 0)
                        res = res / tab[currentIndex].valeur;
                    else
                        etat = C_ERROR;
                    break;
                default:
                    break;
                }
                break;

            default:
                etat = C_ERROR;
                break;
            }
            break;
        case C_ENTIER:
            
            switch (Lex)
            {
            case PLUS:
            case MOINS:
            case MUL:
            case DIV:
                etat = C_OPARATEUR;
                op_prec = Lex;
                
                break;
            case FIN_SEQUENCE:
                
                etat = C_FIN;
                break;
            default:
                etat = C_ERROR;
                break;
            }
            break;

        case C_OPARATEUR:
    
            switch (Lex)
            {
            case ENTIER:
                etat = C_ENTIER;
                switch (op_prec)
                {
                case ENTIER:
                    res = tab[currentIndex].valeur;
                    break;
                case PLUS:
                    res = res + tab[currentIndex].valeur;
                    break;
                case MOINS:
                    res = res - tab[currentIndex].valeur;
                    break;
                case MUL:
                    res = res * tab[currentIndex].valeur;
                    break;
                case DIV:
                    if (tab[currentIndex].valeur != 0)
                        res = res / tab[currentIndex].valeur;
                    else
                        etat = C_ERROR;
                    break;
                default:
                    break;
                }
                break;

            default:
                etat = C_ERROR;
                break;
            }
            break;
        default:
            break;
        }

        currentIndex++;
    }

    
    if (etat == C_FIN)
    {
        printf("L'expression est correcte, le resultat est : %d\n", res);
        (*resultat)= res;
    }
    else
    {
        printf("L'expression est incorrecte!!\n");
    }
}

void lecture_fichier(char *fichier, Lexeme tab[])
{
    int currentIndex = 0;
    
    demarrer(fichier);
    while (!fin_de_sequence())
    {

        tab[currentIndex] = lexeme_courant();

        currentIndex++;
        avancer();
    }

    Lexeme L;
    L.nature = FIN_SEQUENCE;
    tab[currentIndex] = L;
}
