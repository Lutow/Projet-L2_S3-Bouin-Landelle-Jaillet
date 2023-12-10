#ifndef PROJET_S3_V2_CELL_H
#define PROJET_S3_V2_CELL_H

// Structure to create the link between a cell and the following one
typedef struct Cells{
    struct t_d_cell **next;
}Cells;

// Structure of a cell
typedef struct s_d_cell{
    int nbLevels;
    int value;
    struct Cells cellsNext;
}t_d_cell;

t_d_cell* createCell(int value, int nb_levels);

#endif
