/**
 * tokenizer.c - A simple token recognizer.
 *
 * NOTE: The terms 'token' and 'lexeme' are used interchangeably in this
 *       program.
 *
 * @author Your Name
 * @version current date
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

// global variables
char *line;             // Global pointer to line of input
char  token[TSIZE];      /* Spot to hold a token, fixed size */
int tokenLength;     /*current size of token*/

// (optional) can declare some additional variable if you want to

/**
* add comment
*/
int main(int argc, char* argv[]) {
   char  input_line[LINE];  /* Line of input, fixed size        */
   FILE  *in_file = NULL;        /* File pointer                     */
   FILE  *out_file = NULL;
   int   line_count,        /* Number of lines read             */
         start,    /* is this the start of a new statement? */
         count;             /* count of tokens                  */

  if (argc != 3) {
    printf("Usage: tokenizer inputFile outputFile\n");
    exit(1);
  }

  in_file = fopen(argv[1], "r");
  if (in_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);
    exit(1);
  }

  out_file = fopen(argv[2], "w");
  if (out_file == NULL) {
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);
    exit(1);
  }

   // (optional) can add some code here if you want some here
 
   while (fgets(input_line, LINE, in_file) != NULL)
   {
      line = input_line;  // Sets a global pointer to the memory location
                           // where the input line resides.

      start++;
      get_token(&line[0]);
      line_count ++;
      
   }

   fclose(in_file);
   fclose(out_file);
   return 0;
}

/**
* add javadoc-like comment
*/
void get_token(char *token_ptr)
{
   // A string containing all the single-character operators we are interested in
    char operators[] = {ADD_OP, SUB_OP, MULT_OP, DIV_OP, LEFT_PAREN, RIGHT_PAREN, EXPON_OP, '\0'};

   // Add code here. Keep this file no longer than 50 lines of code.
   // Iterate through the string until we find a pre-defined lexeme.
    while (*token_ptr != '\0') {
        if (!(is_delimiter(*token_ptr))){
           if(strchr(operators, *token_ptr) != NULL) {

         
           
}
// A simple function to identify whether a character is a delimiter
int is_delimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' ;
}

int is_operator(char ch) {
    // Add logic to determine if 'ch' is an operator
    return strchr("+-*/^=<>()!;", ch) != NULL;
}

void resetTokenBuffer() {
    tokenLength = 0;
    token[0] = '\0'; // Ensures the buffer is treated as an empty string.
}
