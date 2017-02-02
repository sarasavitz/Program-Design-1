// Sara Savitz
// U37713110
// June 24, 2015
// Homework #5


//Purpose of sorting.c
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	*	This program will sort the name and age of a certain amount * 	*
 *	*	of people, first printed by order of entry, then by name, 	*	*
 *	*	and lastly, by age. 										*	*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/


 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #define MAX_LENGTH 80	// Declare a global variable for maximum length of any given name.

 

// Declare a structure that will create a type "identity" containing the name and age. 
 typedef struct {

 	int age;
 	char name[MAX_LENGTH + 1];

 } identity;


// Function Prototype Declarations
void printStruct(int size, identity infoArray[size]);
int compareAge(const void *a, const void *b);
int compareName(const void *a, const void *b);

// Use command line arguments to be passed in main. 
 int main(int argc, char *argv[]) {

 	int size = (argc - 1) / 2, i, j;	// Declare variable "size" to hold number of people.
 	identity infoArray[size];	// Declare array of type "identity" to hold structure variables. 
 
	// Checks to ensure number of arguments is valid.
 	if (argc == 1 || argc % 2 == 0) {

 	printf("Invalid Argument.\n");
 	printf("Usage: ./hw5 name1 age1 name2 age2 ...\n");
 	return 0;
	}

	else {

		printf("You have entered %d person(s) into the program.\n", size);

		// Index through array and properly assign values into new structure array.
		for(i = 0, j = 0; i < size; i++, j++) {
			strcpy(infoArray[i].name, argv[j+1]);\
			infoArray[i].age = atoi(argv[j+2]);	// Converts any strings in place of age to zero. 
			j++;

			// Check if age is valid (greater than zero).
			if (infoArray[i].age <= 0) {

				printf("Invalid age <= 0. Try again.\n");

				return 0; // End program if condition fails. 
			}
		}
	}
 
	// Print names and ages sorted by entry order, name, and finally age. 
	printStruct(size, infoArray);	

	puts("Sorted by Name: ");
	qsort(infoArray, size, sizeof(identity), compareName);
	printStruct(size, infoArray);

	puts("Sorted by Age: ");
	qsort(infoArray, size, sizeof(identity), compareAge);

	printStruct(size, infoArray);

return 0;

}

 // Purpose of printStruct
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	
*	This function takes in arguments consisting of the name component and age 	* 
*	component of your structure. It then will print out the list of names and	*
*	ages sorted by either entry order, name, or age. This function returns no	*
*	values. 																	*	
*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void printStruct(int size, identity infoArray[size]) {

	int i;
	for(i = 0; i < size; i++) {
		printf("Name: %s \t | \t  Age: %d \n", infoArray[i].name, infoArray[i].age);
	}
}

// Purpose of compareAge
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
*	This function will be an argument passed into our qsort function. 	*
*	It will sort the names and ages in order of age when ran through  	*
*	qsort. This function returns the sorted ages.						*														  	
*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/	
int compareAge(const void *a, const void *b) {

	identity *x = (identity *)a;	// Type cast structure to pointer.
	identity *y = (identity *)b; 

	return x->age - y->age;
}

// Purpose of compareName
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
*	This function will be an argument passed into our qsort function. 	*
*	It will sort the names and ages in order of name when ran through  	*
*	qsort. This function returns the sorted names.						*														  	
*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/
int compareName(const void *a, const void *b) {

	identity *x = (identity *)a;	// Type cast structure to pointer. 
	identity *y = (identity *)b;

	int nameFirst = strcmp(x->name, y->name);	// Compare strings of names to determine which will go first. 
	return nameFirst;
}