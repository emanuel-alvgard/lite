'use strict';

//code
const code = [];
const char = 0;
const line = 0;

//scope
const scope = 0;
const indentation = 0;

//utility
const lower = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r','s', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
];

const upper = 
[
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R','S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z',
];

/* tokens
keyword_func()
keyword_return()
keyword_type()
keyword_if()
keyword_if_else()
keyword_else()
keyword_or()
keyword_and()
keyword_while()
keyword_for()
keyword_in()
keyword_pass()
keyword_exit()

operator_add()
operator_subtract()
operator_multiply()
operator_divide()

operator_equal()
opterator_greater()
operator_lesser()
operator_not_equal()
operator_not_greater()
operator_not_lesser()

symbol_start_parenthesis()
symbol_start_bracket_square()
symbol_start_bracket_curly()
symbol_end_parenthesis()
symbol_end_bracket_square()
symbol_end_bracket_curly()

type_primitive()
type_custom()
structure_string()
structure_array()
*/







//error //problably DEPRECATED?
const error = 0;

function error_pass()
{
    const i = 0;
    const length = error.length;

    while(i < length)
    {
        if(error[i] == 1) //expected indentation error
        {
            console.log
            (
                line_number 
                + '(syntax error): ' 
                + 'expected level' 
                + (scope + 1) 
                + ' indentation'
            );
        }

        else if(error[i] == 2) //unexpected indentation error
        {
            console.log
            (
                line_number 
                + '(syntax error): ' 
                + 'unexpected indentation ' 
            );
        }
        
        else if(errors[i] == 3) //type declaration error
        {
            console.log(line_number + '');
        }
        
        else if(errors[i] == 4) //function declaration error
        {
            console.log(line_number + '');
        }

        else if(errors[i] == 5) //variable declaration error
        {
            console.log(line_number + '');
        }
        i++;
    }
}



function syntax_pass()
{
    if(scope == 0)
    {
        if(code[char] == /*new-line*/)
        {
            line += 1;
        }

        else if(code[char] == '')
        {
            console.log()//unexpected indentation error
        }

        else if //type declaration
        (
            code[char] == 't' &&
            code[char + 1] == 'y' &&
            code[char + 2] == 'p' &&
            code[char + 3] == 'e' &&
            code[char + 4] == '' 
        )
        {
            const upper_true = 0
            const upper_length =  upper.length;
            for(const i = 0; i < upper_length; i++)
            {
                if(code[char + 5] == upper[i])
                {
                    upper_true = 1;
                }
                else
                {
                }
            }
            if(upper_true == 1)
            {
                //next step
            }
            else
            {
                console.log()//type declaration error
                error = 1;
            }
        }

        else if
        (
            code[char] == 'f' &&
            code[char + 1] == 'u' &&
            code[char + 2] == 'n' &&
            code[char + 3] == 'c' &&
            code[char + 4] == '' 
        )
        {
            scope += 1;
            //call syntax_declaration_fuction()
        }
    }

    else if(scope > 1)
    {
        if(code[char] == ''/*new-line*/)
        {
            //pass
        }
        else
        {
            indentation = scope * 4;
            while(indentation_index < indentation)
            {
                if(code[char] != '')
                {
                    error_indentation = 1;
                }
                char += 1;
            }             
        }
    }
}






function main()
{
    const code_length = code.length;
    //thread 1
    while(char < code_length)
    {
        syntax_pass();
    }
    //thread 2
    while(char < code_length)
    {
        token_pass();    
    }
    //thread 3
    while(char < code_length)
    {
        //parsing_pass()
    }
}

main();

