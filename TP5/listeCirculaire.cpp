#include <iostream>
using namespace std;

void afficherListe(maillon *p) {
        maillon *tmp;

        tmp=p;
        cout << "Maillon " << (*p).numero << endl;
        tmp=(*tmp).suivant;
        while (tmp != p) {
            cout << "Maillon " << (*tmp).numero << endl;
            tmp=(*tmp).suivant;
        }
}
