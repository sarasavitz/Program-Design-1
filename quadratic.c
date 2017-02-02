/* * * * * * * * * * * * * * * 
/* * * * * * * * * * * * * * *
/* *	Sara Savitz		   * *
/* *	U37713110 		   * *
/* *	June 10th, 2015	   * *
/* * * * * * * * * * * * * * * 
/* * * * * * * * * * * * * * */			

// Purpose of quadratic.c 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 * 	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 * 	*	This program calculates the roots, vertex, directrix,	*	* 
 * 	*	and direction of a quadratic function consisting of  	*	*
 * 	*	three coefficients provided by the user.             	*	*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

#include <stdio.h>
#include <math.h>	// The math library will provide us with the pow and sqrt function

// Declare function prototypes
int quadraticFormula(float a, float b, float c,  float *rootPointer1, float *rootPointer2);
void quadraticVertex(float a, float b, float c, float *xComponentPointer, float *yComponentPointer);
void quadraticInfo(float a, float yComponent, float *diretrix, char *direction);


int main(void) {
	float a;	// Declare three float variables for your coefficents 
	float b;
	float c;
	
	// Prompt user to enter coefficients
	printf("Please enter coefficients a, b, and c: \n");	
	scanf("%f %f %f", &a, &b, &c);
	
	// Print your quadratic function in the form ax^2 + bx + c
	printf("f(x) = %1.2fx^2 + %1.2fx + %1.2f \n", a, b, c);	
	
	// Declare two variables to store the real roots of your quadratic function
	float root1;
	float root2;

	// Initial a variable for the number of real roots through function call 
	int rootNum = quadraticFormula(a, b, c, &root1, &root2);
	
	// Use conditionals to determine what real roots to print
	if (rootNum == 0) {
		printf("No real roots \n");
	}
	else if (rootNum == 1) {
		printf("Root: %1.2f \n", root1);
	}
	else {
		printf("Roots: %1.2f %1.2f \n", root1, root2);
	}
	
	// Declare two separate variables to represent the vertex of your parabola
	float xComponent;
	float yComponent;

	// Use function call to calculate the vertex and then print vertex
	quadraticVertex(a, b, c, &xComponent, &yComponent);
	printf("Vertex: (%1.2f, %1.2f) \n", xComponent, yComponent);
	
	// Declare two variables for your directrix and direction
	float directrix; 
	char direction;
	
	// Use function call to calculate the directrix and determine direction
	quadraticInfo(a, yComponent, &directrix, &direction);
	printf("Directrix: y = %1.2f \n", directrix);
	
	// Use conditional statements to determine what direction to print 
	if(direction == 'U') {
		printf("The graph is facing up \n");
	}
	else {
		printf("The graph is facing down \n");
	}
	
return 0;

}

// Purpose of quadraticFormula 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
 *	The function quadraticFormula takes in the three coefficients 		*
 *  provided by the user as well as two pointer variables that will		*
 *	provide the values for our roots. This function returns the value	*
 *  for the number of real roots our quadratic function has.			*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

int quadraticFormula(float a, float b, float c, float *rootPointer1, float *rootPointer2) {
	

	int rootNum;	// Declare variable to hold the return value
	int quadraticDiscriminant =(pow(b, 2) - (4 * a * c));	// Declare variable to represent part of the quadratic formula
	
	// Calculate both operations of the quadratic formula and store into your root pointer variables
	*rootPointer1 = ((-b) + sqrt((quadraticDiscriminant))) / (2 * a);	
	*rootPointer2 = ((-b) - sqrt((quadraticDiscriminant))) / (2 * a);

	// Use conditional statements to determine number of real roots
	if (quadraticDiscriminant < 0) {
		rootNum = 0;
	}
	else if (*rootPointer1 != *rootPointer2) {
			rootNum = 2;
		}
		else {
			rootNum = 1;
		} 
		
	
	return rootNum;
		
}
// Purpose of quadraticVertex
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
 *	The function quadraticVertex takes in the three coefficients 		*
 *	provided by the user, as well as two pointer variables that will	*
 *	provide the values for both the x component and y component of your	*
 *	parabola's vertex. This function will return void and all values	* 
 *	will be passed through pointer variables.							*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void quadraticVertex(float a, float b, float c, float *xComponentPointer, float *yComponentPointer) {
	// Use the formula -b/2a to calculate x component of vertex
	*xComponentPointer = (-b) / (2 * a);
	// Plug in x component to quadratic function to find the y component 
	*yComponentPointer = ((4 * a * c) - (b * b)) / (4 * a);
	
}

// Purpose of quadraticInfo
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
 *	The function quadraticInfo takes in just the a coefficent, the y 	*
 *	component value of your vertex, as well as two pointer variables to	*
 *	hold the information of both the directrix and direction of your 	*
 *	parabola. This function will return void and all values will be 	*
 *	passed through pointer variables. 									*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void quadraticInfo(float a, float yComponent, float *directrix, char *direction) {
	
	// Use formula k - p, with vertex of form (h, k) and p = 1/4a
	*directrix = (yComponent) - (1 / (4 * a));
	
	// Use conditional statements with coefficient a to determine direction of parabola
	if (a < 0) {
		*direction = 'D'; // D for Down
	}
	else {
		*direction = 'U'; // U for Up
	}
}	
