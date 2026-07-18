#include <stdio.h>

void url_encode(char *str, int true_len) {

    int space = 0;

    for (int i = 0; i < true_len; i++) {
        if (str[i] == ' ')
            space++;
    }

    int new_length = true_len + (space* 2);
    str[new_length] = '\0';

    for (int i = true_len - 1, j = new_length - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else {
            str[j--] = str[i];
        }
    }
}

int main() {
    char str[100] = "Hello World    ";

    int true_length = 11;

    url_encode(str, true_length);

    printf("%s\n", str);

    return 0;
}
