#include <iostream>
#define INT64_MAX 9223372036854775807
using namespace std;

int n, m;
int arr[400001];
int tree[1<<22];

int maketree(int start, int end,int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    return tree[node] = min(maketree(start, (start + end) / 2, node * 2 ), maketree((start + end) / 2 + 1, end, node * 2 + 1));
}

int query(int start, int end, int left, int right, int node) {
    if (left > end || right < start) {
        return 1000000000;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return min(query(start, (start + end) / 2,left,right, node * 2), query((start + end) / 2 + 1,end ,left,right, node * 2 + 1));
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    maketree(1, n, 1);
    for (int i = 1; i <= m;i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, n, a, b, 1) << '\n';
    }
}