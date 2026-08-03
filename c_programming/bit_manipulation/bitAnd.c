#include <stdio.h>

/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */


int bitAnd(int x, int y) {

  int result = ~(~x | ~y);

  return result;
}

int main(){

    int x = 4;

    int y = 12;

    printf("The and value is %d\n" , bitAnd(x,y));

}
