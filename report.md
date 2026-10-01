# Brief Project Report

## Introduction
The Student Result Management System is a menu-driven C mini-project developed using an array of structures. It is designed to maintain basic student academic records.

## Design Decisions
### 1. Array of Structures
An array of structures is used because each student has multiple related fields: roll number, name and marks. It also satisfies the requirement of implementing the system using arrays.

### 2. Functions
Separate functions are used for add, display, search, update, delete, topper and report operations. This makes the program easier to understand and maintain.

### 3. Searching
A linear search is used to locate a student by roll number. It is simple and suitable for the small fixed-size array used in this project.

### 4. Deletion
After finding a student, later records are shifted one position to the left so that there is no empty gap in the array.

### 5. Total and Average
Total is the sum of five subject marks. Average is calculated as:
`Average = Total / 5`

### 6. Topper
The student having the highest average marks is selected as the topper.

## Limitations
- Data is stored only during program execution.
- Maximum 100 students can be stored.
- Exactly five subjects are used.
- No database or file storage is included.

## Conclusion
The project demonstrates fundamental C programming concepts including arrays, structures, functions, loops, searching, updating and deletion. It provides a simple and practical student result management system.
