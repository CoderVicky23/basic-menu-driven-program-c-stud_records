#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "structure.h"
#include "update.h"
#include "utility.h"
#include "addon.h"

#define MAX_SIZE 100

int main() {

    // declaring a structure of size 100;
    struct STUDENT_RECORD* students = (struct STUDENT_RECORD*) malloc(MAX_SIZE * sizeof(struct STUDENT_RECORD));

    if (students == NULL) {
        perror("Memory Not Allocated!: ");
        return 0;
    }

    // variable to store last active roll number
    int last_index=0;

    while (1)  {
        system("clear");
        printf("\n");
        printf("1. To Insert New Value\n");
        printf("2. To Delete An Entry\n");
        printf("3. To Display All Values\n");
        printf("4. To Display Single Student\n");
        printf("5. To exit the menu\n");
        printf("6. To insert Random Values\n");
        int user_input;
        scanf("%d", &user_input);
        switch (user_input)
        {
        case 1:
            system("clear");
            insert_value(students, &last_index);
            break;
        case 2:
            system("clear");
            delete_value(students, &last_index);
            break;
        case 3:
            system("clear");
            structure_values_display(students, &last_index);
            break;
        case 4:
            system("clear");
            single_value_display(students, &last_index);
            break;
        case 5:
            return 0;
            break;
        case 6:
            system("clear");
            structure_values_generator(students, MAX_SIZE, &last_index);
        default:
            printf("Not A valid Value!");
            break;
        }
    }

    return 0;
}