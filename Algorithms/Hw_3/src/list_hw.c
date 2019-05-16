/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "list_hw.h"

struct node_struct {
    Item item;
    link next;
};

struct list_struct {
    link first;
    int length;
};


/* Builds and returns a list with integers read from standard input.
 * Note that it assumes the Item is int.
 * Notice that all the list access is done through it's interface (functions).
 */
list buildListOfInts() {
   list the_list = newList();

   link current_link = NULL;
   while(1)
   {
      Item number;
      printf("please enter an integer: ");
      int items_read = scanf("%d", &number);
      if (items_read != 1)
      {
         break;
      }

      /* allocate memory for the next link */
      link next_item = newLink(number, NULL);
      insertLink(the_list, current_link, next_item);
      current_link = next_item;
   }
   return the_list;
}


list arrayToList(int arr[], int sz)  {
	int i;
	link p, new_p;
	list A = newList();

	p = newLink(arr[0], NULL);
	insertLink(A, NULL, p);

	for (i = 1; i < sz; i++)
	{
		new_p = newLink(arr[i], NULL);
		insertLink(A, p, new_p);
		p = new_p;
	}

	return A;
}




// ------------- link functions

/* Creates a new link, that contains the value specified in the argument,
 * and that points to next_in.
 */
link newLink(Item value, link next_in) {
    link result = (link) malloc(sizeof (struct node_struct));
    result->item = value;
    result->next = next_in;
    return result;
}

void destroyLink(link the_link) {
    if (the_link != NULL) {
        free(the_link);
    }
}

Item getLinkItem(link the_link) {
    if (the_link != NULL) {
        return the_link->item;
    } else {
        printf("\n getLinkItem: Empty link. Returned -1.");
        return -1; // NOTE: This line can be improved.
    }
}

link getLinkNext(link the_link) {
    if (the_link != NULL) {
        return the_link->next;
    } else {
        return NULL;
    }
}

void setLinkItem(link the_link, Item value) {
    if (the_link != NULL) {
        the_link->item = value;
    }
}

void setLinkNext(link the_link, link next) {
    if (the_link != NULL) {
        the_link->next = next;
    }
}

/*    --------  LIST functions    */

int listIsNULL(list the_list) {
    if (the_list == NULL) {
        printf("\nThe list pointer is NULL)\n");
        return 1;
    }
    else {
        return 0;
    }
}

/* Creates and returns an empty list. */
list newList() {
    list result = (list) malloc(sizeof (*result));
    result->first = NULL;
    result->length = 0;
    return result;
}

/* Deallocates memory for all nodes in the list and the list object itself. */
void destroyList(list the_list) {
    if (listIsNULL(the_list) == 1) {
        return;
    }
    link current = the_list->first;
    while(the_list->length!=0)
    {
            if(current==NULL)
            break;
        link killer = current;

        current = current->next;
        free(killer);
        the_list->length = the_list->length-1;
    }
    free(the_list);
}

link getFirst(list the_list) {
    if (listIsNULL(the_list) == 1) {
        return NULL;
    }

    return the_list->first;
}

int getLength(list the_list) {
    if (listIsNULL(the_list) == 1) {
        return -1;
    }

    return the_list->length;
}

/* Sets the data to empty (first is null, length is 0,...)
 * It does NOT free any memory.
 */
void setEmpty(list the_list) {
    the_list->first = NULL;
    the_list->length = 0;
}

/* Inserts new_link to the specified list, at the position right after
 * the link called "previous". */
void insertLink(list my_list, link previous, link new_link) {
    if (listIsNULL(my_list) == 1) {
        return;
    }

    /* We need a special case when we want to insert to the beginning.
     * In that case, the previous link is NULL. */
    if (previous == NULL) {
        new_link->next = my_list->first;
        my_list->first = new_link;
    } else {
        new_link->next = previous->next;
        previous->next = new_link;
    }

    my_list->length += 1;
}

