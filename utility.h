// basic functions

// function to enter a value in the array
int insert_value(struct STUDENT_RECORD students[], int *last_index) {
    students[(*last_index)].roll = *last_index + 10001;
    fflush(stdin);
    printf("Enter Name:\n");
    scanf(" %[^\n]s", students[(*last_index)].name);
    fflush(stdin);
    printf("Enter Marks:\n");
    scanf(" %f", &students[(*last_index)].marks);
    fflush(stdin);
    printf("Enter Address:\n");
    printf("House No.: ");
    scanf(" %d", &students[(*last_index)].add.house_no);
    fflush(stdin);
    printf("Street: ");
    scanf(" %[^\n]s", students[(*last_index)].add.street);
    fflush(stdin);
    printf("City: ");
    scanf(" %[^\n]s", students[(*last_index)].add.city);
    fflush(stdin);
    printf("State: ");
    scanf(" %[^\n]s", students[(*last_index)].add.state);
    fflush(stdin);
    printf("Enter DOB (use format for inserting: DD MM YYYY): ");
    scanf(" %d %d %d", &students[(*last_index)].dob.date, &students[(*last_index)].dob.month, &students[(*last_index)].dob.year);  
    fflush(stdin);
    (*last_index)++;
}

// function to display all the values of the array
int structure_values_display(struct STUDENT_RECORD students[], int *last_roll) {
    printf("value of last roll is %d\n", *last_roll);
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("|%-8s|%-20s|%-8s|%-50s|%-10s|\n", "Roll", "Name", "Marks", "Address", "Date of Birth");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    for (int i=0; i<*last_roll; i++) {
        if (students[i].roll == -1) continue;
        printf(" %8d|", students[i].roll);
        printf("%20s|", students[i].name);
        printf("%8.2f|", students[i].marks);
        printf("  H.no %2d %13s %13s %13s|", students[i].add.house_no, students[i].add.street, students[i].add.city, students[i].add.state);
        printf("%.2d-%.2d-%4d ", students[i].dob.date, students[i].dob.month, students[i].dob.year);
        printf("\n");
    }
    fflush(stdin);
    while ((getchar()) != '\n');
    char c;
    c = getchar();
    return 0;
}

// function to display only a particular value from the array
int single_value_display(struct STUDENT_RECORD students[], int *last_roll) {
    int user_roll;
    int flag = 0;
    printf("Enter the roll number: ");
    scanf("%d", &user_roll);
    for (int i=0; i<*last_roll; i++) {
        if (user_roll == students[i].roll) {
            printf("\n");
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("Address: %d %s %s %s\n", students[i].add.house_no, students[i].add.street, students[i].add.city, students[i].add.state);
            printf("Date of Birth: %d-%d-%d\n", students[i].dob.date, students[i].dob.month, students[i].dob.year);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Roll Number not found!\n");
    }
    fflush(stdin);
    while ((getchar()) != '\n');
    char c;
    c = getchar();
    return 0;
}

// function to delete a value from the array
int delete_value(struct STUDENT_RECORD students[], int *last_roll) {
    int user_roll;
    int flag = 0;
    printf("Enter the Roll Number you want to delete: ");
    scanf("%d", &user_roll);
    for (int i=0; i<*last_roll; i++) {
        if (user_roll == students[i].roll) {
            students[i].roll = -1;
            printf("Student Deleted Successfully!\n");
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Roll Number Not Found!\n");
    }
    fflush(stdin);
    while ((getchar()) != '\n');
    char c;
    c = getchar();
    return 0;
}
