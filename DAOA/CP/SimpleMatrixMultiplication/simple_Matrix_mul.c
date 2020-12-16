#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int main(int argc, char* argv[]){
    clock_t t; 
    int order = atoi(argv[1]);
    int **A = NULL, **B = NULL, **C = NULL;
    int* p = (int*)malloc(sizeof(int*) * order * order);
    A = (int**)malloc(order * sizeof(int*));
    for (int i = 0; i < order; i++) {
		A[i] = &(p[i * order]);
	}

    int* q = (int*)malloc(sizeof(int*) * order * order);
    B = (int**)malloc(order * sizeof(int*));
    for (int i = 0; i < order; i++) {
		B[i] = &(q[i * order]);
	}

    int* r = (int*)malloc(sizeof(int*) * order * order);
    C = (int**)malloc(order * sizeof(int*));
    for (int i = 0; i < order; i++) {
		C[i] = &(r[i * order]);
	}

    FILE *fp;
    int n;
    fp = fopen("../Data/A_Matrix.txt", "r");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            fscanf(fp, "%d", &n);
            A[i][j] = n;
        }
    }
    fclose(fp);

    fp = fopen("../Data/B_Matrix.txt", "r");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            fscanf(fp, "%d", &n);
            B[i][j] = n;
        }
    }
    fclose(fp);

    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            C[i][j] = 0;
        }
    }

    t = clock();
     for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++){
            for(int k = 0; k< order; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
     }
    t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("%f ", time_taken);
}
