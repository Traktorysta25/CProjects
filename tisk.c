#include <stdio.h>
#include "tisk.h"
#include "zakladni_operace.h"

void printf_fprintf_function(int c, int r, float matice[c][r])
{
    FILE* history = fopen("history.txt", "a");
 
    for (int i = 0; i < c; i++)               // cyklus pro fprintf ( do historie)
    {
        for (int j = 0; j < r; j++) 
        {
            fprintf(history, "%.1f  ", matice[i][j]);    // 1.1
        }
        fprintf(history, "\n\n");
    }
    fprintf(history, "\n");
    fclose(history);

    for (int i = 0; i < c; i++)         // cyklus pro printf do terminalu
    {
        for (int j = 0; j < r; j++) 
        {
            printf("%.1f  ", matice[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}