/*
Let's do a simple case:
   0, 1, 2
0 [3, 0, 1]
1 [5, 6, 3]
If we consider simple rows of 1D, its prefix
sums array would be, in horizontal direction:
   0, 1, 2
0 [3, 3, 4]
1 [8, 14, 18]

The key idea is to carry
the up sum, because in that way
we are adding up the sum of the
whole rectangle.

So, what would be the area of 1, 1 and 1, 2?
It would be the value of the lower right
corner minus the above sum (upper right) and the
left side sum (lower left) and add the
upper left corner diagonal (r1 - 1, c1 - 1)

Pseudocode:
NumMatrix {
Fill our PrefixMatrix, adding one more row
and one more column filled with zeroes, because
when we are filling the first row, remember
we sum our current prefix sum plus the above
value, to carry all the "sum", so filling
the first row without this extra row, would
be row = 0, above value is in row - 1, so
0 - 1 = -1, out of bounds, adding this row
would be, row = 1, row - 1 = 0, the upper
value would be 0, so it does not contribute
to our sum which is correct

for each row in our original matrix
    initialize our prefix row sum variable
    for each column in our original matrix
        add the current value to our prefix varible
        add the upper value to our prefix varible,
        this upper value comes from our prefixMatrix
        write that value in our prefixMatrix
        considering the offset
}

sumRegion {
    int lowerRight = prefixMatrix[row2][col2];
    int upperRight = prefixMatrix[row1 - 1][col2];
    int lowerLeft = prefixMatrix[row2, col1 - 1];
    return lowerRight - upperRight - lowerLeft + prefixMatrix[row1 - 1, col1 - 1];
}

*/

class NumMatrix {
    vector<vector<int>> prefixMatrix;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = (int)matrix.size();
        int COLS = (int)matrix[0].size();
        prefixMatrix.assign(ROWS + 1, vector<int>(COLS + 1));

        for (int row = 0; row < ROWS; row++) {
            int prefixSum = 0;
            for (int col = 0; col < COLS; col++) {
                prefixSum += matrix[row][col];
                prefixMatrix[row + 1][col + 1] = prefixSum + prefixMatrix[row][col + 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int lowerRight = prefixMatrix[row2+1][col2+1];
        int upperRight = prefixMatrix[row1][col2+1];
        int lowerLeft = prefixMatrix[row2+1][col1];
        return lowerRight - upperRight - lowerLeft + prefixMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */