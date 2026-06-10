#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"

int main()
{

    const char* fichier_nom = "annuaire_50_entrees.csv";   // Nom du fichier à manipuler

    CLIENT liste_client[NB_MAX_CLIENT];
    CLIENT client;
    int taille = 0;
    int choix;

    taille = ouvrir_fichier(liste_client, fichier_nom);

    afficher_tableau(liste_client, taille);

    do {
        printf("\n1. Ajouter un client\n");
        printf("2. Modifier les donnees d'un client\n");
        printf("3. Supprimer un client\n");
        printf("4. Afficher la liste de tous les clients\n");
        printf("5. Rechercher un client\n");
        printf("6. Afficher le nombre et la liste des clients avec donnees manquantes\n");
        printf("7. Filtrer les clients\n");
        printf("8. Sauvegarder les donnees\n");
        printf("9. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); // pour vider le buffer

        switch (choix) {
        case 1:
            saisir_client(&client, liste_client, taille);
            taille++;
            break;
        case 2:
            modifier_client(&client, liste_client, taille);
            break;
        case 3:
            printf("fonction non disponible");
        case 4:
            afficher_tableau(liste_client, taille);
            break;
        case 5:
            recherche_par(taille);
            break;
        case 6:
            afficher_Nb_Donnees_Manquantes(taille);
            break;
        case 7:
            printf("fonction non disponible");
            break;
        case 8:
            sauvegarde(liste_client, taille, fichier_nom);
            break;
        case 9:
            break;
        default:
            printf("Choix invalide\n");
        }
    } while (choix != 9);

    return 0;
}
