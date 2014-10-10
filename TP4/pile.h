#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include "fileAttente.h"

type struct e{
    FileAttente *file;
    struct e *suivant;
} element;

type struct {
    element *tete;
}Pile;

#endif // PILE_H_INCLUDED
