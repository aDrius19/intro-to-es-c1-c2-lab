#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MULT 17
#define MOD 256
#define MAX_ARRAY_VAL 30000

int totalSteps = 0;

int main()
{
    FILE *inputFile;
    inputFile = fopen("day15_part1.txt", "r"); // put the input into a file

    if (inputFile != NULL)
    {
        char oneFileLine[MAX_ARRAY_VAL] = {}; //big allocation for one line imput
        char *token;
        while (fgets(oneFileLine, sizeof(oneFileLine), inputFile)) // loops until the last line from the file
        {

            token = strtok(oneFileLine, ","); //delimitate the input into tokens
        }

        while (token != NULL)
        {
            int currentValue = 0; //do the HASH algorithm

            for (int i = 0; token[i] != '\0'; i++) //loop for each token
            {
                char ch = token[i]; // go char by char from each token
                currentValue += (int)ch;
                currentValue *= MULT;
                currentValue %= MOD;
            }
            totalSteps += currentValue; //total sum of each individual step

            token = strtok(NULL, ",");
        }
        printf("%d", totalSteps);
 
        fclose(inputFile);
    }
    else
    {
        printf("Couldn't open file\n");
    }

    return 0;
}