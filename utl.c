#include "utl.h"
#include <string.h>

int ajouter(char * filename, utl p )
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n" ,p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.carte_d_identite, p.numero_de_telephone,p.ddr.jour, p.ddr.mois,p.ddr.annee,p.ddn.jour,p.ddn.mois,p.ddn.annee);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier(char *filename, char *id, utl nouv)
{
    int tr = 0;
    utl p;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w+");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                      p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email, p.carte_d_identite,
                      p.numero_de_telephone, p.ddr.jour, p.ddr.mois,
                      p.ddr.annee, p.ddn.jour, p.ddn.mois, p.ddn.annee) != EOF)
        {
            printf("Lecture depuis le fichier : %s %s %s %s %s %s %s %s %s %s %s %s\n",
                   p.nom_utilisateur, p.prenom_utilisateur, p.etablissement, p.email,p.carte_d_identite, 
                   p.numero_de_telephone, p.ddr.jour, p.ddr.mois,
                   p.ddr.annee, p.ddn.jour, p.ddn.mois, p.ddn.annee);

            if (strcmp(id,p.carte_d_identite) != 0)
            {
            printf("Pas de modification pour ID %s\n", p.carte_d_identite);
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                        p.nom_utilisateur, p.prenom_utilisateur, p.etablissement,
                        p.email,p.carte_d_identite, p.numero_de_telephone, 
                        p.ddr.jour, p.ddr.mois, p.ddr.annee,
                        p.ddn.jour, p.ddn.mois, p.ddn.annee);
            }
            else
            {
                    printf("Modification pour ID %s\n", id);
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                        nouv.nom_utilisateur, nouv.prenom_utilisateur, nouv.etablissement,
                        nouv.email, nouv.carte_d_identite, nouv.numero_de_telephone, 
                        nouv.ddr.jour, nouv.ddr.mois, nouv.ddr.annee,
                        nouv.ddn.jour, nouv.ddn.mois, nouv.ddn.annee);
                tr = 1;
            }
        }
    }

    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimer(char * filename, char * id)
{
    int tr=0;
    utl p;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.numero_de_telephone,p.carte_d_identite,p.ddr.jour,p.ddr.mois,p.ddr.annee,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
          if(strcmp(p.carte_d_identite, id)!=0)
               {  printf("Pas suppresion pour ID %s\n", p.carte_d_identite);
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s\n",
                        p.nom_utilisateur, p.prenom_utilisateur, p.etablissement,
                        p.email,p.carte_d_identite, p.numero_de_telephone, 
                        p.ddr.jour, p.ddr.mois, p.ddr.annee,
                        p.ddn.jour, p.ddn.mois, p.ddn.annee);}
            else
               tr=1 ;
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
utl chercher(char * filename, char * id)
{
    utl p;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom_utilisateur,p.prenom_utilisateur,p.etablissement,p.email,p.numero_de_telephone, p.carte_d_identite,p.ddr.jour,p.ddr.mois,p.ddr.annee,p.ddn.jour,p.ddn.mois,p.ddn.annee)!=EOF)
        {
            if(strcmp(p.carte_d_identite, id)==0)
{}
                else 
            tr=1; 

        }
    }
    fclose(f);
    if(tr==0)
        strcpy(p.carte_d_identite,"-1");
    return p;

}
