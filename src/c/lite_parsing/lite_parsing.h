#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif

// character functions
int digit(char c) {
    if (c > 47 && c < 58) { return 1; }
    else { return 0; }
}

int symbol(char c) {
    if (c > 32 && c < 48) { return 1; }
    else if (c > 57 && c < 65) { return 1; }
    else if (c > 90 && c < 97) { return 1; }
    else if (c > 122 && c < 127) { return 1; }
    else { return 0; }
}

int lower(char c) {
    if (c > 96 && c < 123) { return 1; }
    else { return 0; }
}

int upper(char c) {
    if (c > 64 && c < 91) { return 1; }
    else { return 0; }
}

int space(char c) {
    if (c == 32) { return 1; }
    else { return 0; }
}

int line(char c) {
    if (c == 10) { return 1;}
    else { return 0; }
}


// token functions
int integer(char *code, char c) {
    int a = 0;
    while (1) {
        if (digit(code[c]) == 1) { a ++; }
        else if (code[c] == 46 && digit(code[c + 1]) == 1) { return 0; break; }
        else { return a; break; }
    }
}





// global data
char code[100];
int c = 0;

char character[100];
int ch = 0;

int offset_token[100];
char token[100];
char to = 0;


// passes
void pass_character() {
    while (code[c] != EOF) {
        if (space(code[c]) == 1) {}
        else if (lower(code[c]) == 1) {}
        else if (upper(code[c]) == 1) {}
        else if (symbol(code[c]) == 1) {}
        else if (digit(code[c]) == 1) {}
        else if (line(code[c]) == 1) {}
        else {}
    }
}

void pass_token() {}



/*
int floating() {

}


// symbol
int string() {}
int paren_left() {}
int paren_right() {}
int bracket_left() {}
int bracket_right() {}
int curly_left() {}
int curly_right() {}

int operator_logic() {}
int operator_arithmetic() {}
int operator_assignment() {}


// lower
int keyword_function() {}
int keyword_composite() {}
int keyword_primitive() {}

int primitive() {}

// upper
int composite() {}

*/



