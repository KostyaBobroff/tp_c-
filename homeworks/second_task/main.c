#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
//atof - преобразование из строки в число

struct operationNode {
    char operation;
    int priority;
    struct operationNode *next;
};

struct numberNode {
    double number;
    struct numberNode *next;
};

//sprintf(s,"%f", d);d-double s-string

char claculate (char * expression){
    size_t curPosistion = 0;
    size_t sizeOfOperations = 0;
    size_t sizeOfNumbers = 0;
    struct operationNode *operationStack = NULL;
    struct operationNode *tmpOperation = NULL;
    struct numberNode *tmpNumber = NULL;
    struct numberNode *numberStack = NULL;
    char buf[256];
    if(expression[curPosistion] == '('){
        operationStack = malloc(sizeof(struct operationNode));
        operationStack->priority = -1;
        operationStack->operation = '(';
        operationStack->next = NULL;
        curPosistion++;
        sizeOfOperations++;
    }else{
        if(atof(expression) || expression[0] == 0){
            numberStack = malloc(sizeof(struct numberNode));
            numberStack->number = atof(expression);
            numberStack->next = NULL;
            sizeOfNumbers++;
            sprintf(buf, "%f",numberStack->number);
            curPosistion += strlen(buf);
        }else{
            printf("[error]");
            exit(0);
        }
    }

    while(expression[curPosistion]){
        if()
//        switch(expression[curPosistion]){
//            case '+' :
//                tmpOperation = operationStack;
//                operationStack = malloc(sizeof(struct operationNode));
//                operationStack->next = tmpOperation;
//                operationStack->operation = '+';
//                operationStack->priority = 1;
//                break;
//            case '-':
//                tmpOperation = operationStack;
//                operationStack = malloc(sizeof(struct operationNode));
//                operationStack->next = tmpOperation;
//                operationStack->operation = '-';
//                operationStack->priority = 1;
//                break;
//            case '*':
//                tmpOperation = operationStack;
//                operationStack = malloc(sizeof(struct operationNode));
//                operationStack->next = tmpOperation;
//                operationStack->operation = '*';
//                operationStack->priority = 2;
//                break;
//            case '/':
//                tmpOperation = operationStack;
//                operationStack = malloc(sizeof(struct operationNode));
//                operationStack->next = tmpOperation;
//                operationStack->operation = '/';
//                operationStack->priority = 2;
//                break;
//            default:
//
//                break;
//        }
        curPosistion++;
    }
}


int main(){
    char *expression = NULL;
    expression = malloc(256);
    scanf("%s", expression);
//    expresion[0] = '(';
//    scanf("%s", expresion + 1);
//    expresion[strlen(expresion)] = ')';
//    expresion[strlen(expresion)+1] = '\0';
//    int * priority = calloc(strlen(expresion), sizeof(int));
//
//    printf("%s", expresion);
//    printf("%f", atof(expresion+1));
     free(expression);
//    free(priority);

    return 0;
}