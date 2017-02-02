/*	*	*	*	*	*
 *	Sara Savitz		*
 *	U37713110		*
 *	July 18th, 2015	*
 *	Homework #7		*
 *	*	*	*	*	*/

// Purpose of Program
 /*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
  *	This program will take in a text file from the command line 	*
  *	and print out the total number of characters, words, and lines 	*
  *	contained in the file. 											*
  *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Declare Function Prototype
void read_file(FILE *fp, char *string);

int main(int argc, char *argv[])

{
	// Declare variable of type FILE to hold the text file.
	FILE *fp;

	// Declare a pointer to a string array that will contain all members of the text file.
	char *string;

	// Check for correct number of arguments. 
	if(argc != 2) 
	{
		printf("Invalid arguments.\n");

		return 0;	// End program.
	}

	
	// Check if file can be opened and prompt user if it can't. 
	if((fp = fopen(argv[1], "r")) == NULL)	
	{
		printf("%s can not be opened.", argv[1]);
		return 0;
	}

	// Dynamically allocate memory for your string, starting with a single character.
	string = malloc(sizeof(char));
	
	read_file(fp, string);	// Function Call.
	
	fclose(fp);	// Close File.

	return 0;
}


// Purpose of read_file Function
/*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
 *	 The read_file function will take in arguments consistingof the text file,	*
 *	 as well as the string that will contain the contents of the text file. 	*
 *	 The function will then copy the text file into the string and count the 	*
 *	 number of characters, words, and lines. It will then print these values	*
 *	 to the screen. 															*
 *	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*/

void read_file(FILE *fp, char *string)

{

// Declare integer variables to store values of characters, words, and lines. 
int ch = 0, wrd = 0, ln = 1;

// Declare a char variable to store the current character of the text file. 
char c; 	

// Loop your char variable to read each member of the file until the end of file is met.
while((c = getc(fp)) != EOF)

	{	
		// Allocate memory to store each character and store the character into the string.
		string = realloc(string, sizeof(char) * (ch+1));
		string[ch] = c; 

		// Checking for number of lines in file... 
		if(c == '\n')

			{
				ln++;	// Increment value if new-line character is detected. 

				// Check character that comes before the space. 
				if(ispunct(string[ch-1]) || isalnum(string[ch-1])) // Check for punctuation/alphanumerical character. 

				{
					wrd++; // Increment value if all conditions are met. 

				}

			}

		// Checking for number of words in file... 
		if(isspace(string[ch]))	// Check for spaces. 

			{	
				// Check character that comes before the space. 
				if(ispunct(string[ch-1]) || isalnum(string[ch-1])) // Check for punctuation/alphanumerical character. 

				{
					wrd++; // Increment value if all conditions are met. 

				}

			}	

		ch++;	// Increment character value until End of File is met. 
	}

	// Checks very last word of file.
	if(ispunct(string[ch-1]) || isalnum(string[ch-1]))

		{
			wrd++; 	// Increment word if cond

		}
					

	// Print number of charcters, words, and lines. 
	printf("Number of Characters: %d\nNumber of Words: %d\nNumber of Lines: %d\n", ch, wrd, ln);

// Set the final member of the string equal to a null character. 
string[ch]='\0';
}









