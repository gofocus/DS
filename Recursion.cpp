//
// Created by go_fo on 2019/8/21.
//
#include <cstdio>
#include <malloc.h>

//求阶乘 TODO
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

//TODO  汉诺塔
void hanoi(int n, char X, char Y, char Z){
    if (1 == n) {
        printf("将%c柱子上编号为%d的盘子直接移到%c柱子上\n", X, n, Z);
    }
    else {
        hanoi(n - 1, X, Z, Y);
        printf("将%c柱子上编号为%d的盘子直接移到%c柱子上\n", X, n, Z);
        hanoi(n - 1, Y, X, Z);
    }

}


int main(){
    printf("阶乘%d\n", factorial(5));
    printf("累加和%d\n", sn(5));
    hanoi(3,'A', 'B', 'C');
}