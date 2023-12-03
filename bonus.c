#include <stdio.h>
#include <math.h>
#include "bonus.h"
#include "tisk.h"
#include "zakladni_operace.h"
#include "ostatni_operace.h"

int rank(int c, int r, float m[c][r]) // funkce hodnosti matice
{
    int rank = 0;

    for (int col1 = 0; col1 < c; col1++)
    {
        for (int col2 = 0; col2 < c; col2++)
        {
            for (int col3 = 0; col3 < c; col3++)
            {
                for (int row1 = 0; row1 < r; row1++)
                {
                    for (int row2 = 0; row2 < r; row2++)
                    {
                        for (int row3 = 0; row3 < r; row3++)
                        {
                            if (rank == 0 && c >= 1 && r >= 1)
                            {
                                if (m[row2][row3] != 0)
                                {
                                    rank = 1;
                                }
                            }

                            if (rank == 1 && c >= 2 && r >= 2)
                            {
                                float minor2x2[2][2]=
                                {
                                {m[col2][row2], m[col2][row3]},
                                {m[col3][row2], m[col3][row3]}
                                };

                                if (determinant(2, 2, minor2x2) != 0)
                                {
                                    rank = 2;
                                }    
                            }
                            
                            if (rank == 2 && c >= 3 && r >= 3)
                            {
                                float minor3x3[3][3]=
                                {
                                {m[col1][row1], m[col1][row2], m[col1][row3]},
                                {m[col2][row1], m[col2][row2], m[col2][row3]},
                                {m[col3][row1], m[col3][row2], m[col3][row3]}
                                };

                                if (determinant(3, 3, minor3x3) != 0)
                                {
                                    rank = 3;
                                }
                            }

                            if (rank == 3 && c == 4 && r == 4)
                            {
                                if (determinant(4, 4, m) !=0)
                                {
                                    rank = 4;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return rank; 
}

void inverse(int n, float m[n][n])
{ 
    int c = (n-1);  // c = 3
    int r = (n-1);  // r = 3 

    float alg_dop_m[n][n];   //algebraicke dopolneni matice m

    float t_alg_dop_m[n][n];

    if (determinant(n, n, m) == 0)
    {
        printf("neexistuje inverze");
    }
    else if(determinant(n, n, m) != 0 && n == 4)
    {
        for (int col1 = 0; col1 < n; col1++)   // n = 4
        {
            for (int col2 = col1+1; col2 < n; col2++)
            {
                for (int col3 = col2+1; col3 < n; col3++)
                {
                    for (int row1 = 0; row1 < n; row1++)
                    {
                        for (int row2 = row1+1; row2 < n; row2++)
                        {
                            for (int row3 = row2+1; row3 < n; row3++)
                            {
                                if (n == 4)
                                {
                                    float minor3x3[3][3]=                        // 16 iterace   
                                    {
                                        {m[col1][row1], m[col1][row2], m[col1][row3]},
                                        {m[col2][row1], m[col2][row2], m[col2][row3]},
                                        {m[col3][row1], m[col3][row2], m[col3][row3]}
                                    }; 
                                    if (r > -1)
                                    {
                                        alg_dop_m[c][r] = (pow(-1, c+r)) * (determinant(n-1, n-1, minor3x3));
                                        r--;   
                                    }
                                    else
                                    {
                                        c--;
                                        r = n-1;
                                        alg_dop_m[c][r] = (pow(-1, c+r) * determinant(n-1, n-1, minor3x3));
                                        r--;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    else if (determinant(n, n, m) != 0 && n == 3)
    {
        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = col1+1; col2 < n; col2++)
            {
                for (int row1 = 0; row1 < n; row1++)
                {
                    for (int row2 = row1+1; row2 < n; row2++)    // 9 iteraci
                    {
                        float minor2x2[2][2]=
                        {
                            {m[col1][row1], m[col1][row2]},
                            {m[col2][row1], m[col2][row2]}
                        };

                        if (r > -1)
                        {
                            alg_dop_m[c][r] = (pow(-1, c+r)) * (determinant(2, 2, minor2x2));
                            r--;
                        }
                        else
                        {
                            c--;
                            r = n-1;
                            alg_dop_m[c][r] = (pow(-1, c+r) * (determinant(2, 2, minor2x2)));
                            r--;
                        }
                    }
                }
            }
        }
    }
    else if (determinant(n, n, m) != 0 && n == 2)
    {
        alg_dop_m[0][0] = m[1][1];
        alg_dop_m[0][1] = -1 * m[1][0];
        alg_dop_m[1][0] = -1 * m[0][1];
        alg_dop_m[1][1] = m[0][0];
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
             [j][i] = alg_dop_m[i][j];         // transponujeme alg_dop_m 
        }
    }

    float s = (1/(determinant(n, n, m)));      // skalar
    
    float inverzniM[n][n];  // co hledame

    for (int i = 0; i < n; i++)                 //funkce skalaru
    {
        for (int j = 0; j < n; j++)
        {
            inverzniM[i][j] = s * t_alg_dop_m[i][j];  // vysledek funkce
        }
    }

// konec vypoctu inverzni matice


    FILE* history = fopen("history.txt", "a");          // tisk bez omezeni symbolu po carky

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fprintf(history, "%f  ", inverzniM[i][j]);
        }
        fprintf(history, "\n\n");
    }
    fprintf(history, "\n");
    fclose(history);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%f  ", inverzniM[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}