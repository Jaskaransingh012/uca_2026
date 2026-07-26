#include <stdio.h>
#include <string.h>

void reverse_string(char* str){

    int l = 0;
    int r = strlen(str) -1 ;

    while(left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

}

int main(){
    char str[100];

    printf("Enter: ");
    scanf("%99s", str);

    reverse_string(str);

    printf("reversed string: %s\n", str);

    return 0;
}
