/*!
 *@file Equation.cpp
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF -1          ///< In case of infinite numbers of roots
#define EPS 0.00001     ///< Checking equality float type numbers to zero


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

int square_equation_solve(double  a,
                          double  b,
			  double  c,
	                  double* x1,
      	                  double* x2);


void unit_test();

int main(){
    printf("# Square equation solver\n");
    printf("# By Anton Zezin 2020\n\n");

    unit_test();

    double a = 0,
           b = 0,
           c = 0;
    printf("# Enter a, b, c:\n");

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3){
        printf("# Wrong type of data\n");
        while (getchar() != '\n');
        }

    double x1 = 0,
           x2 = 0;
    int number_of_roots = square_equation_solve(a, b, c, &x1, &x2);

    switch(number_of_roots){
        case   0: printf("# No roots\n");
        break;

        case   1: printf("# Equation has 1 root: %g\n", x1);
        break;

        case   2: printf("# Equation has 2 roots: %g and %g\n", x1, x2);
        break;

        case INF: printf("# Any number\n");
        break;

        default : printf("# Error, equation has %d roots\n", number_of_roots);
        return 1;
        }

    return 0;
    }


int square_equation_solve(double  a,
			  double  b,
	                  double  c,
      	                  double* x1,
	                  double* x2){

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (fabs(a) < EPS){
        if (fabs(b) < EPS){
            return (fabs(c) < EPS) ? INF : 0;
            }
        else{
            *x1 = -c/b;
            return 1;
            }
        }

    else{
        if (fabs(b) < EPS){
            if (fabs(c) < EPS){
                *x1 = 0;
                return 1;
                }

            else{
                double ans = -c/a;
                if (ans > 0){
                    *x1 = -sqrt(ans);
                    *x2 = +sqrt(ans);
                    return 2;
                    }

                else
                    return 0;
                }
            }

        else{
            if (fabs(c) < EPS){
                *x1 = 0;
                *x2 = -b/a;
                return 2;
                }

            else{
                double d = b*b - 4*a*c;

                if (d < 0)
                    return 0;

                else if (fabs(d) < EPS){
                    *x1 = -b/(2*a);
                    return 1;
                    }

                else{
                    *x1 = (-b - sqrt(d))/(2*a);
                    *x2 = (-b + sqrt(d))/(2*a);
                    return 2;
                    }

                }

            }

        }

    }


void unit_test(){
    printf("# Unit test\n\n");

                      // {a, b,  c, nr*, x1, x2}  *number of roots
    double tests[][6] = {{0, 0,  0, INF,  0,  0}, // 1
                         {0, 0,  1, 0  ,  0,  0}, // 2
                         {0, 1,  0, 1  ,  0,  0}, // 3
                         {0, 1,  1, 1  , -1,  0}, // 4
                         {1, 0,  0, 1  ,  0,  0}, // 5
                         {1, 0, -1, 2  , -1,  1}, // 6
                         {1, 0,  1, 0  ,  0,  0}, // 7
                         {1, 1,  0, 2  ,  0, -1}, // 8
                         {1, 1,  1, 0  ,  0,  0}, // 9
                         {1, 2,  1, 1  , -1,  0}, // 10
                         {2, 6,  4, 2  , -2, -1}};// 11

    int i = 0, number_of_tests = sizeof(tests)/sizeof(tests[0]);

    bool report[number_of_tests];

    for(i; i<number_of_tests; i++){
        printf("# Test # %d \n", i+1);

        double x1 = 0,
               x2 = 0;
        int number_of_roots = square_equation_solve(tests[i][0],
                                                    tests[i][1],
                                                    tests[i][2],
                                                      &x1, &x2);

        if ((fabs(number_of_roots - tests[i][3]) < EPS)
                             &&
            (fabs(       x1       - tests[i][4]) < EPS)
                             &&
            (fabs(       x2       - tests[i][5]) < EPS)){

            printf("# Test # %d OK\n\n", i+1);

            report[i] = true;
            }

        else{

            printf("#           a          = %lg\n"
                   "#           b          = %lg\n"
                   "#           c          = %lg\n"
                   "# number of roots(exp) = %lg\n"
                   "#        x1(exp)       = %lg\n"
                   "#        x2(exp)       = %lg\n"
		   "# number of roots(res) = %lg\n"
		   "#        x1(res)       = %lg\n"
		   "#        x2(res)       = %lg\n",
                                   tests[i][0],
                                   tests[i][1],
                                   tests[i][2],
                                   tests[i][3],
                                   tests[i][4],
                                   tests[i][5],
		  		   number_of_roots, x1, x2);

            printf("# Test # %d FAILED\n\n", i+1);

            report[i] = false;
            }
        }
        printf("# Failed test(s) number(s): ");

        i = 0;
        for(i; i<11; i++){
            if (report[i] == false){
                printf("%d ", i+1);
                }
            }
        printf("\n\n# Unit test is over\n\n");
        return;
    }
