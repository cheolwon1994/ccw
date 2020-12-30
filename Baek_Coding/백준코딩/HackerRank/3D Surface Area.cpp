int surfaceArea(vector<vector<int>> A) {
    int row = A.size();
    int col = A[0].size();
    int result = 2*row*col;
    for(int i=0;i<row;i++){
        result+=A[i][0]+A[i][col-1];
        for(int j=0;j<col-1;j++)
            result+=abs(A[i][j]-A[i][j+1]);
    }
    for(int j=0;j<col;j++){
        result+=A[0][j]+A[row-1][j];
        for(int i=0;i<row-1;i++)
            result+=abs(A[i][j]-A[i+1][j]);
    }
    return result;
}