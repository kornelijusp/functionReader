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

// Library
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// File
FILE *fi;

// X limits
#define x_begin -4
#define x_end 4

// Function list
void Generate(double i, int end, double **rez);
double equation(double x);
double **createArray(double **arrayName, int row, int column);
void Search(int *index, double **rez);
void findArrWithMax(int index, double **rez, int *i_begin, int *i_end);
void createArrWithMax(int *i_begin, int *i_end, double **rez, double **rez1);
void Sorting(int *i_begin, int *i_end, double **rez, double **rez1);
void printArr(int i_begin, int i_end, double **rez, double **rez1);

int j = 0;
// =============================================================================================================
int main()
{
    /// Variables
    double t_rez, y;
    int index, t_index, i_begin, i_end;
    // Array -----------
    double **rez, **rez1;
    // **rez = all x & y values
    // **rez1 = only x & y values then y is above 0 and this array have maximum point
    // ----------------------------------------------------------------------------------

    // Dinamic array1
    rez = createArray(rez, 2, 8001);

    // ================= Array generator ======================
    Generate(x_begin, x_end, rez);

    // === Searching maximum number ===========================
    Search(&index, rez);

    // ==== Array copy only positive numbers with m aximum number in it =====
    // Searching index begin and end
    /**
     * @brief Searching for segment of positive values which the maximum number.
     * 
     */
    findArrWithMax(index, rez, &i_begin, &i_end);

    // ----------------------------------------------------------------------------------
    // Dinamic array
    rez1 = createArray(rez1, 2, i_end - i_begin + 1);

    // Create new array
    createArrWithMax(&i_begin, &i_end, rez, rez1);

    // =================== Sorting ============================
    /**
     * @brief Sorting algorithm
     * from smallest to biggest
     * 
     */
    Sorting(&i_begin, &i_end, rez, rez1);

    // =================== Print ===============================
    /**
     * @brief Print loop
     * From smallest to biggest
     * 
     */
    printArr(i_begin, i_end, rez, rez1);
    

    // free space of array
    free(rez);
    free(rez1);

    return 0;
}
// ===================================================================================================
/**
 * @brief Equation
 * 
 * @param x 
 * @return double 
 */
double equation(double x)
{
    return -(pow(x, 4)) + 3 * pow(x, 3) + 2 * pow(x, 2) - 5 * x + 0.5;
}
//-------------------------------------------------------------------------------

/**
 * @brief Create a Array object
 * 
 * @param arrayName 
 * @param row 
 * @param column 
 * @return double** 
 */
double **createArray(double **arrayName, int row, int column)
{
    arrayName = (double **)malloc(row * sizeof(double *));

    for (int i = 0; i < 2; i++)
        arrayName[i] = (double *)malloc(column * sizeof(double));

    return arrayName;
}
//---------------------------------------------------------------------------------

/**
 * @brief Search for maximum number and print that number
 * 
 * @param index 
 * @param rez 
 */
void Search(int *index, double **rez)
{
    /**
     * @brief Searching maximum number
     *
     */
    double t_rez = rez[1][0];

    for (int i = 1; i < j - 2; i++)
    {

        if (rez[1][i] > t_rez)
        {
            t_rez = rez[1][i];
            *index = i;
        }
    }
    fi = fopen("Maximum.txt", "w");

    fprintf(fi, "Maximum y number\nx          y\n%.4lf %.4lf\n\n", rez[0][*index], rez[1][*index]);

    fclose(fi);
}
// -----------------------------------------------------------------------------------

/**
 * @brief Generate array with x and y values
 * 
 * @param i 
 * @param end 
 * @param rez 
 */
void Generate(double i, int end, double **rez)
{
    while (i < end)
    {
        rez[0][j] = i;
        rez[1][j] = equation(i);

        j++;
        i += 0.001;
    }
}
// -----------------------------------------------------------------------------------

/**
 * @brief Find place With max number in it
 * 
 * @param index 
 * @param rez 
 * @param i_begin 
 * @param i_end 
 */
void findArrWithMax(int index, double **rez, int *i_begin, int *i_end)
{
    int t_index = index;
    while (1)
    {
        if (rez[1][t_index - 1] < 0)
            break;

        *i_begin = t_index;
        t_index--;
    }

    t_index = index;
    while (1)
    {
        if (rez[1][t_index + 1] < 0)
            break;

        *i_end = t_index;
        t_index++;
    }
}
// --------------------------------------------------------------------------------

/**
 * @brief Create a array With Max object
 * 
 * @param i_begin 
 * @param i_end 
 * @param rez 
 * @param rez1 
 */
void createArrWithMax(int *i_begin, int *i_end, double **rez, double **rez1)
{
    for (int i = 0; i <= (*i_end - *i_begin); i++)
    {
        rez1[0][i] = rez[0][*i_begin + i];
        rez1[1][i] = rez[1][*i_begin + i];
    }
}
// -------------------------------------------------------------------------------

/**
 * @brief Sorting new array from smallest to biggest
 * 
 * @param i_begin 
 * @param i_end 
 * @param rez 
 * @param rez1 
 */
void Sorting(int *i_begin, int *i_end, double **rez, double **rez1)
{
    double t_rez;
    for (int i = 0; i < (i_end - i_begin); i++)
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
}
// -------------------------------------------------------------------------------

/**
 * @brief Print new smallest sorted array
 * 
 * @param i_begin 
 * @param i_end 
 * @param rez 
 * @param rez1 
 */
void printArr(int i_begin, int i_end, double **rez, double **rez1)
{
    fi = fopen("Array.txt", "w");

    for (int k = 0; k <= (i_end - i_begin); k++)
        fprintf(fi, "%.4lf %.4lf\n", rez1[0][k], rez1[1][k]);

    fclose(fi);
}
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