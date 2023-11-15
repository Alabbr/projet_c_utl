#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
struct date{
char jour[10];
char mois[10];
char annee[10];};

typedef struct utilisateur{
char nom_utilisateur[30];
char prenom_utilisateur[30];
char etablissement[30];
char email[30];
char carte_d_identite[9] ;
char numero_de_telephone[30];
struct date ddr;
struct date ddn;}utl;
int ajouter(char *,utl);
int modifier(char*,char*,utl);
int supprimer(char *,char*);
utl chercher (char*,char*);
#endif
