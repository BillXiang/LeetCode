#include <stdio.h>

#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrix==NULL || matrixRowSize==0 || matrixColSize==0){
        return false;
    }
    int rowStart = 0;
    int mid = 0;
    int rowEnd = matrixRowSize-1;
    int colStart = 0;
    int colEnd = matrixColSize-1;
    do{
        mid = (rowStart+rowEnd)>>1;
        if( *(*(matrix+rowStart)+0)<target
           && *(*(matrix+mid)+colEnd)>target ){
            rowEnd = mid;
        }else if( (*(*(matrix+rowEnd)+colEnd))>target
                 && (*(*(matrix+mid)+colEnd))<target ){
            rowStart = mid+1;
        }else if(*(*(matrix+rowStart)+0)==target
                 || *(*(matrix+mid)+colEnd)==target
                 || *(*(matrix+rowEnd)+colEnd)==target){
            return true;
        }else{
            return false;
        }
        if(rowStart==rowEnd){
            while(colStart<colEnd){
                mid = (colStart+colEnd)>>1;
                if(*(*(matrix+rowStart)+colStart)<target
                   && *(*(matrix+rowStart)+mid)>target){
                    colEnd = mid;
                }else if(*(*(matrix+rowStart)+colEnd)>target
                         && *(*(matrix+rowStart)+mid)<target){
                    colStart = mid;
                }else if(*(*(matrix+rowStart)+colStart)==target
                         || *(*(matrix+rowStart)+mid)==target
                         || *(*(matrix+rowStart)+colEnd)==target){
                    return true;
                }else{
                    return false;
                }
                if(colStart+1==colEnd){
                    return false;
                }
            }
            return false;
        }
    }while(rowStart<rowEnd);
    return false;
}

void searchMatrixMain(void){
//    int row1[] = {1,2,3,4};
//    int row2[] = {5,6,7,8};
//    int row3[] = {9,10,11,12};
//    int *matrix[3] = {row1, row2, row3};
//    int row1[] = {1};
//    int *matrix[] = {row1};
    int row1[] = {1};
    int row2[] = {5};
    int row3[] = {9};
    int *matrix[3] = {row1, row2, row3};
    printf("%d\n", searchMatrix(matrix, 3, 1, 10));
}
