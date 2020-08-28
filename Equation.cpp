/*!
 *@file Equation.cpp
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#define INF -1
#define EPS 0.00001


/*!
 *@brief Solves square equation ax^2+bx+c=0
 *
 *@param [in]  a   a-coef
 *@param [in]  b   b-coef
 *@param [in]  c   c-coef
 *@param [out] x1  pointer to the 1st root
 *@param [out] x2  pointer to the 2nd root
 *
 *@return Number of roots
 */

int square_equation_solve(double a, double b, double c, double* x1, double* x2);

int main()
    {
    printf("# Square equation solver\n");
    printf("# By Anton Zezin 2020\n\n");


    double a = 0, b = 0, c = 0;
    printf("# Enter a, b, c:\n");
    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
        {
        printf("Wrong type of data\n");
        while (getchar() != '\n');
        }

    double x1 = 0, x2 = 0;
    int number_of_roots = square_equation_solve(a, b, c, &x1, &x2);

    switch(number_of_roots)
        {
        case 0: printf("No roots");
        break;

        case 1: printf("Equation has 1 root: %g\n", x1);
        break;

        case 2: printf("Equation has 2 roots: %g and %g\n", x1, x2);
        break;

        case INF: printf("Any number\n");
        break;

        default: printf("Error, equation has %d roots", number_of_roots);
        return 1;
        }

    return 0;
    }


int square_equation_solve(double a, double b, double c, double* x1, double* x2)
    {

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (fabs(a) < EPS)
        {
        if (fabs(b) < EPS)
            {
            return (c == 0)? INF : 0;
            }
        else
            {
            *x1 = - c/b;
            return 1;
            }
        }

    else
        {
        if (fabs(b) < EPS)
            {
            if (fabs(c) < EPS)
                {
                *x1 = 0;
                return 1;
                }
            else
                {
                double ans = -c/a;
                if (ans > 0)
                    {
                    *x1 = -sqrt(ans);
                    *x2 = sqrt(ans);
                    return 2;
                    }
                else
                    {
                    return 0;
                    }
                }
            }
        else
            {
            if (fabs(c) < EPS)
                {
                *x1 = 0;
                *x2 = -b/a;
                return 2;
                }
            else
                {
                double d = b*b - 4*a*c;
                if (d < 0)
                    {
                    return 0;
                    }
                else if (fabs(d) < EPS)
                    {
                    *x1 = -b/(2*a);
                    return 1;
                    }
                else
                    {
                    *x1 = (-b - sqrt(d))/(2*a);
                    *x2 = (-b + sqrt(d))/(2*a);
                    return 2;
                    }
                }
            }
        }
    }
