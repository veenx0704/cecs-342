// Taiki Tsukahara
#include <stdio.h>
#include <ctype.h>

int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();

/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

void expr();
void term();
void factor();

int main() {
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("Test3.txt", "r")) == NULL)
        printf("ERROR - cannot open file \n");
    else
    {
        getChar();
        do {
            lex();
            expr(); // calling expr
        } while (nextToken != EOF);
    }
    return 0;
}

int lookup(char ch) {
    switch (ch) {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    case '=':
            addChar();
            nextToken = ASSIGN_OP;
            break;
    case '+':
        addChar();
        nextToken = ADD_OP;
        break;
    case '-':
        addChar();
        nextToken = SUB_OP;
        break;
    case '*':
        addChar();
        nextToken = MULT_OP;
        break;
    case '/':
        addChar();
        nextToken = DIV_OP;
        break;
    }
    return nextToken;
}

void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = '\0'; // Null-terminate the lexeme
    } else
        printf("Error - lexeme is too long \n");
}

void getChar() {
    if ((nextChar = getc(in_fp)) != EOF) {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    } else
        charClass = EOF;
}

void getNonBlank() {
    while (isspace(nextChar))
        getChar();
}

int lex() {
    lexLen = 0;
    getNonBlank();
    switch (charClass) {
    /* Parse identifiers */
    case LETTER:
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT) {
            addChar();
            getChar();
        }
        nextToken = IDENT;
        break;

    case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT)
            {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;
    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;

    /* EOF */
    case EOF:
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0; // Null-terminate the lexeme
        break;
    } /* End of switch */
    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    return nextToken;
} /* End of function lex */

// Recursive-descent subprogram for <expr>
void expr() {
    printf("Enter <expr>\n");
    // Parse the first term
    term();
    // As long as the next token is + or -, get the next token and parse the next term
    while (nextToken == ADD_OP || nextToken == SUB_OP) {
        lex();
        term();
    }
    // Display exit message
    printf("Exit <expr>\n");
}

// Subprogram for <term>
void term() {
    printf("Enter <term>\n");
    // Parse the first factor
    factor();
    // As long as the next token is * or /, get the next token and parse the next factor
    while (nextToken == MULT_OP || nextToken == DIV_OP) {
        lex();
        factor();
    }
    // Display exit message
    printf("Exit <term>\n");
}

// Subprogram for <factor>
void factor() {
    printf("Enter <factor>\n");
    // Determine which RHS: variable or constant
    if (nextToken == IDENT || nextToken == INT_LIT) {
        // Get the next token
        lex();
    }
    // If the RHS is ( <expr> ), call lex to pass over the left parenthesis, call expr, and check for the right parenthesis
    else {
        if (nextToken == LEFT_PAREN) {
            lex();
            expr();
            if (nextToken == RIGHT_PAREN) {
                lex();
            } else {
                printf("Syntax error \n");
                ;
            }
        }
        // It was not an id, an integer literal, or a left parenthesis
        else {
            printf("Syntax error \n");
            ;
        }
    }
    // Display exit message
    printf("Exit <factor>\n");
}
