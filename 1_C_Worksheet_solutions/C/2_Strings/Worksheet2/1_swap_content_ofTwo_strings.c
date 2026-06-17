#include <stdio.h>
#include <string.h>

int main() {
    char str1[10], str2[10];
    int i, len;

    scanf("%s", str1);
    scanf("%s", str2);

    len = strlen(str1);

    for (i = 0; i <= len; i++) {
        str1[i] = str1[i] ^ str2[i];
        str2[i] = str1[i] ^ str2[i];
        str1[i] = str1[i] ^ str2[i];
    }

    printf("str1 = %s\n", str1);
    printf("str2 = %s", str2);

    return 0;
}