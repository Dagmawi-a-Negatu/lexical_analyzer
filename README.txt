Tokenizer Program README

Authors:
Dagmawi Negatu
Darwin Bueso Galdamez

Date of Submissio: March 17, 2024


Overview

This project implements a simple tokenizer in C, capable of analyzing 
input text files and identifying various tokens based on predefined patterns. 
The tokenizer recognizes arithmetic operators, parentheses, integer literals, 
and several other token categories, marking unrecognized tokens as lexical 
errors. This utility is particularly useful for lexical analysis in compilers 
or interpreters.


Project Files

tokenizer.c: The main program source file that includes the tokenization logic.
tokenizer.h: Header file containing constants, function declarations, and the 
TokenCategory enumeration used by the tokenizer.

unix_input.txt & unix_input_errors.txt: Sample input files with and without 
intentional errors, respectively, for testing.

output_with_tokens.txt & output_errors_with_tokens.txt: Corresponding output 
files showcasing the tokenizer's ability to parse input and handle errors.


Usage

To compile and run the tokenizer program in Agora, follow these steps...

Make sure you are inside the Project Directory.

To complile use: 
gcc -o tokenizer tokenizer.c -lpcre 

To compile with warnings use: 
gcc -Wall -o tokenizer tokenizer.c -lpcre

Note: It does not display any warnings!
 
Run the program:

To verify the correct operation of the tokenizer, you can use the provided 
unix_input.txt and unix_input_errors.txt files. 

./tokenizer unix_input.txt output_test.txt

and 

./tokenizer unix_input_errors.txt output_test.txt



After running the tokenizer as described above, compare 
the output files to the expected outputs provided in output_with_tokens.txt 
and output_errors_with_tokens.txt. 

The tokenizer should correctly categorize each token and 
handle lexical errors for unrecognized symbols.


For any inquiries or further assistance, please contact the authors.
