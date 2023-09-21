#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct date
{
    int jour;
    int mois;
    int annee;
} date;

typedef struct tache
{
    int id;
    char titre[100];
    char description[500];
    date deadline;
    char statut[100];
} tache;
int taille = 0;
void ajouter(tache tch[])
{
    if (taille == 0)
    {
        tch[taille].id = 1;
    }
    else
    {
        tch[taille].id = tch[taille - 1].id + 1;
    }

    printf("Veuillez entrer le titre : ");
    scanf(" %[^\n]", tch[taille].titre);

    printf("Veuillez entrer la description : ");
    scanf(" %[^\n]", tch[taille].description);

    printf("Veuillez entrer le statut : ");
    scanf(" %[^\n]", tch[taille].statut);

    printf("Entrer le jour : ");
    scanf("%d", &tch[taille].deadline.jour);

    printf("Entrer le mois : ");
    scanf("%d", &tch[taille].deadline.mois);

    printf("Veuillez entrer l'annee : ");
    scanf("%d", &tch[taille].deadline.annee);

    taille++;
}

void ajouterTaches(tache tch[], int nombreTaches)
{
    for (int i = 0; i < nombreTaches; i++)
    {
        ajouter(tch);
    }
}
void trie(tache tch[])
{
    int cmp;
    do
    {
        cmp = 0;
        for (int i = 0; i < taille - 1; i++)
        {
            if (strcmp(tch[i].titre, tch[i + 1].titre) > 0)
            {
                tache temp = tch[i];
                tch[i] = tch[i + 1];
                tch[i + 1] = temp;
                cmp = 1;
            }
        }
    } while (cmp);
}

void affichages(tache tch[])
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("\t\t\t\t\t----Votre taches-----\n");
        printf("\t\t\t\t\t------Tache %d---- \n", tch[i].id);
        printf("\t\t\t\t\tId : %d \n", tch[i].id);
        printf("\t\t\t\t\tTitre : %s \n", tch[i].titre);
        printf("\t\t\t\t\tDescription : %s \n", tch[i].description);
        printf("\t\t\t\t\tStatut : %s \n", tch[i].statut);
        printf("\t\t\t\t\tLa date  %d/%d/%d \n", tch[i].deadline.jour, tch[i].deadline.mois, tch[i].deadline.annee);
    }
}
int main()
{
    int choix, affi, modifier, recherche, statistiques;
    tache tch[100];
    int nombreTaches;

    do
    {
        printf("\n\t\t\t\t\t-------Menu-------\n\n");
        printf("\n\t\t\t\t\t1 - Ajouter une nouvelle tache.");
        printf("\n\t\t\t\t\t2 - Ajouter plusieurs nouvelles taches.");
        printf("\n\t\t\t\t\t3 - Afficher la liste de toutes les taches.");
        printf("\n\t\t\t\t\t4 - Modidier une tache.");
        printf("\n\t\t\t\t\t5 - Supprimer une tache par identifiant.");
        printf("\n\t\t\t\t\t6 - Rechercher les taches.");
        printf("\n\t\t\t\t\t7 - Statistiques.");
        printf("\n\t\t\t\t\t8 - Quitter.\n");

        printf("Votre choix est : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Ajouter une nouvelle tache.\n");
            ajouter(tch);
            affichages(tch);
            break;
        case 2:
            printf("Ajouter plusieurs nouvelles taches.\n");
            printf("Combien de taches voulez vous ajouter : ");
            scanf("%d", &nombreTaches);
            ajouterTaches(tch, nombreTaches);
            affichages(tch);
            break;
        case 3:
            printf("Afficher la liste de toutes les taches.\n");
            do
            {
                printf("\t\t\t\t\t1 - Trier la tache par ordre alphabetique.\n");
                printf("\t\t\t\t\t2 - Trier la tache par deadline.\n");
                printf("\t\t\t\t\t3 - Afficher les taches dont le deadline est 3 jours ou moins.\n");
                printf("\t\t\t\t\t4 - Quitter.\n");
                printf("\t\t\t\t\tChoisi le tri que vous voulez : ");
                scanf("%d", &affi);
                switch (affi)
                {
                case 1:
                    printf("\t\t\t\t\tTrier les tache par ordre alphabetique.\n");
                    trie(tch);
                    printf("\t\t\t\t\tTaches triees par titre :\n");
                    for (int i = 0; i < taille; i++)
                    {
                        printf("Tache %d : %s\n", tch[i].id, tch[i].titre);
                    }
                    break;
                case 2:
                    printf("\t\t\t\t\tTrier les tache par deadline.\n");
                case 3:
                    printf("\t\t\t\t\tAfficher les taches dont le deadline est dans 3 jours ou moins.\n");
                case 4:
                    printf("\t\t\t\t\tQuitter.\n");
                default:
                    printf("choix invalid.\n");
                    break;
                }

                break;
            } while (affi != 4);
            break;
        case 4:
            printf("Modidier une tache \n");
            do
            {
                printf("\t\t\t\t\t1 - Modifier la description d une tache.\n");
                printf("2 - Modifier la statut d une tache.\n");
                printf("3 - Modifier la deadline d une tache.\n");
                printf("4 - Quitter \n");
                printf("Choisi le modifier que vous voulez : ");
                scanf("%d", &modifier);
                switch (modifier)
                {
                case 1:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 2:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 3:
                    printf("Modifier la description d une tache.\n");
                    break;
                case 4:
                    printf("Quitter \n");
                default:
                    printf("Choix invalide");
                    break;
                }
            } while (modifier != 4);

            break;
        case 5:
            printf("Supprimer une tache par identifiant \n");
            break;
        case 6:
            printf("Rechercher les taches \n");
            do
            {
                printf("\t\t\t\t\t1 - Rechercher une tache par son identifiant.\n");
                printf("\t\t\t\t\t2 - Rechercher une tache par son titre.\n");
                printf("\t\t\t\t\t3 - Quitter.\n");
                printf("Choisi le recherche que vous voulez : ");
                scanf("%d", &recherche);
                switch (recherche)
                {
                case 1:
                    printf("Rechercher une tache par son identifiant.\n");
                    break;
                case 2:
                    printf("Rechercher une tache par son titre.\n");
                    break;
                case 3:
                    printf("Quitter.\n");
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (recherche != 3);

            break;
        case 7:
            printf("Statistiques \n");
            do
            {
                printf("\t\t\t\t\t1 - Afficher le nombre total des taches.\n");
                printf("\t\t\t\t\t2 - Afficher le nombre de taches comletes et incompletes.\n");
                printf("\t\t\t\t\t3 - afficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                printf("\t\t\t\t\t4 - Quitter.\n");
                printf("choisi le statistique que vous voulez : ");
                scanf("%d", &statistiques);
                switch (statistiques)
                {
                case 1:
                    printf("Afficher le nombre total des taches.\n");
                    break;
                case 2:
                    printf("Afficher le nombre de taches comletes et incompletes.\n");
                    break;
                case 3:
                    printf("Afficher le nombre dejours restants jusqu au delai de chaque tache.\n");
                    break;
                case 4:
                    printf("Quitter.\n");
                    break;
                default:
                    printf("choix invalid \n");
                    break;
                }
            } while (statistiques != 4);

            break;
        case 8:
            printf("\t\t\t\t\tQuitter \n");

        default:
            printf("Choix invalide \n");
            break;
        }
    } while (choix != 8);
    return 0;
}
