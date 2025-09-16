#include <stdio.h>

#define MAX 100

// Function to print sparse matrix
void printSparse(int mat[MAX][3], int size) {
    printf("Row Col Val\n");
    for(int i = 0; i < size; i++)
        printf("%3d %3d %3d\n", mat[i][0], mat[i][1], mat[i][2]);
}

// Function to transpose a sparse matrix
void transposeSparse(int mat[MAX][3], int trans[MAX][3]) {
    trans[0][0] = mat[0][1]; // rows become columns
    trans[0][1] = mat[0][0]; // columns become rows
    trans[0][2] = mat[0][2]; // number of non-zero elements

    int k = 1;
    for(int i = 0; i < mat[0][1]; i++) { // scan by column index
        for(int j = 1; j <= mat[0][2]; j++) {
            if(mat[j][1] == i) {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

// Function to add two sparse matrices
int addSparse(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Matrix sizes don’t match!\n");
        return 0;
    }

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    int i = 1, j = 1, k = 1;
    while(i <= a[0][2] && j <= b[0][2]) {
        if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        } else if(a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        } else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    while(i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }

    while(j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
    return k;
}

int main() {
    // Example sparse matrix in triplet form
    int mat1[MAX][3] = {
        {3, 3, 2},  // 3x3 matrix, 2 non-zero
        {0, 2, 3},
        {1, 2, 5}
    };

    int mat2[MAX][3] = {
        {3, 3, 2},
        {0, 1, 2},
        {1, 2, 1}
    };

    int trans[MAX][3], sum[MAX][3];

    // Transpose mat1
    transposeSparse(mat1, trans);
    printf("Transpose of Matrix 1:\n");
    printSparse(trans, trans[0][2] + 1);

    // Sum mat1 + mat2
    int sumSize = addSparse(mat1, mat2, sum);
    printf("\nSum of Matrix 1 and Matrix 2:\n");
    printSparse(sum, sumSize);

    return 0;
}
