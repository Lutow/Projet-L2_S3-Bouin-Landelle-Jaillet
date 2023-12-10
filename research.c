#include "research.h"
#include "list.h"
#include "Cell.h"
#include <stdio.h>
#include <math.h>

int research_classic(t_d_list* myList, int value){
    t_d_cell **temp=myList->cellsHeads.next;
    while ((*temp) != NULL){
        if ((*temp)->value==value){
            return 1;
        }
        temp=(*temp)->cellsNext.next;
    }
    return 0;
}

int high_search(int val, t_d_list* lst){
    int n = lst->nbLevels-1;
    t_d_cell *temp = lst->cellsHeads.next[n];
    t_d_list *copy = create_levels(n+1);
    int nn = n;
    for(int i = 0; i < nn; i ++)
        if (val == temp->value)
        {
            return 1;
        }
    if (val < temp->value) {
        temp = copy->cellsHeads.next[n--];
    }
    if (val > temp->value) {
        copy->cellsHeads = temp->cellsNext;
        temp = copy->cellsHeads.next[n--];
    }
    return research_classic(copy, val);
}
