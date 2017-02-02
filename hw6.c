/*    *    *    *    *    *    
 *    Sara Savitz         *
 *    U37713110           *
 *    Homework #6         *
 *    July 9th, 2015      *
 *    *    *    *    *    */

 // Purpose of Program
 /*    *    *    *    *    *    *    *    *    *    *    *    *
  *    This program will prompt the user to input a series of *
  *    random words that it will sort in alphabetical order.  *
  *    The length of the words must not exceed 20 characters. *
  *    *    *    *    *    *    *    *    *    *    *    *    */


  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #define N 20         // Max character length of word


  // Function Prototype Declarations 
  void read_line(char *string);
  int check_words(const void *a, const void *b);

  int main() {

      // Declare two pointers to character arrays that will hold 
      // the words entered by the user, as well as the characters
      // of each word. 
      int i, size;
    char **words, *string;


    // Allocate memory that will hold the address of a pointer
    // to a string array that will be stored in words. Next
    // allocate memory that will store the user entered strings. 
    words = malloc(sizeof(char *));
    string = malloc(sizeof(char));

    // Increment i.
    for(i = 0;; i++) 
    {

    printf("Enter Word: ");    // Prompt User.
    read_line(string);        // Function call. 

    // End loop if user presses enter twice. 
    if(string[0] == '\0') 
    {
        break;
    }

    // Set the size of the word entered by the user. 
    // Reallocate memory that matches the size of the word.
    // Allocate the memory of string into words, adding 
    // plus 1 for the NULL char.  
    size = i + 1;
    words = realloc(words, (size * sizeof(char *)));
    words[i] = malloc(strlen(string) + 1);

    // Copy corresponding word into element of array.
    strcpy(words[i], string);

    }

    puts("");    
    size = i;    

    // Call qsort function to sort the elements of words
    // and return them in alphabetical order. 
    qsort(words, size, sizeof(char *), check_words);
    printf("In Sorted Order: ");
    

    // Use for loop to print out the sorted list of words. 
    for(i = 0; i < size; i++) 
    {
        printf("%s ", words[i]);
    }

      return 0;
  }


// Purpose of read_line Function 
/*    *    *    *    *    *    *    *    *    *    *    *    *    
 *    This function will take in the pointer to the string   *
 *    array that will hold the user entered words. The       *
 *    function will then use a while loop to take in the     *
 *    individual characters entered by the user. The loop    *
 *    will break once the user has pressed enter twice. This *
 *    function returns no value.                             *    
 *    *    *    *    *    *    *    *    *    *    *    *    */

void read_line(char *string) {

    // Declare variable to hold character, as well as an incrementor. 
    int ch, x = 0;
    

    // Use while loop to take in values entered by the user that will
    // terminate the loop when the user enters a new line character. 
    while((ch = getchar()) != '\n') 
    {
        // Use if statement to check if length of word meets requirements.
        if(x < N) 
            {
                // Reallocate the memory of the string to match the size of
                // the word length plus space for the NULL character. 
                string = realloc(string, sizeof(char) * (x + 2));
                // Store characters in string array while incrementing x. 
                string[x++] = ch;    
            }
    }
    // Set the last character of the string equal to the NULL character.
    string[x] = '\0';
}

// Purpose of check_words Function
/*    *    *    *    *    *    *    *    *    *    *    *    *    *    *
 *    The function will be a parameter of our qsort function.          *
 *    It takes in arguments of two random pointers that are constant   *
 *    and lacking a type. It uses these pointers to compare members    * 
 *    of the character array of user entered words. This function      *
 *    will return a value less than, greater than, or equal to zero.   *
 *    *    *    *    *    *    *    *    *    *    *    *    *    *    */

int check_words(const void *a, const void *b) {

    return (strcmp(*(char **)a, *(char **)b));
}