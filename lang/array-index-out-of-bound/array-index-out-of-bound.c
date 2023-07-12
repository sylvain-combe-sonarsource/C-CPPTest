#include <stdio.h>

int main() {
    int arr[5];
    // ruleid: array-index-out-of-bound
    int a = arr[6];

    // ruleid: array-index-out-of-bound
    int b = arr[-1], c = arr[-100];
    int d = -2;

    // ruleid: array-index-out-of-bound
    int e = arr[d];

    // ruleid: array-index-out-of-bound
    arr[d] = 10;

    // ruleid: array-index-out-of-bound
    if (arr[d] > 0) {
        
    }
    
    // ok: array-index-out-of-bound
    int d = arr[1];

    int arr1[5], arr2[5];
    // todoruleid: array-index-out-of-bound
    int f = arr1[-1];

    return 0;
}
