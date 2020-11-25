#include <stdio.h>
#include <string.h>

char code[1024] = "some_var: \n";
char character = 0;
char line = 0;

char scope = 0;
char indentation = 0;

char syntax_error = 0;

char state = 0;



void variable_name()
{
    while(1)
    {
        if (state == 0)
        {
            break;
        }
        else if ((code[character] > 96 && code[character] < 123) || code[character] == 95)
        {
            printf("%d", character);
            character += 1;
        }
        else if (code[character] == 58 && code[character + 1] == 32)
        {
            printf("%d%d", character, character + 1);
            state = 1;
            character += 1;
            break;
        }
        else
        {
            syntax_error = 1;
            break;
        }
    }
    return;
}



int main()
{
    while(syntax_error == 0)
    {
        variable_name();
    }
    if (syntax_error == 0)
    {
        printf("success!\n");
    }
    else
    {
        printf("error!\n");
    }            
}




