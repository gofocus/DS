//
// Created by go_fo on 2019/8/21.
//
#include <cstdio>
#include <malloc.h>

//��׳� TODO
int factorial(int n){
    if (1 == n) {
        return 1;
    }
    else {
        return factorial(n - 1) * n;
    }
}

int sn(int n){
    if (1 == n) {
        return 1;
    } else {
        return sn(n - 1) + n;
    }

}

//TODO  ��ŵ��
void hanoi(int n, char X, char Y, char Z){
    if (1 == n) {
        printf("��%c�����ϱ��Ϊ%d������ֱ���Ƶ�%c������\n", X, n, Z);
    }
    else {
        hanoi(n - 1, X, Z, Y);
        printf("��%c�����ϱ��Ϊ%d������ֱ���Ƶ�%c������\n", X, n, Z);
        hanoi(n - 1, Y, X, Z);
    }

}


int main(){
    printf("�׳�%d\n", factorial(5));
    printf("�ۼӺ�%d\n", sn(5));
    hanoi(3,'A', 'B', 'C');
}