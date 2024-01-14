// function to create a csv file from structure
int createFile(struct STUDENT_RECORD students[], int nos) {
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        perror("Error: ");
        return -1;
    }
    fprintf(file, "roll,name,marks,house_no,street,city,state,date,month,year");
    for (int i=0; i<nos; i++) {
        fprintf(file, "%d,%s,%f,%d,%s,%s,%s,%d,%d,%d\n", 
        students[i].roll,
        students[i].name,
        students[i].marks,
        students[i].add.house_no,
        students[i].add.street,
        students[i].add.city,
        students[i].add.state,
        students[i].dob.date,
        students[i].dob.month,
        students[i].dob.year);
    }
    fclose(file);
    return 0;
}

// function to read a csv file to a structure
int readFile(struct STUDENT_RECORD students[], int nos) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error: ");
        return -1;
    }
    int i = 0;
    while(fscanf(
        file, 
        "%d,%19[^,\n],%f,%d,%19[^,\n],%19[^,\n],%19[^,\n],%d,%d,%d",
        &students[i].roll,
        students[i].name,
        &students[i].marks,
        &students[i].add.house_no,
        students[i].add.street,
        students[i].add.city,
        students[i].add.state,
        &students[i].dob.date,
        &students[i].dob.month,
        &students[i].dob.year
        ) == 10) {
        i++;
    }
    return 0;
}