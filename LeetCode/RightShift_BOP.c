//void Reverse(int* array, int start, int end){
//    int i = 0;
//    int mid = (end-start)>>1;
//    for(; i<mid; i++){
//        array[start+i] += array[end-i];
//        array[end-i] = array[start+i]-array[end-i];
//        array[start+i] = array[start+i]-array[end-i];
//    }
//    if(start+i!=end-i){
//        array[start+i] += array[end-i];
//        array[end-i] = array[start+i]-array[end-i];
//        array[start+i] = array[start+i]-array[end-i];
//    }
//}
void Reverse(int* array, int start, int end){
    while(start<end){
        array[start] += array[end];
        array[end] = array[start]-array[end];
        array[start] = array[start]-array[end];
        start++;
        end--;
    }
}
void RightShift(int* array, int size, int shift){
    shift = shift%size;
    Reverse(array, 0, size-shift-1);
    Reverse(array, size-shift, size-1);
    Reverse(array, 0, size-1);
}

void RightShiftMain(){
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(array)/sizeof(array[0]);
    RightShift(array, size, 8);
    int i = 0;
    for(i=0; i<size; i++){
        printf("%d\n", array[i]);
    }
}
