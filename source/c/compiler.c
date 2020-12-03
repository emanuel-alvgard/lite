#include <stdio.h>
#include <string.h>

char code[1024] = "some_var: \n";
char character = 0;
char line = 0;

char scope = 0;
char indentation = 0;

char syntax_error = 0;

char state = 0;



void new_line() {
    if (code[character] == '\n') {
        character += 1; 
        } 
    return;
    }



void case_snake() {
    while(1) {
        if (code[character] > 96 && code[character] < 123) {
            character += 1; }
        else if (code[character] == 95) {
            character += 1; }
        else if () {
            if (code[character] == 58 && code[character + 1] == 32) {
            state = 1;
            character += 2;
            break; } }
        else {
            syntax_error = 1;
            break; } }
    return; }



// STATES
// 0 = keyword / symbol
// 1 = assignment
// 2 = declaration
// 3 = definition

// TYPES
// case_snake
// operator_assignment
// operator_arithmetic
// literal_number
// literal_string
// keyword_procedure



int main() {
    while (code[character] != 0 || syntax_error == 0) {
        // indentation
        // new_line
        // keywords
        case_snake();
        // case_camel
    
        printf("%d", character); }

    if (syntax_error == 0) {
        printf("success!\n"); }
    else {
        printf("error!\n"); } }




