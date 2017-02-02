/*	*	*	*	*	*	*	*
 *	*	*	*	*	*	*	*
 *	*	Sara Savitz		*	*
 *	*	U37713110		*	*
 *	*	Homework #4		*	*
 *	*	June 22nd, 2015	*	*
 *	*	*	*	*	*	*	*
 *	*	*	*	*	*	*	*/

 // Purpose of triangle.c 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
 *	The purpose of this program is to take three user defined 		*
 *	points of a hypothetical triangle, and find three new sets		*
 *	of points representing the triangle after it has been rotated	*
 *	clockwise 90 degrees, reflected across an axis of the user's	*
 *	choice, and translated across an axis of the user's choice. 	*
 *	Finally, the program will conclude with printing the user's		*
 *	original triangle. 												*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
 
 #include <stdio.h>

 // We will declare four function prototypes to perform our four tasks.
 void clockwiseRotateTriangle(const int a[3][2], int b[3][2]);
 int reflectTriangle(int const a[3][2], int b[3][2], char c);
 void translateTriangle(int const a[3][2], int b[3][2], int x, int y);
 void printTriangle(const int points[3][2]);
 
 
 int main(void) {
	 
	 // Declare arrays to hold user's points and arrays to hold the new points.
	 int pointArray[3][2] = {{0},{0}};
	 int rotationArray[3][2] = {{0},{0}};
	 int reflectArray[3][2] = {{0},{0}};
	 int translateArray[3][2] = {{0},{0}};

	 // Declare variables for the axis of rotation and the translation values.
	 char axis;
	 int xTranslate, yTranslate;
	 
	 
	 // Prompt user to input the three points of the triangle.
	 printf("Enter point #1 as x and y: ");
	 scanf("%d %d", &pointArray[0][0], &pointArray[0][1]);
	 
	 printf("Enter point #2 as x and y: ");
	 scanf("%d %d", &pointArray[1][0], &pointArray[1][1]);
	 
	 printf("Enter point #3 as x and y: ");
	 scanf("%d %d", &pointArray[2][0], &pointArray[2][1]);
	 fflush(stdin);	// Flush out the buffer for the scan function so the correct value is used.

	 // Print the starting points of your triangle.
	 printf("Starting Triangle: ");
	 printTriangle(pointArray);

	 // Call your rotation function to rotate your triangle and print your new points.
	 clockwiseRotateTriangle(pointArray, rotationArray);
	 printf("Rotated Triangle: ");
	 printTriangle(rotationArray);
	
	 // Prompt user to enter the axis to reflect our triangle across.
	 printf("Enter axis to reflect: ");
	 scanf("%c", &axis);
 	 scanf("%c", &axis);	// Error: Problems with scanf, had to duplicate
	 
	 fflush(stdin); // Flush out the buffer for the scan function so the correct value is used.

	 // Use an if statement to check the return value of our function call to determine what to print.
	 if (reflectTriangle(pointArray, reflectArray, axis) == -1) {
	 	printf("Invalid axis. Please enter x or y next time.\n");
	 }
	 else {

		reflectTriangle(pointArray, reflectArray, axis);
	 	printf("Reflected Triangle: ");
	 	printTriangle(reflectArray);
	 }
	 
	 // Prompt user to enter the x and y translation values.
	 printf("Enter translation values: ");
	 scanf("%d %d", &xTranslate, &yTranslate);

	 // Call your translation function and print your new points. 
	 translateTriangle(pointArray, translateArray, xTranslate, yTranslate);
	 printf("Translated Triangle: ");
	 printTriangle(translateArray);
	 
	 return 0;
 }
 
 // Purpose of clockwiseRotateTriangle
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	This function will caculate the resulting points of a clockwise 	*
 *	rotation of the user's triangle. Our function's arguments will 		*
 *	consist of the array containing the user's points as well as an 	*
 *	array to hold the new points after the functionhas been executed.	*
 *	This function returns no value.										*	
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

 void clockwiseRotateTriangle(const int a[3][2], int b[3][2]) {
	
	 int row;
	 int column;
	 
	 // Iterate through array
	 for(row = 0; row < 3; row++) {
		 for(column = 0; column < 2; column++) {	 
			 
			 // Checking if element in array is an x or y value.
			if(column == 0) {
				b[row][1] = - a[row][column];	// Negate x value and set equal to y.
			}
			else {
				b[row][0] = a[row][column];		// Set y value equal to x. 
			}

			 
		 }
	
	}	
		 
}
		 

// Purpose of reflectTriangle 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	This function will calculate the points of reflecting the user's 		*
 *	triangle over a specified axis. Our function's arguments will consist	*
 *	of the array containing the user's points, an array to hold the new		*
 *	points, as well as a character to indicate the choice of axis. This 	*	
 *	function can return only 0 or -1. 										*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

int reflectTriangle(const int a[3][2], int b[3][2], char c)	{

	int row, column;
	
	//Check if specified axis is x or y. 
	if(c == 'x'|| c == 'X') {
		
		// Iterate through array.
		for(row = 0; row < 3; row++) {
			for(column = 0; column < 2; column++) {
				
				if(column == 0) {					// If x axis... 
				
				b[row][column] = a[row][column]; 	// X value does not change. 
				
				}
				else {

				b[row][column] = - a[row][column];	// Y value becomes negative. 
				
				}

			}
		}
		return 0;
	}
	else if(c == 'y'|| c == 'Y') {					
		
		for(row = 0; row < 3; row++) {
			for(column = 0; column < 2; column++) {
				
				if(column == 0) {					// If y axis... 

				b[row][column] =  - a[row][column];	// x value becomes negative.

				}
			else {

				b[row][column] = a[row][column];	// y value does not change. 

				}
			}
		}
		return 0;
	}
	else {
		return -1;
	}
	
}


// Purpose of translateTriangle 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	This function will calculate the points of translating the user's 			*
 *	triangle over a specified x and y value. Our function's arguments will 		*
 *	consist of the array containing the user's points, an array to hold the 	*
 *	new points, as well as the values of x and y. This function will return 	*
 *	no value.							 										*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void translateTriangle(int const a[3][2], int b[3][2], int x, int y) {
	
	int row, column;
	
	for(row = 0; row < 3; row++) {
		for(column = 0; column < 2; column++) {
			
			if(column == 0) {

				b[row][column] = a[row][column] + x;

			}
			else {

				b[row][column] = a[row][column] + y;
			}
		}
	}
}

// Purpose of translateTriangle 
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	This function will print three points from a given an array. This array 	*
 *	will be the argument of our function. This function returns no value.		*							 										*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void printTriangle(const int points[3][2]) {
	
	int i, *p = points;	// Declare an iterator and a pointer value.

	// Use pointer arithmetic to loop through the array and print the appropriate values. 
	for(i = 0; i < 6; i++) {
		printf("(%d, %d)", *(p + i), *(p + i + 1));
		i++;	// Iterate i again to avoid repeating elements. 
	}

printf("\n");
	
}
	
 
	