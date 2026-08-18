#include <stdio.h> 
#include<string.h>

#define MAX 200 

/* Function Declarations */ 

void readString(char str[]); 
void removeNewline(char str[]); 
int getLength(char str[]); 
int findPattern(char str[], char pat[], int start); 
int replacePattern(char str[], char pat[], char rep[], char result[]); 
void displayResult(int flag, char result[]); 

int main() 
{ 
    char str[MAX]; 
    char pat[MAX]; 
    char rep[MAX]; 
    char result[MAX]; 
    int flag; 

    printf("Enter the string: "); 
    readString(str); 

    printf("Enter the pattern: "); 
    readString(pat); 

    printf("Enter the replacement: "); 
    readString(rep); 

    removeNewline(str); 
    removeNewline(pat); 
    removeNewline(rep); 

    flag = replacePattern(str, pat, rep, result); 

    displayResult(flag, result); 

    return 0; 
} 

/* Function to read string */ 

void readString(char str[]) 
{ 
    fgets(str,MAX,stdin);
} 

/* User-defined function to remove newline character */ 

void removeNewline(char str[]) 
{ 
  int i=0;
  while(str[i]!='\0'){
      if(str[i]=='\n'){
          str[i]='\0';
          break;
      }
      i++;
  }
} 

/* Function to find string length */ 

int getLength(char str[]) 
{ 
    int length=0;
    while(str[length]!='\0'){
        length++;
    }
    return length;
} 

/* Function to check pattern match */ 

int findPattern(char str[], char pat[], int start) 
{ 
    int m=0;
    while(pat[m]!='\0'){
        if(str[start+m]=='\0'){
           return 0; 
        }
        if(str[start+m]!=pat[m]){
            return 0;
        }
        m++;
    }
    return 1;
} 

/* Function to replace pattern */ 

int replacePattern(char str[], char pat[], char rep[], char result[]) 
{ 
   int i=0;
   int j=0;
   int k;
   int flag=0;
   int patLength;
   patLength=getLength(pat);
   while(str[i]!='\0'){
       if(findPattern(str,pat,i)==1){
           flag=1;
           k=0;
           while(rep[k]!='\0'){
               result[j]=rep[k];
               j++;
               k++;
           }
           i=i+patLength;
       }
       else{
           result[j]=str[i];
           j++;
           i++;
       }
   }
   result[j]='\0';
   return flag;
} 

/* Function to display result */ 

void displayResult(int flag, char result[]) 
{ 
    if(flag==0){
        printf("Pattern does not exist");
    }
    else{
        printf("The main string after replacement is:\n");
        printf("%s",result);
    }
}
