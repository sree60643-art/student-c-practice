#include <stdio.h>
#include <string.h>

/* Structure Definition */
typedef struct{
    int flight_number;
    char Destination[50];
    int available_seats;
}Flight;


/* Function Prototypes */
void input_flights(int n, Flight flights[n]);
int search_flights(int n, Flight flights[n], char destination[], int result[]);
void display(int count, int result[], Flight flights[]);

int main()
{
    int n=4;
    Flight flights[n];
    input_flights(n,flights);
    char destination[50];
    printf("\nEnter destination to search: ");
    scanf("%s",destination);
    int count;
    int result[4];
    count=search_flights(n,flights,destination,result);
    display(count,result,flights);

    return 0;
}

/* Function to input flight details */
void input_flights(int n, Flight flights[n])
{
    for(int i=0;i<n;i++){
        printf("\nEnter details of flight %d\n",i+1);

        printf("Enter flight number: ");
        // write code
        scanf("%d",&flights[i].flight_number);

        printf("Enter destination: ");
        // write code
        scanf("%s",flights[i].Destination);

        printf("Enter available seats: ");
        // write code
        scanf("%d",&flights[i].available_seats);
        printf("\n");
    }
}

/* Function to search flights */
int search_flights(int n, Flight flights[n], char destination[], int result[])
{
    
        // write condition using strcmp
        // store index in result[count]
        int count=0;
        for(int i=0;i<n;i++){
            if(strcmp(flights[i].Destination,destination)==0){
            result[count]=i;
            count++;
            }
        }
return count;
}

/* Function to display result */
void display(int count, int result[], Flight flights[])
{
    if(count==0){
   printf("No flight available to the given destination\n");
    }
    else
        printf("Flights available:\n");
        for(int i=0;i<count;i++){
            int idx=result[i];
        printf("Flight Number: %d\n",flights[idx].flight_number );
        }

}
