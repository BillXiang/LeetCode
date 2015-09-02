#include <stdbool.h>
bool isPalindrome(int x) {
    return x>=0 && x==reverse(x);
}

void isPalindromeMain(void){
    printf("%d\n", isPalindrome(0));
    printf("%d\n", isPalindrome(11));
    printf("%d\n", isPalindrome(111));
    printf("%d\n", isPalindrome(101));
    printf("%d\n", isPalindrome(10));
    printf("%d\n", isPalindrome(-101));
    printf("%d\n", isPalindrome(567));
}
