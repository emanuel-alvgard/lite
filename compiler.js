'use strict';

//code
const code = [];
const char = 0;
const line = 0;

//scope
const scope = 0;
const indentation = 0;

//error
const compilation_error = 0;

//utility
const number_case = 
[
    '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
]

const lower_case = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z'
];

const upper_case = 
[
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y', 'Z'
];

const snake_case = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r', 's', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
    '_', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9'
];

const camel_case =
[
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
]



const syntax_log = []; 
const semantic_log = [];



//DONE??
function syntax_comment_single() //gets impolemented by all other syntax functions
//except for multi line comment function
{
    while(code[char] != '\n')
    {
        char += 1;
    }
    char += 1;
    return
}



//DONE??
function syntax_comment_multiple()
{
    while
    (
        code[char] != '\n' &&
        code[char + 1] != '/' && 
        code[char + 2] != '#'
    )
    {
        char += 1;
    }
    char += 3;
    return
}



//DONE??
function syntax_declaration_variable()
{ 
    const error = 0;
    const name = '';

    while(error == 0)
    {
        for(const i = 0; i < snake_case.length; i++)
        {   
            if(code[char] == snake_case[i])
            {
                name += code[char];
                break
            }
            else if(code[char] == ':' && name != '')
            {
                syntax_log.push(line_str + 'variable name must contain at least (1) character.');
                break
            }
            else
            {   
                syntax_log.push(line_str + 'unexpected character: ' + code[char]);
                error = 1;
            }
        }
        char += 1;
    }
    
    if(error != 1)
    {
        if(code[char] == '')
        {
            char += 1;
            loop = 1;
            while(loop == 1)
            {
                if(code[char] == '#' && code[char + 1] == ' ')
                {
                    syntax_comment_single();
                    loop = 0;
                }
                if(code[char] == '\n')
                {
                    loop = 0;
                }
                else
                {
                    char += 1;
                }
            }
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







//NOT
function syntax_declaration_function()
{
    const error = 0;
    const name = '';

    while(error == 0)
    {
        for(const i = 0; i < snake_case.length; i++)
        {   
            if(code[char] == snake_case[i])
            {
                name += code[char];
                break
            }
            else if(code[char] == ':' && name != '')
            {
                syntax_log.push(line_str + 'function name must contain at least (1) character.');
                break
            }
            else
            {   
                syntax_log.push(line_str + 'unexpected character: ' + code[char]);
                error = 1;
            }
        }
        char += 1;
    }
    
    if(error != 1)
    {
        if(code[char] == '' || '\n')
        {
            char += 1;
            loop = 1;
            while(loop == 1)
            {
                if(code[char] == '\n')
                {
                    loop = 0;
                }
                char += 1;
            }
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










//NOT
function syntax_pass()
{
    indentation = scope * 4;
    if(indentation == 0)
    {}
    else
    {
        while(indentation_index < indentation)
        {
            if(code[char] != '')
            {
                syntax_log.push('line ' + line + ':' + 'expected ' + scope + ' levels of indentation');
                error_compilation = 1;
                break
            }
            char += 1;
        }             
    }


    if(code[char] == '\n')
    {}

    else if //single line comment
    (
        code[char] == '#' && 
        code[char + 1] == ' '
    )
    {
        char += 2;
        syntax_comment_single();
    }

    else if //multi line coment
    (
        code[char] == '#' && 
        code[char + 1] == '/' &&
        code[char + 2] == '\n')
    {
        char += 3;
        syntax_comment_multiple();
    }

    else if(code[char] == '')
    {
        console.log('line ' + line + ':' + 'expected ' + scope + ' levels of indentation');
        compilation_error = 1;
    }

    else if //type
    (
        code[char] == 't' &&
        code[char + 1] == 'y' &&
        code[char + 2] == 'p' &&
        code[char + 3] == 'e' &&
        code[char + 4] == '' 
    )
    {
        char += 5;
        //syntax_declaration_type();
        scope += 1;
    }

    else if //function
    (
        code[char] == 'f' &&
        code[char + 1] == 'u' &&
        code[char + 2] == 'n' &&
        code[char + 3] == 'c' &&
        code[char + 4] == 't' &&
        code[char + 5] == 'i' &&
        code[char + 6] == 'o' &&
        code[char + 7] == 'n' &&
        code[char + 8] == '' 
    )
    {
        char += 9;
        syntax_declaration_function();
        scope += 1;
    }

    else if //if
    (
        code[char] == 'i' && 
        code[char + 1] == 'f' &&
        code[char + 2] == ''
    )
    {
        char += 3;
        //if()
        scope += 1;
    }

    else if //else if
    (
        code[char] == 'e' &&
        code[char + 1] == 'l' &&
        code[char + 2] == 's' &&
        code[char + 3] == 'e' &&
        code[char + 4] == '' &&
        code[char + 5] == 'i' &&
        code[char + 6] == 'f' &&
        code[char + 7] == '' 
    )
    {
        char += 0;
        //else if()
        scope += 1;
    }

    else if //else
    (
        code[char] == 'e' &&
        code[char + 1] == 'l' &&
        code[char + 2] == 's' &&
        code[char + 3] == 'e' &&
        code[char + 4] == ''
    )
    {
        char += 5;
        //else()
        scope += 1;
    }

    else //variable
    {
        syntax_declaration_variable();
    }
    line += 1;
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
        //semantic_pass();    
    }
    //thread 3
    while(char < code_length)
    {
        //parsing_pass()
    }
}

main();





















const variable_name = [];
const variable_scope = [];
const variable_type = [];
const variable_value = [];





/*

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




// variable semantic token arrays
const variable_name = [];
const variable_scope = [];
const variable_value_type = [];
const varialble_value_known = [];
const variable_value = [];
const variable_lock = [];

//function semantic token arrays