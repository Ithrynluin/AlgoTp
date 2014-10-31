#include <iostream>
#include "arbre.h"
#include "liste.h"

using namespace std;


int main(){

    abin a, ag, ad, ag1, ad1;
    Liste listeEtiquette;
    abin *file = new abin[2];

    //Branche gauche
    arbnouv(ag);
    ag = enracine('t', NULL, NULL);
    arbnouv(ad);
    ad = enracine('s', ag, NULL);

    arbnouv(ag);
    ag = enracine('v', NULL, NULL);

    arbnouv(a);
    a = enracine('r', ag, ad);

    // Branche droite
    arbnouv(ag);
    ag = enracine('q', NULL, NULL);
    arbnouv(ad);
    ad = enracine('b', NULL, NULL);

    arbnouv(ag1);
    ag1 = enracine('u', NULL, NULL);
    arbnouv(ad1);
    ad1 = enracine('p', ag, ad);

    arbnouv(ad);
    ad = enracine('t', ag1, ad1);
    ag = a;

    arbnouv(a);
    a = enracine('a', ag, ad);

    cout << "Construction de l'arbre terminé " << endl << endl;

    //Utilisation des fonctions et des procédures

    cout << "La hauteur de l'arbre créé est de : " << hauteur(a) << endl << endl;

    cout << "Utilisation de la fonction parcoursSuffixe : " << endl;
    listeEtiquette = parcoursSuffixe(a);
    afficherListe(listeEtiquette);
    desinitListe(&listeEtiquette);
    cout << endl;

    cout << "Utilisation de la fonction parcoursInfixe : " << endl;
    listeEtiquette = parcoursInfixe(a);
    afficherListe(listeEtiquette);
    desinitListe(&listeEtiquette);
    cout << endl;

    cout << "Utilisation de la fonction parcoursPrefixe : " << endl;
    listeEtiquette = parcoursPrefixe(a);
    afficherListe(listeEtiquette);
    desinitListe(&listeEtiquette);
    cout << endl;

    cout << "Utilisation de la fonction parcoursLargeur : " << endl;
    file[0] = a;
    file[1] = NULL;
    listeEtiquette = parcoursLargeur(file);
    afficherListe(listeEtiquette);
    desinitListe(&listeEtiquette);
    cout << endl;

    cout << "Utilisation de la fonction \'gauche(a)\' : " << endl;
    cout << charEtiquette(gauche(a)) << endl << endl;

    cout << "Utilisation de la fonction \'droite(a)\' : " << endl;
    cout << charEtiquette(droite(a)) << endl << endl;

    arbdetruit(a);

    if (estVide(a) == NULL) {
        cout << "L'arbre a été détruit." << endl;
    } else {
        cout << "L'arbre n'a pas été détruit." << endl;
    }

    return 0;
}
