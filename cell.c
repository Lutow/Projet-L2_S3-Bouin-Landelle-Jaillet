#include "Cell.h"
#include <stdio.h>
#include <stdlib.h>

// Function that allows to create a cell with a given value (int) and a given number of levels (int)
// it returns a new cell of type t_d_cell
t_d_cell* createCell(int value, int nb_levels){
    t_d_cell* newCell=(t_d_cell*)malloc(sizeof(t_d_cell));               // allocate memory for a new cell
    newCell->value=value;         // assign the given value
    newCell->nbLevels=nb_levels;  // Set the number of levels
    t_d_cell **newCells=(t_d_cell**)malloc(sizeof(t_d_cell*)*nb_levels); // allocate memory for an array of pointers to cells for each level
    newCell->cellsNext.next=newCells;
    for(int i=0; i<nb_levels; i++){
        newCell->cellsNext.next[i]=NULL;
    }
    return newCell;
}
