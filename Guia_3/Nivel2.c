#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(const char *text) {
    if (text == NULL) printf("text is null");
    
    const char *izq = text;
    if (strlen(text)== 0) printf("text has no characters");
    const char *der = text + (strlen(text) - 1);

    while (izq<der) {
        if (*izq != *der) {
            printf("The text %s is not a palindrome", text);
            return 1;
        }
        else {
            *izq++;
            *der--;
        }
    }
    printf("The text %s is a palindrome\n", text);
    return 0;
}





int main() {
    const char a[] = "reconocer";
    const char b[] = "sistemas";
    is_palindrome(a);
    is_palindrome(b);

}