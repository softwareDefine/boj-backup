#include <iostream>
#include <vector>


using namespace std;
vector<int> arr;
vector<int> answer;

int n;
int c;
bool isTrue;
void mergesort(int start, int end);
void merge(int start, int mid, int end);


void mergesort(int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    merge(start, mid, end);
}
void merge(int start, int mid, int end) {
    vector<int> tmp;
    vector<int> tmp2;
    tmp.resize(mid - start + 1);
    tmp2.resize(end - mid);
    copy(arr.begin() + start, arr.begin() + mid + 1, tmp.begin());
    copy(arr.begin() + mid + 1, arr.begin() + end + 1, tmp2.begin());

    int st = start;
    int i = 0, j = 0;
    int tmpsze = tmp.size();
    int tmp2sze = tmp2.size();
    while (i < tmpsze && j < tmp2sze) {
        if (tmp[i] <= tmp2[j]) {
            int temp = arr[st];
            arr[st] = tmp[i];
            if (temp == answer[st] && temp != arr[st]) {
                c--;
            }
            else if (arr[st] == answer[st] && temp != arr[st]) {
                c++;
            }
            if (c == answer.size()) {
                isTrue = true;
            }
            st++;
            i++;
        }
        else {
            int temp = arr[st];
            arr[st] = tmp2[j];
            if (temp == answer[st] && temp != arr[st]) {
                c--;
            }
            else if (arr[st] == answer[st] && temp != arr[st]) {
                c++;
            }
            if (c == answer.size()) {
                isTrue = true;
            }
            st++;
            j++;
        }
    }
    if (i >= tmpsze) {
        while (j < tmp2sze) { 
            int temp = arr[st];
            arr[st] = tmp2[j];
            if (temp == answer[st] && temp != arr[st]) {
                c--;
            }
            else if (arr[st] == answer[st] && temp != arr[st]) {
                c++;
            }
            if (c == answer.size()) {
                isTrue = true;
            }
            st++;
            j++;
        }
    }
    else {
        while (i < tmpsze) {
            int temp = arr[st];
            arr[st] = tmp[i];
            if (temp == answer[st] && temp != arr[st]) {
                c--;
            }
            else if (arr[st] == answer[st] && temp != arr[st]) {
                c++;
            }
            if (c == answer.size()) {
                isTrue = true;
            }
            st++;
            i++;
        }
    }
}


int main()
{
    
    cin >> n ;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (arr[i] == a) {
            c++;
        }
        answer.push_back(a);
    }
    if (c == answer.size()) {
        isTrue = true;
    }
    mergesort(0, n - 1);
    if (!isTrue) {
        cout << 0;
    }
    else {
        cout << 1;
    }
    
}