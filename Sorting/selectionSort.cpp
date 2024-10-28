#include<cstdlib>
#include<iostream>
void swap(int& n, int& p){
    int temp = n;
    n = p;
    p = temp;
    }
    
void selectionSort(int* arr, int n){
    int i ;
    for(i = 0; i<n; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
        }
        }
        if (min_index!=i){
            swap(arr[min_index], arr[i]);
        }
    }
}

void print(int* arr, int n){
    for(int i =0; i<n; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}


int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout<<("Original array: ");
    print(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    print(arr, n);

    return 0;
}
