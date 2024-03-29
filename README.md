# Gradebook Program

This program is a gradebook management system that reads student data from a CSV file and performs various operations on the data. The program is written in C and consists of a main function and several supporting functions and data structures.

## Functionality

The main function of the gradebook program does the following:

1. Reads student data from a CSV file specified as a command-line argument.
2. Creates Student objects for each line in the CSV file and stores them in a dynamically allocated gradebook array.
3. The gradebook array is grown as needed to accommodate all the students in the file.
4. After loading all the students, the program sorts the gradebook array based on the student scores using the `qsort()` function and the `CompareStudents()` function for comparison.
5. Finally, the program iterates through the sorted gradebook array and displays each student's information using the `PrintStudent()` function.
6. The program handles errors gracefully by displaying appropriate error messages and exiting with a non-zero status code.
7. It also frees all dynamically allocated memory before terminating.

## Implementation Details

The main function is implemented in the file `main.c`. It takes command-line arguments to specify the CSV file containing the student data. The program uses the following data structures and functions:

- `Student` struct: Represents a student with their last name, first name, ID, and score.
- `CreateStudent()` function: Creates a new Student object with the provided data.
- `CompareStudents()` function: Compares two Student objects based on their scores.
- `PrintStudent()` function: Prints the information of a Student object.
- `DestroyStudent()` function: Frees the memory allocated for a Student object.

The program dynamically allocates memory for the gradebook array using `malloc()` and `realloc()` to accommodate the student data. It also handles errors related to file opening and memory allocation.

## Usage

To run the gradebook program, compile the source files and provide the CSV file containing the student data as a command-line argument:

```
./gradebook gradebook.csv
```

The program will load the student data from the CSV file, sort the students based on their scores, and display the sorted student information.

## Acknowledgments

The `Student.h` and `Student.c` files containing the `Student` struct and related functions were provided as part of the project. The main function and the overall program logic were implemented by brycekratzer.
