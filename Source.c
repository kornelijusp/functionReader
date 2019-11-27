/**
 * @file Source.c
 * @author Kornelijus Petronis
 * @brief 
 * @version 1.5.3
 * @date 2019-11-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *fi;

/**
 * @brief Math function
 * 
 * @param x 
 * @return double 
 */
double equation(double x);

double **createArray(double **arrayName, int row, int column);

// void Search(int index, double t_rez, double **rez);

int j = 0;

int main()
{
    //===================================
    double t_rez, y;
    int index, t_index, i_begin, i_end;
    // Array -----------
    double **rez, **rez1;
    // **rez = all x & y values
    // **rez1 = only x & y values then y is above 0 and this array have maximum point
    //===================================

    // Dinamic array
    /**
     * @brief Dinamic array 1
     */

    rez = createArray(rez, 2, 8001);

    // ================= Array generator ======================
    /**
     * @brief Calculate y value
     */
    // ==========================================
    double i = -4;

    while (i < 4)
    {
        rez[0][j] = i;
        rez[1][j] = equation(i);

        j++;
        i += 0.001;
    }

    // === Searching maximum number ===========================

    // Search(index, t_rez, rez);

    /**
//      * @brief Searching maximum number
//      * 
//      */
    t_rez = rez[1][0];

    for (int i = 1; i < j - 2; i++)
    {

        if (rez[1][i] > t_rez)
        {
            t_rez = rez[1][i];
            index = i;
        }
    }
    fi = fopen("Maximum.txt", "w");

    fprintf(fi, "Maximum y number\nx          y\n%lf %lf\n\n", rez[0][index], rez[1][index]);

    fclose(fi);

    // ==== Array copy only positive numbers with m aximum number in it =====
    // Searching index begin and end
    /**
     * @brief Searching for segment of positive values which the maximum number.
     * 
     */
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
    /**
     * @brief Dinamic array 2
     * 
     */
    rez1 = createArray(rez, 2, i_end - i_begin + 1);

    // Create new array
    /**
     * @brief Creating new array
     * 
     */
    for (int i = 0; i <= (i_end - i_begin); i++)
    {
        rez1[0][i] = rez[0][i_begin + i];
        rez1[1][i] = rez[1][i_begin + i];
    }

    // =================== Sorting ============================
    /**
     * @brief Sorting algorithm
     * from smallest to biggest
     * 
     */
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
    /**
     * @brief Print loop
     * From smallest to biggest
     * 
     */
    fi = fopen("Array.txt", "w");

    for (int k = 0; k <= (i_end - i_begin); k++)
        fprintf(fi, "%lf %lf\n", rez1[0][k], rez1[1][k]);

    fclose(fi);

    /** 
     * @brief Construct a new free object
     */
    free(rez);
    free(rez1);

    return 0;
}

double equation(double x)
{
    return -(pow(x, 4)) + 3 * pow(x, 3) + 2 * pow(x, 2) - 5 * x + 0.5;
}

//===================================================================================
// Dinamic array
double **createArray(double **arrayName, int row, int column)
{
    arrayName = (double **)malloc(row * sizeof(double *));

    for (int i = 0; i < 2; i++)
        arrayName[i] = (double *)malloc(column * sizeof(double));

    return arrayName;
}

// === Searching maximum number ===========================
// void Search(int index, double t_rez, double **rez)
// {
//     /**
//      * @brief Searching maximum number
//      *
//      */
//     t_rez = rez[1][0];

//     for (int i = 1; i < j - 2; i++)
//     {

//         if (rez[1][i] > t_rez)
//         {
//             t_rez = rez[1][i];
//             index = i;
//         }
//     }
//     fi = fopen("Maximum.txt", "w");

//     fprintf(fi, "Maximum y number\nx          y\n%lf %lf\n\n", rez[0][index], rez[1][index]);

//     fclose(fi);
// }
//====================================================================================
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