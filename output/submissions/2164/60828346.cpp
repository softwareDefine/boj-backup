#include <cstdio>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int main()
{
    queue<int> top;
    int n;
    int tem;
    int a;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        top.push(i);
    }
    while (1) {
        if (top.size() == 1) {
            break;
        }
        top.pop();
        tem = top.front();
        top.pop();
        top.push(tem);
    }
    printf("%d", top.front());
}