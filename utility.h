
// function to generate random values in the array
int structure_values_generator(struct STUDENT_RECORD students[], int nos, int *last_roll) {

    // data
    char first_names[10][10] = {"Vicky", "Micky", "Ticky", "Licky", "Bicky", "Vasu", "Lakshay", "Harshit", "Abhishek", "Ritik"};
    char last_names[10][10] = {"Singh", "Chauhan", "Gond", "Patel", "Kumar", "Tiwari", "Paul", "Taunk", "Gupta", "Mishra"};
    char streets[5][20] = {"New Colony", "Old Colony", "Extension Colony", "Camp Colony", "Civil Lines"};
    char cities[10][20] = {"Palwal", "Faridabad", "Gurugram", "Noida", "Dwarka", "Mumbai", "Banglore", "Indore", "Gwalior", "Jaipur"};
    char state[10][20] = {"Haryana", "MP", "Delhi", "UP", "Bihar", "Punjab", "J&K", "Karnataka", "Tamil Nadu", "Goa"};

    srand(time(NULL));
   
    for (int i=0; i<nos; i++) {
        students[i].roll = 1000 + i;
        *last_roll = students[i].roll;
        strcpy(students[i].name, first_names[rand()%10]);
        // strcpy(students[i].name[1], last_names[rand()%10]);
        students[i].marks = rand()%(100-30)+30;
        students[i].add.house_no = rand()%9;
        strcpy(students[i].add.street, streets[rand()%5]);
        strcpy(students[i].add.city, cities[rand()%10]);
        strcpy(students[i].add.state, state[rand()%10]);
        students[i].dob.date = rand()%30+1;
        students[i].dob.month = rand()%12+1;
        students[i].dob.year = rand()%(2020-1990+1)+1990;
    }

    return 0;
}

// function to enter a value in the array
int insert_value(struct STUDENT_RECORD students[], int *last_roll) {
    struct STUDENT_RECORD temp_record;
    temp_record.roll = *last_roll + 1;
    printf("Enter Name:\n");
    scanf("%s", temp_record.name);
    printf("Enter Marks:\n");
    scanf("%f", &temp_record.marks);
    printf("Enter Address:\n");
    printf("House No.: ");
    scanf("%d", &temp_record.add.house_no);
    printf("Street: ");
    scanf("%s", temp_record.add.street);
    printf("City: ");
    scanf("%s", temp_record.add.city);
    printf("State: ");
    scanf("%s", temp_record.add.state);
    printf("Enter DOB (use format for inserting: DD MM YYYY)");
    scanf("%d %d %d", temp_record.dob.date, temp_record.dob.month, temp_record.dob.year);  
}

// function to display all the values of the array
int structure_values_display(struct STUDENT_RECORD students[], int nos) {
    for (int i=0; i<nos; i++) {
        printf("\n");
        printf("%d\t", students[i].roll);
        printf("%s\t", students[i].name);
        // printf("%s ", students[i].name[1]);
        printf("%.2f\t", students[i].marks);
        printf("H no. %d %s ,%s %s\t", students[i].add.house_no, students[i].add.street, students[i].add.city, students[i].add.state);
        printf("%d-%d-%d", students[i].dob.date, students[i].dob.month, students[i].dob.year);
        printf("\n");
    }
    return 0;
}

// function to fetch values from file to structure;
// int fetchValues()