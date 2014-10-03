#ifndef FILEATTENTE_H_INCLUDED
#define FILEATTENTE_H_INCLUDED

typedef struct pers {
    int numero;
    char * nom;
    struct pers * suivant;
} maillon;

typedef struct {
    maillon * tete;
    maillon * queu;
} FileAttente;

void initFileAttente(FileAttente * file);
void desinitFileAttente(FileAttente *file);
void retireTete(FileAttente * file);
void ajoutPers (FileAttente * f, const int num, char * nom);
void consulterTete (FileAttente file);
int longueurFile(const FileAttente file);
#endif // FILEATTENTE_H_INCLUDED
