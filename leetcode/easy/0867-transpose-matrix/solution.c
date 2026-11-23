/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
       int rows = matrixSize, cols = matrixColSize[0];
    *returnSize = cols;
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));
    int** res = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        res[i] = (int*)malloc(rows * sizeof(int));
        (*returnColumnSizes)[i] = rows;
        for (int j = 0; j < rows; j++)
            res[i][j] = matrix[j][i];
    }
    return res; 
}