#include<stdio.h>
#include<stdlib.h>

#include "list_hw.h"


int test_sublist(list A) {
    printf("\n\n--------------------------------------\n");
    printf("Testing sublist (for lists of ints).\n\n");
    printf("original list A:");
    printListHorizPointer(A);

    int arr_pos[] = {3, 0, 6, 4};
    list pos_list = arrayToList(arr_pos, 4);
    printf("List with positions pos_list:");
    printListHoriz(pos_list);

    list res = sublist(A, pos_list);
    destroyList(pos_list);

    printf("SUBLIST:");
    printListHorizPointer(res);
    destroyList(res);

    printf("original list A:");
    printListHorizPointer(A);
    return 0;
}

int test_swapFirstThird(list A) {
    printf("\n\n--------------------------------------\n");
    printf("Test swapFirstThird (for lists of ints).\n\n");
    printf("LIST A:");
    printListHorizPointer(A);

    swapFirstThird(A);

    printf("After calling swapFirstThird(A) (currently not implemented).\n");
    printf("After you implement this function, list A (printed below).\n");
    printListHorizPointer(A);

    printf("\n----------  end test function -------------------\n");
    return 0;
}

int test_deleteOccurrences(list A) {
    printf("\n\n--------------------------------------\n");
    printf("Test deleteOccurrences (for lists of ints).\n\n");
    printf("LIST A:");
    //printListHoriz(A);
    printListHorizPointer(A);

    deleteOccurrences(A, 7);

    printf("After calling deleteOccurrences(A,7) (currently not implemented).\n");
    printf("After you implement this function, list A (printed below) should not have any values of 7.\n");
    //printListHoriz(A);
    printListHorizPointer(A);

    printf("\n----------  end test function -------------------\n");
    return 0;
}

int test_moveAllMaxAtEnd(list A) {
    printf("\n\n--------------------------------------\n");
    printf("Test moveAllMaxAtEnd (for lists of ints).\n\n");
    printf("LIST A:");
    //printListHoriz(A);
    printListHorizPointer(A);

    moveAllMaxAtEnd(A);

    printf("After calling moveAllMaxAtEnd (currently not implemented).\n");
    printf("After you implement this function, list A (printed below) should have the largest value(s) at the end.\n");
    //printListHoriz(A);
    printListHorizPointer(A);

    printf("\n----------  end test function -------------------\n");
    return 0;
}

int main() {

    run_student_tests();

    list A = NULL;
    int arr[] = {15, 100, 7, 5, 100, 7, 30};
    A = arrayToList(arr, 7);
    //A = buildListOfInts() ;  // use this line and redirect input to run test cases from data files. See posted example data file.
    printf("LIST A:");
    printListHorizPointer(A);

    test_sublist(A);
    test_deleteOccurrences(A);
    test_moveAllMaxAtEnd(A);
    test_swapFirstThird(A);

    destroyList(A);

    return 0;
}
