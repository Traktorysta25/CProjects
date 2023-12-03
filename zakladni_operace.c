#include <stdio.h>
#include "tisk.h"
#include "zakladni_operace.h"
#include "ostatni_operace.h"


void scitani(int c, int r, float m1[c][r], float m2[c][r])
{
    float result[c][r];

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf_fprintf_function(c, r, result);
}

void odcitani(int c, int r, float m1[c][r], float m2[c][r])
{
    float result[c][r];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    printf_fprintf_function(c, r, result);
}

void nasobeni(int c1, int r1, int c2, int r2, float m1[c1][r1], float m2[c2][r2])
{   
    float sum;
    float result[c1][c1];
    
    for (int i = 0; i < c1; i++)                                            
    {
        for (int j = 0; j < c1; j++)                                         
        {
            sum = 0;   
            for (int k = 0; k < r1; k++)                                      
            {
                sum += m1[i][k] * m2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf_fprintf_function(c1, c1, result);
}

void skalar(int c, int r, float s, float m[c][r])
{
    float result[c][r];

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            result[i][j] = s * m[i][j];
        }
    }

    printf_fprintf_function(c, r, result);
}