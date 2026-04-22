#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int BUF_SIZE = 4096;
char buf[BUF_SIZE];

void print_letter(char c, int count) {
    memset(buf, c, BUF_SIZE);
    while (count > 0) {
        int n = count > BUF_SIZE ? BUF_SIZE : count;
        fwrite(buf, 1, n, stdout);
        count -= n;
    }
}

int main() {
    static int countsA[26] = {0}, countsB[26] = {0}, countsC[26] = {0};
    static char a[1000001], b[1000001];
    scanf("%s", a);
    scanf("%s", b);

    for (int i = 0; a[i]; ++i) {
        countsA[a[i] - 'a']++;
    }
    for (int i = 0; b[i]; ++i) {
        countsB[b[i] - 'a']++;
    }
    int total_length = 0;
    for (int c = 0; c < 26; ++c) {
        countsC[c] = countsA[c] > countsB[c] ? countsA[c] : countsB[c];
        total_length += countsC[c];
    }

    for (int c = 0; c < 26; ++c) {
        if (countsC[c] > 0) {
            print_letter(c + 'a', countsC[c]);
        }
    }
    putchar('\n');
    return 0;
}
