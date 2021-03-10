#include "lite_parsing.h"

char code[100] = {"var: 42"};

int main() {
    int digit_result = digit('1');
    int symbol_result = symbol(':');
    int lower_result = lower('a');
    int upper_result = upper('A');
    int space_result = space(' ');

    printf("digit() = %d\n", digit_result);
    printf("symbol() = %d\n", symbol_result);
    printf("lower() = %d\n", lower_result);
    printf("upper() = %d\n", upper_result);
    printf("space() = %d\n", space_result);

    return 0;
}

/* future API?

enable_aritmetic();
enable_comparison();
enable_assignemt();
enable_flow();

GENERAL
- Arithemtic
arithmetic_token_add("+");
token_subtract("-");
token_multiply("*");
token_divide("/");
arithmetic_rule_();


-Assignment
assignment_token(":");

-Comparison
token_equal("=");
token_not_equal("!=");
token_lesser("<");
token_greater(">");
token_not_lesser("!<");
token_not_greater("!>");

-Flow
token_conditional_initiator("if");
token_conditional_alternative("if else");
token_conditional_default("else");

SPECIFIC
token_keyword("import");
token_keyword("function");


RULES

