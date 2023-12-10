//
// Created by Matthieu on 06/12/2023.
//

#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>

t_d_cell* createCell(int value, int nb_levels){
    t_d_cell* newCell=(t_d_cell*)malloc(sizeof(t_d_cell));
    newCell->value=value;
    newCell->nbLevels=nb_levels;
    t_d_cell **newCells=(t_d_cell**)malloc(sizeof(t_d_cell*)*nb_levels);
    newCell->cellsNext.next=newCells;
    for(int i=0; i<nb_levels; i++){
        newCell->cellsNext.next[i]=NULL;
    }
    return newCell;
}
