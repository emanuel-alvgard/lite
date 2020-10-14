#include <stdio.h>
#include <time.h>

//file

//code
char code[1024] = "# 11\n#/ 111 /#\n";
char character = 0;
char line = 0;

//scope
char scope = 0;
char indentation = 0;

//error
char compilation_error = 0;

//utility
char case_number[10] = 
{
    '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
};

char case_arithmetic[5] = 
{
    '+', '-', '*', '/', '%'
}

char case_lower[26] = 
{
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z'
};

char case_upper[26] = 
{
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z'
};

char case_snake[37] = 
{
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
    '_', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
};

char case_camel[62] =
{
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
    '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
};




// DONE
// # this is a comment
void syntax_comment_single() // gets impolemented by all other syntax functions
{
    int comment_character = 0;
    while (1)
    {
        if (code[character] == '\n')
        {
            character += 1;
            line += 1;
            break;
        }
        else
        {
            comment_character += 1;
            character += 1;
        }
    }
    printf("single comment is %d characters long!\n", comment_character);
    return;
}



// DONE
//  #/ this is multi line
//  comment with 2 lines /#
void syntax_comment_multiple()
{
    int comment_character = 0;
    int comment_line = 1;
    while (1)
    {
        if (code[character] == ' '
        && code[character + 1] == '/' 
        && code[character + 2] == '#'
        && code[character + 3] == '\n')
        {
            character += 4;
            line += 1;
            break;
        }
        else
        {
            comment_character += 1;
            character += 1;
            if (code[character] == '\n')
            {
                comment_line += 1;
                line += 1;
            }
        }
    }
    printf("multi comment is %d characters long and %d lines long!\n", comment_character, comment_line);
    return;
}



void syntax_declaration_variable()
{}

void syntax_daclaration_function()
{}

void syntax_declaration_type()
{}


//
void syntax_expression()
{
    int scope = 0;
    int state = 0;

    while (1)
    {
        for (i = 0; i < case_number; i++)
        {
            if (character[code] == case_number[i])
            {
                character += 1;
                break;
            }
        }
    }
}


//
void syntax_definition_variable()
{}

//
void syntax_definition_function()
{}

//
void syntax_definition_type()
{}



int main()
{
    //FILE *fp = fopen(file_name, "r"); // read mode
    character += 2;
    syntax_comment_single();
    character += 3;
    syntax_comment_multiple();

    printf("current line is: %d\n", line);
    printf("current character is: %d\n", character);
}
