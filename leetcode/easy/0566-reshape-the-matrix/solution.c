/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
       int m = matSize, n = matColSize[0];
    if (m * n != r * c) {
        r = m;
        c = n;
    }
    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    int** res = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        res[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }
    for (int k = 0; k < r * c; k++)
        res[k / c][k % c] = mat[k / n][k % n];
    return res; 
}