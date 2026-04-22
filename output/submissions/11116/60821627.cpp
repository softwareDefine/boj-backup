// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    int cnt = 0;
    int leftcheck[200]={0,};
    int rightcheck[200]={0,};
    scanf("%d",&m);
    for (int l = 0; l < m; l++) {
        cnt=0;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &leftcheck[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &rightcheck[i]);
        }
        for (int i = 0; i < n-1;i++) {
            for (int j = i+1; j < n; j++) {
                if (leftcheck[i] + 500 == leftcheck[j]) {
                    for (int k = 0; k < n; k++) {
                        if (leftcheck[j] + 500 == rightcheck[k]) {
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
  

}