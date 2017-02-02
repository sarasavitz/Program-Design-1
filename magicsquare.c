// Sara Savitz
// U37713110
// COP 3514
/* This program creates a magic square out of a two-dimensional
array provided by the user. When the rows, columns, and diagonals 
of the array are summed, they will all be equal to one another. */

#include <stdio.h>
#include <stdlib.h>

// Declare user-defined functions prior to main to ensure no errors with function order
void createSquare(int n);	
void printSquare(int n);   
int findSum(int n);

// Declare global variable for array with max dimensions of 11
int magicSquare[][11] = {{0}, {0}}; 

int main() {
	
	int n; // declare n to be the dimensions of the array
	
	
	printf("Please enter an odd value between 1 and 11: ");	// prompt user to input value of n
	scanf("%d", &n);

	// Ensure that n is an odd number between 1 and 11 (end program if not)
	if (n < 1 || n > 11 || n % 2 == 0) {		
		printf("Please enter a valid integer! \n");
		exit(1);
	} 
	
	

	createSquare(n);	// call function to create magic square

	printSquare(n);		// call function to print magic square

	printf("\n");

	printf("The sum of the magic square is %d \n", findSum(n)); // call function to return sum


	
	return 0;
}
// Function used to create the magic square
void createSquare(int n) {	
	int i;
	int j;

	// use a for loop to initialize all elements to 0
	for (i = 0; i < n; i++) {	
		for (j = 0; j < n; j++) {
		magicSquare[i][j] = 0;

		}
	}
	
	int x = 0;		// Set x equal to the first row
	int y = n/2;	// Set y equal to the middle column
	
	magicSquare[x][y] = 1;	// Set this cell of your array equal to 1

	int k;

	// Use a for loop to assign values to cells of array 
	for (k = 2; k <= (n * n); k++) { 
		x--;	
		y++; 

	// To prevent overflow, check values to ensure they're within bounds
	if (y > (n - 1)) {
		y = 0;	 
		}	

	if (x < 0) {
		x = n - 1;	
		}

	// check to see if cell is empty, then assign cell the value of i	
	if (magicSquare[x][y] == 0) {
		magicSquare[x][y] = k;	
		}
	// if cell is full, assign i in the cell below the previous cell
	else {	
		x++; 
		magicSquare[x][y] = k;	
		}

	}
	

	return;	
}

// Function used to print square
void printSquare(int n) {

	int i;
	int j;

	// Use nested for loops to print the matrix of values
	for (i = 0; i < n; i++)

	{	printf("\n");

		for (j = 0; j < n; j++) 
		{
			printf("%d \t", magicSquare[i][j]);
		}

		printf("\n");	
	}

return;
}

// Function used to calculate total sum of matrix
int findSum(int n) {
	
	int sum = 0;
	int i = 0;
	int j = 0; 

	// Use while loop to sum all values of matrix together
	while (i < n) {
		j = 0;
		while (j < n) {

			sum += magicSquare[i][j];
					
			j++;
		}

		i++;
	}

	return sum;	// This is the only function returning a value
}


