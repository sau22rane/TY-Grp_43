//  Find max of two numbers
#include<stdio.h>
int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main (){
    int a = 0, b = 0;
    read(a);
    read(b);
    write(max(a,b));
    return 0;
}