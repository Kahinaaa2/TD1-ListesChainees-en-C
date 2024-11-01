 Exercice 3 (Suppression de Chaînon)
 1. Définir une liste chaînée d’entiers composée de 10 Chainons dont les valeurs seront aléatoires entre 0 et 5 compris.
 2. Écrire des fonctions prenant en paramètre un pointeur sur liste et un entier qui permettent de supprimer dans une
 liste :
 — Lepremier Chainon dont la valeur est égale au paramètre.
 — Tous les Chainon dont la valeur est égale au paramètre.
 3. Tester ces fonctions avec la liste de la question 1

  #include<stdio.h>
  #include<stdlib.h>
   
   typedef struct chainon{
      int valeur;
      struct chainon *suivant;
   }Chainon;

   Chainon *createChainon(int v){
       Chainon *new = malloc(sizeof(Chainon));
           if(new == NULL){
               exit(1);
           }
       new->valeur = v;
       new->suivant = NULL;
       return new;
   }

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

Chainon *supprimerPremier(Chainon *tete, int a) {
    if (tete == NULL) { // si la tete et nulle
        return tete; // La liste est vide
    }
    
    // Cas où l'élément à supprimer est le premier de la liste
    if (tete->valeur == a) {
        Chainon *suppr = tete; // Stocke l'élément à supprimer
        tete = tete->suivant; // Le suivant devient le premier
        free(suppr); // Libère la mémoire
        return tete; // Retourne la nouvelle tête
    }
    
    // Cas général : l'élément est ailleurs dans la liste
    Chainon *tmp = tete;
    Chainon *suppr = NULL;
    
    // Parcours de la liste pour trouver l'élément
    while (tmp->suivant != NULL) {
        if (tmp->suivant->valeur == a) { // Si le suivant a la valeur à supprimer
            suppr = tmp->suivant; // Stocke le chainon à supprimer
            tmp->suivant = tmp->suivant->suivant; // Saute le chainon supprimé
            free(suppr); // Libère la mémoire de l'élément supprimé
            break; // Arrête la boucle après la suppression du premier élément trouvé
        }
        tmp = tmp->suivant; // Passe à l'élément suivant
    }
    
    return tete; // Retourne la tête de la liste
}

Chainon *supprimerTous(Chainon *tete, int a) {
    // Suppression des éléments en tête s'ils contiennent la valeur 'a'
    while (tete != NULL && tete->valeur == a) {
        Chainon *suppr = tete; // Stocke le chainon à supprimer
        tete = tete->suivant; // Avance la tête au suivant
        free(suppr); // Libère la mémoire de l'élément supprimé
    }// pas besoin de retourner la tete dans ce ca, on veut juste supp toutes le valeurs de la chaine egale a 'a'

    // Cas où la liste est désormais vide après suppression des premiers éléments
    if (tete == NULL) {
        return NULL;
    }

    // Parcours de la liste pour les autres éléments
    Chainon *tmp = tete;
    while (tmp->suivant != NULL) {
        if (tmp->suivant->valeur == a) {
            Chainon *suppr = tmp->suivant; // Stocke le chainon à supprimer
            tmp->suivant = tmp->suivant->suivant; // Saute le chainon
            free(suppr); // Libère la mémoire
        } else {
            tmp = tmp->suivant; // Avance au chainon suivant seulement si pas de suppression
        }
    }

    return tete;
}

int main(){
  srand(time(NULL));
  Chainon *liste = NULL; 
  for(int i=0; i<10; i++){
      liste = insertFin(liste, rand()%6);
  }

afficheListe(liste);
    
   
    liste = SupprimerPremier(liste, 2);
    afficheListe(liste); 

    liste = SupprimerTout(liste, 5);
    afficheListe(liste); 

    Chainon* tmp = liste;
    while (liste != NULL){
        tmp = liste->suivant;
        free(liste);
        liste = tmp;
    }
    
    return 0;
}
