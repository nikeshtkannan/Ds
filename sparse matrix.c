#include <stdio.h>

void transpose(int a[10][3], int t[10][3]) {
    t[0][0] = a[0][1];    // rows become cols
    t[0][1] = a[0][0];    // cols become rows
    t[0][2] = a[0][2];    // number of non-zero elements stays the same
    int k = 1;
    for (int i = 0; i < a[0][1]; i++) {
        for (int j = 1; j <= a[0][2]; j++) {
            if (a[j][1] == i) {
                t[k][0] = a[j][1];  // column becomes row
                t[k][1] = a[j][0];  // row becomes column
                t[k][2] = a[j][2];  // value stays same
                k++;
            }
        }
    }
}

void add(int a[10][3], int b[10][3], int result[20][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Addition not possible due to size mismatch\n");
        return;
    }
    result[0][0] = a[0][0];
    result[0][1] = a[0][1];
    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] || 
                  (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++; k++;
        } else {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++; k++;
        }
    }

    // Copy remaining terms
    while (i <= a[0][2]) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }
    result[0][2] = k - 1; // total non-zero values
}

void printSparse(int mat[20][3]) {
    printf("Row Col Val\n");
    for (int i = 0; i <= mat[0][2]; i++) {
        printf(" %2d  %2d  %2d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

int main() {
    int a[10][3] = {
        {3, 3, 2},   // 3x3 matrix, 2 non-zero
        {0, 2, 3},
        {1, 2, 5}
    };

    int b[10][3] = {
        {3, 3, 2},   // 3x3 matrix, 2 non-zero
        {0, 1, 2},
        {1, 2, 1}
    };

    int t[10][3], result[20][3];

    printf("Transpose of Matrix 1:\n");
    transpose(a, t);
    printSparse(t);

    printf("\nSum of Matrix 1 and Matrix 2:\n");
    add(a, b, result);
    printSparse(result);

    return 0;
}
