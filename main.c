#include "stdio.h"
#include "list.h"
#include "research.h"
#include "timer.h"
#include <stdlib.h>

int main() {
    // TEST of part 1
    t_d_list* myList = createEmptyLevelList(5);
    insertHeadList(myList,1,4);
    insert_sorted_List(myList, 3, 3);
    insert_sorted_List(myList, 6, 2);
    insert_sorted_List(myList, 9, 3);
    insert_sorted_List(myList, 7, 1);
    insert_sorted_List(myList, 15,1);
    displayList(myList);
    insert_sorted_List(myList,5,2);
    displayList(myList);
    //insertHeadList(myList,9,1);
    insert_sorted_List(myList,25,1);
    displayList(myList);


    startTimer();
    printf("%d\n",research_classic(myList,90));
    printf("%d\n", research_classic(myList,3));
    stopTimer();
    displayTime();

    // TEST of part 2
    t_d_list *list2= create_levels(3);
    displayList(list2);

    srand(41);

    FILE *log_file = fopen("log.txt", "w");
    char format[] = "%d\t%s\t%s\n";
    char *time_lvl0;
    char *time_all_levels;
    int level;

    //classical research
    
    for (int f = 0; f < 30; f++) {
        startTimer();
        for (int k = 0; k < 10000; k++) {
            int rdm = rand() % 15;
            printf("%d", research_classic(list2, rdm));

        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        fprintf(log_file, format, level, time_lvl0, time_all_levels);
    }
    time_all_levels = getTimeAsString();

     // highest level research

    for( int f = 0; f < 30; f ++) {
        startTimer();

        for (int k = 1; k < 10000; k++) {
            int rdm = rand() % 15;
            printf("%d", high_search(rdm, list2));
        }
        stopTimer();
        displayTime();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        printf("\n");
        fprintf(log_file, format, level, time_lvl0, time_all_levels);
    }

    time_all_levels = getTimeAsString();
    fclose(log_file);
    return 0;
}
