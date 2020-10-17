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
char syntax_error = 0;





void syntax_expression_value_identifier() // always user defined // needs recursion?
{
    while (1)
    {
        if (code[character] > 96 &&
            code[character] < 123 ||
            code[character] == 95)
        {
            character += 1;
        }
        else if (code[character] == '(')
        {
            character += 1;
            
            if (code[character] == ')' &&
                code[character + 1] == ' ')
            {
                character += 2;
                break;
            }
            else
            {
                syntax_expression_value_identifier();
            }

        }
    
        else if (code[character] == ' ')
        {
            character += 1;
            break;
        }
        else
        {
            printf('identifier is not valid.');
            syntax_error = 1;
            break;
        }
        
    }
}

void syntax_expression_value_number()
{

}

void syntax_expression_value_string()
{

}

void syntax_expression_operator()
{
}

void syntax_expression_type() 
{
    // language defined (u8, f32 etc.)
    // user defined (Vector2 etc.)
    // input type (both language and user defined)
}


//
void syntax_expression()
{
    int scope = 0;
    int state = 0;

}


void syntax_identifier()
{

}


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
