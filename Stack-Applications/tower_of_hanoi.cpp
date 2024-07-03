#include <iostream>

int moveCounter = 0; // Global variable to count the number of moves

void TOH(int n, char source, char auxillary, char target) {
    if(n==1){
        ++moveCounter;
        std::cout<<"Step "<<moveCounter<<" - "<<"From: "<<source<<" to: "<<target<<std::endl;
        return;
    }
    TOH(n-1, source, target, auxillary);
    TOH(1, source, auxillary, target);
    // ++moveCounter;
    // std::cout<<"Step "<<moveCounter<<" - "<<"From: "<<source<<" to: "<<target<<std::endl;
    TOH(n-1, auxillary, source, target);
}

int main() {
    int n; // Number of disks
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    TOH(n, 'A', 'B', 'C'); // A, B, and C are names of rods
    std::cout << "Total number of moves: " << moveCounter << std::endl;
    return 0;
}
