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
typedef enum {
    ADD_OP, SUB_OP, MULT_OP, DIV_OP,
    LEFT_PAREN, RIGHT_PAREN, EXPON_OP, ASSIGN_OP,
    LESS_THEN_OP, LESS_THEN_OR_EQUAL_OP, GREATER_THEN_OP, GREATER_THEN_OR_EQUAL_OP,
    EQUALS_OP, NOT_OP, NOT_EQUALS_OP, SEMI_COLON,
    INT_LITERAL, UNKNOWN
} TokenCategory;

/**
* add comment
*/
int isNotWhitespaceOrTab(char *);
void process_last_match(char *, int , FILE *);
void process_nonmatch(FILE *out_file, char *token_ptr);
void get_token(char *);   
void process_lexeme(char*);
TokenCategory match_token_category(char *);
void process_matching(FILE *, char * );
