#include <stdio.h>
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}


int main(){

    printf("%d\n", bang(0));
    printf("%d\n", bang(5));

}