/* Inserts new_link to the beginning of the list. */
void insertAtBeginning(list my_list, link new_link) {
    setLinkNext(new_link, getFirst(my_list)); // replaces: new_link->next = my_list->first;
    my_list->first = new_link;
    my_list->length += 1;
}

/* Removes from the list and returns the link coming AFTER link x.
 * This function DOES NOT remove link x itself.
 */
link removeNext(list my_list, link x) {
    if (listIsNULL(my_list) == 1) {
        return NULL;
    }

    link temp;
    if (x == NULL) // try to delete the first node
    {
        temp = my_list->first;
        if (my_list->first != NULL) // There is at least one node in the list.
        {
            my_list->first = my_list->first->next;
            my_list->length -= 1;
        }
    } else {
        temp = x->next;
        x->next = x->next->next; // IS THIS CODE SAFE? JUSTIFY YOUR ANSWER.
        my_list->length -= 1;
    }
    return temp;
}

/* Removes from the list and returns the link at the beginning of the list.
It does not free the memory for that node. */
link removeFirst(list my_list) {
    if (listIsNULL(my_list) == 1) {
        return NULL;
    }

    link first_node = my_list->first;
    if (first_node != NULL) {
        my_list->first = first_node->next;
        my_list->length -= 1;
    }
    return first_node;
}

void printList(list my_list) {
    if (listIsNULL(my_list) == 1) {
        return;
    }


    int i = 0;
    int n = my_list->length;
    link curr;
    printf("\n List length = %d\n List items:\n", my_list->length);
    for (i = 0, curr = my_list->first; (curr != NULL) && (i < n); curr = curr->next) {
        printf("item %d: %d\n", i, curr->item);
        i++;
    }
    printf("\n");
}

void printListHoriz(list my_list) {
    if (listIsNULL(my_list) == 1) {
        return;
    }


    int i = 0;
    int n = my_list->length;
    link curr;
    printf("\n List length = %d\n List items:\n", my_list->length);
    for (i = 0, curr = my_list->first; (curr != NULL) && (i < n); curr = curr->next) {
        printf("%5d    ", curr->item);
        i++;
    }
    printf("\n");
}

void printListHorizPointer(list my_list) {
    if (listIsNULL(my_list) == 1) {
        return;
    }


    int i = 0;
    int n = my_list->length;
    link curr;
    printf("\n List length = %d\nList items:    ", my_list->length);
    for (i = 0, curr = my_list->first; (curr != NULL) && (i < n); curr = curr->next) {
        printf("%-11d  ", curr->item);
        i++;
    }
    printf("\n");
    printf("List pointers: ");
    for (i = 0, curr = my_list->first; (curr != NULL) && (i < n); curr = curr->next) {
        printf("%p ", curr);
        i++;
    }
    printf("\n");
}

int computeLength(list my_list) {
    if (listIsNULL(my_list) == 1) {
        return -1;
    }

    int counter = 0;
    link i;
    for (i = my_list->first; i != NULL; i = i->next) {
        counter++;
    }
    return counter;
}

/*----------------------------------------------------------------
 New functions.
 Finish their implementation below.
 If you need to use helper functions you can define them and use them in this file.
 ***You should not change the behavior of any of the functions defined above.
 Instead, write a new function with the behavior that you want.***
 */

