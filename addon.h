

// function to generate random values in the array
int structure_values_generator(struct STUDENT_RECORD students[], int size, int *last_roll) {

    // data
    char first_names[10][10] = {"Vicky", "Micky", "Ticky", "Licky", "Bicky", "Vasu", "Lakshay", "Harshit", "Abhishek", "Ritik"};
    char last_names[10][10] = {"Singh", "Chauhan", "Gond", "Patel", "Kumar", "Tiwari", "Paul", "Taunk", "Gupta", "Mishra"};
    char streets[5][20] = {"New Colony", "Old Colony", "Extension", "Camp Colony", "Civil Lines"};
    char cities[10][20] = {"Palwal", "Faridabad", "Gurugram", "Noida", "Dwarka", "Mumbai", "Banglore", "Indore", "Gwalior", "Jaipur"};
    char state[10][20] = {"Haryana", "MP", "Delhi", "UP", "Bihar", "Punjab", "J&K", "Karnataka", "Tamil Nadu", "Goa"};

    srand(time(NULL));

    int n = *last_roll;
    int nos;

    printf("\nEnter the number of entries you want to insert. ");
    scanf("%d", &nos);

    if ((nos + *last_roll) > size) {
        printf("\nSize is out of range!\n");
        return 0;
    }
   
    for (int i=n; i<nos; i++) {
        students[i].roll = *last_roll + 10001;
        // *last_roll = students[i].roll;
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
        *last_roll += 1;
    }

    printf("\nValues generated Successfully!\n");

    return 0;
}