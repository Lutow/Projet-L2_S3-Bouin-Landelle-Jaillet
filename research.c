#include "research.h"
#include "list.h"
#include "Cell.h"
#include <stdio.h>
#include <math.h>

//Classic research researches a value within the first level of a list one element by element
int research_classic(t_d_list* myList, int value) {
    t_d_cell **temp=myList->cellsHeads.next; //We create the cursor that will check every value one by one
    while ((*temp) != NULL){ //This loop will keep the search going until we get to the end of the list
        if ((*temp)->value==value){
            return 1; //If we find the value we return 1
        }
        temp=(*temp)->cellsNext.next; //We get to the next element
    }
    return 0; //If we did not find the element during the loop then it isnt there and we return 1
}

//High search researches a value within level lists through dichotomy search
int high_search(int val, t_d_list* lst) {
    int n = lst->nbLevels - 1; //We create an index based on the number of levels so we can travel the list
    t_d_cell *temp = lst->cellsHeads.next[n]; //We get our first value
    t_d_list *copy = create_levels(n + 1); //We create a copy of our level list
    int nn = n; //We create a copy of our index for for loop purpose
    for (int i = 0; i < nn; i++) //This loop will loop n times at most
        if (val == temp->value) {
            return 1; //If we get the value we return 1
        }
    if (val < temp->value) {  //If the value we search for is smaller than the one we are checking currently
        temp = copy->cellsHeads.next[n--]; //We check the value before in terms of height
    }
    if (val > temp->value) { // Same for if the value is bigger
        copy->cellsHeads = temp->cellsNext; //If it is, we cut the left half of our list to focus on the next one
        temp = copy->cellsHeads.next[n--];
    }
    return research_classic(copy,
                            val); //If we still did not find the value on the list, we check the remaining elements in the list with research classic
}
