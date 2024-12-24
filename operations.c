/*
 * File: operations.c
 * Description: Implements arithmetic operations for large numbers represented as
 *              doubly linked lists, including addition, subtraction, multiplication,
 *              division, and modulus. The code also includes utility functions for
 *              comparing and manipulating doubly linked lists.
 *
 * Features:
 * - Addition:
 *   Calculates the sum of two large numbers and stores the result in a doubly linked list.
 *
 * - Subtraction:
 *   Performs subtraction of two large numbers. Assumes the first number is greater than
 *   or equal to the second number.
 *
 * - Multiplication:
 *   Multiplies two large numbers using digit-wise multiplication and accumulation,
 *   storing the result in a doubly linked list.
 *
 * - Division:
 *   Divides two large numbers using repeated subtraction and produces the quotient.
 *   Handles division by zero with appropriate error messages.
 *
 * - Modulus:
 *   Computes the remainder of the division of two large numbers using repeated subtraction.
 *
 * - Comparison:
 *   Compares two doubly linked lists representing numbers and returns:
 *     1  -> If the first number is greater.
 *     -1 -> If the second number is greater.
 *     0  -> If both numbers are equal.
 *
 * Functions:
 * - int addition(DList **head1, Node *tail1, DList **head2, Node *tail2, DList **headR):
 *     Adds two numbers and stores the result in `headR`.
 *
 * - int subtraction(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Subtracts the second number from the first and stores the result in `headR`.
 *
 * - int multiplication(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Multiplies two numbers and stores the result in `headR`.
 *
 * - int division(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Divides the first number by the second and stores the quotient in `headR`.
 *     Returns 0 for division by zero.
 *
 * - int modulus(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Calculates the modulus (remainder) of the first number divided by the second
 *     and stores the result in `headR`. Returns 0 for modulus by zero.
 *
 * - int compare_dlists(DList *lst1, DList *lst2):
 *     Compares two doubly linked lists and returns the comparison result as described above.
 *
 * Usage:
 * - Include this file as part of a larger program for arbitrary precision arithmetic.
 * - Ensure that the dependent files `dlist.h` and related utility functions are present.
 *
 * Dependencies:
 * - Requires `dlist.h` for doubly linked list definitions and utilities.
*/


#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

// Function to add two large numbers represented as doubly linked lists
int addition(DList **head1, Node *tail1, DList **head2, Node *tail2, DList **headR) {
    Node *ptr1 = tail1;
    Node *ptr2 = tail2;
    int carry = 0;

    while (ptr1 != NULL || ptr2 != NULL || carry) {
        int sum = carry;
        if (ptr1 != NULL) {
            sum += ptr1->data;
            ptr1 = ptr1->prev;
        }
        if (ptr2 != NULL) {
            sum += ptr2->data;
            ptr2 = ptr2->prev;
        }
        carry = sum / 10;
        Node *newNode = create_node(sum % 10);
        insert_at_head(headR, newNode);
    }
    return 1; // Indicate success
}

