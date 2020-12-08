#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("A_Matrix.txt","w+");
    for(int i = 0;i< 1000; i++){
        for(int j = 0;j<1000;j++){
            fprintf(fp,"%d ",rand() % 20);
        }
    }
    printf("Matrix A created\n");
    fclose(fp);

    fp = fopen("B_Matrix.txt","w+");
    for(int i = 0;i< 1000; i++){
        for(int j = 0;j<1000;j++){
            fprintf(fp,"%d ",rand() % 20);
        }
    }
    printf("Matrix B created\n");
    fclose(fp);

    return 0;
}