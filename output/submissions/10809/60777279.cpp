#include <stdio.h>
#include <string.h>
 
 
int main(void)
{
    int number[26] ;
    char voca[101];
    int index;
 
    scanf("%s", voca);
 
    for (int i = 0; i < 26; i++) {
        number[i] = -1;
    }
 
    for (int i = 0; voca[i] != '\0'; i++) {
        index = voca[i] - 97;
        if (number[index] == -1) {
            number[index] = i;
        }
    }
 
    for (int i = 0; i<26; i++) {
        printf("%d ", number[i]);
    }
 
    return 0;
}