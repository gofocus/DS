//
// Created by go_fo on 2019/8/1.
//

#include <stdio.h>
#include <malloc.h>


typedef struct Node {
    int data;
    struct Node *pNext;
}Node, *PNode;

PNode create_list();
void traverse_list(PNode);
bool is_empty(PNode);
int length_list(PNode);
bool insert_list(PNode);

bool delete_list(PNode, int, int);
void sort_list(PNode);


int main()
{
    PNode pHead = nullptr;
    pHead = create_list();
    sort_list(pHead);
    traverse_list(pHead);

    if (is_empty(pHead)) {
        printf("链表为空\n");
    }
    printf("链表长度为%d\n", length_list(pHead));

    return 0;
}

PNode create_list()
{
    int len;
    int i;
    int val;

    printf("输入要创建的节点的个数:");
    scanf("%d", &len);

    PNode pHead = (PNode)malloc(sizeof(Node));
    PNode pTail = pHead;
    pTail->pNext = nullptr;

    for (i = 0; i < len; i++) {
        printf("输入第%d个节点的值", i + 1);
        scanf("%d", &val);
        Node *pNew = (Node*)malloc(sizeof(Node));
        pNew->data = val;
        pNew->pNext = nullptr;

        pTail->pNext = pNew;
        pTail = pNew;
    }

    return pHead;
}

void traverse_list(PNode pNode) {
    pNode = pNode->pNext;
    printf("链表为");
    while (pNode != nullptr) {
        printf("%d ", pNode->data);
        pNode = pNode->pNext;
    }
    printf("\n");
}

bool is_empty(PNode pNode) {
    return pNode->pNext == nullptr;
}

int length_list(PNode pNode) {
    int len = 0;
    while (pNode->pNext != nullptr)
    {
        len++;
        pNode = pNode->pNext;
    }
    return len;
};

//只交换数据域
void sort_list(PNode pHead) {
    PNode p1 = pHead->pNext;
    PNode p2 = p1->pNext;
    int len = length_list(pHead);
    int cnt = 1;
    while (cnt < len) {
        while (p2 != NULL) {
            if (p1->data > p2->data) {
                int tmp = p1->data;
                p1->data = p2->data;
                p2->data = tmp;
            }
            p2 = p2->pNext;
        }
        p1 = p1->pNext;
        p2 = p1->pNext;
        cnt++;
    }
};

bool insert_list(PNode pNode) {

    return false;
};

bool delete_list(PNode pNode, int i,int j) {

    return false;
};



