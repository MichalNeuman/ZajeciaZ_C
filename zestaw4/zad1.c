#include <stdio.h>

int factorial(int a){
    if(a==1){
        return a;
    }
    else{
    return a*factorial(a-1);
}
   
}

int main() {
    printf(" %d", factorial(5));
    return 0;
}
