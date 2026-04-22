#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char str[1001];

char ucpc[4] = { 'U','C','P','C' };
int cur = 0;
int main()
{
    cin.getline(str, 1000, '\n');
    for (int i = 0; str[i]!='\0'; i++) {
        if (ucpc[cur]== str[i]) {
            cur++;
            if (cur == 4) {
                break;
            }
        }
    }
    if (cur == 4) {
        cout << "I love UCPC";
    }
    else {
        cout << "I hate UCPC";
    }
}