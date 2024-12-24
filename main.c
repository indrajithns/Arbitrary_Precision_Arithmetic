/*
 * File: main.c
 * Description: Arbitrary precision arithmetic application that performs basic
 *              arithmetic operations (+, -, *, /, %) on two large numbers represented
 *              using doubly linked lists.
 *
 * Features:
 * - Accepts large numbers and an operator as input (e.g., 123456789+987654321).
 * - Uses doubly linked lists to represent numbers for efficient manipulation.
 * - Supports the following operations:
 *   - Addition (+)
 *   - Subtraction (-)
 *   - Multiplication (*)
 *   - Division (/)
 *   - Modulus (%)
 * - Handles user input validation and provides feedback for incorrect formats.
 * - Allows the user to perform multiple calculations in a single session.
 * - Frees all dynamically allocated memory to prevent memory leaks.
 *
 * Functions:
 * - void handle_operation(char operator, DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR):
 *     Dispatches the appropriate arithmetic operation based on the given operator.
 * - int main():
 *     Handles user input, processes operations, displays results, and manages program flow.
 *
 * Usage:
 * - Compile the program with its dependencies (`dlist.h` and `operations.h`).
 * - Run the executable and enter input in the specified format (e.g., "12345+67890").
 * - Follow prompts to continue or exit the application.
 *
 * Dependencies:
 * - dlist.h: Provides definitions and functions for managing doubly linked lists.
 * - operations.h: Contains implementations of arithmetic operations for large numbers.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"
#include "operations.h"

// Updated handle_operation to accept Node pointers directly
void handle_operation(char operator, DList *head1, Node *tail1, DList *head2, Node *tail2, DList **headR) {
    switch (operator) {
        case '+':
            addition(&head1, tail1, &head2, tail2, headR);
            break;
        case '-':
            subtraction(head1, tail1, head2, tail2, headR);
            break;
        case '*':
            multiplication(head1, tail1, head2, tail2, headR);
            break;
        case '/':
            division(head1, tail1, head2, tail2, headR);
            break;
        case '%':
            modulus(head1, tail1, head2, tail2, headR);
            break;
        default:
            printf("Error!!! Unsupported Operation '%c'\n", operator);
            break;
    }
}

int main() {
    char input[256];
    char continue_choice;

    do {
        printf("Enter Your Input (e.g., 123456789012345+67890): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for operator presence and split input
        char *operator_pos = strpbrk(input, "+-*/%");
        if (operator_pos == NULL) {
            printf("Invalid Input Format.... Please Try Again.\n");
            continue;
        }

        char operator = *operator_pos; // Get the operator
        *operator_pos = '\0'; // Null terminate the first part to isolate the first number
        char *first_number = input; // The first number is before the operator
        char *second_number = operator_pos + 1; // The second number is after the operator

        // Check if both numbers are provided
        if (*first_number == '\0' || *second_number == '\0') {
            printf("Invalid Input Format.... Please Try Again.\n");
            continue;
        }

        // Create doubly linked lists for both numbers
        DList *head1 = create_empty_list();
        DList *head2 = create_empty_list();
        DList *headR = NULL;

        // Convert string numbers to doubly linked lists
        for (int i = 0; first_number[i] != '\0'; i++) {
            insert_at_tail(&head1, create_node(first_number[i] - '0')); // Convert char to int
        }
        for (int i = 0; second_number[i] != '\0'; i++) {
            insert_at_tail(&head2, create_node(second_number[i] - '0')); // Convert char to int
        }

        // Perform the operation
        handle_operation(operator, head1, head1->tail, head2, head2->tail, &headR);

        // Display result
        printf("Result: ");
        print_list(headR); // Assuming print_list prints the content of the list
        printf("\n");

        // Free memory for the lists
        free_list(head1);
        free_list(head2);
        free_list(headR);

        // Ask user to continue with validation
        do {
            printf("Want To Continue? Press [Y / N]: ");
            scanf(" %c", &continue_choice); // The space before %c ignores any whitespace
            getchar(); // To consume the newline character left in the input buffer

            if (continue_choice != 'Y' && continue_choice != 'y' &&
                continue_choice != 'N' && continue_choice != 'n') {
                printf("Invalid input. Please enter 'Y' or 'N'.\n");
            }
        } while (continue_choice != 'Y' && continue_choice != 'y' &&
                 continue_choice != 'N' && continue_choice != 'n');

    } while (continue_choice == 'Y' || continue_choice == 'y');

    printf("Application Terminated.\n");
    return 0;
}
