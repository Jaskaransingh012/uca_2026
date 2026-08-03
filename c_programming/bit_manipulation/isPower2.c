#include <stdio.h>
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */


int isPower2(int x) {


    return !(x & (x + (~1 + 1)));
}

int main(){

    printf("%d\n", isPower2(64));
    printf("%d\n", isPower2(13));
    printf("%d\n", isPower2(128));
    printf("%d\n", isPower2(512));

}
