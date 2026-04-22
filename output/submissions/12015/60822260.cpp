#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
int num;
int arr[1000010];
int curser;


using namespace std;
int main()
{
    vector<int> lis;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    lis.push_back(arr[0]);
    for (int i = 0; i < num; i++) {
        if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
        }
        else {
            curser = lower_bound(lis.begin(), lis.end(), arr[i])-lis.begin();
            lis[curser] = arr[i];
        }
    }
    printf("%d", lis.size());
}