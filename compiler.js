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

const snake_case = 
[
    'a', 'b', 'c', 'd', 'e', 
    'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n', 'o', 
    'p', 'q', 'r','s', 't', 
    'u', 'v', 'w', 'x', 'y', 'z',
    '_'
];











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
                console.log(line_str + 'variable name must contain at least (1) character.');
                break
            }
            else
            {   
                console.log(line_str + 'unexpected character: ' + code[char]);
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
                console.log(line_str + 'function name must contain at least (1) character.');
                break
            }
            else
            {   
                console.log(line_str + 'unexpected character: ' + code[char]);
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
                console.log('line ' + line + ':' + 'expected ' + scope + ' levels of indentation');
                error_compilation = 1;
                break
            }
            char += 1;
        }             
    }


    if(code[char] == '\n')
    {}

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
        code[char + 4] == '' 
    )
    {
        char += 5;
        syntax_declaration_function();
        scope += 1;
    }

    else //variable
    {
        syntax_declaration_variable();
    }
    line += 1;
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    /*else if(scope > 1)
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
}*/






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