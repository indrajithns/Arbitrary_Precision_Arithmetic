
# Arbitrary Precision Calculator (APC)

This project implements an arbitrary precision calculator using doubly linked lists. It supports basic arithmetic operations like addition, subtraction, multiplication, division, and modulus for large numbers, represented as doubly linked lists. The program is written in C and can handle integers of virtually any size, constrained only by memory.

## Features

- **Addition**: Adds two large numbers.
- **Subtraction**: Subtracts one large number from another.
- **Multiplication**: Multiplies two large numbers.
- **Division**: Divides one large number by another, handling division by zero errors.
- **Modulus**: Computes the remainder when one large number is divided by another.
- **Comparison**: Compares two large numbers and returns whether one is greater than, less than, or equal to the other.

## Files Overview

### 1. `dlist.h`
This header file defines the structures and function prototypes for managing the doubly linked list data structure used to represent large numbers.

#### Key Structures:
- **Node**: Represents a single digit of the large number. Each node contains:
  - `data`: The digit value (0-9).
  - `next`: Pointer to the next node in the list.
  - `prev`: Pointer to the previous node in the list.

- **DList**: A doubly linked list structure that represents the large number.
  - `head`: Points to the first node.
  - `tail`: Points to the last node.

#### Functions:
- **create_node**: Creates a new node with a given data value.
- **insert_at_head**: Inserts a node at the head of the list.
- **insert_at_tail**: Inserts a node at the tail of the list.
- **free_list**: Frees the memory allocated for the list.

### 2. `dlist.c`
This file contains the implementation of the functions declared in `dlist.h`. It provides the functionality to create, modify, and free doubly linked lists, which are used to store large numbers.

### 3. `operations.h`
This header file defines the function declarations for performing arithmetic operations on large numbers represented as doubly linked lists.

#### Functions:
- **addition**: Adds two large numbers.
- **subtraction**: Subtracts one large number from another.
- **multiplication**: Multiplies two large numbers.
- **division**: Divides one large number by another.
- **modulus**: Computes the modulus of two large numbers.
- **compare_dlists**: Compares two large numbers.

### 4. `operations.c`
This file implements the arithmetic functions declared in `operations.h`. It contains the logic for performing addition, subtraction, multiplication, division, modulus, and comparison of large numbers.

### 5. `main.c`
The entry point of the program. It handles user input, processes commands, and displays the results of arithmetic operations on large numbers.

### 6. `Makefile`
The Makefile is used to compile and link the program. It defines the compiler, flags, object files, and the target executable (`apc`).

### Example Usage

To use the calculator, you can input two large numbers and specify an arithmetic operation between them. For example:

```text
Enter first number: 12345678901234567890
Enter operator (+, -, *, /, %): +
Enter second number: 98765432109876543210
Result: 111111111011111111100
```

## Compilation and Running

### To Compile and Run:

1. Compile the program using `make`:
   ```bash
   make
   ```

2. Run the program:
   ```bash
   ./apc
   ```

### To Clean Up:
To remove the compiled object files and executable:
```bash
make clean
```

## Detailed Explanation of Arithmetic Operations

### 1. Addition
The `addition` function adds two large numbers. It starts from the least significant digit (the tail of the doubly linked list) and iteratively adds corresponding digits, carrying over when necessary.

### 2. Subtraction
The `subtraction` function subtracts one large number from another, similar to the addition function but handling borrowing.

### 3. Multiplication
The `multiplication` function multiplies two large numbers using digit-wise multiplication and stores the intermediate results in a temporary list. It then adds these partial results together.

### 4. Division
The `division` function divides one large number by another, using repeated subtraction. It handles division by zero errors gracefully.

### 5. Modulus
The `modulus` function calculates the remainder of the division between two large numbers using repeated subtraction.

### 6. Comparison
The `compare_dlists` function compares two doubly linked lists and returns:
- `1` if the first number is greater.
- `-1` if the second number is greater.
- `0` if both numbers are equal.
