#include <stdio.h>

int is_palindrome(int n) {
    int reversed = 0, temp = n;
    while (temp != 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    return n == reversed;
}

int main() {
    int largest_palindrome = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product <= largest_palindrome) {
                break;
            }
            if (is_palindrome(product)) {
                largest_palindrome = product;
            }
        }
    }

    FILE *file = fopen("102-result", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%d", largest_palindrome);
    fclose(file);

    return 0;
}
