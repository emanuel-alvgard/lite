#include <stdio.h>
#include <time.h>



// DONE
// # this is a comment
void syntax_comment_single() // gets impolemented by all other syntax procedures
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


void main()
{}