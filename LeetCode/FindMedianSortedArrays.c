#include <stdlib.h>
//四个数中找中位数
double findMedianSortedArraysWithin4(int *nums, int numsSize)
{
    if(numsSize==2)
    {
        return ( nums[0]+nums[1] )/2.0;
    }
    if(numsSize==3)
    {
        if(nums[0]<nums[1] && nums[1]<nums[2])
        {
            return nums[1];
        }
        if(nums[0]<nums[2] && nums[2]<nums[1])
        {
            return nums[2];
        }
        return nums[0];
    }
    if(numsSize==4)
    {
        if( nums[3]<=nums[0] || (nums[0]>=nums[2] && nums[0]<=nums[3] && nums[1]>=nums[3]) )
            return ( nums[0]+nums[3] )/2.0;

        if( nums[1]<=nums[2] || (nums[1]>=nums[2] && nums[0]<=nums[2] && nums[1]<=nums[3]) )
            return ( nums[1]+nums[2] )/2.0;

        if( nums[0]<=nums[2] && nums[1]>=nums[3] )
            return ( nums[2]+nums[3] )/2.0;

        if( nums[0]>=nums[2] && nums[1]<=nums[3] )
            return ( nums[0]+nums[1] )/2.0;
    }
}

//使用归并排序
double findMedianSortedArraysByMergeSort(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if(!(nums1 && nums2))
        return 0;
    int total = nums1Size+nums2Size;
    int mid = total>>1;
    double result;
    int *mergedNums = (int *)malloc((nums1Size+nums2Size)*sizeof(int));
    int *p = mergedNums;
    int i=0, j=0, k=0;
    //归并
    while( i<nums1Size && j<nums2Size && k<=mid )
    {
        *p = nums1[i]<=nums2[j]?nums1[i++]:nums2[j++];//会先取到数组中值然后索引增一
        p++;

        k++;
    }

    if(k>mid)//已经过半
    {
        if((total)&1)//奇数
        {
            result = mergedNums[mid];
        }
        else
        {
            result = (mergedNums[mid-1]+mergedNums[mid])/2.0;
        }
        free(mergedNums);
        return result;
    }

    if(j<nums2Size)
    {
        i = j;
        nums1 = nums2;
        nums1Size = nums2Size;
    }
    while( i<nums1Size && k<=mid )
    {
        *p = nums1[i++];
        p++;

        k++;
    }//归并

    //已经过半
    if((total)&1)//奇数
    {
        result = mergedNums[mid];
    }
    else
    {
        result = (mergedNums[mid-1]+mergedNums[mid])/2.0;
    }
    free(mergedNums);
    return result;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{

}
#define GET_ARRAY_LEN(array, len) {len=sizeof(array)/sizeof(array[0]);}
//测试
void findMedianSortedArraysMain(void)
{
    int nums1[] = {0};
    int nums2[] = {1};
    int len1;
    int len2;
    GET_ARRAY_LEN(nums1, len1);
    GET_ARRAY_LEN(nums2, len2);
    printf("%d %d\n", len1, len2);
    printf("%f", findMedianSortedArraysByMergeSort(nums1, len1, nums2, len2));
    //int i=0;
    //printf("%d\n", nums1[i++]);
}
