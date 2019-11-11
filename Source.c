#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double equation(double x);

int j = 0;

int main()
{
    double t_rez, y;
    int index, t_index, i_begin, i_end;

    // Dinamic array
    double **rez = (double **)malloc(2 * sizeof(double *));
    for (int i = 0; i < 2; i++)
        rez[i] = (double *)malloc(8001 * sizeof(double));

    // ================= Array generator ======================
    for (double i = -4; i < 4; i += 0.001)
    {
        rez[0][j] = i;
        rez[1][j] = equation(i);

        j++;
    }

    // === Searching maximum number ===========================
    t_rez = rez[1][0];

    for (int i = 1; i < j - 2; i++)
    {

        if (rez[1][i] > t_rez)
        {
            t_rez = rez[1][i];
            index = i;
        }
    }
    printf("Maximum y number\nx          y\n%lf %lf\n\n", rez[0][index], rez[1][index]);

    // ==== Array copy only positive numbers with maximum number in it =====
    // Searching index begin and end
    t_index = index;
    while (1)
    {
        if (rez[1][t_index - 1] < 0)
            break;

        i_begin = t_index;
        t_index--;
    }

    t_index = index;
    while (1)
    {
        if (rez[1][t_index + 1] < 0)
            break;

        i_end = t_index;
        t_index++;
    }
    // ------------------------------------------------------------
    // Dinamic array
    double **rez1 = (double **)malloc(2 * sizeof(double *));
    for (int i = 0; i < 2; i++)
        rez1[i] = (double *)malloc((i_end - i_begin + 1) * sizeof(double));

    // Create new array
    for (int i = 0; i <= (i_end - i_begin); i++)
    {
        rez1[0][i] = rez[0][i_begin + i];
        rez1[1][i] = rez[1][i_begin + i];
    }

    // =================== Sorting ============================
    for (int i = 0; i <= (i_end - i_begin) - 1; i++)
    {
        for (int k = i + 1; k <= (i_end - i_begin); k++)
        {
            if (rez1[1][i] > rez1[1][k])
            {
                t_rez = rez1[1][i];
                rez1[1][i] = rez1[1][k];
                rez1[1][k] = t_rez;

                t_rez = rez1[0][i];
                rez1[0][i] = rez1[0][k];
                rez1[0][k] = t_rez;
            }
        }
    }

    // =================== Print ===============================
    for (int k = 0; k <= (i_end - i_begin); k++)
    {
        printf(" %lf %lf\n", rez1[0][k], rez1[1][k]);
        // printf("%lf %lf\n", rez[0][k], rez[1][k]);
    }

    free(rez);
    free(rez1);

    return 0;
}

double equation(double x)
{
    double y;
    y = -(pow(x, 4)) + 3 * pow(x, 3) + 2 * pow(x, 2) - 5 * x + 0.5;

    return y;
}

/*
begin 5112 | end 7145

2033

x = rez[0][5112] = 1.112000 
y = rez[1][5112] = 0.009158

x = rez[0][7145] = 3.145000 
y = rez[1][7145] = 0.046495

Maximum
rez[0][6450]=2.450000
rez[1][6450]=8.343369


*/