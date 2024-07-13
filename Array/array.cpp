#include <iostream>

void printArray(int arr[], int size); // Declare the function prototype
void cin_arr(int size, int *arr);

int main() {

    int size;
    std::cout<<"Enter the size of array for input: ";
    std::cin>>size;
    int *arr1 = new int[size];
    cin_arr(size, arr1);
    printArray(arr1, size); // Pass the array and its size to the function
    return 0;
}

void printArray(int arr[], int size) { // Define the function
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
    }
}
void cin_arr(int size, int *arr){
    for(int i = 0; i<size; i++){
        std::cin>>*arr;
        arr++;
    }
}