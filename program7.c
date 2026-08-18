#include <stdio.h>
#include<string.h>
// Function prototypes
void readString(char *str, int size);
void removeNewline(char *str);
int compareStrings(char *str1, char *str2); // to be implemented
void displayResult(int result);

int main() {
char str1[50],str2[50];
    // Input
    printf("Enter first string: ");
    readString(str1,50);

    printf("Enter second string: ");
    readString(str2,50);

    // Pre-processing
    removeNewline(str1);
    removeNewline(str2);


    // Processing
    int result=compareStrings(str1,str2);

    // Output
    displayResult(result);

    return 0;
}

// Reads input
void readString(char *str, int size) {
fgets(str,size,stdin);
}

// Removes newline
void removeNewline(char *str) {
    str[strcspn(str,"\n")]='\0';

}


int compareStrings(char *str1, char *str2) {
    // Write your logic here
    return strcmp(str1,str2);
}

// Displays result
void displayResult(int result) {
    
    if(result==0){
        printf("Both strings are equal.\n");
    }
else if(result>=0){
        printf("First string is lexicographically greater.\n");
}
  else{
        printf("Second string is lexicographically greater.\n");
  }
}
