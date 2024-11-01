      #include<stdio.h>
      #include<stdlib.h>
      
      //declarer la structure du chainon   
         typedef struct chainon{
            int valeur;
            struct chainon *suivant;
         }Chainon;
      //creation chainon
         Chainon *createChainon(int v){
             Chainon *new = malloc(sizeof(Chainon));
                 if(new == NULL){
                     exit(1);
                 }
             new->valeur = v;
             new->suivant = NULL;
             return new;
         }
      //ajouter chainon au debut
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
      
      //ajouter chainon a la fin
      
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
      
      //afficher une liste chainnée
      
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

                                                              // trier la liste par ordre croissant
                                                              13->32->3->92->12->8
                                                              3->8->12->13->32->92

      Chainon *insertTrie(Chainon *tete, int a){
          if(tete == NULL || a<= tete->valeur){
            // Insère au début si la liste est vide ou si 'a' est plus petit que la première valeur
              return insertDebut(tete, a);
          }
        
          Chainon *tmp = tete;
        
          // Parcourt la liste jusqu'à trouver le bon emplacement pour insérer 'a'
          while(tmp->suivant != NULL && tmp->suivant->valeur < a){
              tmp = tmp->suivant; // Avance dans la liste
          }
              Chainon *new = createChainon(a);
              new->suivant = tmp->suivant;// Connecte le nouveau chainon au suivant de 'tmp'
              tmp->suivant =new;// Connecte 'tmp' au nouveau chainon
              return tete;
      }
