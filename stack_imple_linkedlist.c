//
// Created by 황성윤 on 2/5/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

typedef struct stackNode {
    int data;
    struct stackNode *link;
} stackNode;

stackNode *top;

int isEmpty() {
    if(top == NULL) return 1;
    else return 0;
}

void push(int item) {
    stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

int pop() {
    int item;
    stackNode* temp = top;

    if(top == NULL) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

void d_stack() {
    stackNode* p = top;
    int i;
    printf("\n current STACK state(top==>bottom): ");
    while(p) {
        putchar(p->data);
        p = p->link;
    }
    printf("\n");
}

void main(void) {
    int item;
    top = NULL;

    printf("<<포인터 이용한 스택(stack)에서의 삽입 삭제>>\n\n");
    while(1) {
        printf("\n---- Selection number(1, or 2, or 0) ---\n");
        printf("   1.push     2.pop    0.end \n");
        printf("-----------------------------------------\n");
        switch(getchar()) {
            printf("---- Press character -----------------\n");
            case '1':
                printf("PUSH: ");
                printf(" 영문자 Key pressed ==> "); push(getch()); d_stack();
                printf("\n");
                printf("    영문자 key pressed ==> "); push(getch()); d_stack();
                printf("\n");
                printf("    영문자 key pressed ==> "); push(getch()); d_stack();
                printf("\n");
                printf(" 영문자 key pressed ==> "); push(getch()); d_stack();
                printf("\n");
                printf("    영문자 key pressed ==> "); push(getch()); d_stack();
                printf("\n");
                break;
            case '2': printf("POP: ");
                putchar(pop()); d_stack;
                printf("\n");
                printf("POP:    ");
                putchar(pop()); d_stack();
                printf("\n");
                printf("POP:    ");
                putchar(pop()); d_stack();
                printf("\n");
                printf("POP     ");
                putchar(pop()); d_stack();
                printf("\n");
                printf("POP:    ");
                putchar(pop()); d_stack();
                printf("\n");
                break;
            case '0': return;
        }
    }
}