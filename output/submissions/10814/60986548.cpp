// a-12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

int n;
using namespace std;

int cmp(pair<int,string> a, pair<int,string> b) {
    /*if (a.first == b.first) {
        return a.second < b.second;
    }*/
    return a.first < b.first;
}

int main()
{
    cin >> n;
    pair<int, string> tmp;
    vector<pair<int,string>> arr;
    for (int i = 0; i < n; i++) {
        cin >> tmp.first >> tmp.second;
        arr.push_back(tmp);
    }
    stable_sort(arr.begin(),arr.end(),cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << '\n';
    }
}