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
#include <pcre.h>                                                               
#include <ctype.h>                                                              
#include "tokenizer.h"                                                          
                                                                                
// global variables                                                             
char *line; // Global pointer to line of input                                  
// (optional) can declare some additional variable if you want to               
                                                                                
FILE  *out_file = NULL;                                                         
int count; //Global variable that counts lexeme                                 
int line_count; //Gloabal varaible that counts statements                       
                                                                                
// Function prototypes                                                          
void get_token(char *token_ptr);                                                
                                                                                
/**                                                                             
 * add comment                                                                  
 */                                                                             
int main(int argc, char *argv[])                                                
{                                                                               
  char token[TSIZE];     /* Spot to hold a token, fixed size */                 
  char input_line[LINE]; /* Line of input, fixed size        */                 
  FILE *in_file = NULL;  /* File pointer                     */                 
  int start = 0;                                                                
                                                                                
                                                                                
  if (argc != 3)                                                                
  {                                                                             
    printf("Usage: tokenizer inputFile outputFile\n");                          
    exit(1);                                                                    
  }                                                                             
                                                                                
  in_file = fopen(argv[1], "r");                                                
  if (in_file == NULL)                                                          
  {                                                                             
    fprintf(stderr, "ERROR: could not open %s for reading\n", argv[1]);         
    exit(1);                                                                    
  }                                                                             
                                                                                
  out_file = fopen(argv[2], "w");                                               
  if (out_file == NULL)                                                         
  {                                                                             
    fprintf(stderr, "ERROR: could not open %s for writing\n", argv[2]);         
    exit(1);                                                                    
  }                                                                             
                                                                                
  // (optional) can add some code here if you want some here                    
                                                                                
  while (fgets(input_line, LINE, in_file) != NULL)                              
  {                                                                             
    // Add code here. Keep this file no longer than 50 lines of code.           
    // Use helper functions.                                                    
    line = input_line;                                                          
   // start = TRUE;                                                             
                                                                                
    count = 0; //lexeme count                                                   
    get_token(line);                                                            
    // Output the statement number                                              
   // fprintf(out_file, "Statement #%d\n", line_count);                         
                                                                                
                                                                                
                                                                                
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
    // Add code here. Keep this file no longer than 50 lines of code.           
    // Use helper functions. No duplicate code!                                 
                                                                                
    const char *error;                                                          
    int erroffset;                                                              
    pcre *re;                                                                   
    int ovector[30];                                                            
    int rc;                                                                     
                                                                                
    // Pattern to match numbers (digits) or single character operators          
    char *pattern = "(\\d+|!=|==|<=|>=|\\*\\*|[=+\\-*/^<>();])";                
                                                                                
    // Compile the regular expression pattern                                   
    re = pcre_compile(pattern, 0, &error, &erroffset, NULL);                    
                                                                                
                                                                                
    if (re == NULL)                                                             
    {                                                                           
      printf("PCRE compilation failed at offset %d: %s\n", erroffset, error);   
      exit(EXIT_FAILURE);                                                       
    }                                                                           
                                                                                
    // Execute the regular expression to find the next token                    
    // Execute the regular expression and find matches                          
    int i = 0;                                                                  
    while ((rc = pcre_exec(re, NULL, token_ptr, strlen(token_ptr), i, 0, ovector, sizeof(ovector)/sizeof(ovector[0]))) >= 0) {
         char substring[128]; // Buffer to hold the matched substring           
         int substring_length = ovector[1] - ovector[0];                        
         strncpy(substring, token_ptr  + ovector[0], substring_length);         
         substring[substring_length] = '\0';                                    
                                                                                
        fprintf(out_file, "Lexeme %d is %s and is a", count, substring);        
        count++;                                                                
        i = ovector[1]; // Update position to continue searching                
                                                                                
        if(strcmp(substring, ";") == 0){                                        
            fprintf(out_file, "---------------------------------------------------------\n");
            fprintf(out_file, "Statement #%d\n", ++line_count);                 
            count = 0; // Reset lexeme count for the new statement              
                                                                                
        }                                                                       
                                                                                
    }                                                                           
                                                                                
                                                                                
   // Free up the regular expression**/                                         
  pcre_free(re);                                                                
}                
