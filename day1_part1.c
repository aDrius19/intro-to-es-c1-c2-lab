#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARRAY_VAL 256

int calibValSum = 0;

int main()
{
    FILE *inputFile;
    inputFile = fopen("day1_part1.txt", "r"); // put the input into a file

    if (inputFile != NULL)
    {
        char oneFileLine[MAX_ARRAY_VAL] = "";
        while (fgets(oneFileLine, sizeof(oneFileLine), inputFile)) // loops until the last line from the file
        {
            char var[MAX_ARRAY_VAL] = "";
            char calibValLine[MAX_ARRAY_VAL] = "";

            for (int i = 0; oneFileLine[i] != '\0'; i++)
            {
                char ch = oneFileLine[i]; //go char by char
                if (isdigit(ch))
                {
                    strncat(var, &ch, 1); //add the char to the var array
                }
            }

            calibValLine[0] = var[0]; //take the first element
            calibValLine[1] = var[strlen(var) - 1]; //take the last element

            calibValSum += atoi(calibValLine); //sum all of the parts corresponding to each line
        }
        fclose(inputFile);
    }
    else
    {
        printf("Couldn't open file\n");
    }

    printf("%d\n", calibValSum);

    return 0;
}