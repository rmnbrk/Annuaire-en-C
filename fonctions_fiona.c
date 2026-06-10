#include "header.h"

#include <stdio.h>  //printf
#include <stdlib.h> //FILE
#include <string.h> //Fonction strcmp

void affich_client(int index){
    printf("Client numero %.4d : ", index) ;
    printf("%s, %s, %s %s, %s, %s, %s, %s\n",
           liste_client[index].prenom,
           liste_client[index].nom,
           liste_client[index].ville,
           liste_client[index].cp,
           liste_client[index].num_tel,
           liste_client[index].mail,
           liste_client[index].profession,
           liste_client[index].date_nais) ;
}

/**
 * entr�e date1 et date2: char
 * pr�-cond: date1 et date2 �critent sous la forme jj/mm/aaaa
 * sortie :
 * post-cond: retourne la diff�rence entre les annees, les mois (si les annees sont les m�mes) ou les jours (si les annees sont les m�mes) des 2 dates.
 * auteur : Fiona
 */
int compare_date(const char* date1, const char* date2) {
    int jour1 = date1[0] * 10 + date1[1];  // Extraire le jour
    int mois1 = date1[3] * 10 + date1[4];  // Extraire le mois
    int annee1 = (date1[6] * 1000) + (date1[7] * 100) + (date1[8] * 10) + date1[9];  // Extraire l'ann�e

    int jour2 = date2[0] * 10 + date2[1];  // Extraire le jour
    int mois2 = date2[3] * 10 + date2[4];  // Extraire le mois
    int annee2 = (date2[6] * 1000) + (date2[7]* 100) + (date2[8] * 10) + date2[9];  // Extraire l'ann�e

    // Comparaison des ann�es
    if (annee1 != annee2)
        return annee1 - annee2;
    // Si les ann�es sont �gales, comparer les mois
    if (mois1 != mois2)
        return mois1 - mois2;
    // Si les mois sont �gaux, comparer les jours
    return jour1 - jour2;
}

/**
 * entr�e n, tab, critere : int, [char], int
 * pr�-cond: n > 0 le nombre de clients stocker dans l'annuaire, tab un tableau de chaines de caract�res, critere �gal a 0 ou 1.
 * sortie : aucune
 * post-cond: tri les clients dans l'orde alphab�tique selon les chaines contenu dans tab.
 * auteur : Fiona
 */
void tri(int n, char tab[n][200], int critere) {
    int i_maxi;
    char temp[200];
    int i = n - 1;

    while (i > 0) {
        i_maxi = i;
        for (int j = 0; j < i; j++) {
            // Comparaison des pr�noms, noms, ville etc...
                if (critere == 1) {  // Tri par pr�nom, nom, etc.
                    if (strcmp(tab[j], tab[i_maxi]) > 0) {
                        i_maxi = j;
                    }
                }
                else if (critere == 2) {  // Comparaison des dates de naissances
                    if (compare_date(tab[j], tab[i_maxi]) > 0) {
                        i_maxi = j;
                }
            }
        }

        // �change des �l�ments
        strcpy(temp, tab[i]);
        strcpy(tab[i], tab[i_maxi]);
        strcpy(tab[i_maxi], temp);

        // R�organiser les clients en fonction du tableau tri� de pr�noms
        CLIENT temp_client = liste_client[i];
        liste_client[i] = liste_client[i_maxi];
        liste_client[i_maxi] = temp_client;

        i = i - 1;
    }
}


/**
 * entr�e n: int
 * pr�-cond: n > 0 le nombre de clients stocker dans l'annuaire
 * sortie : aucune
 * post-cond: affiche la liste des clients trier (dans l'ordre alphab�tique ou chronologique) selon un crit�re pr�alablement choisi par l'utilisateur.
 * auteur : Fiona
 */
