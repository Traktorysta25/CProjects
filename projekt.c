#include <stdio.h>
#include "tisk.h"
#include "zakladni_operace.h"
#include "ostatni_operace.h"
#include "bonus.h"

void main()
{
    FILE* history = fopen("history.txt", "w");   //přepis historie
    fclose(history);

    int C1 = 0;    // kolik sloupců
    int C2 = 0;
    int R1 = 0;    // kolik řadků
    int R2 = 0;

    char operace = '0';     // aktualni operace

    printf("\nvyberete operace:\n\n(+) - scitani\n(-) - odcitani\n(*) - nasobeni\ns - skalarni soucin\nd - determinant\nt - transpozice\nh - hodnost\ni - inverzni matice\ne - exit\n\n:");   // seznam operaci

    while (operace != 'e')
    {
        if (operace == '+')
        {
            while (1)   // kontrola na spravne hodnoty
            {
                printf("\n\n1)Vyberete rozmer prvni matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                printf("\n2)Vyberete rozmer druhou matice(columns rows): ");
                scanf("%d %d", &C2, &R2);
                getchar();

                if (C1 == 0 && C2 == 0 || R1 == 0 || R2 == 0)  //  kontrola na pismeno 
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || C2 > 5 || R1 > 5 || R2 > 5)  // kontrola na rozmer
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else if (C1 != C2 && R1 != R2)           // pokud rozmer neni strejny 
                    {
                        printf("\n- matice musi byt stejneho rozmeru\n"); 
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m1[C1][R1];      // zadavame prvni matice
            float m2[C2][R2];      // zadavame druhou matice
            
            printf("\nzadejte prvni matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)         // ciklus pro zadavani hodot prvni matice
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m1[i][j]);
                }
            }

            printf("\nzadejte druhou matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)       // ciklus pro zadavani hodot druhou matice
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m2[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");    // print vysledek do historie
            fprintf(history, "nvysledek scitani:\n\n");
            fclose(history);
           
            printf("\nvysledek scitani:\n\n");      // print vysledek do terminalu
           
            scitani(C1, R1, m1, m2);      // volani funkce scitani
            printf(":");
        }

        else if (operace == '-')
        {
            while (1)
            {
                printf("\n\n1)Vyberete rozmer prvni matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                printf("\n2)Vyberete rozmer druhou matice(columns rows): ");
                scanf("%d %d", &C2, &R2);
                getchar();
                if(C1 == 0 || C2 == 0 || R1 == 0 || R2 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || C2 > 5 || R1 > 5 || R2 > 5)
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else if (C1 != C2 && R1 != R2)
                    {
                        printf("\n- matice musi byt stejneho rozmeru\n"); 
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m1[C1][R1];
            float m2[C2][R2];

            printf("\nzadejte prvni matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m1[i][j]);
                }
            }

            printf("\nzadejte druhou matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m2[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "nvysledek odcitani:\n\n");
            fclose(history);
            
            printf("\nvysledek odcitani:\n\n");  
            
            odcitani(C1, R1, m1, m2);  // volame odecitani (zakladni operace header) 
            printf(":");
        }
        else if (operace == '*')
        {
            while (1)
            {
                printf("\n\n1)Vyberete rozmer prvni matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                printf("\n2)Vyberete rozmer druhou matice(columns rows): ");
                scanf("%d %d", &C2, &R2);
                getchar();
                if(C1 == 0 || C2 == 0 || R1 == 0 || R2 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || C2 > 5 || R1 > 5 || R2 > 5)
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else if (C1 != R2 || C2 != R1)
                    {
                        printf("\n- pocet sloupcu prvni matice se musi rovnat poctu radku druhe matice  a naopak\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m1[C1][R1];
            float m2[C2][R2];

            printf("\nzadejte prvni matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m1[i][j]);
                }
            }

            printf("\nzadejte druhou matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C2; i++)
            {
                for (int j = 0; j < R2; j++)
                {
                    scanf("%f", &m2[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "nvysledek nasobeni:\n\n");
            fclose(history);
           
            printf("\nvysledek nasobeni:\n\n");  
           
            nasobeni(C1, R1, C2, R2, m1, m2); 
            printf(":");
        }
        else if (operace == 't')
        {
            while (1)
            {
                printf("\n\nVyberete rozmer matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                if(C1 == 0 || R1 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || R1 > 5)
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m[C1][R1];

            printf("\nzadejte matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "nvysledek transpozice:\n\n");
            fclose(history);

            printf("\nvysledek transpozice:\n\n");  
           
            transpozice(C1, R1, m);
    
            printf(":");
        }
        else if (operace == 's')
        {
            while (1)
            {
                printf("\n\nVyberete rozmer matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                if(C1 == 0 || R1 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || R1 > 5)
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m[C1][R1];

            printf("\nzadejte matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m[i][j]);
                }
            }

            float s;

            printf("\nzadejte skalar: ");
            scanf("%f", &s);

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "nvysledek skalarniho soucinu:\n\n");
            fclose(history);

            printf("\nvysledek skalarni soucin:\n\n");  
           
            skalar(C1, R1, s, m);    // volame funkce skalaru
            printf(":");
        }
        else if (operace == 'd')
        {
            while (1)
            {
                printf("\n\n1)Vyberete rozmer prvni matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                printf("\n2)Vyberete rozmer druhou matice(columns rows): ");
                scanf("%d %d", &C2, &R2);
                getchar();
                if(C1 == 0 || C2 == 0 || R1 == 0 || R2 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 5 || C2 > 5 || R1 > 5 || R2 > 5)
                    {
                        printf("\n- maximalni rozmer: 5x5\n");
                    }
                    else if (C1 != R1)
                    {
                        printf("\n- matice neni kvadraticka\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m[C1][R1];

            printf("\nzadejte matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "\ndeterminant je:\n\n");
            fclose(history);

            printf("\ndeterminant je:\n\n");  
           
            printf("%.1f\n\n", determinant(C1, R1, m));     // volani determinantu
            printf(":");
        }
        else if (operace == 'h')
        {
            while (1)
            {
                printf("\n\nVyberete rozmer matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                if(C1 == 0 ||  R1 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 4 ||  R1 > 4)
                    {
                        printf("\n- maximalni rozmer: 4x4\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m[C1][R1];  // rozmer = C1, R1

            printf("\nzadejte matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "\nrank je:\n\n%d\n\n", rank(C1, R1, m));
            fclose(history);
           
            printf("\nrank je:\n\n%d\n\n", rank(C1, R1, m));     // volame funkce rank (hodnost matice)
            printf(":");
        }
        else if (operace == 'i')
        {
            while (1)
            {
                printf("\n\nVyberete rozmer matice(columns rows): ");
                scanf("%d %d", &C1, &R1);
                getchar();
                if(C1 == 0 ||  R1 == 0)
                {
                    printf("\n- napiste cislo\n");
                }
                else
                {
                    if(C1 > 4 ||  R1 > 4)
                    {
                        printf("\n- maximalni rozmer: 4x4\n");
                    }
                    else if (C1 != R1)
                    {
                        printf("\n- matice neni kvadraticka\n");
                    }
                    else
                    {
                        break;
                    }
                }
            }

            float m[C1][R1];

            printf("\nzadejte matice (1 2 3 4 5 'shift enter' 6 7 8 9 10 'shift enter'...):\n");
            for (int i = 0; i < C1; i++)
            {
                for (int j = 0; j < R1; j++)
                {
                    scanf("%f", &m[i][j]);
                }
            }

            FILE* history = fopen("history.txt", "a");
            fprintf(history, "\ninversni matice je:\n");
            fclose(history);
           
            printf("\ninversni matice je:\n\n");

            inverse(C1, m);   // volame funkce inverse (inverzni matice)

            printf(":");              
        }

        scanf("%c", &operace);
    }
}