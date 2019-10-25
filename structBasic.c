/* implementing structures in c */

#include <stdio.h>
#include <stdlib.h>    //using malloc

struct student{
    char firstName[30];
    char lastName[30];
    int birthYear;
    double aveGrade;
};

void printPersonPtr(struct student *);
void printPerson(struct student);
void readStudent(struct student *);
void readClassics(struct student *);
void printClassics(struct student *, int);

int main(void) {
	//! showMemory(start=65520)
  int stp;
  int i;
  int num;
    struct student me  = {"Federica", "Signorini", 1989, 3.5};
    struct student *fede = &me;
    struct student you = {"Remi", "Sharrock", 2005, 3.5};

    struct student stemStudent;

    struct student *language;

    struct student *classics;
+
    printf("Names: %s %s, %s %s\n", me.firstName, me.lastName, you.firstName, you.lastName);
    printf("Year of birth: %d\n", me.birthYear);
    printf("Average grade: %.2lf\n", me.aveGrade);
    printf("other: %s %s %d %.2lf\n", fede->firstName, fede->lastName, fede->birthYear, fede->aveGrade);

    printPersonPtr(fede);
    printPerson(me);
    
    // using functions on stemStudent, pointer not used in this example 
    // stemStudent is not a pointer so do not need to set up memory allocation
    printf("Next enter details of Science student\n");
    readStudent(&stemStudent);  
    printPerson(stemStudent); 
    
  
    /* using language struct, pointer used in set up of language
       so we have to first allocate memory to the pointer
       otherwise the program will crash as pointer not
       pointing to anything. */
    
    language = (struct student *)malloc(sizeof(struct student));          // allocate memory to pointer struct
    printf("Next enter details of Language student\n");
    readStudent(language);  
    printPersonPtr(language);
    free(language);         // free memory allocated to language, probably better to put this at every end of program

    printf("\n");
    printf("************************************\n");
    printf("****  classic students example  ****\n");
    printf("************************************\n");

    /* using the classics struct */
    printf("How many classics students are attending the course? ");
    scanf("%d", &num);                                                     // enter number of classics students
    classics = (struct student *) malloc(num * sizeof(struct student));    // allocate memory to enter the students
    for (i=0; i<num; i++){
      readClassics(&classics[i]);                                          // for each student run readClassics routine 
    }

    printClassics(classics,num);                                           // run the printClassics routine

    free(classics);                                                        // free memory allocated for classics


    scanf("%d", &stp);

    return 0;
}

void printPersonPtr(struct student *person) {
  printf("Person details ptr type: %s\n", person->firstName);
	 }

void printPerson(struct student person) {
  printf("Person details non ptr type: %s\n", person.firstName);
}

void readStudent(struct student *science){
  printf("Enter first name of student ");
  scanf("%s", science->firstName);
}

void readClassics(struct student *classicStudent){
  printf("Enter firstname : ");
  scanf("%s", classicStudent->firstName);
  
}

void printClassics(struct student *ptr, int reg){
  int i = 0;
  for (i=0; i<reg; i++){
    printPerson(ptr[i]);            // this function is with non pointer parameter
    printPersonPtr(ptr+i);          // the same result but with a pointer parameter so now use pointer arithmatic
  }
}


