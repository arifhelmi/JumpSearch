#include <iostream>
#include <cmath>

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[std::min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) { 
            return -1;
        }
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == std::min(step, n)) { 
            return -1;
        }
    }

 
    if (arr[prev] == x) {
        return prev;
    }

    return -1;
}

int main() {
    
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = jumpSearch(arr, n, x);

    if (index != -1) {
        std::cout << "Elemen " << x << " ditemukan pada indeks " << index << std::endl;
    } else {
        std::cout << "Elemen " << x << " tidak ditemukan dalam array" << std::endl;
    }

    return 0;
}
