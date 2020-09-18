'use strict';

//code
const code = [];
const char = 0;
const line = 0;
const line_str = 'line ' + line + ': ';

//scope
const scope = 0;
const indentation = 0;

//error
const compilation_error = 0;

//utility
const lower = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r','s', 't', 
    'u', 'v', 'w', 'x', 'y', 'z'
];

const upper = 
[
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R','S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z'
];

const variable_characters = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r','s', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
    '_', ':'
]

const variable_name = [];
const variable_scope = [];
const variable_type = [];
const variable_value = [];

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

operator_add() : +
operator_subtract() : -
operator_multiply() : *
operator_divide() : /

operator_equal() : =
opterator_greater() : > 
operator_lesser() : <
operator_not_equal() : !=
operator_not_greater() : !>
operator_not_lesser() : !<

symbol_comment() : #
symbol_start_comment_multi() : #/
symbol_start_parenthesis() : (
symbol_start_bracket_square() : [
symbol_start_bracket_curly() : {
symbol_end_comment_multi() : /#
symbol_end_parenthesis() : )
symbol_end_bracket_square() : ]
symbol_end_bracket_curly() : }


type_primitive() : 0, 0.0
type_custom() : ex. Vector3()
structure_string() : 'string'
structure_array() : [16] f32
*/




/* Syntax Token
lower case: 0
upper case: 1
colon: 2
*/



function syntax_declaration_variable()
{ 
    const error = 0;
    const name = '';

    while(error == 0)
    {
        for(const i = 0; i < variable_symbols.length; i++)
        {   
            if(code[char] == variable_symbols[i])
            {
                name += code[char];
                break
            }
            else if(code[char] == ':' && name != '')
            {
                console.log(line_str + 'Variable name must contain at least (1) character.');
                break
            }
            else
            {
                error = 1;
            }
        }
        char += 1;
    }
    
    if(error != 1)
    {
        if(code[char] == '')
        {
            //check type name for supported characters until new line char.
        }
        else
        {
            error = 1;
        }
    }
    else
    {
        compilation_error = 1;
    }
    
    return
}








function syntax_pass()
{
    if(scope == 0)
    {
        if(code[char] == '\n')
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
        if(code[char] == '\n')
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
        //token_pass();    
    }
    //thread 3
    while(char < code_length)
    {
        //parsing_pass()
    }
}

main();

