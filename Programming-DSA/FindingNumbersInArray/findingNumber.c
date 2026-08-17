#include <stdio.h>


/*
Finding numbers in Array
Given an Array of size n. It has integers where all the numbers are repeated 3 times but one number is repeated 4 times. Write a code to find the number repeating 4 times.

Constraints:

size of array: 0 > n > 10^5
Each element i : 0 < i < n
Expected Run time complexity: O(n)
Expected Space complexity: O(1)
Example:

input: [1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 3]
Expected output: 3
Explanation: 3 comes 4 times but others are 3 times in array.

*/


int findNumbers(int *a, size_t n){

    int current = *a;
    int ones = 0;
    int twos = 0;
    for(int i = 0; i<n; i++){

        ones = (ones ^ a[i]) & ~twos;
        twos = (twos ^ a[i]) & ~ones;

    }

    return ones;

}


int main(){

    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 5, 5, 5,5};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n",findNumbers(arr, n));


}
