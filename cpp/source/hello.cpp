#include <iostream>
#include <conio.h>
#include <stdio.h>

#define LIMIT 100

int main(){
    int a = 0;
    int * ap;
    ap = &a;
    *ap = 20;

    std::cout << "Hello World!" << std::endl;
    std::cout << "Hello World!" << std::endl;
    printf("Buenas noches");
    return 0;
}