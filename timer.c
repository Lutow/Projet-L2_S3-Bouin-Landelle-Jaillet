#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

t_d_list* createEmptyLevelList(int max_levels){
    if(max_levels==0){
        return NULL;
    }
    t_d_list* List=(t_d_list*)malloc(sizeof(t_d_list));
    List->nbLevels=max_levels;
    t_d_cell** newCells =(t_d_cell**)malloc(sizeof(t_d_cell*) * max_levels);
    List->cellsHeads.next=newCells;
    for(int i=0; i<max_levels; i++){
        List->cellsHeads.next[i]=NULL;
    }
    return List;
}


t_d_list* insertHeadList(t_d_list* Lst,int val, int level) {
    t_d_cell *newCell = createCell(val, level);
    for (int i = 0; i < level; i++) {
        t_d_cell **temp = &Lst->cellsHeads.next[i];
        newCell->cellsNext.next[i] = *temp;
        *temp = newCell;
    }
}


t_d_list* insert_sorted_List(t_d_list* Lst, int value, int nb_levels){
    t_d_cell* newCell=createCell(value, nb_levels);
    for (int i=0; i < nb_levels; i++) {
        t_d_cell** temp=&Lst->cellsHeads.next[i];
        while (*temp != NULL && (*temp)->value < value) {
            temp = &(*temp)->cellsNext.next[i];
        }
        newCell->cellsNext.next[i] =*temp;
        *temp=newCell;
    }

    return Lst;
}


void displayList(t_d_list* Lst){
    for(int level=1; level<=Lst->nbLevels; level++){
        t_d_cell *temp=Lst->cellsHeads.next[0];
        printf("[list head_%d @-]--", level-1);
        while (temp!=NULL) {
            if(temp->nbLevels>= level){
                printf(">[ %d|@-]--", temp->value);
            }
            else{
                printf("----------");
            }
            temp=temp->cellsNext.next[0];
        }
        printf(">NULL\n");
    }
    printf("\n");
}

t_d_list* create_levels(int n)
{
    t_d_list *lst1 = createEmptyLevelList(n);
    double ind = pow(2,n) -1;
    int intind = (int)(ind);
    int levels[intind];
    for (int f = 0; f < intind; f++)
        levels[f] = 0;
    for (int i = 1; i <= n; i+=2)
    {
        for (int j = i; j< intind; j+=2*i)
        {
            levels[j]++;
        }
    }

    for (int k = 0; k < intind; k++){
        insertHeadList(lst1, abs(k-intind), levels[k]+1);
    }
    return lst1;
}
