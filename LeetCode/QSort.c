#include <stdlib.h>
/**
快排
**/

/**
交换
**/
void my_swap(int *array, int i, int j)
{
    if(array!=NULL && i!=j)
    {
        array[i] ^= array[j];
        array[j] = array[i]^array[j];
        array[i] = array[i]^array[j];
    }
}

int index_partition(int *array, int *index, int start, int end)
{
    if(start>=end || array==NULL)
        return -1;
    int i = start;
    int j = end;

    while(i<j)
    {
        while(i<j && array[i]<array[j])
            j--;
        if(i<j)
        {
            my_swap(array, i, j);
            my_swap(index, i, j);
            i++;
        }
        while(i<j && array[i]<array[j])
            i++;
        if(i<j)
        {
            my_swap(array, i, j);
            my_swap(index, i, j);
            j--;
        }
    }
    return i;
}
/**
快排，另外存贮原来各元素位置
**/
void my_index_qsort(int *array, int *index, int start, int end )
{
    if(start>=end || array==NULL)
        return;
    int p = index_partition(array, index, start, end);
    if(p==-1)
        return;
    if(p-1 > start)
        my_index_qsort(array, index, start, p-1);
    if(p+1 < end)
        my_index_qsort(array, index, p+1, end);
}
