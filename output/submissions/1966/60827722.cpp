// printerqueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct inner{
    int value;
    int index;
}I;
bool cmp(int a ,int b) {
    if (a>b) {
        return true;
    }
    return false;
}
int main()
{
    int n;
    int k, l;
    int tv;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        queue<I> checker;
        int cnt=0;
        int im[100]={0, };
        int k, l;
        scanf("%d %d", &k, &l);
        for (int j = 0; j < k; j++) {
           
            scanf("%d", &tv);
            checker.push({tv,j});
            im[j] = tv;
        }
        sort(im, im + k, cmp);
        int a, b;
         while (1){
           
           while (checker.front().value != im[cnt]) {
                a=checker.front().value;
                b=checker.front().index;
                checker.push({a,b});
                checker.pop();
            }if (checker.front().index == l && checker.front().value == im[cnt]) {
                    break;
           }
           cnt++;
           checker.pop();
         }
         printf("%d\n", cnt+1);
    }
}