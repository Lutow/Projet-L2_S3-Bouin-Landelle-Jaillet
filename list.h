#ifndef PROJET_S3_V2_LIST_H
#define PROJET_S3_V2_LIST_H
#include "cell.h"

typedef struct s_d_list{
    Cells cellsHeads;
    int nbLevels;
}t_d_list;

t_d_list* createEmptyLevelList(int max_levels);

t_d_list* insertHeadList(t_d_list* Lst,int value, int level);

t_d_list* insert_sorted_List(t_d_list* Lst, int value, int nb_levels);

void displayList(t_d_list* Lst);

t_d_list* create_levels(int n);

#endif
