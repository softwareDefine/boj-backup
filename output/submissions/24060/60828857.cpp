#include <iostream>
#include <vector>


using namespace std;
vector<int> arr;

int cnt = 0;
int n;
int c;

void mergesort(int start, int end);
void merge(int start, int mid, int end);

int yes;


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
            cnt++;
            if (cnt == c) {
                yes = tmp[i];
            }
            arr[st++] = tmp[i++];
            
            
        }
        else {
            cnt++;
            if (cnt == c) {
                yes = tmp2[j];
            }
            arr[st++] = tmp2[j++];
            
        }
    }
    if (i >= tmpsze) {
        while (j < tmp2sze) { 
            cnt++;
            if (cnt == c) {
                yes = tmp2[j];
            }
            arr[st++] = tmp2[j++];
           
        }
    }
    else {
        while (i < tmpsze) {
            cnt++;
            if (cnt == c) {
                yes = tmp[i];
            }
            arr[st++] = tmp[i++];
            
        }
    }
}


int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    mergesort(0, n - 1);
    if (cnt < c) {
        cout << -1;
    }
    else {
        cout << yes;
    }
}