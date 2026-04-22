#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[100000];
int main(void) {
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + 3);
    cout << arr[1];
}