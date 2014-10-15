#include <iostream>

using namespace std;

int main(){



    do{
        do{
            cout << "FILE D'ATTENTE" << endl;
            cout << "1- Ajouter une personne en queue" << endl;
            cout << "2- Retirer la personne en tête" << endl;
            cout << "3- Consulter la personne en tête de file" << endl;
            cout << "4- Calculer la longueur de la fime d'attente" << endl;
            cout << "5- Undo" << endl;
            cout << "6- Quitter" << endl;
            cout << "Votre choix : ";
            cin >> choix;

        }while(choix > 6 || choix < 1);

        switch(choix){
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                break;
            case 5:

                break;
            case 6:
                cout << "Au revoir" << endl;
                break;
            default:
                cout << "Commande invalide !" << endl << endl;
        }
        cout << endl;
    }while(choix != 6);
    return 0;
}
