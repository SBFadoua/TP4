#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1
typedef struct Date{
	int jj;
	int mois;
	int Annee;
} Date;
typedef struct Produit{
	char Reference[15];
	float Prix;
	int Qt_Stock_Actuel;
	int Qt_Stock_Alerte;
	Date Date_Expiration;
}Produit;
//Q2
Produit * SaisieProduit(Produit* T, int N){
	int i;
	T=(Produit*)malloc(sizeof(Produit));
	if(T==NULL) 
		printf("Echec d'allocation!");
	else {
		for (i=0; i<N; i++) {
			printf("Donner la reference du produit %d: ",i+1);
			scanf("%s",&(T+i)->Reference);
			printf("Donner le prix du produit %d: ",i+1);
			scanf("%f",&(T+i)->Prix);
			printf("Donner la quantite du stock actuel %d: ",i+1);
			scanf("%d",&(T+i)->Qt_Stock_Actuel);
			printf("Donner la quantite du stock d'alerte %d: ",i+1);
			scanf("%d",&(T+i)->Qt_Stock_Alerte);
			printf("Date d'expiration\n ");
			printf("Donner le jour : ");	
			scanf("%d",&(T+i)->Date_Expiration.jj);
			printf("Donner le mois : ");
			scanf("%d",&(T+i)->Date_Expiration.mois);
			printf("Donner l Annee : ");
			scanf("%d",&(T+i)->Date_Expiration.Annee);
		} 
	}
	return T; 
}
//Q3
void AffichageProduit(Produit* T, int N){
	int i;
	for (i=0; i<N; i++) {
		printf("-------------- Produit %d ---------------\n",i+1);
		printf("La reference: %s\n",(T+i)->Reference);
		printf("le prix: %2f\n",(T+i)->Prix);
		printf(" la quantite du stock actuel: %d\n",(T+i)->Qt_Stock_Actuel);
		printf(" la quantite du stock d'alerte: %d\n",(T+i)->Qt_Stock_Alerte);
		printf("La date d'expiration: %d%s%d%s%d\t",(T+i)->Date_Expiration.jj,"/",(T+i)->Date_Expiration.mois,"/",(T+i)->Date_Expiration.Annee);
		printf("\n");
	}
}

//Q4
void rechercheProduit (Produit * T, int N){
	int i;
	int OK=0;
	int Annee, mois;
	printf("Saisir la date d'expiration a chercher : ");
	printf("Saisir l'Annee : ");
	scanf("%d", &Annee);
	printf("Saisir le mois : ");
	scanf("%d", & mois);
	for (i=0; i<N; i++) {
		if (((T[i].Date_Expiration.mois)== mois)&&(T[i].Date_Expiration.Annee)== Annee) {
			printf("%s\n", T[i].Reference);
			OK=1; 
		} 
	}
	if (!OK) printf ("Produit introuvable"); 
}

//Q5
void Commande (Produit * T, int N){
	int i;
	int OK=0;
	int Qte;
	for (i=0; i<N; i++) {
		if ((T[i].Qt_Stock_Actuel)==(T[i].Qt_Stock_Alerte)) {
			printf("Le produit dont le stock alerte est atteint est %s\n", T[i].Reference);
			printf("Entrer la quantite du produit a commander :\n");
			scanf("%d",&Qte);
			printf("Le prix de la commande à lancer est : %2f \t", Qte*(T[i].Prix));
			OK=1; 
		} 
	}
	if (!OK) printf ("Pas de commande a faire"); 
}

int main(){
	int n;
    printf("Nombre de produits: ");
    scanf("%d", &n);

    // Allocation de mémoire pour le tableau de produits
    Produit* produits = NULL;

    // Appel de la fonction SaisieProduit pour saisir les produits
    printf("**** Saisie des produits ****\n");
    produits = SaisieProduit(produits, n);
    // Appel de la fonction AffichageProduit pour afficher les produits
    printf("**** Affichage des produits ****\n");
    AffichageProduit(produits, n);

    // Appel de la fonction rechercheProduit pour chercher les produits expirant à une certaine date
    printf("**** Recherche des produits expirant ce mois-ci ****\n");
    rechercheProduit(produits, n);

    // Appel de la fonction Commande pour commander les produits ayant atteint le stock d'alerte
    printf("**** Commande des produits ****\n");
    Commande(produits, n);

    // Libération de la mémoire allouée dynamiquement
    free(produits);


	return 0;
}
