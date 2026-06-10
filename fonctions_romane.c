#include "header.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Fonction : retirer_retour_chariot
 * Entrée : chaine (char*)
 * Pré-condition : La chaine doit être une chaîne de caractères valide se terminant potentiellement par un '\n'.
 * Sortie : aucune
 * Post-condition : Supprime le caractère de retour chariot '\n' à la fin de la chaîne si présent.
 * Auteur : Romane
 */
void retirer_retour_chariot(char* chaine)
{
    size_t longueur = strlen(chaine);
    if (longueur > 0 && chaine[longueur - 1] == '\n') {
        chaine[longueur - 1] = '\0';
    }
}

/**
 * Fonction : saisir_client
 * Entrée : client (CLIENT*), liste_client (CLIENT[]), taille (int)
 * Pré-condition : La taille doit être un nombre positif, liste_client doit être un tableau de structures CLIENT préalablement alloué.
 * Sortie : aucune
 * Post-condition : Crée un client en demandant des informations à l'utilisateur et l'ajoute dans le tableau liste_client.
 * Auteur : Romane
 */
void saisir_client(CLIENT* client, CLIENT liste_client[], int taille) {
    printf("Entrer votre prenom puis appuyer sur entrer : ");
    fgets(client->prenom, sizeof(client->prenom), stdin);
    retirer_retour_chariot(client->prenom);

    printf("\nEntrer votre nom puis appuyer sur entrer : ");
    fgets(client->nom, sizeof(client->nom), stdin);
    retirer_retour_chariot(client->nom);

    printf("\nEntrer votre ville puis appuyer sur entrer : ");
    fgets(client->ville, sizeof(client->ville), stdin);
    retirer_retour_chariot(client->ville);

    printf("\nEntrer votre code postal puis appuyer sur entrer : ");
    fgets(client->cp, sizeof(client->cp), stdin);
    retirer_retour_chariot(client->cp);

    // Vérification du numéro de téléphone
    int valid = 0;
    while (!valid) {
        printf("\nEntrer votre numero de telephone (au format XX.XX.XX.XX.XX) puis appuyer sur entrer : ");
        fgets(client->num_tel, sizeof(client->num_tel), stdin);
        retirer_retour_chariot(client->num_tel);

        // Vérifier le format du numéro de téléphone
        if (strlen(client->num_tel) != 14) {
            valid = 0;
        } else {
            valid = 1;
            for (int i = 0; i < 14; i++) {
                if (i % 3 == 2) {
                    if (client->num_tel[i] != '.') {
                        valid = 0;
                        break;
                    }
                } else {
                    if (client->num_tel[i] < '0' || client->num_tel[i] > '9') {
                        valid = 0;
                        break;
                    }
                }
            }
        }

        if (!valid) {
            printf("Format invalide. Veuillez ressaisir.\n");
        } else {
            // Vérifier si le numéro de téléphone existe déjà dans la liste
            int exists = 0;
            for (int i = 0; i < taille; i++) {
                if (strcmp(liste_client[i].num_tel, client->num_tel) == 0) {
                    exists = 1;
                    break;
                }
            }

            if (exists) {
                printf("Le numero de telephone existe deja. Veuillez ressaisir.\n");
                valid = 0; // Si déjà existant, redemander
            }
        }
    }

    // Entrée de l'email
    printf("\nEntrer votre adresse mail puis appuyer sur entrer : ");
    fgets(client->mail, sizeof(client->mail), stdin);
    retirer_retour_chariot(client->mail);

    // Entrée de la profession
    printf("\nEntrer votre profession puis appuyer sur entrer : ");
    fgets(client->profession, sizeof(client->profession), stdin);
    retirer_retour_chariot(client->profession);

    // Entrée de la date de naissance
    printf("\nEntrer votre date de naissance puis appuyer sur entrer : ");
    fgets(client->date_nais, sizeof(client->date_nais), stdin);
    retirer_retour_chariot(client->date_nais);

    // Ajouter le client à la liste
    liste_client[taille] = *client;
}

/**
 * Fonction : sauvegarde
 * Entrée : liste_client (CLIENT[]), taille (int), fichier_nom (const char*)
 * Pré-condition : taille > 0, fichier_nom doit être le chemin valide d'un fichier.
 * Sortie : aucune
 * Post-condition : Ajoute les nouvelles lignes saisies dans le fichier, en supprimant tout le contenu existant du fichier.
 * Auteur : Romane
 */
void sauvegarde(CLIENT liste_client[], int taille, const char* fichier_nom)
{
    // supprimer tout le contenu du fichier
    FILE* fichier = fopen(fichier_nom, "w");

    // copier le contenu du tableau dans le fichier
    fichier = fopen(fichier_nom, "a");
    for (int i = 0; i < taille; i++) {
        // il faut les copier en format csv donc avec des virgules puis un retour a la ligne a la fin
        fprintf(fichier, "%s,", liste_client[i].prenom);
        fprintf(fichier, "%s,", liste_client[i].nom);
        fprintf(fichier, "%s ", liste_client[i].ville);
        fprintf(fichier, "%s,", liste_client[i].cp);
        fprintf(fichier, "%s,", liste_client[i].num_tel);
        fprintf(fichier, "%s,", liste_client[i].mail);
        fprintf(fichier, "%s,", liste_client[i].profession);
        fprintf(fichier, "%s\n", liste_client[i].date_nais);
    }
    fclose(fichier);
}

