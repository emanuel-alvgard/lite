#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char code[10240000];
//char ch = 0;
//int token[10240000];
//char to = 0;

//int line = 0;
//int scope = 0;
//int indentation = 0;
//int syntax_error = 0;
//int state = 0;


// TODO
// add offset for each token

// belongs to lite_io.h
char *read_file(char *file_name) {
    
    FILE *file;
    long file_size;
    char *buffer;

    file = fopen(file_name, "r");
    file_size = fseek( file, 0L, SEEK_END);
    rewind(file);

    buffer = (char *) calloc(1, file_size + 1);
    fread(buffer, file_size, 1, file);

    fclose(file);
    return buffer;
}


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



// digit

// consider changing to number instead
int integer(char *code, char c) {
    int a = 0;
    while (1) {
        if (digit(code[c]) == 1) { a ++; }
        else if (code[c] == 46 && digit(code[c + 1]) == 1) { return 0; break; }
        else { return a; break; }
    }
}

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



