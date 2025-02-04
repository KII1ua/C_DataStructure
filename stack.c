//
// Created by 황성윤 on 2/5/25.
//

#include <stdio.h>
#define MAX 20
char stack[MAX];
int top = -1;
char pop();
void d_stack();
void push(char);

void main() {
    printf("<<배열 이용한 스택(stack)에서의 삽입 삭제>>\n\n");
    while(1) {
        printf("\n---- Selection number(1, or 2,or 0) ---\n");
        printf("   1.push     2.pop    0.end \n");
        printf("-----------------------------------------\n\n");
        switch(getchar()) {
            printf("----- Press character -------------------\n");
            case '1':
                printf("PUSH: ");
                push(getchar());
                d_stack();
                break;
            case '2':
                printf("POP: ");
                printf("%c", pop());
                d_stack();
                break;
            case '0': return;
        }
    }
}

void push(char push_in) {
    if(top == MAX) puts("stack is full! Insertion is impossible!");
    else {
        top++;
        stack[top] = push_in;
    }
}

void d_stack() {
    int i;
    printf("\n current STACK state: ");

    for(i = 0; i <= top; i++)
        putchar(stack[i]);
    printf("\n");
}

char pop() {
    char pop_result;

    if(top == 1) puts("stack is empty! Deletion is impossible!");
    else {
        pop_result = stack[top];
        top--;
    }
    return pop_result;
}