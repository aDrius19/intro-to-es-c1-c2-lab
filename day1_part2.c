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
            char c1[MAX_ARRAY_VAL] = "";
            char *calibTextValLine[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //harcoded values to use as substring
            printf("\n%s", oneFileLine);

            for (int i = 0; oneFileLine[i] != '\0'; i++)
            {
                char ch = oneFileLine[i];
                c1[i] = oneFileLine[i];

                if (strstr(c1, calibTextValLine[0]) != NULL) //a little boilerplate, unfortunately, for finding the occurence of the "digits"
                {
                    strcat(var, "1"); //add the corresponding digit to the var array
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[1]) != NULL) 
                {
                    strcat(var, "2");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[2]) != NULL) 
                {
                    strcat(var, "3");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[3]) != NULL) 
                {
                    strcat(var, "4");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[4]) != NULL) 
                {
                    strcat(var, "5");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[5]) != NULL) 
                {
                    strcat(var, "6");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[6]) != NULL) 
                {
                    strcat(var, "7");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[7]) != NULL) 
                {
                    strcat(var, "8");
                    memset(c1, ' ', sizeof(c1));
                }else if ( strstr(c1, calibTextValLine[8]) != NULL) 
                {
                    strcat(var, "9");
                    memset(c1, ' ', sizeof(c1));
                }

                if (isdigit(ch))
                {
                    strncat(var, &ch, 1);
                }
            }

            calibValLine[0] = var[0];
            calibValLine[1] = var[strlen(var) - 1];

            calibValSum += atoi(calibValLine);
            printf("%s\n", calibValLine);
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