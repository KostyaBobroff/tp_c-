#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>


/*
 * Составить программу для перевода чисел из системы счисления по основанию P в систему счисления по основанию Q,
 * где 2 меньше или равно Q меньше P меньше или равно 36.
Значения P, Q и строковое представление S числа в исходной системе счисления вводятся с клавиатуры в следующем порядке:
P Q S

S не выходит за границы size_t.

Процедура перевода не может использовать соответствующей функции системной библиотеки и должна быть оформлена
в виде отдельной функции, на вход которой подаются значения P, Q и S, размещенные в динамической памяти.
На выход функция должна возвращать строковое представление S1 числа в целевой системе счисления.

Программа должна уметь обрабатывать ошибки во входных данных.
В случае возникновения ошибки нужно вывести в поток стандартного вывода сообщение "[error]" (без кавычек)
и завершить выполнение программы.

ВАЖНО! Программа в любом случае должна возвращать 0.
 Не пишите return -1, exit(1) и т.п. Даже если обнаружилась какая-то ошибка,
 все равно необходимо вернуть 0! (и напечатать [error] в stdout).
 */


size_t power(size_t a, size_t n){
    size_t result = 1;
    size_t power = a;
    while(n > 0) {
        if((n & 1) == 1) {
            result *= power;
        }
        power *= power;
        n = n >> 1;
    }
    return result;
}

void reverseString(char * str){
    size_t end = strlen(str) - 1;
    size_t begin = 0;
    char tmp;
    while((begin != end) && (begin - 1 != end )) {
        tmp = str[end];
        str[end] = str[begin];
        str[begin] = tmp;
        begin++;
        end--;
    }

}

void from10toQ(size_t *Q, size_t number, char * buf){
    size_t i = 0;
    while(number >= *Q){
        if (number % *Q < 10) {
            buf[i] = (char) (number % *Q + '0');
        } else{
            buf[i] = (char) (number % *Q + 'A' - 10);
        }
        number /= *Q;
        i++;

    }
    if(number < 10){
        buf[i++] = (char)(number  + '0');
    }else{
        buf[i++] = (char)(number + 'A' - 10);
    }

    buf[i] = '\0';
    reverseString(buf);

}




size_t fromPto10(size_t *P, size_t *Q, char * number){
    size_t size = (size_t)strlen(number);
    size_t i = size;
    size_t k = 0;
    size_t res = 0;
    bool t;
    while(i--){
        t = false;
        if((47 < number[i]) && (number[i]< 58)){
            if((size_t) number[i] - (char)48 < *P ){
                res +=  ((size_t) number[i] - '0') *  power(*P, k);
                t = true;
            }
            else{
                printf("[error]");
                exit(0);
            }

        }
        if((64 < number[i]) && ( number[i]< 91)){
            if((size_t) number[i] - (char)55 < *P) {
                res += ((size_t) number[i] - (char) 55) * power(*P, k);
                t = true;
            }else{
                printf("[error]");
                exit(0);
            }
        }
        if((96 < number[i]) && (number[i] < 123)){
            if ((size_t) number[i] - (char)87 < *P){
                res +=((size_t) number[i] - (char)87) * power(*P, k);
                t = true;
            }else{
                printf("[error]");
                exit(0);
            }
        }

        if(!t){
            printf("[error]");
            exit(0);
        }
        k++;

    }

    return res;

}

char * fromPtoQ(size_t *P, size_t *Q, char * number){
    if((*Q < 2) || (*Q >= *P) || (*P > 36)){
        printf("[error]");
        exit(0);
    }
    size_t inDecimal = fromPto10(P, Q, number);
    free(number);
    number = calloc(255,1);
    if(!number){
        printf("[error]");
        exit(0);
    }
    from10toQ(Q, inDecimal, number);
    return number;
}


int main(){
    size_t *P = NULL, *Q = NULL;
    char *number = NULL, *number2 = NULL;
    P = malloc(8);
    Q = malloc(8);
    number = calloc(255, 1);
    if((P == NULL) || (Q == NULL) || (number == NULL)){
        printf("[error]");
        exit(0);
    }
    scanf("%zu %zu %s", P, Q, number);
    number2 = fromPtoQ(P, Q, number);
    if(!number2){
        printf("[error]");
        exit(0);
    }
    printf("%s", number2);
    free(P);
    free(Q);
    free(number2);
    return 0;
}

