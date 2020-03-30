#include <iostream>
#include <conio.h>
#include <stdio.h>

#define LIMIT 100

using namespace std;

int main(){
    int a = 0;
    int * ap;
    ap = &a;
    *ap = 20;

    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl;
    printf("Buenas noches");
    return 0;
}