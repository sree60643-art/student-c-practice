#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char language[50];
    int year;
    float rating;
} Movie;

/* Function Prototypes */

int countMovies(char filename[]);
Movie* allocateMemory(int count);
void readMovies(char filename[], Movie *movies, int count);
void displayMoviesFromFile(char filename[], int n);
void sortMovies(Movie *movies, int count);
void writeMovies(char filename[], Movie *movies, int count);
void freeMemory(Movie **movies);

/* Main Function */

int main()
{
int count;
int n;
Movie*movies;
count=countMovies("IMDb_400_Movies1.csv");
movies=allocateMemory(count);
readMovies("IMDb_400_Movies1.csv",movies,count);
    printf("Enter how many movie records to display: ");
    scanf("%d",&n);
    if(n > count)
    {
        n = count;
    }
    printf("\nBefore Sorting:\n\n");
    displayMoviesFromFile("IMDb_400_Movies1.csv",n);
    sortMovies(movies,count);
    writeMovies("sorted_movies.csv",movies,count);
    printf("\nAfter Sorting:\n\n");
    displayMoviesFromFile("sorted_movies.csv",n);
    printf("\nSorted movie data stored successfully.\n");
    freeMemory(&movies);
    return 0;
}

/* Function Definitions */

int countMovies(char filename[])
{
   FILE*fp;
   char line[200];
   int lines=0;
   fp=fopen(filename,"r");
   if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    while(fgets(line,sizeof(line),fp)!=NULL){
        lines++;
    }
    fclose(fp);
    return lines-1;
}

Movie* allocateMemory(int count)
{
    Movie*movies;
    movies=(Movie*)malloc(count*sizeof(Movie));
    if(movies==NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return movies;
}

void readMovies(char filename[], Movie *movies, int count)
{
    FILE*fp;
    int i;
    char header[200];
    fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    fgets(header,sizeof(header),fp);
    for(i=0;i<count;i++){
        fscanf(fp," %99[^,],%49[^,],%d,%f",movies[i].name,movies[i].language,&movies[i].year,&movies[i].rating);
    }
    fclose(fp);
}

void displayMoviesFromFile(char filename[], int n)
{
FILE*fp;
int i;
Movie movie;
char header[200];
fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("File cannot be opened\n");
        exit(1);
    }
    fgets(header,sizeof(header),fp);
for(i=0;i<n;i++)
    {
        fscanf(fp," %99[^,],%49[^,],%d,%f",movie.name,movie.language,&movie.year,&movie.rating);
        printf("%s | %s | %d | %.1f\n",movie.name,movie.language,movie.year,movie.rating);
    }
    fclose(fp);
}

void sortMovies(Movie *movies, int count)
{
Movie temp;
int i,j;
for(i=0;i<count-1;i++){
    for(j=0;j<count-i-1;j++){
        if(strcmp(movies[j].name,movies[j+1].name)>0){
            temp=movies[j];
            movies[j]=movies[j+1];
            movies[j+1]=temp;
        }
    }
}
}

void writeMovies(char filename[], Movie *movies, int count)
{
    FILE*fp;
    int i;
    fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("Cannot create output file\n");
        exit(1);
    }
    fprintf(fp, "Movie Name,Language,Year,Rating\n");
    for(i=0;i<count;i++){
        
        fprintf(fp , "%s,%s,%d,%.1f\n",movies[i].name,movies[i].language,movies[i].year,movies[i].rating);
   }
 fclose(fp);
}

void freeMemory(Movie **movies)
{
free(*movies);
*movies=NULL;
}
