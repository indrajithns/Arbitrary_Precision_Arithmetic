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