/**
 * Fonction : modifier_client
 * Entrée : client (CLIENT*), liste_client (CLIENT[]), taille (int)
 * Pré-condition : taille > 0, liste_client doit contenir au moins un client.
 * Sortie : aucune
 * Post-condition : Modifie un client existant dans le tableau liste_client en utilisant son numéro de téléphone pour l'identifier.
 * Auteur : Romane
 */
void modifier_client(CLIENT* client, CLIENT liste_client[], int taille)
{
    char telephone[TAILLE_NUM_TEL];
    printf("Entrer le numero de telephone du client a modifier : ");
    fgets(telephone, sizeof(telephone), stdin);
    retirer_retour_chariot(telephone);

    printf("telephone : %s\n", telephone);

    // on cherche le client a modifier
    for (int i = 0; i < taille; i++) {
        if (strcmp(liste_client[i].num_tel, telephone) == 0) {
            saisir_client(client, liste_client, i); // on modifie le client
            printf("Client modifie !\n");
            break;
        }
    }
}

/**
 * Fonction : ouvrir_fichier
 * Entrée : liste_client (CLIENT[]), fichier_nom (const char*)
 * Pré-condition : fichier_nom doit être un chemin de fichier valide.
 * Sortie : Retourne le nombre de clients chargés dans liste_client.
 * Post-condition : Charge les données d'un fichier CSV dans le tableau liste_client.
 * Auteur : Romane
 */
int ouvrir_fichier(CLIENT liste_client[], const char* fichier_nom) {
    FILE* fic = fopen(fichier_nom, "r") ;        //Ouverture de l'annuaire
    if(fic == NULL){
        printf("Echec de l'ouverture du fichier :(\n") ;
        exit(EXIT_FAILURE) ;
    }

    char ligne[TAILLE * 10] ;
    int i = 0, j = 0, k = 0 ;

    do {                                                    //Lecture du fichier et copie dans un tableau structurel
        fgets(ligne, TAILLE * 6, fic) ;

        while(ligne[j] != ','){
            liste_client[i].prenom[k] = ligne[j] ;
            k++ ;
            j++ ;
        }
        liste_client[i].prenom[k] = '\0' ;
        if(ligne[j] == ',') j++ ;
        k = 0 ;

        while(ligne[j] != ','){
            liste_client[i].nom[k] = ligne[j] ;
            j++ ;
            k++ ;
        }
        liste_client[i].nom[k] = '\0' ;
        if(ligne[j] == ',') j++ ;
        k = 0 ;

        if(ligne[j] != ','){
            while(ligne[j] != ' '){
                liste_client[i].ville[k] = ligne[j] ;
                j++ ;
                k++ ;
            }
            liste_client[i].ville[k] = '\0' ;
            if(ligne[j] == ' ') j++ ;
            k = 0 ;

            while(ligne[j] != ','){
                liste_client[i].cp[k] = ligne[j] ;
                j++ ;
                k++ ;
            }
            liste_client[i].cp[k] = '\0' ;
            if(ligne[j] == ',') j++ ;
            k = 0 ;
        }
        else j++ ;

        while(ligne[j] != ','){
            liste_client[i].num_tel[k] = ligne[j] ;
            j++ ;
            k++ ;
        }
        liste_client[i].num_tel[k] = '\0' ;
        if(ligne[j] == ',') j++ ;
        k = 0 ;

        while(ligne[j] != ','){
            liste_client[i].mail[k] = ligne[j] ;
            j++ ;
            k++ ;
        }
        liste_client[i].mail[k] = '\0' ;
        if(ligne[j] == ',') j++ ;
        k = 0 ;

        while(ligne[j] != ','){
            liste_client[i].profession[k] = ligne[j] ;
            j++ ;
            k++ ;
        }
        liste_client[i].profession[k] = '\0' ;
        if(ligne[j] == ',') j++ ;
        k = 0 ;

        while(ligne[j] != '\n'){
            liste_client[i].date_nais[k] = ligne[j] ;
            j++ ;
            k++ ;
        }
        liste_client[i].date_nais[k] = '\0' ;
        k = 0 ;

        j = 0 ;
        i++ ;

    } while (!feof(fic)) ;

    int nb_client = i + 1 ;

    fclose(fic) ;
    printf("Copie du fichier reussite !\n") ;

    return nb_client;
}

/**
 * Fonction : afficher_tableau
 * Entrée : liste_client (CLIENT[]), taille (int)
 * Pré-condition : taille > 0, liste_client doit contenir des entrées valides.
 * Sortie : aucune
 * Post-condition : Affiche les informations de tous les clients présents dans le tableau liste_client.
 * Auteur : Romane
 */
void afficher_tableau(CLIENT liste_client[], int taille)
{
    for (int i = 0; i < taille; i++) {
        printf("Client %d\n", i + 1);
        printf("Prenom : %s\n", liste_client[i].prenom);
        printf("Nom : %s\n", liste_client[i].nom);
        printf("Ville : %s\n", liste_client[i].ville);
        printf("Code postal : %s\n", liste_client[i].cp);
        printf("Numero de telephone : %s\n", liste_client[i].num_tel);
        printf("Mail : %s\n", liste_client[i].mail);
        printf("Profession : %s\n", liste_client[i].profession);
        printf("Date de naissance : %s\n", liste_client[i].date_nais);
        printf("\n");
    }
}
