#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int allocMatrix(int*** mat, int order) {
	// Allocate rows*cols contiguous items
	int* p = (int*)malloc(sizeof(int*) * order * order);
	if (!p) {
		return -1;
	}
	// Allocate row pointers
	*mat = (int**)malloc(order * sizeof(int*));
	if (!mat) {
		free(p);
		return -1;
	}

	// Set up the pointers into the contiguous memory
	for (int i = 0; i < order; i++) {
		(*mat)[i] = &(p[i * order]);
	}
	return 0;
}

int** add(int** M1, int** M2, int n) {
    int** temp;
    allocMatrix(&temp,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int** subtract(int** M1, int** M2, int n) {
    int** temp;
    allocMatrix(&temp,n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}

int freeMatrix(int ***mat) {
	free(&((*mat)[0][0]));
	free(*mat);
	return 0;
}

int** strassenMultiply(int** A, int** B, int n){
    if (n == 1) {
        int** C;
        allocMatrix(&C,n);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int** C;
    allocMatrix(&C,n);
    int k = n/2;

    int **A11, **A12, **A21, **A22, **B11, **B12, **B21, **B22;
    allocMatrix(&A11,n);
    allocMatrix(&A12,n);
    allocMatrix(&A21,n);
    allocMatrix(&A22,n);
    allocMatrix(&B11,n);
    allocMatrix(&B12,n);
    allocMatrix(&B21,n);
    allocMatrix(&B22,n);
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k+j];
            A21[i][j] = A[k+i][j];
            A22[i][j] = A[k+i][k+j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k+j];
            B21[i][j] = B[k+i][j];
            B22[i][j] = B[k+i][k+j];
        }
    }
    int** P1 = strassenMultiply(A11, subtract(B12, B22, k), k);
    int** P2 = strassenMultiply(add(A11, A12, k), B22, k);
    int** P3 = strassenMultiply(add(A21, A22, k), B11, k);
    int** P4 = strassenMultiply(A22, subtract(B21, B11, k), k);
    int** P5 = strassenMultiply(add(A11, A22, k), add(B11, B22, k), k);
    int** P6 = strassenMultiply(subtract(A12, A22, k), add(B21, B22, k), k);
    int** P7 = strassenMultiply(subtract(A11, A21, k), add(B11, B12, k), k);
    
    freeMatrix(&A11);
    freeMatrix(&A12);
    freeMatrix(&A21);
    freeMatrix(&A22);
    freeMatrix(&B11);
    freeMatrix(&B12);
    freeMatrix(&B21);
    freeMatrix(&B22);
    
    int** C11 = subtract(add(add(P5, P4, k), P6, k), P2, k);
    int** C12 = add(P1, P2, k);
    int** C21 = add(P3, P4, k);
    int** C22 = subtract(subtract(add(P5, P1, k), P3, k), P7, k);

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++) {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[k+i][j] = C21[i][j];
            C[k+i][k+j] = C22[i][j];
        }
    }

    
    freeMatrix(&P1);
    freeMatrix(&P2);
    freeMatrix(&P3);
    freeMatrix(&P4);
    freeMatrix(&P5);
    freeMatrix(&P6);
    freeMatrix(&P7);
    freeMatrix(&C11);
    freeMatrix(&C12);
    freeMatrix(&C21);
    freeMatrix(&C22);

    return C;
}



int main(int argc, char* argv[]){
    clock_t t;
    int order = atoi(argv[1]);
    int **A = NULL, **B = NULL, **C = NULL;
    int* p = (int*)malloc(sizeof(int*) * order * order);
    if(allocMatrix(&A,order) == -1)
        exit;
    if(allocMatrix(&B,order) == -1)
        exit;
    if(allocMatrix(&C,order) == -1)
        exit;

    
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
    C = strassenMultiply(A, B, order);
    t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("%f ", time_taken);
    return 0;
}

