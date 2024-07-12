#include <iostream>
#include <cstdlib>

enum { N = 100 };

struct Heap {
    int* arr;
    int n;
    Heap() : arr(new int[N]), n(0) {}  // Initialize n to 0 for a 1-indexed heap
};

Heap* insert(Heap* bheap, int key) {
    bheap->n++;
    int index = bheap->n;
    int* list = bheap->arr;
    list[index] = key;

    while (index > 1 && list[index] > list[index / 2]) {
        // Swap the key with its parent
        int temp = list[index / 2];
        list[index / 2] = list[index];
        list[index] = temp;

        // Move up to the parent index
        index = index / 2;
    }

    return bheap;
}

int main() {
    Heap* maxheap = new Heap();  // Allocate memory for Heap object

    // Insert elements into the heap
    maxheap = insert(maxheap, 0);
    maxheap = insert(maxheap, 2);
    maxheap = insert(maxheap, 6);
    maxheap = insert(maxheap, 8);
    maxheap = insert(maxheap, 10);
    std::cout << "Heap array: ";
    for (int i = 1; i <= maxheap->n; ++i) {
        std::cout << maxheap->arr[i] << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
