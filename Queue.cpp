//
// Created by go_fo on 2019/8/16.
// 循环队列
#include <cstdio>
#include <malloc.h>

typedef struct Queue {
    int *pBase;
    int front;
    int rear;
} Queue;

void init(Queue *);

bool entry(Queue *, int val);

int exit(Queue *);

bool isFull(Queue *);

void traverse(Queue *);

int main() {
    Queue queue;
    init(&queue);
    entry(&queue, 1);
    entry(&queue, 2);
    entry(&queue, 3);
    entry(&queue, 4);
    entry(&queue, 5);
    entry(&queue, 6);
    entry(&queue, 7);
    traverse(&queue);
    printf("%d\n", exit(&queue));
    printf("%d\n", exit(&queue));
    printf("%d\n", exit(&queue));
    entry(&queue, 8);
    entry(&queue, 9);
    entry(&queue, 10);
    traverse(&queue);

    return 0;
}

void init(Queue *pQueue) {
    pQueue->front = 0;
    pQueue->rear = 0;
    pQueue->pBase = (int *) malloc(sizeof(int) * 7);
}

bool entry(Queue *pQueue, int val) {
    if (isFull(pQueue)) {
        return false;
    } else {
        pQueue->pBase[pQueue->rear] = val;
        pQueue->rear = (pQueue->rear + 1) % 7;  //
        return true;
    }
}

int exit(Queue *pQueue) {   //
/*    if (pQueue->rear != pQueue->front) {
        if (pQueue->rear == 0 && pQueue->front != 0) {
            pQueue->rear += 7;
        }
        pQueue->rear--;
        return pQueue->pBase[pQueue->rear];
    } else return 0;    //todoError:队列是先进先出
*/
    while (pQueue->rear != pQueue->front){
        pQueue->front = pQueue->front % 7;
        return pQueue->pBase[pQueue->front++];
    }
}


bool isFull(Queue *pQueue) {
    return (pQueue->rear + 1) % 7 == pQueue->front;
}

void traverse(Queue *pQueue) {
    int i = pQueue->front;
//    while (i < pQueue->rear) {
    while (i != pQueue->rear) {
        printf("%d ", pQueue->pBase[i]);
        i = (i + 1) % 7;
    }
    printf("\n");
}

