'use strict';

//code
const file = await Deno.open("lite_tests.txt", { read: true });
const code = await Deno.readAll(file);
Deno.close(file.rid);

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

console.log(code);

//write test here for each function in compiler.