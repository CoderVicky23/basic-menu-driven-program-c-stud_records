// basic functions

// function to enter a value in the array
int insert_value(struct STUDENT_RECORD students[], int *last_roll) {
    students[(*last_roll)].roll = *last_roll + 10001;
    fflush(stdin);
    printf("Enter Name:\n");
    scanf(" %[^\n]s", students[(*last_roll)].name);
    fflush(stdin);
    printf("Enter Marks:\n");
    scanf("%f", &students[(*last_roll)].marks);
    fflush(stdin);
    printf("Enter Address:\n");
    printf("House No.: ");
    scanf("%d", &students[(*last_roll)].add.house_no);
    fflush(stdin);
    printf("Street: ");
    scanf("%s", students[(*last_roll)].add.street);
    fflush(stdin);
    printf("City: ");
    scanf("%s", students[(*last_roll)].add.city);
    fflush(stdin);
    printf("State: ");
    scanf("%s", students[(*last_roll)].add.state);
    fflush(stdin);
    printf("Enter DOB (use format for inserting: DD MM YYYY): ");
    scanf("%d %d %d", &students[(*last_roll)].dob.date, &students[(*last_roll)].dob.month, &students[(*last_roll)].dob.year);  
    fflush(stdin);
    (*last_roll)++;
}

// function to display all the values of the array
int structure_values_display(struct STUDENT_RECORD students[], int *last_roll) {
    printf("%8s\t%20s\t%8s\t%25s\t%10s", "Roll", "Name", "Marks", "Address", "Date of Birth");
    for (int i=0; i<*last_roll; i++) {
        printf("\n");
        printf("%8d\t", students[i].roll);
        printf("%20s\t", students[i].name);
        printf("%8.2f\t", students[i].marks);
        printf("%3d %8s %8s %8s\t", students[i].add.house_no, students[i].add.street, students[i].add.city, students[i].add.state);
        printf("%d-%d-%d", students[i].dob.date, students[i].dob.month, students[i].dob.year);
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

// function to fetch values from file to structure;
// int fetchValues()