#include<stdio.h>
#include<stdlib.h>

typedef struct chainon{
    int valeur;
    struct chainon *suivant;
}Chainon;

Chainon *createChainon(int v){
    Chainon *new = malloc(sizeof(Chainon));
        if(new == NULL){
            exit(1); //erreur allocation
        }
        new ->valeur = v;
        new ->suivant = NULL;
        return new;
}

Chainon *ajout_Debut(Chainon *tete, int val){
    if(tete == NULL){
        tete = createChainon(val);
    }
    else{
        Chainon *new = createChainon(val);
        if(new==NULL){
            exit(3); //toujours vérifier meme si deja vérifier dans la fonction precedente 
        }
        new->suivant=tete;
        tete=new; //mise a jour de la tete
    }
     return tete;
}

Chainon *ajout_Fin(Chainon *tete, int val){
    if(tete == NULL){
        tete = createChainon(val);
    }
    else{
        Chainon *new=createChainon(val);
        if(new == NULL){
            exit(4);
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
        printf("La liste est vide.\n");
    }
    else{
        while(liste->suivant != NULL){
            printf("%d->", liste->valeur);
            liste = liste->suivant;
        }        
    }
    printf("\n");
}

Chainon *inverserChaine(Chainon *tete){
    Chainon *newliste = NULL; //liste intermediaire initialement vide
    Chainon *tmp =tete;
    while(tmp != NULL){
        newliste = ajout_Debut(newliste, tmp->valeur);
        tmp = tmp->suivant;
    }
    return newliste;
}

int main(){
    srand(time(NULL));
    Chainon *liste = NULL;
    
    for(int i=0; i<10; i++){
        liste = ajout_Fin(liste, rand()%6);//aléatoire entre 0 et 5
    }
    afficherListe(liste);

    Chainon *liste2 = inverser(liste);
    afficherListe(liste2);

    //important de libérer la memoire apreès l'allocation ;)

    Chainon *tmp =liste;
    while(liste != NULL){
        tmp=liste->suivant;
        free(liste);
        liste = tmp;
    }

    tmp=liste2;
    while(liste2 != NULL){
        tmp = liste2->suivant;
        free(liste2);
        liste2=tmp;
    }
    return 0;
}
