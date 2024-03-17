**
 * @file tokenizer.h
 * @brief Header file for the tokenizer project, which provides functionality for tokenizing
 * textual input into recognizable tokens (lexemes) according to specified patterns. It includes
 * definitions for maximum line lengths, token sizes, boolean values, and token categories. This
 * file declares functions for processing tokens, handling unmatched segments, and categorizing
 * lexemes. The tokenizer is capable of distinguishing various types of operators, parentheses,
 * integer literals, and identifies unrecognized segments as unknown tokens. It supports detailed
 * token analysis, including identifying token categories and handling lexical errors. This header
 * facilitates the implementation of a lexical analyzer as part of a compiler or interpreter for
 * programming languages or data formats.
 *
 * @author Dagmawi Negatu and Darwin Bueso Galdamez
 * @version 03/16/2024
 */

/* Constants */
#define LINE 100
#define TSIZE 20
#define TRUE 1
#define FALSE 0

    
/**                                                                             
 * Token categories enumeration.                                                
 * Defines various categories of tokens that the tokenizer can recognize,       
 * including operators, parentheses, literals, and more.                        
 */
typedef enum {
    ADD_OP, SUB_OP, MULT_OP, DIV_OP,
    LEFT_PAREN, RIGHT_PAREN, EXPON_OP, ASSIGN_OP,
    LESS_THEN_OP, LESS_THEN_OR_EQUAL_OP, GREATER_THEN_OP, GREATER_THEN_OR_EQUAL_OP,
    EQUALS_OP, NOT_OP, NOT_EQUALS_OP, SEMI_COLON,
    INT_LITERAL, UNKNOWN
} TokenCategory;

/**                                                                             
 * Determines if a character is neither a space nor a tab.                      
 *                                                                              
 * @param c Pointer to the character being checked.                             
 * @return Returns 1 if not a space/tab, 0 otherwise.                           
 */
int isNotWhitespaceOrTab(char *);

/**                                                                             
 * This function processes any remaining text in the input after the            
 * last recognized token. It filters out whitespace and handles                 
 * any non-whitespace segments that were not matched by the token patterns.     
 *                                                                              
 * @param token_ptr Pointer to the start of the text being tokenized.           
 * @param previous_end Index where the last token match ended.                  
 * @param out_file Pointer to the output file for logging.                      
 */
void process_last_match(char *, int , FILE *);

/**                                                                             
 * Handles non-matching segments found during tokenization.                     
 * This function will print or log the non-matching segment                     
 * to help identify issues with the input.                                      
 *                                                                              
 * @param out_file File pointer to the output file                              
 * @param unmatch String containing the non-matching segment                    
 */
void process_nonmatch(FILE *out_file, char *token_ptr);

/**                                                                             
 * Tokenizes a given string based on predefined                                 
 * regular expressions.                                                         
 *                                                                              
 * It finds all the tokens in the given string and                              
 * prints them to the output file.                                              
 *                                                                              
 * @param token_ptr Pointer to the string to be tokenized                       
 */
void get_token(char *);

/**                                                                             
 * Processes a lexeme, prints its details, and determines if a new statement begins.
 * This function increments the statement count and resets the lexeme count     
 * when encountering a semicolon, indicating the start of a new statement.      
 *                                                                              
 * @param lexeme The lexeme to process and print.                               
 */
void process_lexeme(char*);

/**                                                                             
 * Determines the category of a given lexeme based on its value.                
 * It matches the lexeme to a predefined set of token categories,               
 * including operators, parentheses, and literals.                              
 *                                                                              
 * @param lexeme The lexeme to categorize.                                      
 * @return The TokenCategory enum value corresponding to the lexeme.            
 */
TokenCategory match_token_category(char *);

/**                                                                             
 * Processes the given lexeme by matching it to its corresponding token category
 * and prints its category to the output file. If the lexeme does not match any 
 * predefined category, a lexical error message is printed.                     
 *                                                                              
 * @param file The output file where the lexeme category is printed.            
 * @param lexeme The lexeme to process.                                         
 */
void process_matching(FILE *, char * );
