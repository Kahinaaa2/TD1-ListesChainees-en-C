Exercice 5 (Gestion des étudiants (extrait du devoir de 2021/2022)) On souhaite gérer les notes et les informations de
 l’ensemble des étudiants de CY–Tech.
 1. Un étudiant de deuxième année est défini par son nom, son prénom, son groupe et ses notes. Plus précisément, chaque
 étudiant reçoit toujours 10 (constante) notes. Pour plus de facilité, le groupe de l’étudiant sera défini par un entier
 correspondant au numéro de son groupe (exemple : groupe 1, groupe 6 etc...). Définir la structure Etudiant permettant
 de stocker ces informations.
 2. Comme on peut avoir des retards à l’inscription ou des étudiants qui partent en cours d’année, les étudiants vont être ran
gés dans une liste dynamique. Définir la ou les structures nécessaires pour construire la liste dynamique LstEtudiants
 des étudiants
 3. Écrire une fonction saisirEtudiant(LstEtudiants lst) qui permet de saisir les données d’un nouvel étudiant et de
 l’ajouter à la fin de la liste. Les notes seront aléatoires.
 4. Proposer une procédure listeParGroupe(LstEtudiants lst, int groupe) permettant d’afficher le nom de tous les
 étudiants du groupe passé en paramètre.
 5. Écrire une fonction moyTab( int *tab) qui prend en argument un tableau statique de taille N et qui renvoie la
 moyenne de ses éléments.
 6. Écrire une fonction trouveEtudiant( char *nom, char * prenom, LstEtudiants lst) qui recherche un étudiant
 par son nom et son prénom et renvoie un pointeur sur l’étudiant ou NULL s’il n’existe pas.
 7. Proposer un algorithme permettant de calculer la moyenne de l’élève dont le nom est «Spiruline Barnabus». Affichez
 un message d’erreur si aucun élève de ce nom n’existe.
 8. Calculer la moyenne de toute la promotion.
 9. Afficher le nom de l’Etudiant ayant la plus mauvaise moyenne de la promotion.


#define NB_NOTES 10
//1
typedef struct etudiant {
    char nom[50];
    char prenom[50];
    int groupe;
    float note[NB_NOTES];
} Etudiant;

typedef struct chainon {
    Etudiant etudiant;
    struct chainon *suivant;
} Chainon;

//2
Etudiant createEtudiant(const char *nom, const char *prenom, int groupe) {
    Etudiant newEtudiant;
    // Copie les valeurs des chaînes dans la structure
    strcpy(newEtudiant.nom, nom);
    strcpy(newEtudiant.prenom, prenom);
    newEtudiant.groupe = groupe;
    
    // Génère des notes aléatoires entre 0 et 20
    for(int i = 0; i < NB_NOTES; i++) {
        newEtudiant.note[i] = rand() % 21; // Notes aléatoires
    }

    return newEtudiant; // Retourne l'étudiant créé
}
//3
void saisirEtudiant(Chainon **lst) {
    // Création d'un nouveau chaînon
    Chainon *nouveau = malloc(sizeof(Chainon));
    if (nouveau == NULL) {
        exit(1); // Gérer l'échec de l'allocation mémoire
    }

    // Saisir les informations de l'étudiant
    const char *nom = "Hammad";  // Remplace par une saisie utilisateur si nécessaire
    const char *prenom = "Kahina"; // Remplace par une saisie utilisateur si nécessaire
    int groupe = 2; // Remplace par une saisie utilisateur si nécessaire
    nouveau->etudiant = createEtudiant(nom, prenom, groupe); // Création de l'étudiant
    nouveau->suivant = NULL; // Le chaînon suivant est NULL pour le moment

    // Ajout du nouvel étudiant à la liste
    if (*lst == NULL) {
        *lst = nouveau; // Si la liste est vide, le nouvel élément devient la tête
    } else {
        Chainon *tmp = *lst; // Pointeur temporaire pour parcourir la liste
        while (tmp->suivant != NULL) {
            tmp = tmp->suivant; // Avancer jusqu'au dernier chaînon
        }
        tmp->suivant = nouveau; // Ajouter le nouveau chaînon à la fin de la liste
    }
}

//4. Procédure pour afficher les étudiants d'un groupe

