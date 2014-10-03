#include <iostream>
#include <stdio.h>
#include "fileAttente.h"

using namespace std;

int main(){
    FileAttente file;
    int choix;
    int num;
    char * nom;

    initFileAttente(&file);

    do{
        do{
            cout << "FILE D'ATTENTE" << endl;
            cout << "1- Ajouter une personne en queue" << endl;
            cout << "2- Retirer la personne en tête" << endl;
            cout << "3- Consulter la personne en tête de file" << endl;
            cout << "4- Calculer la longueur de la fime d'attente" << endl;
            cout << "5- Quitter" << endl;

            cin >> choix;

        }while(choix > 5 || choix < 1);

        switch(choix){
            case 1:
                cout << "Entrer le numero de la personne : ";
                cin >> num;
                cout << "Entrer le nom de la personne : ";
                scanf("%s", nom);
                ajoutPers(&file, num, nom);
                cout << "Ajout effectué. " << endl << endl;
                break;
            case 2:
                retireTete(&file);
                cout << "Suppresion effectuée" << endl << endl;
                break;
            case 3:
                consulterTete(file);
                cout << endl;
                break;
            case 4:
                cout << "La longueur de la liste est de " << longueurFile(file) << endl << endl;
                break;
            default:
                cout << "Commande invalide" << endl << endl;
        }

    }while(choix != 5);

    cout << "Au revoir" << endl;

    return 0;
}
