struct ADDRESS {
    int house_no;
    char street[20];
    char city[20];
    char state[20];
};

struct DOB {
    int date;
    int month;
    int year;
};

struct STUDENT_RECORD {
    int roll;
    char name[20];
    float marks;
    struct ADDRESS add;
    struct DOB dob;
};