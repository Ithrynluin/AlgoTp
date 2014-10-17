#include <iostream>
#include "listeCirculaire.h"
using namespace std;

int main(){
    maillon *m;
    int choix;
    int numero;

    initListeCirculaire(&m);

    do{
        do{
            cout << "LISTE CIRCULAIRE" << endl;
            cout << "1- Afficher la liste" << endl;
            cout << "2- Ajouter un element" << endl;
            cout << "3- Supprimer un element" << endl;
            cout << "4- Faire une rotation" << endl;
            cout << "5- Nombre de maillons" << endl;
            cout << "6- Quitter" << endl;
            cout << "Votre choix : ";
            cin >> choix;

        }while(choix > 6 || choix < 1);

        switch(choix){
            case 1:
                afficherListe(m);
                break;
            case 2:
                cout << "Entrer un numero : ";
                cin >> numero;
                insere(&m, numero);
                cout << "Ajout effectué" << endl;
                break;
            case 3:
                supprime(&m);
                cout << "Suppression effectué " << endl;
                break;
            case 4:
                rotation(&m);
                cout << "Rotation effectuée" << endl;
                break;
            case 5:
                cout << "La liste a " << nombreMaillons(m) << " maillons" << endl;
                break;
            case 6:
                cout << "Au revoir" << endl;
                break;
            default:
                cout << "Commande invalide !" << endl << endl;
        }
        cout << endl;
    }while(choix != 6);

    initListeCirculaire(&m);

    return 0;
}
