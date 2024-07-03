#include<iostream>
#include<cstdlib>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void insertionsort(int* arr, size_t size){
    int k = 0;
    while(k<size){
        int end = k;
        while(end>=0 && end<size&& *(arr+end)>*(arr+end+1)){
                swap((arr+end+1), (arr+end));
                end--;
        }
        k++;
    }
    return;
}
void print(int* arr, size_t size){
    auto i = arr;
    while(i<arr+size){
        std::cout<<*i<<" ";
        i++;
    }
    std::cout<<std::endl;
}

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    print(arr, size);
    insertionsort(arr, size);
    print(arr, size);
    return 0;
}