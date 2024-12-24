/*
 * File: operations.h
 * Description: Header file defining function declarations for performing arithmetic
 *              operations on large numbers represented as doubly linked lists.
 *
 * Features:
 * - Addition:
 *   Adds two large numbers and stores the result in a doubly linked list.
 *
 * - Subtraction:
 *   Subtracts the second large number from the first and stores the result.
 *
 * - Multiplication:
 *   Multiplies two large numbers and stores the product in a doubly linked list.
 *
 * - Division:
 *   Divides the first large number by the second and stores the quotient.
 *   Includes error handling for division by zero.
 *
 * - Modulus:
 *   Computes the remainder of the division of two large numbers and stores the result.
 *   Includes error handling for modulus by zero.
 *
 * - Comparison:
 *   Compares two large numbers represented as doubly linked lists and returns:
 *     1  -> If the first number is greater.
 *     -1 -> If the second number is greater.
 *     0  -> If both numbers are equal.
 *
 * Function Declarations:
 * - int addition(DList **head1, Node *tail1, DList **head2, Node *tail2, DList **headR):
 *     Performs addition of two large numbers.
 *
 * - int subtraction(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Performs subtraction of two large numbers.
 *
 * - int multiplication(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Performs multiplication of two large numbers.
 *
 * - int division(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Performs division of two large numbers.
 *
 * - int modulus(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Performs modulus operation of two large numbers.
 *
 * - int compare_dlists(DList *lst1, DList *lst2):
 *     Compares two large numbers represented as doubly linked lists.
 *
 * Usage:
 * - Include this header in any program requiring arbitrary precision arithmetic operations.
 * - Ensure the `dlist.h` file is included to provide data structure definitions.
 *
 * Dependencies:
 * - Requires `dlist.h` for data structure definitions.
*/

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
