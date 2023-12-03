#include <stdio.h>
#include "tisk.h"
#include "zakladni_operace.h"
#include "ostatni_operace.h"


float determinant(int c, int r, float m[c][r])
{
    float result;
    if (c == 2 && r == 2)
    {
        result = m[0][0]*m[1][1] - m[0][1]*m[1][0];
        return result;
    }
    else if (c == 3 && r == 3)
    {
        result = (m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1]) - (m[0][2]*m[1][1]*m[2][0] + m[0][1]*m[1][0]*m[2][2] + m[0][0]*m[1][2]*m[2][1]);
        return result;    
    }
    else if(c == 4 && r == 4)
    {
            float rozklad_radka1[3][3] =
        {
            {m[1][1], m[1][2], m[1][3]},
            {m[2][1], m[2][2], m[2][3]},
            {m[3][1], m[3][2], m[3][3]}
        };

        float determinant1 = (rozklad_radka1[0][0]*rozklad_radka1[1][1]*rozklad_radka1[2][2] + rozklad_radka1[0][1]*rozklad_radka1[1][2]*rozklad_radka1[2][0] + rozklad_radka1[0][2]*rozklad_radka1[1][0]*rozklad_radka1[2][1]) - (rozklad_radka1[0][2]*rozklad_radka1[1][1]*rozklad_radka1[2][0] + rozklad_radka1[0][1]*rozklad_radka1[1][0]*rozklad_radka1[2][2] + rozklad_radka1[0][0]*rozklad_radka1[1][2]*rozklad_radka1[2][1]);

        float rozklad_radka2[3][3] =
        {
            {m[1][0], m[1][2], m[1][3]},
            {m[2][0], m[2][2], m[2][3]},
            {m[3][0], m[3][2], m[3][3]}
        };

        float determinant2 = (rozklad_radka2[0][0]*rozklad_radka2[1][1]*rozklad_radka2[2][2] + rozklad_radka2[0][1]*rozklad_radka2[1][2]*rozklad_radka2[2][0] + rozklad_radka2[0][2]*rozklad_radka2[1][0]*rozklad_radka2[2][1]) - (rozklad_radka2[0][2]*rozklad_radka2[1][1]*rozklad_radka2[2][0] + rozklad_radka2[0][1]*rozklad_radka2[1][0]*rozklad_radka2[2][2] + rozklad_radka2[0][0]*rozklad_radka2[1][2]*rozklad_radka2[2][1]);

        float rozklad_radka3[3][3] =
        {
            {m[1][0], m[1][1], m[1][3]},
            {m[2][0], m[2][1], m[2][3]},
            {m[3][0], m[3][1], m[3][3]}
        };

        float determinant3 = (rozklad_radka3[0][0]*rozklad_radka3[1][1]*rozklad_radka3[2][2] + rozklad_radka3[0][1]*rozklad_radka3[1][2]*rozklad_radka3[2][0] + rozklad_radka3[0][2]*rozklad_radka3[1][0]*rozklad_radka3[2][1]) - (rozklad_radka3[0][2]*rozklad_radka3[1][1]*rozklad_radka3[2][0] + rozklad_radka3[0][1]*rozklad_radka3[1][0]*rozklad_radka3[2][2] + rozklad_radka3[0][0]*rozklad_radka3[1][2]*rozklad_radka3[2][1]);

        float rozklad_radka4[3][3] =
        {
            {m[1][0], m[1][1], m[1][2]},
            {m[2][0], m[2][1], m[2][2]},
            {m[3][0], m[3][1], m[3][2]}
        };

        float determinant4 = (rozklad_radka4[0][0]*rozklad_radka4[1][1]*rozklad_radka4[2][2] + rozklad_radka4[0][1]*rozklad_radka4[1][2]*rozklad_radka4[2][0] + rozklad_radka4[0][2]*rozklad_radka4[1][0]*rozklad_radka4[2][1]) - (rozklad_radka4[0][2]*rozklad_radka4[1][1]*rozklad_radka4[2][0] + rozklad_radka4[0][1]*rozklad_radka4[1][0]*rozklad_radka4[2][2] + rozklad_radka4[0][0]*rozklad_radka4[1][2]*rozklad_radka4[2][1]);        
        
        result = m[0][0]*determinant1 - m[0][1]*determinant2 + m[0][2]*determinant3 - m[0][3]*determinant4;

        return result;
    }
}

void transpozice(int c, int r, float m[c][r])
{
    float t_m[r][c];

    for (int i = 0; i < c; i++)            // cyklus transpozice
    {
        for (int j = 0; j < r; j++)
        {
            t_m[j][i] = m[i][j];  /
        }
    }
    
    printf_fprintf_function(r, c, t_m);
}