// Function to subtract two large numbers represented as doubly linked lists
int subtraction(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR) {
    Node *ptr1 = tail1;
    Node *ptr2 = tail2;
    int borrow = 0;

    while (ptr1 != NULL) {
        int diff = ptr1->data - borrow;
        if (ptr2 != NULL) {
            diff -= ptr2->data;
            ptr2 = ptr2->prev;
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        Node *newNode = create_node(diff);
        insert_at_head(headR, newNode);
        ptr1 = ptr1->prev;
    }
    return 1; // Indicate success
}

// Function to multiply two large numbers represented as doubly linked lists
int multiplication(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR) {
    DList *tempResult = create_empty_list();
    Node *ptr1 = tail1;
    int position = 0;

    while (ptr1 != NULL) {
        DList *partialResult = create_empty_list();
        Node *ptr2 = tail2;
        int carry = 0;

        for (int i = 0; i < position; i++) {
            insert_at_tail(&partialResult, create_node(0));  // Pass a pointer to the partialResult
        }

        while (ptr2 != NULL) {
            int product = ptr1->data * ptr2->data + carry;
            carry = product / 10;
            insert_at_tail(&partialResult, create_node(product % 10));  // Pass a pointer to the partialResult
            ptr2 = ptr2->prev;
        }
        if (carry) {
            insert_at_tail(&partialResult, create_node(carry));  // Pass a pointer to the partialResult
        }
        addition(&tempResult, tempResult->tail, &partialResult, partialResult->tail, &tempResult);  // No change needed here
        ptr1 = ptr1->prev;
        position++;
    }

    *headR = tempResult;
    return 1; // Indicate success
}

// Function to compare two doubly linked lists
int compare_dlists(DList *lst1, DList *lst2) {
    Node *ptr1 = lst1->tail;
    Node *ptr2 = lst2->tail;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data != ptr2->data) {
            return (ptr1->data > ptr2->data) ? 1 : -1;
        }
        ptr1 = ptr1->prev;
        ptr2 = ptr2->prev;
    }

    if (ptr1 != NULL) return 1; // lst1 is longer
    if (ptr2 != NULL) return -1; // lst2 is longer
    return 0; // They are equal
}

// Function to divide two large numbers represented as doubly linked lists
int division(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR) {
    // Check for division by zero
    if (head2->head == NULL || (head2->head->data == 0 && head2->head->next == NULL)) {
        printf("Error: Division by zero\n");
        return 0; // Indicate failure
    }

    DList *tempDividend = create_empty_list();
    Node *ptr1 = tail1; // Pointer to the dividend
    Node *ptr2 = tail2; // Pointer to the divisor
    DList *quotient = create_empty_list(); // Resultant quotient

    // Copy the dividend into tempDividend
    while (ptr1 != NULL) {
        Node *newNode = create_node(ptr1->data);
        insert_at_tail(&tempDividend, newNode);
        ptr1 = ptr1->prev;
    }

    // Perform the division
    while (compare_dlists(tempDividend, head2) >= 0) {
        DList *tempSubtractionResult = create_empty_list();
        Node *tempPtr1 = tempDividend->tail; // Pointer to the current dividend

        // Subtract the divisor from the current dividend
        int borrow = 0;
        while (tempPtr1 != NULL) {
            int sub = (tempPtr1->data - (ptr2 ? ptr2->data : 0) - borrow);
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            insert_at_head(&tempSubtractionResult, create_node(sub));
            tempPtr1 = tempPtr1->prev;
            if (ptr2) ptr2 = ptr2->prev; // Move to the next digit of the divisor
        }

        // Set tempDividend to the result of the subtraction
        free_list(tempDividend);
        tempDividend = tempSubtractionResult;

        // Increment the quotient by 1 for each successful subtraction
        insert_at_tail(&quotient, create_node(1)); // Increment the quotient
    }

    // Set headR to the resultant quotient
    *headR = quotient;

    // Free memory for tempDividend
    free_list(tempDividend);
    
    return 1; // Indicate success
}



// Function to calculate modulus of two large numbers represented as doubly linked lists
int modulus(DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR) {
    if (head2->head == NULL || (head2->head->data == 0 && tail2 == head2->head)) {
        printf("Error: Modulus by zero.\n");
        return 0; // Failure
    }

    DList *tempDividend = create_empty_list();
    Node *ptr1 = head1->head; // Pointer to the dividend

    while (ptr1 != NULL) {
        // Bring down the next digit
        insert_at_tail(&tempDividend, create_node(ptr1->data));

        // Perform the subtraction until tempDividend < head2
        while (compare_dlists(tempDividend, head2) >= 0) {
            subtraction(tempDividend, tempDividend->tail, head2, tail2, &tempDividend); // tempDividend -= head2
        }

        ptr1 = ptr1->next; // Move to the next digit in the dividend
    }

    // Assign the remainder to the result
    *headR = tempDividend; // The remainder is the final tempDividend
    return 1; // Indicate success
}

