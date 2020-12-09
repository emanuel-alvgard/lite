#include <stdio.h>
#include <string.h>
#include <pthread.h>

char code[10240000];
char character = 0;
int line = 0;

int scope = 0;
int indentation = 0;

int syntax_error = 0;

int state = 0;



void read_file(char *file_name) {
    
    FILE *file = fopen(file_name, "r");
    int a = 0;

    while (1) {
        code[a] = fgetc(file);
        printf("%c", code[a]);
        if (code[a] != -1) {
            a ++; }
        else {
            break; } }
    return; }



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
        /*else if () {
            if (code[character] == 58 && code[character + 1] == 32) {
            state = 1;
            character += 2;
            break; } }*/
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





int main(int argc, char *argv[]) {
    
    read_file(argv[1]);
    
    /*
    while (code[character] != -1 && syntax_error == 0) {
        // indentation
        // new_line
        // keywords
        //case_snake();
        //case_camel }
        */

    if (syntax_error == 0) {
        printf("success!\n"); }
    else {
        printf("error!\n"); } }
