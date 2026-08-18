#include <stdio.h>
#include<string.h>

// Function Prototypes
void input(char *str);
void concatenate_strings(char *str1, char *str2);
void display(char *str);

int main() {
    char str1[50],str2[50];
    printf("Enter the first string:\n");
    // read the first string
    input(str1);
    printf("Enter the second string:\n");
    //read the second string
    input(str2);
    /*concatenate strings*/
    concatenate_strings(str1,str2);
    /*display the concatenated string*/
    display(str1);
    return 0;
}

void input(char *str) {
    
    // Write code to read the string
    scanf("%s",str);
}

void concatenate_strings(char *str1, char *str2) {
    // Write code to concatenate str2 to str1 using while/do while
    int i=0,j=0;
    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
        str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i]='\0';
}

void display(char *str) {
    printf("Concatenated Result:%s\n",str);
    // Write code to display the string
}
