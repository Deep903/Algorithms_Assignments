/* This program uses code from "Algorithms in C, Third Edition,"
 *               by Robert Sedgewick, Addison-Wesley, 1998.
 *
 * - Alexandra Stefan
 */


#ifndef LIST_HW_H
#define	LIST_HW_H

typedef int Item;
typedef struct node_struct * link;
typedef struct list_struct * list;  // Use pointers to hide the list
                                    // implementation from the client code.

list buildListOfInts();
list arrayToList(int arr[], int sz);

int run_student_tests();

/* Creates a new link, that contains the value specified in the argument,
 * and that points to next_in.
 */
link newLink(Item value, link next_in);

void destroyLink(link the_link);

void setLinkItem(link the_link, Item value);

void setLinkNext(link the_link, link next);

/*  Note that these functions do not have all the security checks.
E.g. not all the functions reading and setting members of a node pointer,
check that the node is not NULL  */

Item getLinkItem(link the_link);

link getLinkNext(link the_link);




/* LIST  */

// Creates and returns an empty list.
list newList();

void destroyList(list the_list);

// Returns a pointer to the first node in the list.
link getFirst(list the_list);

// Uses the field variable.
int getLength(list my_list);

// Iterates through list and counts nodes.
int computeLength(list my_list);

/* Sets the data to empty (first is null, length is 0,...)
 * It does NOT free any memory.
 */
void setEmpty(list the_list);


// Inserts new_link to the specified list, at the position right after
// the link called "previous".
void insertLink(list my_list, link previous, link new_link);

/* Inserts new_link to the beginning of the list. */
void insertAtBeginning(list my_list, link new_link);

// Removes from the list and returns the link coming AFTER link x.
// This function DOES NOT  remove the link x itself.
link removeNext(list my_list, link x);

// Removes and returns the first node from the list. It does NOT free the memory.
link removeFirst(list my_list);

void printList(list my_list);

void printListHoriz(list my_list);

void printListHorizPointer(list my_list);

/*----------------------------------------------------------------
 New functions that you will need to implement.
 DO not change their declaration or anything else in this file. declaration.
 */


void swapFirstThird(list A);

void deleteOccurrences(list A, Item V);

list sublist(list A, list pos_list);

void moveAllMaxAtEnd(list A);


#endif	/* LIST_HW_H */
