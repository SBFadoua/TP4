#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct module{
	char Nom_M[20] ;
	float Note_Module;
}Module ;
typedef struct Etudiant {
	char CNE[20] ;
	char Nom_Prenom[50] ;
	Module* mod ;
	int Nbre_module ;
} Etudiant;


//Q1
Etudiant saisie(Etudiant E){
	int i;
	// saisir CNE
	printf("Entrer le CNE");
	scanf("%s", E.CNE);
	//saisir nom
	printf("Entrer le nom et prenom "); 
	scanf("%s", E.Nom_Prenom);
	//saisir nb modules
	printf("Entrer le nombre de modules ");
	scanf("%d",&E.Nbre_module);
	
	//créer liste de modules pour chaqueetudiant
	E.mod=(Module*)malloc(E.Nbre_module*sizeof(Module));

	// saisir nom et note de chaque module
	for(i=0;i<E.Nbre_module;i++){
		printf("Entrer le nom du module ");
		scanf("%s", E.mod[i].Nom_M);
		printf("Entrer la note du module ");
		scanf("%f", &E.mod[i].Note_Module); 
	}
	return E;
}
	
Etudiant* lire(Etudiant* T,int N){
	int i;
	T=(Etudiant*)malloc(N*sizeof(Etudiant));
	for(i=0;i<N;i++){T[i]=saisie(T[i]);}
	return T; 
}
//Q2
void affiche(Etudiant* T,int N){
	int i,j;
	for(i=0 ; i < N ; i++){
		puts(T[i].Nom_Prenom);
		// printf("%s\n", T[i].Nom_Prenom);
		printf("\n");
		puts(T[i].CNE);
		//printf("%s\n", T[i].CNE);
		printf("\n");
		for(j=0 ; j<T[i].Nbre_module ; j++){
			puts(T[i].mod[j].Nom_M);
			//printf("%s\n", T[i].mod[j].Nom_M);
			printf("Note = %.2f\n",T[i].mod[j].Note_Module);
		}
		printf("\n");	
	}
}
//Q3
void valide_semestre(Etudiant* T,int N){
	int comp=0, i, j ;
	float s;
	for(i=0;i<N;i++){
		s=0;
		for(j=0;j<T[i].Nbre_module;j++){
			s+=T[i].mod[j].Note_Module;	
		}
		if(s/T[i].Nbre_module>=10) 
			comp++; 
	}
	printf("%d",comp);
}
//q4
int inscrit_module(Etudiant* T,int N, char* nom_module){
	int comp,i,j;
	comp=0;
	for(i=0;i<N;i++){
		for(j=0;j<T[i].Nbre_module;j++){
			if(strcasecmp(T[i].mod[j].Nom_M,nom_module)==0) comp++;
		} 
	}
	return comp;
}


int main(){
	int n;
	printf("Nombre d'etudiants: ");
    scanf("%d", &n);
    Etudiant* etudiants = (Etudiant*)malloc(n * sizeof(Etudiant));
    printf("**** saisie ****\n");
    etudiants=lire(etudiants,n);
    printf("**** affichage ****\n");
	affiche(etudiants,n);
	printf("étudiants ayant valide le semestre : ");
	valide_semestre(etudiants, n);
	char nom_module[20]; // Supposons que le nom du module soit saisi par l'utilisateur
    printf("\nEntrez le nom du module: ");
    scanf("%s", nom_module);
    int nb_inscrits = inscrit_module(etudiants, n, nom_module);
    printf("\nNombre d'etudiants inscrits dans le module %s: %d\n", nom_module, nb_inscrits);
	return 0;
}
