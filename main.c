#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "Student.h"
#define MAX_LINE_LENGTH 1024
#define INITIAL_CAPACITY 8

/*
 * The main function of the gradebook program.
 * This program reads student data from a CSV file specified as a command-line argument.
 * It creates Student objects for each line in the CSV file and stores them in a dynamically
 * allocated gradebook array. The gradebook array is grown as needed to accommodate all the
 * students in the file.
 * After loading all the students, the program sorts the gradebook array based on the student
 * scores using the qsort() function and the CompareStudents() function for comparison.
 * Finally, the program iterates through the sorted gradebook array and displays each student's
 * information using the PrintStudent() function.
 * The program handles errors gracefully by displaying appropriate error messages and exiting
 * with a non-zero status code. It also frees all dynamically allocated memory before terminating.
 * @author brycekratzer
 */
int main(int argSize, char *argValues[]) {
   if (argSize != 2) {
      fprintf(stderr, "Usage: %s <gradebook.csv>\n", argValues[0]);
      exit(1);
   }

      char *filename = argValues[1];
      FILE *file = fopen(filename, "r");
      if (file == NULL) {
         perror("fopen"); //prints valid error message
         exit(1);
   }

   int capacity = INITIAL_CAPACITY;
      Student **gradebook = (Student **)malloc(capacity * sizeof(Student *));

      char line[MAX_LINE_LENGTH];
      int studentCount = 0;

      while (fgets(line, sizeof(line), file) != NULL) {// Iterate through each line in the CSV file
         line[strcspn(line, "\n")] = '\0';

         char *lastname = strtok(line, ","); //gets values for gradebook
         char *firstname = strtok(NULL, ",");
         char *studentID = strtok(NULL, ",");
         char *studentScore = strtok(NULL, ",");

         int id = atoi(studentID);
         int score = atoi(studentScore);

         Student *student = CreateStudent(lastname, firstname, id, score); //Creates new student
         gradebook[studentCount++] = student;

         if (studentCount == capacity) { // Grow the gradebook if it fills up
            capacity *= 2;
            printf("Growing Array: %d -> %d\n", capacity / 2, capacity);
            Student **newGradebook = (Student **)realloc(gradebook, capacity * sizeof(Student *));
            gradebook = newGradebook;
         }
      }
      printf("Successfully loaded %d Students!\n", studentCount);

      qsort(gradebook, studentCount, sizeof(Student *), CompareStudents);// Sort the gradebook array

      for (int i = 0; i < studentCount; i++) {
         PrintStudent(gradebook[i]);
      }

      for (int i = 0; i < studentCount; i++) {// Release allocated memory
         DestroyStudent(gradebook[i]);
      }
      free(gradebook);
      fclose(file);

      return 0;
}