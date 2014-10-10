//main.cpp
//Programme principal
#include <iostream>
#include <stdio.h>
#include "fileAttente.h"

using namespace std;

int main(){
    FileAttente file;
    int choix;
    int num;
    char nom[30];
    maillon *tmp;

    initFileAttente(file);

    do{
        do{
            cout << "FILE D'ATTENTE" << endl;
            cout << "1- Ajouter une personne en queue" << endl;
            cout << "2- Retirer la personne en tête" << endl;
            cout << "3- Consulter la personne en tête de file" << endl;
            cout << "4- Calculer la longueur de la fime d'attente" << endl;
            cout << "5- Quitter" << endl;
            cout << "Votre choix : ";
            cin >> choix;

        }while(choix > 5 || choix < 1);

        switch(choix){
            case 1:
                cout << "Entrer le numero de la personne : ";
                cin >> num;
                cout << "Entrer le nom de la personne : ";
                scanf("%s", nom);
                ajoutPers(file, num, nom);
                cout << "Ajout de la personne numero " << num << " du nom de " << nom << " effectué. " << endl << endl;
                break;
            case 2:
                if(file.tete != NULL){
                    retireTete(file);
                    cout << "Suppresion effectuée" << endl << endl;
                }else{
                    cout << "La file est vide" << endl << endl;
                }
                break;
            case 3:
                tmp = consulterTete(file);
                if(tmp != NULL){
                    cout << "La tete de file est : " << (*tmp).nom << " qui possede le numero " << (*tmp).numero << endl;
                }else{
                    cout << "La file est vide" << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << "La longueur de la liste est de " << longueurFile(file) << endl << endl;
                break;
            case 5:
                cout << "Au revoir" << endl;
                break;
            default:
                cout << "Commande invalide !" << endl << endl;
        }
        cout << endl;
    }while(choix != 5);



    desinitFileAttente(file);

    return 0;
}
