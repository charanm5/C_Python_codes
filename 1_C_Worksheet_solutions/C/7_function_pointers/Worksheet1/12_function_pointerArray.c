#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void countVowels(char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    printf("Vowel count = %d\n", count);
}

int main() {
    void (*operations[3])(char[]) = {
        reverseString,
        toUpperCase,
        countVowels
    };

    char str[100];
    int choice;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);

    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Count Vowels\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice\n");
        return 1;
    }

    operations[choice - 1](str);

    if (choice == 1 || choice == 2) {
        printf("Result: %s\n", str);
    }

    return 0;
}