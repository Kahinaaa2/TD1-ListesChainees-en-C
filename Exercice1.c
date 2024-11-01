//Exercice 1 (Listes des puissances de deux)
// 1. Déclarer une structure Chainon permettant de construire une liste chaînée comportant des entiers.
// 2. Écrire une fonction Chainon * creationChainon(int a) qui retourne un pointeur vers un nouveau Chainon contenant
 l’entier a.
// 3. Écrire une fonction Chainon * insertDebut(Chainon* pliste, int a) permettant d’insérer un nouvel entier a en début de la liste chaînée pointée par pliste. Cette fonction retourne la tête de la liste chaînée.
// 4. Écrire une fonction insertFin(Chainon* pliste, int a) permettant d’insérer un nouvel entier a en fin de la liste chaînée pointée par pliste.
// 5. Écrire une procédure afficheListe(Chainon* pliste) permettant d’afficher les différents éléments de la liste chaînée pointée par pliste. Les entier seront séparés par le symbole "->". Ex : 1-> 10-> 3-> 15
// 6. Dans le programme principal, initialiser un pointeur sur une liste vide.
// 7. On souhaite que ce programme affiche une liste des puissances de deux dans l’ordre. La taille de cette liste sera décidée par l’utilisateur; on affiche la liste chaînée et on demande à l’utilisateur s’il souhaite voir la puissance de deux suivante, si c’est le cas, on rajoute un Chainon supplémentaire à la liste et on l’affiche à nouveau, sinon on arrête le programme.

   #include<stdio.h>
   #include<stdlib.h>
// 1
   
   typedef struct chainon{
      int valeur;
      struct chainon *suivant;
   }Chainon;

// 2
   Chainon *createChainon(int v){
       Chainon *new = malloc(sizeof(Chainon));
           if(new == NULL){
               exit(1);
           }
       new->valeur = v;
       new->suivant = NULL;
       return new;
   }
// 3
   Chainon *insertDebut( Chainon *tete, int val){
        if(tete == NULL){
          tete = createChainon(val);
        }
   else{
     Chainon *new = createChainon(val);
          if(new == NULL){
            exit(2);
          }
      new->suivant = tete;
      tete = new; // mise a jour de la tete      
    }
   return tete;
   }

// 4

Chainon *insertFin(Chainon* tete, int val){
    if(tete == NULL){
        tete=createChainon(val);
    }
    else
    {
        Chainon *new = createChainon(val);
        if (new==NULL){
            exit(2);
        }
        Chainon *tmp = tete;
        while(tmp->suivant != NULL){
            tmp=tmp->suivant;
            }
            tmp->suivant=new;
        }
        return tete;
    }

// 5

void afficherListe(Chainon *liste){
    if(liste == NULL){
         printf("La liste et vide.\n");
    }
    else{
        while(liste->suivant != NULL){
            printf("%d->", liste->valeur);
            liste = liste->suivant;
        }
    }
    printf("\n");
}

// 6 7

int main(){
    
    Chainon* liste = NULL; 
    char reponse = '0';
    int i = 1;
    while (reponse == 0) // Tant que je souhaite ajouter des éléments
    {   
        liste = insertFin(liste, i); // ajouter i à la fin de la liste
        afficheListe(liste); // Afficher la liste 
        i = i * 2; // On veut inesrer des multiples de deux
        do{
        printf("voulez-vous ajouter un nombre?\n0:oui\nN:non");
        scanf("%d->", &reponse);
        }while(reponse !='0' && reponse !='N');
    
    // On libére la mémoire 
        Chainon* tmp = liste;
        while (liste != NULL){
    
        tmp = liste->suivant; // Sauvegarder le prochain chainon
        free(liste); // Libérer la mémoire du chainon actuel
        liste = tmp; // Passer au chainon suivant
    }
    
    return 0;
}
