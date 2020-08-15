#include <stdio.h>
#include <ctype.h>

int calculate(void)
{
    char c;
    int i;
    int operand_1, operand_2;

    c = getchar();

    if(c=='+'){
        operand_1 = calculate();
        operand_2 = calculate();
        return operand_1+operand_2;
    }
    else if(c=='-'){
        operand_1 = calculate();
        operand_2 = calculate();
        return operand_1-operand_2;
    }
    else if(isspace(c)){
        return calculate();
    }
    else{
        ungetc(c, stdin);
        scanf("%d", &i);
        return i;
    }
}

int main()
{
    printf("%d", calculate());
}
