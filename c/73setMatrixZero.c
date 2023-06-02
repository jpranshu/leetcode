void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,flag=1;
    int n=matrixSize;
    int m=*matrixColSize;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){

            if(matrix[i][j]==0){

                matrix[i][0]=0;
                if(j!=0)
                    matrix[0][j]=0;
                else
                    flag=0;
            }
        }
    }

    for(i=1;i<n;i++){
        if(matrix[i][0]==0){
            for(j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    for(j=1;j<m;j++){
        if(matrix[0][j]==0){
            for(i=0;i<n;i++){
                if(matrix[i][j]!=0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    if(matrix[0][0]==0){
        for(int j=1;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(flag==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}