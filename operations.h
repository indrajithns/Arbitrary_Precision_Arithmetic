#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "dlist.h"

// Function declarations
int addition(DList **head1, Node *tail1, DList **head2, Node *tail2, DList **headR);
int subtraction(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR);
int multiplication(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR);
int division(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR);
int modulus(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR);
int compare_dlists(DList *lst1, DList *lst2);

#endif // OPERATIONS_H