void deleteOccurrences(list A, Item V) {
    link current = A->first;
    link previous = A->first;
    while(current!=NULL)
    {
        if(current->item == V)
        {
            if(current == previous)
            {
                A->first = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            A->length = (A->length) - 1;
        }
        previous = current;
        current = previous->next;
    }
    return;
}
//---------------------------------------------------------------------------------------------------------------------------LIST SUBLIST
list sublist(list A, list pos_list) {
    list sublisting = newList();
    link new_link;
    link start;

    link current = A->first; //link current is the first A link;
    link find = pos_list->first; //link find is the first post_list link;
    int loop;
    int count = 0;
    int first = 0;

    if(A->first == NULL || pos_list->first == NULL)
    {
        return NULL;
    }

    while(find!=NULL) //loop till out of things to find
    {
        loop = find->item; //How many times I should loop to get to item
        count = 0;
        if(A->length < loop)
        {
        return NULL;
        }
        while(count <= loop-1)
        {
            current = current->next;
            count++;
        }
        if (first == 0)
        {
            start = newLink(current->item, NULL);
            insertLink(sublisting, NULL, start);
            first = 1;
        }
        else
        {
            new_link = newLink(current->item, NULL);
            insertLink(sublisting, start, new_link);
            start = new_link;
        }
        current = A->first;
        find = find->next; //Go to next item to find
    }



    return sublisting;
}

void moveAllMaxAtEnd(list A) {
    link current = A->first;
    link previous = A->first;
    link last = A->first;
    link temp = A->first;
    int max = 0;
    int compare;
    int loop; //count how many max numbers there are
    //Step 1: Find the max

   /* if(A->first == NULL) //Make sure list is not empty
    {
        return;
    }*/
    while(current->next != NULL)
    {
        compare = current->item;
        if (max < compare)
        {
            max = current->item;
        }
        current = current->next;
    }

    current = A->first;


    while(current->next != NULL)
    {
        compare = current->item;
        if (max == compare)
        {
            loop++;
        }
        current = current->next;
    }

    current = A->first;


    //swap high values to end
    //find swap location
while(loop > 0)
{
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;
        compare = current->item;
        if(max == compare)
        {
                //Get the last node and make it point at the current.
                //make current point to null
                while(last->next != NULL)
                {
                    last = last->next;
                }
                temp = current;
                last->next = temp;
                previous->next = current->next;
                temp->next = NULL;
                last = A->first;
        }
        //current = current->next;
    }
    current = A->first;
    loop--;
}

    return;
}


// swaps the first and the third nodes
void swapFirstThird(list A) {

    if(A->length==0 || A->length == 1)
    {
        return;
    }

    if(A->length==2)
    {
        link first = A->first;
        link second = A->first->next;
        link swap = second;
        A->first = second;
        second->next = first->next;
        A->first->next = first;
        first->next = swap->next; //NULL
        return;
    }

    link first = A->first;
    link third = A->first->next->next;
    link swap = third;

    A->first = third; //A points to third node first.
    third->next = first->next; //Corrects where the new first node points next.
    A->first->next->next = first; //Makes address of 3rd node the old first one.
    first->next = swap->next;



    return;
}

// Set-up and call your testing functions from this function.

