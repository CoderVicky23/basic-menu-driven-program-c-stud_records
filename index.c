#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "structure.h"
#include "update.h"
#include "utility.h"

#define MAX_SIZE 100

int main() {

    struct STUDENT_RECORD students[50];
    int nos = 50;

    // variable to store last active roll number
    int last_roll=0;

    // to enter random values in the structure
    structure_values_generator(students, nos, &last_roll);

    // to insert a particular value in the array
    insert_value(students, &last_roll);

    // to display the values of the structure
    structure_values_display(students, nos);

    return 0;
}