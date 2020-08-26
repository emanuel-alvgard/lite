'use strict';

//code
const code = [];
const char = 0;
const line = 0;

//scope
const scope = 0;
const indentation = 0;

//error
const line_number = 'line' + toString(line) + ': ';
const error_indentation = 0;


//create variable for expected syntax versus actual syntax

function error()
{
    if(error_indentation == 1)
    {
        console.log(line_number + 'indentation error')
    }
    //if() for every other type of syntax error.
}



function syntax()
{
    if(scope == 0)
    {
        if(code[char] == ''/*new-line*/)
        {
            //pass
        }
        else if(code[char] == ':')
        {
            //call syntax_function_call()
        }
        else if
        (
            code[char] == 't' &&
            code[char + 1] == 'y' &&
            code[char + 2] == 'p' &&
            code[char + 3] == 'e' &&
            code[char + 4] == '' 
        )
        {
            scope += 1;
        //call syntax_define_type()
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
            //call syntax_define_fuction()
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
    //run loop trough the code here calling syntax() every iteration.
}

main();

