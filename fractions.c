//Sara Savitz
//U37713110
//COP 3514
//Homework #1 


#include <stdio.h>
int main(void) {

	int numeratorVal1;		// Declare variables for numerator 
	int numeratorVal2;		
	int denominatorVal1;	// Declare variables for denominator 
	int denominatorVal2;

	printf("Enter Fraction 1: ");
	scanf("%d/%d", &numeratorVal1, &denominatorVal1);		// Input first fraction 

	printf("Enter Fraction 2: ");
	scanf("%d/%d", &numeratorVal2, &denominatorVal2);	// Input second fraction 

	int numeratorSum;			// Declare variables for addition of fractions
	int denominatorSum;

	numeratorSum = (numeratorVal1 * denominatorVal2) + (numeratorVal2 * denominatorVal1);	//Calculate sums
	denominatorSum = denominatorVal1 * denominatorVal2;

	printf("Addition of Fractions: %d/%d\n", numeratorSum, denominatorSum);	

	int numeratorDifference;	// Declare variables for subtraction of fractions
	int denominatorDifference;

	numeratorDifference = (numeratorVal1 * denominatorVal2) - (numeratorVal2 * denominatorVal1);	// Calculate differences
	denominatorDifference = denominatorVal1 * denominatorVal2;

	printf("Subtraction of Fractions: %d/%d\n", numeratorDifference, denominatorDifference);

	int numeratorProduct;		// Declare variable for multiplication of fractions
	int denominatorProduct;

	numeratorProduct = numeratorVal1 * numeratorVal2;		// Calculate product
	denominatorProduct = denominatorVal1 * denominatorVal2;

	printf("Multiplication of Fractions: %d/%d\n", numeratorProduct, denominatorProduct);

	int numeratorQuotient;		// Declare variables for division of fractions
	int denominatorQuotient; 

	numeratorQuotient = numeratorVal1 * denominatorVal2;	// Calculate quotient
	denominatorQuotient = denominatorVal1 * numeratorVal2;

	printf("Division of Fractions: %d/%d\n", numeratorQuotient, denominatorQuotient);

	int mixedNumberWholeNumber; 	// Declare variables for determining if fraction is whole number or not
	int mixedNumberFraction;

	if (numeratorVal1 > denominatorVal1) {					// Use if statement to determine if fraction is whole or not
		printf("Fraction 1 is an improper fraction \n");
		mixedNumberWholeNumber = numeratorVal1 / denominatorVal1;
		mixedNumberFraction = numeratorVal1 % denominatorVal1;
		if (mixedNumberFraction == 0) {
			printf("Fraction 1 as a mixed number: %d \n", mixedNumberWholeNumber);
		}

		else 
			printf("Fraction 1 as a mixed number: %d %d/%d \n", mixedNumberWholeNumber, mixedNumberFraction, denominatorVal1);		

	}

	else 
		printf("Fraction 1 is a proper fraction.\n");

	float decimalVal;		// Declare a float type for the decimal value of fraction 1

	decimalVal = (float) numeratorVal1 / (float) denominatorVal1;	// Type cast fraction 1 to determine decimal form

	printf("Decimal approximation of fraction 1: %.2f\n", decimalVal);	// Print with a .2 precision 

	int gpa;		// Declare variable for GPA

	printf("Enter a GPA for the class (0-4 integer): ");	// Prompt user to enter a GPA value between 1-4
	scanf("%d", &gpa);

	switch(gpa) {		// Use switch statement to determine grade based on GPA

		case 4: 	printf("You got an A!\n");
					break;
		case 3:		printf("You got a B!\n");
					break;
		case 2:		printf("You got a C!\n");
					break;
		case 1:		printf("You got a D!\n");
					break;
		case 0: 	printf("You got an F!\n");
					break;
		default:	printf("This isn't a grade.\n");

	}



	return 0;



}