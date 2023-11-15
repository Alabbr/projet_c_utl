#include<stdio.h>
#include <string.h>
#include "utl.h"
int main(){
utl utl0,utl1,utl2;
strcpy(utl0.nom_utilisateur,"ali");
strcpy(utl0.prenom_utilisateur,"Arij");
strcpy(utl0.etablissement,"iset");
strcpy(utl0.email,"abb");
strcpy(utl0.carte_d_identite,"101010");
strcpy(utl0.numero_de_telephone,"21733782");
strcpy(utl0.ddr.jour,"1");
strcpy(utl0.ddr.mois,"9");
strcpy(utl0.ddr.annee,"2023");
strcpy(utl0.ddn.jour,"10");
strcpy(utl0.ddn.mois,"8");
strcpy(utl0.ddn.annee,"2005");

//

strcpy(utl1.nom_utilisateur,"ahmed");
strcpy(utl1.prenom_utilisateur,"salah");
strcpy(utl1.etablissement,"isetrades");
strcpy(utl1.email,"alabbr@gmailcom");
strcpy(utl1.carte_d_identite,"07237472");
strcpy(utl1.numero_de_telephone,"7312314");
strcpy(utl1.ddr.jour,"1");
strcpy(utl1.ddr.mois,"1");
strcpy(utl1.ddr.annee,"2023");
strcpy(utl1.ddn.jour,"1");
strcpy(utl1.ddn.mois,"10");
strcpy(utl1.ddn.annee,"2044");






int x;
x=ajouter("utl.txt",utl0);
if(x==1)
printf("ajout de point avec succée");
else printf("erreur d'ajout");

printf("%s\n",utl0.carte_d_identite);

/*x=modifier("utl.txt","101010",utl1);
if(x==1){
printf("\n Modification de point avec succée");}
else {
printf("\néchec de modification\n");}





x=supprimer("utl.txt","07237472");
if (x==1)
printf("suppresion despoint avec succes");
else printf("echec suppression");*/
utl2=chercher("utl.txt","101010");
printf("%s",utl2.email);

return 0;
}
