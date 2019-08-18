#include <stdio.h>
#include <stdlib.h>

int main()
{
    char file_name[25];
    char *c = NULL;
    size_t len = 0;
    FILE *fptr;
    ssize_t read;

    int counter = 0;

    printf("Enter file name to be read\n");
    gets(file_name);
    if ((fptr = fopen(file_name, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
    // reads text until newline 
    printf("Data from the file:\n");

//    while((c=fgetc(fp)))


    while ((read = getline(&c, &len, fptr)) != -1) {
        printf("Retrieved line of length %d:", counter);
        printf("%s", c);
        counter++;
    }

    fclose(fptr);
    
    return 0;
}
