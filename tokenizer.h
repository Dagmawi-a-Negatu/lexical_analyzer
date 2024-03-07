/**
 * Header file for the tokenizer project 
 * @author your_name
 * @version date
 */
/* Constants */
#define LINE 100
#define TSIZE 20
#define TRUE 1
#define FALSE 0
/* Define token categories for the lexemes recognized by the lexical analyzer*/
#define ADD_OP 1
#define SUB_OP 2
#define MULT_OP 3
#define DIV_OP 4
#define LEFT_PAREN 5
#define RIGHT_PAREN 6
#define EXPON_OP 7
#define ASSIGN_OP 8
#define LESS_THEN_OP 9
#define LESS_THEN_OR_EQUAL_OP 10
#define GREATER_THEN_OP 11
#define GREATER_THEN_OR_EQUAL_OP 12
#define EQUALS_OP 13
#define NOT_OP 14
#define NOT_EQUALS_OP 15
#define SEMI_COLON 16
#define INT_LITERAL 17

/**
* add comment
*/
void get_token(char *);   


