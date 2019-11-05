#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double equation(double x);

double rez[2][8001], rez1[2][8001];
int j = 0;

int main()
{

    double t_rez;
    // ================= Array generator ======================
    for (double i = -4; i < 4; i += 0.001)
    {

        rez[0][j] = i;
        rez[1][j] = equation(i);

        j++;
    }

    // ============ Array copy ================================
    for (int i = 0; i < 2; i++)
        for (int k = 0; k < j - 1; k++)
            rez1[i][k] = rez[i][k];

    // =================== Sorting ============================
    for (int i = 0; i < j - 2; i++)
    {
        for (int k = i + 1; k < j - 1; k++)
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

    for (int k = 0; k < j-1; k++)
    {
        printf("%lf %lf\n", rez1[0][k], rez1[1][k]);
        // printf("%lf %lf\n", rez[0][k], rez[1][k]);
    }

    // printf("%lf %lf \n", rez1[0][0], rez1[1][0]);
    //  printf("%d", j);
    return 0;
}

double equation(double x)
{
    double y;
    y = -(pow(x, 4)) + 3 * pow(x, 3) + 2 * pow(x, 2) - 5 * x + 0.5;

    return y;
}