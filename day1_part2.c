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
            char *calibTextValLine[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // harcoded values to use as substring

            for (int i = 0; oneFileLine[i] != '\0'; i++)
            {
                // check for values "one" through "nine"s
                for (int j = 0; j < 9; j++) 
                {
                    int wordLen = strlen(calibTextValLine[j]);

                    // check if the substring matches and can handle the overlapping values
                    if (strncmp(&oneFileLine[i], calibTextValLine[j], wordLen) == 0) 
                    {
                        strcat(var, (char[]){'1' + j, '\0'}); // concat the corresponding digit
                    }
                }

                if (isdigit(oneFileLine[i]))
                {
                    strncat(var, &oneFileLine[i], 1);
                }
            }

            calibValLine[0] = var[0];
            calibValLine[1] = var[strlen(var) - 1];

            calibValSum += atoi(calibValLine);
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