//
// Created by go_fo on 2019/8/15.
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

int main() {
    Stack stack;
    init(&stack);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    traverse(&stack);

}

void init(PStack pStack) {
    pStack->pBottom = (PNode) malloc(sizeof(Node));
    pStack->pBottom->pNext = nullptr;
    pStack->pTop = pStack->pBottom;
}

void push(PStack pStack, int toPush){
    PNode newNode = (PNode) malloc(sizeof(Node));
    newNode->data = toPush;
    newNode->pNext = pStack->pTop;
    pStack->pTop = newNode;
}

void traverse(PStack pStack) {
    PNode pTmp = pStack->pTop;
    while (pTmp != pStack->pBottom) {
        printf("%d", pTmp->data);
        pTmp = pTmp->pNext;
    }

}
