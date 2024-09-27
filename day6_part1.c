#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 64
#define ENTRY_POINTS 4

int main()
{
    char* token;
    char buffer[BUFFER_SIZE];

    if (!fgets(buffer, sizeof(buffer), stdin) || !strtok(buffer, " "))
    {
        return 1;
    }

    int pointCount = 0;
    int time[ENTRY_POINTS];
    int distance[ENTRY_POINTS];

    while ((token = strtok(NULL, " ")))
    {
        time[pointCount] = atoi(token);
        pointCount++;
    }

    if (!fgets(buffer, sizeof(buffer), stdin) || !strtok(buffer, " "))
    {
        return 1;
    }

    for (int i = 0; i < pointCount; i++)
    {
        token = strtok(NULL, " ");

        distance[i] = atoi(token);
    }

    long result = 1;

    for (int i = 0; i < pointCount; i++)
    {
        int t = time[i];
        int dx = distance[i];

        result *= ceil((t + sqrt(t * t - 4 * dx)) / 2)
            - floor((t - sqrt(t * t - 4 * dx)) / 2)
            - 1;
    }

    printf("The result is: %ld\n", result);

    return 0;
}