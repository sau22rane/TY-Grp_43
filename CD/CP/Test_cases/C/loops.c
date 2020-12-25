int main(){
    int i = 1, fib =1;
    int target = 10;
    int temp = 0;
    while(i < target){
        temp = fib;
        fib += temp;
        i++;
    }
    write(fib);
    return 0;
}