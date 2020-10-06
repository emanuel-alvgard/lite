#include <stdio.h>
#include <string.h>

//file

//code
char code[1024] = "# hello\n#/ test /#";
char character = 0;
char line = 0;

//scope
char scope = 0;
char indentation = 0;

//error
char compilation_error = 0;

//utility
char number_case[10] = 
{
    '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
};


char lower_case[27] = 
{
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z'
};



//DONE??
void syntax_comment_single() // gets impolemented by all other syntax functions
{
    while (strncmp(&code[character], "\n", 1) != 0)
    {
        character += 1;
        printf("1");
    }
    character += 1;
    printf("syntax_comment_single(): Success!\n");
    return;
}



//NOT WORKING
void syntax_comment_multiple()
{
    while
    (
        strncmp(&code[character], "", 1) != 0 &&
        strncmp(&code[character + 1], "/", 1) != 0 &&
        strncmp(&code[character + 2], "#", 1) != 0 
    )
    {
        character += 1;
        printf("0");
    }
    character += 3;
    printf("syntax_comment_multiple(): Success!\n");
    return;
}



int main()
{
    //FILE *fp = fopen(file_name, "r"); // read mode
    syntax_comment_single();
    syntax_comment_multiple();
}