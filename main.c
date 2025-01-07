#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures de données
typedef struct {
    char nom[50];
    int horaires[24];
    int nb_horaires;
} Arret;

typedef struct {
    char nom[50];
    Arret* arrets;
    int nb_arrets;
} Ligne;

typedef struct {
    Ligne* lignes;
    int nb_lignes;
} Reseau;

// Prototypes des fonctions
void afficher_menu();
void ajouter_ligne(Reseau* reseau);
void afficher_lignes(Reseau reseau);

// Fonction principale
int main() {
    Reseau reseau = {NULL, 0}; // Initialisation du réseau
    int choix;

    do {
        afficher_menu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_ligne(&reseau);
                break;
            case 2:
                afficher_lignes(reseau);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n--- Menu Principal ---\n");
    printf("1. Ajouter une ligne\n");
    printf("2. Afficher les lignes\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
}

// Fonction pour ajouter une ligne
void ajouter_ligne(Reseau* reseau) {
    printf("\nAjout d'une nouvelle ligne...\n");

    // Réallocation mémoire pour ajouter une nouvelle ligne
    reseau->lignes = realloc(reseau->lignes, (reseau->nb_lignes + 1) * sizeof(Ligne));
    Ligne* nouvelle_ligne = &reseau->lignes[reseau->nb_lignes];

    // Demander le nom de la ligne
    printf("Nom de la ligne : ");
    scanf("%s", nouvelle_ligne->nom);

    // Initialisation des arrêts
    nouvelle_ligne->arrets = NULL;
    nouvelle_ligne->nb_arrets = 0;

    // Mise à jour du compteur de lignes
    reseau->nb_lignes++;
    printf("Ligne ajouté avec succès !\n");
}

// Fonction pour afficher les lignes
void afficher_lignes(Reseau reseau) {
    printf("\n--- Liste des lignes ---\n");
    for (int i = 0; i < reseau.nb_lignes; i++) {
        printf("%d. %s\n", i + 1, reseau.lignes[i].nom);
    }
}
