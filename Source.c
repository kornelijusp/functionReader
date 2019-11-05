#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double equation(double x);

double rez[2][8000];
int j = 0;

int main()
{

    for (double i = -4; i < 4; i += 0.001)
    {
        // printf("%lf \n", equation(i));
        rez[0][j] = i;
        rez[1][j] = equation(i);

        j++;
    }

    for (int k = 0; k < j; k++)
    {
        printf("%lf %lf\n", rez[0][k], rez[1][k]);
    }

    return 0;
}

double equation(double x)
{
    double y;
    y = -(pow(x, 4)) + 3 * pow(x, 3) + 2 * pow(x, 2) - 5 * x + 0.5;

    return y;
}