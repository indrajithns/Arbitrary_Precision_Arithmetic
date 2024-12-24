/*
 * File: dlist.c
 * Description: Implementation of a doubly linked list with basic operations.
 *
 * This file defines functions to create, manipulate, and manage a doubly linked list.
 * The doubly linked list supports the following operations:
 * - Creating an empty list
 * - Adding nodes to the head or tail of the list
 * - Printing the list for debugging
 * - Freeing memory allocated for the list
 *
 * Data Structures:
 * - DList: Represents the doubly linked list, containing pointers to the head and tail nodes.
 * - Node: Represents a node in the list, containing data and pointers to the previous and next nodes.
 *
 * Functions:
 * - DList* create_empty_list(): Creates an empty doubly linked list.
 * - Node* create_node(int data): Creates a new node with the specified data.
 * - void insert_at_head(DList **list, Node *new_node): Inserts a new node at the head of the list.
 * - void insert_at_tail(DList **list, Node *new_node): Inserts a new node at the tail of the list.
 * - void print_list(DList *list): Prints the list contents from head to tail.
 * - void free_list(DList *list): Frees all memory allocated for the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// Create an empty doubly linked list
DList* create_empty_list() {
    DList *list = (DList *)malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Create a new node with the given data
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Insert a new node at the head of the list
void insert_at_head(DList **list, Node *new_node) {
    if (*list == NULL) {
        *list = create_empty_list();
    }
    new_node->next = (*list)->head;
    if ((*list)->head != NULL) {
        (*list)->head->prev = new_node;
    } else {
        (*list)->tail = new_node; // If the list was empty, tail is also new_node
    }
    (*list)->head = new_node;
}

// Insert a new node at the tail of the list
void insert_at_tail(DList **list, Node *new_node) {
    if (*list == NULL) {
        *list = create_empty_list();
    }
    new_node->prev = (*list)->tail;
    if ((*list)->tail != NULL) {
        (*list)->tail->next = new_node;
    } else {
        (*list)->head = new_node; // If the list was empty, head is also new_node
    }
    (*list)->tail = new_node;
}

// Print the list for debugging
void print_list(DList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free allocated memory for the list
void free_list(DList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}