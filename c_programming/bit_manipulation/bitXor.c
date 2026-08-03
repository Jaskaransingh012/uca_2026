#include <stdio.h>

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

  int result = ~(~(x&~y) & ~(~x&y));
  return result;
}


int main(){

    int x = 4;
    int y = 9;

    printf("Xor of %d and %d is : %d\n", x, y, bitXor(x,y));

}
