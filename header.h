#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_LIGNE 500
#define TAILLE 50
#define TAILLE_CP 7
#define TAILLE_NUM_TEL 16
#define TAILLE_DATE_NAIS 12
#define NB_MAX_CLIENT 5100


typedef struct{
    char prenom[TAILLE], nom[TAILLE], ville[TAILLE], cp[TAILLE_CP], num_tel[TAILLE_NUM_TEL], mail[TAILLE], profession[TAILLE], date_nais[TAILLE_DATE_NAIS] ;
}CLIENT;

CLIENT liste_client[NB_MAX_CLIENT] ;

/**
 * Gatien
 */
char menu_princ(int) ;
void menu_affichage(int) ;
void affich_tous_clients(int) ;
void affich_client(int) ;
int confirm() ;
int cherch_par_num_tel(int, char) ;
void supprimer_client() ;

/**
 * Romane
 */
void retirer_retour_chariot(char* chaine);
void saisir_client(CLIENT* client, CLIENT liste_client[], int taille);
void sauvegarde(CLIENT liste_client[], int taille, const char* fichier_nom);
void modifier_client(CLIENT* client, CLIENT liste_client[], int taille);
int ouvrir_fichier(CLIENT liste_client[], const char* fichier_nom);
void afficher_tableau(CLIENT liste_client[], int taille);

/**
 * Fiona
 */
void affiche_trier(int);
void recherche_par(int) ;
void afficher_Nb_Donnees_Manquantes(int);
void filtre(int);

#endif // FONCTIONS_H_INCLUDED
