#include <stdio.h>

#define MAX 100

// Function to print sparse matrix
void printSparse(int trans[MAX][3], int size) {
    printf("Row Col Val\n");
    for(int i = 0; i < size; i++)
        printf("%3d %3d %3d\n", trans[i][0], trans[i][1], trans[i][2]);
}

// Function to transpose a sparse matrix
void transposeSparse(int mat[MAX][3], int trans[MAX][3]) {
    trans[0][0] = mat[0][1]; // rows become columns
    trans[0][1] = mat[0][0]; // columns become rows
    trans[0][2] = mat[0][2]; // number of non-zero elements

    int k = 1;
    for(int i = 0; i < mat[0][1]; i++) { // scan by column index
        for(int j = 1; j <= mat[0][2]; j++) {
            if(mat[j][1] == i) { //- the column index of the j‑th non‑zero element.
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}



int main() {
    // Example sparse matrix in triplet form
    int mat[MAX][3] = {
        {3, 3, 2},  // 3x3 matrix, 2 non-zero
        {0, 2, 3},
        {1, 2, 5}

    };
    int trans[MAX][3];

    // Transpose mat1
    transposeSparse(mat, trans);
    printf("Transpose of Matrix:\n");
    printSparse(trans, trans[0][2] + 1);

    return 0;
}
