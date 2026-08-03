#include <stdio.h>
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {

    int shifted_x = x >> n;
  return shifted_x & ((1<<(32 +(~n +1))) -1);

}

int main() {

    printf("%X\n", logicalShift(0x87654321,4));

}
