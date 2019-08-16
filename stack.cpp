//
// Created by go_fo on 2019/8/15.
// 动态栈的初始化、压栈、出栈、遍历、清空
//
#include <cstdio>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} *PNode;

typedef struct Stack {
    PNode pTop;
    PNode pBottom;
} *PStack;

void init(PStack);

void push(PStack, int);

void traverse(PStack);

void pop(PStack, int *);

void clear(PStack);

int main() {
    Stack stack;
    int val;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    traverse(&stack);
    pop(&stack, &val);
    printf("\n出栈的值为 %d", val);
    clear(&stack);
    traverse(&stack);
}

void init(PStack pStack) {
    pStack->pBottom = (PNode) malloc(sizeof(Node));
    pStack->pBottom->pNext = nullptr;
    pStack->pTop = pStack->pBottom;
}

void push(PStack pStack, int toPush) {
    PNode newNode = (PNode) malloc(sizeof(Node));
    newNode->data = toPush;
    newNode->pNext = pStack->pTop;
    pStack->pTop = newNode;
}

void traverse(PStack pStack) {
    PNode pTmp = pStack->pTop;
    if (pTmp == pStack->pBottom) {
        printf("\n栈为空");
    } else printf("栈为:");
    while (pTmp != pStack->pBottom) {
        printf("%d", pTmp->data);
        pTmp = pTmp->pNext;
    }
}

void pop(PStack pStack, int *val) {
    PNode toPop = pStack->pTop;     //防止内存泄露
    pStack->pTop = pStack->pTop->pNext;
    *val = toPop->data;     //给指针变量指向的变量赋值
    free(toPop);
    toPop = nullptr;        //防止野指针
}

void clear(PStack pStack) {
    while (pStack->pTop != pStack->pBottom) {
        PNode p = pStack->pTop;
        pStack->pTop = pStack->pTop->pNext;
        free(p);
    }
}