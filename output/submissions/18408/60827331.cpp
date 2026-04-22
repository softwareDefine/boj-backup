#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[100000];
int cnt1;
int cnt2;
int main(void) {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }
    if (cnt1 > cnt2) {
        cout << 1;
    }
    else {
        cout << 2;
    }
}