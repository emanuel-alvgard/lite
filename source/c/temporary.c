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






//
void syntax_definition_procedure()
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







// TOKEN procedures
// some smaller subprocedures can be combined into 
// a larger procedure for simplicity
// all the following procedures will we looped in a main loop
// every proc. will return an exit code which will trigger the next proc.
// if the proc. to be executed does not exist further down the loop the
// loop will restart whilst retaining the exit code and look for the 
// right proc. to execute


/* global [0]
# (single line comment)
#/ (multi line comment start)
/# (multi line comment end)
{} (thread)
package
import
inline
shared
variable
procedure_call
map
primitive
composite
procedure
loop
if
else if
else
& (and)
| (or)
try
catch
lock
unlock
allocate
free
*/

/* package
package_name
*/

/* import
alias_variable
import_path
*/

/* inline
c_code
*/

/* primitive
primitive_name
primitive_literal
item_delimiter (,)

/* shared
allocate
variable
*/

/* variable [1]
variable_name
index ([])
property_access
property_name
property_procedure_call
type_annotation
number_literal
string_literal
primitive_literal
composite_literal
item_delimiter (,)
arithmetic_expression
procedure_call
init_length ([])
init_number_literal
init_string_literal
init_primitive_literal
init_composite_literal
init_arithmetic_expression
init_procedure_call
*/

/* procedure
procedure_name
type_annotation
input_variable
# (single line comment)
#/ (multi line comment start)
/# (multi line comment end)
{} (thread)
package
import
inline
shared
variable
procedure_call
map
primitive
composite
procedure
loop
if
else if
else
& (and)
| (or)
try
catch
lock
unlock
allocate
free
return
return_variable_name
*/

/* procedure_call

*/

/* thread ({})
thread_name
*/

/* if / if else

*/


