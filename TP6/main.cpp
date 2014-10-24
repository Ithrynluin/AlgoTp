#include <iostream>
#include "arbre.h"

using namespace std;


int main(){

    abin a, ag, ad, ag1, ad1;
    char *par;

    //Branche gauche
    arbnouv(ag);
    ag = enracine('t', NULL, NULL);
    arbnouv(ad);
    ad = enracine('s', ag, NULL);

    arbnouv(ag);
    ag = enracine('v', NULL, NULL);

    arbnouv(a);
    a = enracine('r', ag, ad);

    // brnche droite
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

    cout << "Construction de l'arbre terminé " << endl;

    par = parcoursSuffixe(a);
    cout << par << endl;

    par = parcoursInfixe(a);
    cout << par << endl;

    par = parcoursPrefixe(a);
    cout << par << endl;

    return 0;
}