void affiche_trier(int n) {
    int choix;
    char tab[n][200];  // Tableau temporaire pour stocker les pr�noms
    printf("\nPar quoi voulez-vous trier la liste de clients ?\n\n");
    printf("1.Prenom    2.Nom    3.Ville    4.Code postal    5.Numero    6.Email    7.Profession    8.Date de naissance : ");
    scanf("%d", &choix);  // Utilisation de %d pour un entier, pas %c

    switch (choix) {
        case 1:  // Trier par pr�nom
            // Copier les pr�noms dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].prenom);
            }
            tri(n, tab, 1);  // Tri des clients par pr�nom
            break;

        case 2:  // Trier par nom
            // Copier les noms dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].nom);
            }
            tri(n, tab, 1);  // Tri des clients par nom
            break;

        case 3:  // Trier par ville
            // Copier les villes dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].ville);
            }
            tri(n, tab, 1);  // Tri des clients par ville
            break;

        case 4:  // Trier par code postal
            // Copier les codes postaux dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].cp);
            }
            tri(n, tab, 1);  // Tri des clients par code postal
            break;

        case 5:  // Trier par num�ro de t�l�phone
            // Copier les num�ros de t�l�phone dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].num_tel);
            }
            tri(n, tab, 1);  // Tri des clients par num�ro de t�l�phone
            break;

        case 6:  // Trier par email
            // Copier les emails dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].mail);
            }
            tri(n, tab, 1);  // Tri des clients par email
            break;

        case 7:  // Trier par profession
            // Copier les professions dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].profession);
            }
            tri(n, tab, 1); // Tri des clients par profession
            break;

        case 8:  // Trier par date de naissance
            // Copier les dates de naissance dans tab
            for (int i = 0; i < n; i++) {
                strcpy(tab[i], liste_client[i].date_nais);
            }
            tri(n, tab, 2);  // Tri des clients par date de naissance
            break;

        default:
            printf("Choix invalide.\n");
            break;
    }

    // Affichage des clients tri�s
    printf("\nListe des clients tri�e :\n");
    for (int i = 0; i < n; i++) {
        affich_client(i);
    }
}

/**
 * entr�e n: int
 * pr�-cond: n > 0 le nombre de clients stocker dans l'annuaire
 * sortie : aucune
 * post-cond: affiche la liste des clients correspondant � la recherche de l'utilisateur.
 * auteur : Fiona
 */
void recherche_par(int n)
{
    int choix;
    char chaine[20];
    int nb_clients_trouve=0;

    printf("\nSelon quelle information souhaitez vous emettre votre recherche ?\n\n");
    printf("1.Prenom    2.Nom    3.Ville    4.Code postal    5.Numero    6.Email    7.Profession    8.Date de naissance : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:  // Recherche par prenom
            printf("\nQuel est le prenom recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour prenom %s :\n\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].prenom) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 2:  // Recherche par nom
            printf("\nQuel est le nom recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour nom %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].nom) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 3:  // Recherche par ville
            printf("\nQuelle est la ville recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour ville %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].ville) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 4:  // Recherche par code postal
            printf("\nQuel est le code postal recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour code postal %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].cp) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 5:  // Recherche par num�ro de t�l�phone
            printf("\nQuel est le numero de telephone recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nVoici le client correspondant au numero %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].num_tel) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 6:  // Recherche par email
            printf("\nQuel est le mail recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour mail %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].mail) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 7:  // Recherche par profession
            printf("\nQuel est la profession recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour profession %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].profession) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        case 8:  // Recherche par date de naissance
            printf("\nQuel est la date de naissance recherche ?\n\n");
            scanf("%s", &chaine);

            printf("\nListe des clients avec pour date %s :\n", chaine);
            for (int i = 0; i < n; i++) {
                if (strcmp(chaine, liste_client[i].date_nais) == 0) {
                    affich_client(i);
                    nb_clients_trouve++;
                }
            }
            break;

        default:
            printf("Choix invalide.\n");
            break;

    }
    if (nb_clients_trouve==0 && choix>0 && choix<8)
    {
        printf("Aucun clients trouve");
    }
}

/**
 * entr�e n: int
 * pr�-cond: n > 0 le nombre de clients stocker dans l'annuaire
 * sortie : aucune
 * post-cond: affiche le nombre de clients dont des donnees sont manquantes ainsi que la liste de ces derniers.
 * auteur : Fiona
 */
void afficher_Nb_Donnees_Manquantes(int n)
{
    printf("\nListe des clients avec des donnees manquantes :\n\n");

    int clientsManquants = 0;
    int donneesManquantes = 0;

    // Parcours de tous les clients
    for (int i = 0; i<n; i++) {
        donneesManquantes = 0;

        // V�rification des champs manquants
        if (strlen(liste_client[i].prenom) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].nom) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].ville) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].cp) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].num_tel) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].mail) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].profession) == 0)
            donneesManquantes++;
        if (strlen(liste_client[i].date_nais) == 0)
            donneesManquantes++;


        if (donneesManquantes > 0){
            clientsManquants++;
            affich_client(i);
        }
    }
    printf("\nNous comptabilisons %d clients dont des donnees sont manquantes ! \n", clientsManquants) ;
}
