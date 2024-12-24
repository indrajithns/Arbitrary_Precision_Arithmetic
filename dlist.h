/*
 * File: dlist.h
 * Description: Header file for a doubly linked list implementation.
 *
 * This file contains the type definitions and function declarations for
 * managing a doubly linked list. A doubly linked list allows traversal in
 * both forward and backward directions, making it versatile for various
 * applications.
 *
 * Data Structures:
 * - Node: Represents an element of the doubly linked list, storing data
 *         and pointers to the previous and next nodes.
 * - DList: Represents the doubly linked list, with pointers to the head
 *          and tail nodes.
 *
 * Function Declarations:
 * - DList* create_empty_list(): Creates and initializes an empty doubly linked list.
 * - Node* create_node(int data): Allocates and initializes a new node with the given data.
 * - void insert_at_head(DList **list, Node *new_node): Adds a new node to the beginning of the list.
 * - void insert_at_tail(DList **list, Node *new_node): Adds a new node to the end of the list.
 * - void print_list(DList *list): Prints the contents of the list (for debugging purposes).
 * - void free_list(DList *list): Frees the memory allocated for the list and its nodes.
 *
 * Usage:
 * Include this header file in your implementation to use the doubly linked
 * list data structures and functions. Ensure to link with the corresponding
 * implementation file (dlist.c).
*/


#ifndef DLIST_H
#define DLIST_H

typedef struct Node {
    int data;                // Value stored in the node
    struct Node *prev;      // Pointer to the previous node
    struct Node *next;      // Pointer to the next node
} Node;

typedef struct DList {
    Node *head;             // Pointer to the head of the list
    Node *tail;             // Pointer to the tail of the list
} DList;

// Function declarations
DList* create_empty_list();
Node* create_node(int data);
void insert_at_head(DList **list, Node *new_node);
void insert_at_tail(DList **list, Node *new_node);
void print_list(DList *list); // For debugging
void free_list(DList *list);   // To free allocated memory

#endif // DLIST_H