void ListeParGroupe(Chainon *lst, int groupe){
    Chainon *tmp =lst;
    if(tmp->etudiant.groupe == groupe){;
        printf("%s %s\n", tmp->etudiant.nom, tmp->etudiant.prenom);
    }
    tmp=tmp->suivant;
}

//5 fonction moyTab(int *tab)

float moyTab(int *tab){
    float somme = 0;
    float moyenne;
    for(int i=0;i<NB_NOTES;i++){
        somme = somme+tab[i];
    }
    moyenne=somme/ NB_NOTES;
    return moyenne;
}

//6 fonction trouveEtudiant( char *nom, char * prenom, LstEtudiants lst) qui recherche un étudiant
 par son nom et son prénom et renvoie un pointeur sur l’étudiant ou NULL s’il n’existe pas.
Chainon* trouveEtudiant(char* nom, char* prenom, Chainon* lst) {
    Chainon* tmp = lst;
    while (tmp != NULL) {
        if (strcmp(tmp->etudiant.nom, nom) == 0 && strcmp(tmp->etudiant.prenom, prenom) == 0) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

//7 
void moyenneEtudiant(Chainon* lst, char* nom, char* prenom) {
    Chainon* etudiant = trouveEtudiant(nom, prenom, lst);
    if (etudiant) {
        printf("Moyenne de %s %s: %f\n", nom, prenom, moyTab(etudiant->etudiant.notes));
    } else {
        printf("Erreur: aucun étudiant avec le nom %s %s trouvé.\n", nom, prenom);
    }
}

float moyennePromotion(Chainon* lst) {
    float somme = 0;
    int count = 0;
    Chainon* tmp = lst;
    while (tmp != NULL) {
        somme += moyTab(tmp->etudiant.notes);
        count++;
        tmp = tmp->next;
    }

    return count ? somme / count : 0;
}

void etudiantPireMoyenne(Chainon* lst) {
    if (lst == NULL) {
        printf("Pas d'étudiants dans la liste.\n");
        return;
    }

    Chainon* tmp = lst;
    Chainon* pire = lst;
    float pireMoyenne = moyTab(tmp->etudiant.notes);

    while (tmp != NULL) { //calcul classique de minimum
        float moyenneActuelle = moyTab(tmp->etudiant.notes);
        if (moyenneActuelle < pireMoyenne) {
            pire = tmp;
            pireMoyenne = moyenneActuelle;
        }
        tmp = tmp->next;
    }

int main() {
    srand(time(NULL));
    Chainon* etudiant_plist = NULL;
    int choix, groupe;
    char nom[50], prenom[50];

    do {
        printf("\nMenu:\n");
        printf("1. Saisir un nouvel étudiant\n");
        printf("2. Afficher les étudiants par groupe\n");
        printf("3. Calculer la moyenne d'un étudiant\n");
        printf("4. Calculer la moyenne de la promotion\n");
        printf("5. Afficher l'étudiant avec la plus mauvaise moyenne\n");
        printf("6. Quitter\n");
        printf("Votre choix: ");
        choix = better_scan("Votre choix: ");

        switch (choix) {
            case 1:
                saisirEtudiant(&etudiant_plist);
                break;
            case 2:
                groupe = better_scan("Entrez le numéro du groupe: ");
                listeParGroupe(etudiant_plist, groupe);
                break;
            case 3:
                printf("Entrez le nom de l'étudiant: ");
                if (fgets(nom, 50, stdin) == NULL){
                    exit(EXIT_FAILURE); 
                }
                nom[strlen(nom)-1] = '\0';
                printf("Entrez le prénom de l'étudiant: ");
                if (fgets(prenom, 50, stdin) == NULL){
                    exit(EXIT_FAILURE); 
                }
                prenom[strlen(prenom)-1] = '\0';
                moyenneEtudiant(etudiant_plist, nom, prenom);
                break;
            case 4:
                printf("Moyenne de la promotion: %f\n", moyennePromotion(etudiant_plist));
                break;
            case 5:
                etudiantPireMoyenne(etudiant_plist);
                break;
            case 6:
                printf("Salem !\n");
                break;
            default:
                printf("Choix invalide!\n");
                break;
        }
    } while (choix != 6);

    Chainon* actual = etudiant_plist; //On oublie pas de free la memoire
    while (etudiant_plist != NULL){
        actual = etudiant_plist->next;
        free(etudiant_plist);
        etudiant_plist = actual;
    }
    return 0;
}