int run_student_tests() {

    printf("\n Running function run_student_test.\n ");
    printf("\n\n--------------------------------------\n");

//Test Sublist Index out of bounds:------------------------------------------------------------------------------------------------------------


    printf("Testing sublist A (for index out of bounds).\n\n");

    list A = NULL;
    int arr[] = {10, 10, 40, 20};
    A = arrayToList(arr, 4);
    printf("LIST A:");
    printListHorizPointer(A);

    int arr_pos[] = {3, 80000, 3};
    list pos_list = arrayToList(arr_pos, 3);
    printf("List with positions pos_list:");
    printListHoriz(pos_list);

    list res = sublist(A, pos_list);
    destroyList(pos_list);

    printf("SUBLIST:");
    printListHorizPointer(res);
    destroyList(res);

    printf("original list A:");
    printListHorizPointer(A);
    destroyList(A);

//Test Sublist B is NULL:------------------------------------------------------------------------------------------------------------

   /* printf("\n\n--------------------------------------\n");
    printf("Testing sublist (for B is NULL).\n\n");

    list B = NULL;
    printf("LIST B:");
    printf("original list B:");
    printListHorizPointer(B);

    int arr_posB[] = {3, 0, 6};
    list pos_listB = arrayToList(arr_posB, 3);
    printf("List with positions pos_listB:");
    printListHoriz(pos_listB);

    list resB = sublist(B, pos_listB);
    destroyList(pos_listB);

    printf("SUBLIST:");
    printListHorizPointer(resB);
    destroyList(resB);

    printf("original list B:");
    printListHorizPointer(B);
    destroyList(B); */

//Test Sublist C is empty:------------------------------------------------------------------------------------------------------------

   /* printf("\n\n--------------------------------------\n");
    printf("Testing sublist (for C is empty).\n\n");

    list C = NULL;
    int arrC[] = {};
    C = arrayToList(arrC, 0);
    printf("LIST C:");
    printListHorizPointer(C);

    int arr_posC[] = {0, 1};
    list pos_listC = arrayToList(arr_posC, 2);
    printf("List with positions pos_listC:");
    printListHoriz(pos_listC);

    list resC = sublist(C, pos_listC);
    destroyList(pos_listC);

    printf("SUBLIST:");
    printListHorizPointer(resC);
    destroyList(resC);

    printf("original list C:");
    printListHorizPointer(C);
    destroyList(C); */


//Test Sublist D pos_list is empty:------------------------------------------------------------------------------------------------------------

    printf("\n\n--------------------------------------\n");
    printf("Testing sublist (for pos_list D is empty).\n\n");

    list D = NULL;
    int arrD[] = {10, 10, 40, 20};
    D = arrayToList(arrD, 4);
    printf("LIST D:");
    printListHorizPointer(D);

    int arr_posD[] = {};
    list pos_listD = arrayToList(arr_posD, 0);
    printf("List with positions pos_listD:");
    printListHoriz(pos_listD);

    list resD = sublist(D, pos_listD);
    destroyList(pos_listD);

    printf("SUBLIST:");
    printListHorizPointer(resD);
    destroyList(resD);

    printf("original list D:");
    printListHorizPointer(D);
    destroyList(D);

//Test Sublist E pos list is null:------------------------------------------------------------------------------------------------------------

    printf("\n\n--------------------------------------\n");
    printf("Testing sublist (for E is pos_list is null).\n\n");

    list E = NULL;
    int arrE[] = {10, 10, 40, 20};
    E = arrayToList(arrE, 4);
    printf("LIST E:");
    printf("original list E:");
    printListHorizPointer(E);

    //int arr_posE[] = {0, 1, 2, 3};
    list pos_listE = NULL;
    printf("List with positions pos_listE:");
    printListHoriz(pos_listE);

    //list resE = sublist(E, pos_listE);
    destroyList(pos_listE);

    printf("SUBLIST:");
    //printListHorizPointer(resE);
    //destroyList(resE);

    printf("original list E:");
    printListHorizPointer(E);
    destroyList(E);



    printf("\n\n-------end student test function------\n\n");



//Test Sublist F, F is not modified by sublist():------------------------------------------------------------------------------------------------------------

    printf("\n\n--------------------------------------\n");
    printf("Testing sublist F (for F is not modified by sublist).\n\n");

    list F = NULL;
    int arrF[] = {10, 10, 40, 20};
    F = arrayToList(arrF, 4);
    printf("LIST F:");
    printListHorizPointer(F);

    int arr_posF[] = {0, 1, 2};
    list pos_listF = arrayToList(arr_posF, 3);
    printf("List with positions pos_listF:");
    printListHoriz(pos_listF);

    list resF = sublist(F, pos_listF);
    destroyList(pos_listF);

    printf("SUBLIST:");
    printListHorizPointer(resF);
    destroyList(resF);

    printf("original list F:");
    printListHorizPointer(F);
    destroyList(F);


//Test Sublist G, repeated position ():------------------------------------------------------------------------------------------------------------
//--------------------------------------------------




    printf("\n\n--------------------------------------\n");
    printf("Testing sublist G (for pos_list repeats).\n\n");

    list G = NULL;
    int arrG[] = {10, 10, 40, 20};
    G = arrayToList(arrG, 4);
    printf("LIST G:");
    printListHorizPointer(G);

    int arr_posG[] = {1, 1, 1, 1};
    list pos_listG = arrayToList(arr_posG, 4);
    printf("List with positions pos_listG:");
    printListHoriz(pos_listG);

    list resG = sublist(G, pos_listG);
    destroyList(pos_listG);

    printf("SUBLIST:");
    printListHorizPointer(resG);
    destroyList(resG);





   return 0;
}
