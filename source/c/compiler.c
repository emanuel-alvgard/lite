#include <stdio.h>
#include <string.h>
#include <pthread.h>

char code[10240000];
char c = 0;
char token[10240000];
char t = 0;

//int line = 0;
//int scope = 0;
//int indentation = 0;
//int syntax_error = 0;
//int state = 0;



void read_file(char *file_name) {
    
    FILE *file = fopen(file_name, "r");
    int a = 0;

    while (1) {
        code[a] = fgetc(file);
        if (code[a] != EOF) {
            printf("%c", code[a]);
            a ++; }
        else {
            printf("\n");
            break; } }
    fclose(file);
    return; }



// keyword tokens 0-49
/*
0: package
1: import
2: switch
3: loop
4: skip
5: next
6: exit
7: if
8: else
9: try
10: catch
11: lock
12: unlock
13: dynamic
14: scope
*/

/*
: ' i8 '
: ' i16 '
: ' i32 '
: ' i64 '
: ' i128 '
: ' f32 ' 
: ' f64 '
: ' f128 '
: ' str '
*/

// symbol tokens (symbol + space) 50 - 100
/*
: ' + '
: ' - '
: ' * '
: ' / '
: ' % '
: ' = '
: ' < '
: ' > '
: ' != '
: ' !< '
: ' !> '
: ' & '
: ' | '

: '#/ ' multiline_comment_start
: ' /#' multiline_comment_end
: '# ' comment
: ': (' input/output_start
: ') ' input/output_end
: ' [' size_start
: '] ' size_end
: ': ' assignment_operator
: ':\n'
: ':: ' procedure_definition
: ' <a' incrementor_start
: '..>' incrementor_end
: 'A..' (A stands for upper case character)
: 'a..' (.. stands for A/a/_)
: '_a..'

: '[' index_start
: (]) index_end
: (() proc_input_start
: ()) proc_input_end
: ({) thread_start
: (}) thread_end

: ' '
: '\n'
: '.'

*/





void tokenizer(){
    while (code[c] != EOF) {
        
        // variable/procedure name
        if (code[c] > 96 && 
            code[c] < 123) {
            
            c += 1;
            while (1) {
                if (code[c] > 96 && code[c] < 123) {c += 1;}
                else if (code[c] > 64 && code[c] < 91) {c += 1;}
                else if (code[c] == '_') {c += 1;}
                else { 
                    token[t] = 1;
                    t += 1;
                    printf("[var/proc_name]");
                    break;
                }
            }
        }

        // assignment operator
        else if (code[c] == ':' && code[c + 1] == ' ') {
            c += 2;
            token[t] = 2;
            t += 1;
            printf("[assign]");
        }

        // scoped assignment operator
        else if (code[c] == ':' && code[c + 1] == '\n') {
            c += 2;
            token[t] = 3;
            t += 1;
            printf("[scoped assign]");
        }

        // numerical value
        else if (code[c] > 47 && 
            code[c] < 58) {
            
            c += 1;
            while (1) {
                if (code[c] > 47 && code[c] < 58) {c += 1;}
                else if (code[c] == '.') {c += 1;}
                else { 
                    token[t] = 4;
                    t += 1;
                    printf("[num value]");
                    break;
                }
            }
        }

        // newline
        else if (code[c] == '\n') {
            c += 1;
            token[t] = 5;
            t += 1;
        }


        // unknown
        else {
            printf("[unknown token]\n");
            break;
        }
    }
}



int main(int argc, char *argv[]) {
    
    read_file(argv[1]);
    tokenizer();
}
