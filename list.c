#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Function that creates an empty level list with a given maximum number of levels
// Returns a new empty level list of type t_d_list
t_d_list* createEmptyLevelList(int max_levels){
    if(max_levels==0){
        return NULL;
    }
    t_d_list* List=(t_d_list*)malloc(sizeof(t_d_list));  // Allocate memory for a new level list
    List->nbLevels=max_levels;
    t_d_cell** newCells =(t_d_cell**)malloc(sizeof(t_d_cell*) * max_levels); //Allocate memory for an array of pointers for each level
    List->cellsHeads.next=newCells;
    for(int i=0; i<max_levels; i++){  // Initialize each level's pointer to NULL (empty list at each level)
        List->cellsHeads.next[i]=NULL;
    }
    return List;
}


t_d_list* insertHeadList(t_d_list* Lst,int val, int nbLevel) {
    t_d_cell *newCell = createCell(val, nbLevel);  // We allocate memory for our new head cell
    for (int i = 0; i < nbLevel; i++) {  //We start a loop to create all levels in our head cell
        t_d_cell **temp = &Lst->cellsHeads.next[i]; //We give them the same value
        newCell->cellsNext.next[i] = *temp;
        *temp = newCell;
    }
}

// Function to insert a new cell with a given value and number of levels in a sorted list
// Inserts the cell into the appropriate positions
// Returns the modified list (Lst)
t_d_list* insert_sorted_List(t_d_list* Lst, int value, int nb_levels){
    t_d_cell* newCell=createCell(value, nb_levels); //Create a new cell with the given value and number of levels

    for (int i=0; i < nb_levels; i++) {    //Iterate through each level of the list
        t_d_cell** temp=&Lst->cellsHeads.next[i];
        while (*temp != NULL && (*temp)->value < value) { //Go trough the list to find the good position to insert the new cell based on its value
            temp = &(*temp)->cellsNext.next[i];
        }
        newCell->cellsNext.next[i] =*temp;
        *temp=newCell;
    }
    return Lst;
}

// Function to display the contents of the given list
void displayList(t_d_list* Lst){

    for(int level=1; level<=Lst->nbLevels; level++){      //Go trough the list
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
    t_d_list *lst1 = createEmptyLevelList(n); //We create our level list
    double ind = pow(2,n) -1; //We prepare the index for our loops
    int intind = (int)(ind);
    int levels[20];
    for (int f = 0; f < intind; f++)
        levels[f] = 0; //We fill our list with zeroes so we can modify them later on
    for (int i = 1; i <= n; i+=2) //These loops helps us fill our level list
    { // The change in index makes sure we add the correct way (in indexes to the power 2)
        for (int j = i; j< intind; j+=2*i)
        {
            levels[j]++; //We increment the value at index j
        }
    }

    for (int k = 0; k < intind; k++){ //We add a loop to make sure every
        insertHeadList(lst1, abs(k-intind), levels[k]+1);
    }
    return lst1;
}
