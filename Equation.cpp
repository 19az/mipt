/*!
 *@file Equation.cpp
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF -1                         ///< In case of infinite numbers of roots
#define EPS 0.00001                    ///< Checking equality of two numbers
#define NUMBER_OF_TESTS_EQUATION 11    ///< Number of unit-tests for square_equation_solve func
#define NUMBER_OF_TESTS_EQUALITY 3     ///< Number of unit-tests for equality_check func
#define UT Y                           ///< Do you want to test functions? (Y / N)
#define Y true                         ///< Y == Yes == true
#define N false                        ///< N == No == false

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



/*!
 *@brief Checks equality of two numbers
 * 
 *@param [in] num1    1st number
 *@param [in] num2    2nd number
 * 
 *@return true if num1 == num2, false if num1 != num2
 */

bool equality_check(double num1, double num2);

void unit_test_equation_solver();

void unit_test_equality_check();

//=============================================================================

int main() {
	
    printf("# Square equation solver\n");
    printf("# By Anton Zezin 2020\n\n");

    if (UT) {
        
	unit_test_equation_solver();
        unit_test_equality_check();

    }	    
	    
    double a = 0;
    double b = 0;
    double c = 0;
    printf("# Enter a, b, c:\n");

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3) {
	    
        printf("# Wrong type of data\n");
        while (getchar() != '\n');
	    
    }

    double x1 = 0;
    double x2 = 0;
    int number_of_roots = square_equation_solve(a, b, c, &x1, &x2);

    switch(number_of_roots) {
		    
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

//=============================================================================

int square_equation_solve(double  a,
			  double  b,
	                  double  c,
      	                  double* x1,
	                  double* x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
	
    if (std::isfinite());

    if (equality_check(a, 0)) {
	    
        if (equality_check(b, 0)) {
		
            return (equality_check(c, 0)) ? INF : 0;
		
        }
        else {
		
            *x1 = -c/b;
            return 1;
		
        }
    }
    else {
	    
        if (equality_check(b, 0)) {
		
            if (equality_check(c, 0)) {
		    
                *x1 = 0;
                return 1;
		    
            }
            else {
		    
                double ans = -c/a;
                if (ans > 0) {
			
                    *x1 = -sqrt(ans);
                    *x2 = -*x1;
                    return 2;
			
                }
                else
                    return 0;
		    
            }
		
        }
	else {
		
            if (equality_check(c, 0)) {
		    
                *x1 = 0;
                *x2 = -b/a;
                return 2;
		    
            }
	    else {
		    
		double d = b*b - 4*a*c;    
                if (d < 0)
                    return 0;
		else {
			
		    double square_root_of_d = sqrt(d);
                    *x1 = (-b - square_root_of_d)/(2*a);
                    *x2 = (-b + square_root_of_d)/(2*a);
                    return (equality_check(d, 0)) ? 1 : 2;
			
                }
		    
            }
		
        }
	    
    }
	
}

//=============================================================================

void unit_test_equation_solver() {
    printf("# Unit test for square_equation_solver func\n\n");

	                                      // {a, b,  c, nr*, x1, x2}  *number of roots
    double tests[NUMBER_OF_TESTS_EQUATION][6] = {{0, 0,  0, INF,  0,  0}, // 1
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


    bool report[NUMBER_OF_TESTS_EQUATION] = {};

    double x1 = 0;
    double x2 = 0;
	
    for(int i = 0; i < NUMBER_OF_TESTS_EQUATION; i++) {
	    
        printf("# Test # %d \n", i + 1);
        
	x1 = 0;
	x2 = 0;
	
        int number_of_roots = square_equation_solve(tests[i][0],
                                                    tests[i][1],
                                                    tests[i][2],
                                                      &x1, &x2);

        if ((equality_check(number_of_roots, tests[i][3])) &&
            (equality_check(       x1      , tests[i][4])) &&
            (equality_check(       x2      , tests[i][5]))) {

            printf("# Test # %d OK\n\n", i + 1);

            report[i] = true;
		
        }
	else {

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

            printf("# Test # %d FAILED\n\n", i + 1);

            report[i] = false;
		
        }
	    
    }
        printf("# Failed test(s) number(s): ");

        for(int i = 0; i < NUMBER_OF_TESTS_EQUATION; i++) {
		
            if (not report[i]) {
                printf("%d ", i + 1);
            
	    }
        
	}
        printf("\n\n# Unit test is over\n\n");
        return;

}

//=============================================================================

bool equality_check(double num1, double num2) {
	
    return (fabs(num1 - num2) < EPS);
	
}

//=============================================================================

void unit_test_equality_check() {
    printf("# Unit test for equality_check func\n\n");
	                                     //{num1  , num2, ans},
    double tests[NUMBER_OF_TESTS_EQUALITY][3] {{1     , 0   , 0  }, //1
					       {EPS   , 0   , 0  }, //2
					       {EPS/10, 0   , 1  }};//3
    
    bool report[NUMBER_OF_TESTS_EQUALITY];
    
    for (int i = 0; i < NUMBER_OF_TESTS_EQUALITY; i++) {
	    
        printf("# Test # %d\n", i);
	    
	if (equality_check(tests[i][0], tests[i][1]) == tests[i][2]) {
		
	    printf("# Test # %d OK\n\n", i);
	    report[i] = true;
		
	}
	else {
		
	    printf("# Test # %d FAILED\n\n", i);
 	    report[i] = false;
	
	}
    
    }
    
    printf("# Failed test(s) number(s): ");
	
    for(int i = 0; i < NUMBER_OF_TESTS_EQUALITY; i++) {
            
	    if (not report[i]) {
            
		printf("%d ", i + 1);
            
	    }
        
    }
    printf("\n\n# Unit test is over\n\n");
    return;

}
