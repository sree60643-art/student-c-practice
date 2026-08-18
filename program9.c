#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
#define FILENAME "student.txt"


typedef struct {
    int id;
    char name[50];
    float marks;
} Student;

// Function declarations
void inputStudents(Student students[], int n);
void writeToTextFile(Student students[], int n, const char *filename);
int readFromTextFile(Student students[], int max, const char *filename);
void printStudents(Student students[], int n);

// Main
int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);

    if (n<=0) {
        printf("Invalid input\n");
        return 0;
    
    }
     Student students[MAX];

    // Input
    inputStudents(students,n);

    // Write to file
    writeToTextFile(students,MAX,FILENAME);

    // Read from file
    int count=readFromTextFile(students,MAX,FILENAME);

    // Output
    printf("\n--- Students read from ASCII file ---\n");
    printStudents(students,n);
    return 0;
}

// Function to take input
void inputStudents(Student students[], int n) {
    for(int i=0;i<n;i++){
        printf("\nEnter details for student %d:\n",i+1 );

        printf("Enter ID: ");
        scanf("%d",&students[i].id);

        printf("Enter Name: ");
        scanf("%s",&students[i].name);

        printf("Enter Marks: ");
        scanf("%f",&students[i].marks);
    }

}

// Write to text file
void writeToTextFile(Student students[], int n, const char *filename) {
    FILE*fp=fopen(filename,"w");
    if(fp==NULL){
        printf("Error opening file for writing\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        fprintf(fp,"%d,%s,%f\n",students[i].id,students[i].name,students[i].marks);
    }
 fclose(fp);
}

// Read from text file
int readFromTextFile(Student students[], int max, const char *filename) {
     FILE*fp=fopen(filename,"w");
     int count;
    if(fp==NULL){
   printf("Error opening file for reading\n");
   return 0;
    }
    int i=0;
    while(i<max && fscanf(fp,"%d%s%f",&students[i].id,&students[i].name,&students[i].marks)!=EOF){
        i++;
    }
    fclose(fp);
    return count;

}

// Print students
void printStudents(Student students[], int n) {
    for(int i=0;i<n;i++){
        printf("%d %s %.2f\n",students[i].id,students[i].name,students[i].marks);
    }
}
