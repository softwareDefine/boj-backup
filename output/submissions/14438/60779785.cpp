#include <iostream>
#define INT64_MAX 9223372036854775807
#define LLONG_MAX 9223372036854775807
using namespace std;

int n, m;
pair<long long, long long> tree[1 << 22];
int arr[4000010];

pair<long long, long long> maketree(int start, int end, int node) {
    if (start == end) {
        tree[node].first = arr[start];
        tree[node].second = start;
        return { tree[node].first,tree[node].second };
    }
    pair<long long, long long> a = maketree(start, (start + end) / 2, node * 2);
    pair<long long, long long> b = maketree((start + end) / 2 + 1, end, node * 2 + 1);
    if (a.first <= b.first) {
        tree[node].first = a.first;
        tree[node].second = a.second;
    }
    else if (a.first > b.first) {
        tree[node].first = b.first;
        tree[node].second = b.second;
    }
    return { tree[node].first, tree[node].second };
}

void update(int start, int end, int node, int findnode, long long value) {
    if (findnode < start || findnode > end) {
        return;
    }
    if (start == end) {
        tree[node].first = value;
        tree[node].second = start;
        return;
    }
    update(start, (start + end) / 2, node * 2, findnode, value);
    update((start + end) / 2 + 1, end, node * 2 + 1, findnode, value);
    if (tree[node * 2] <= tree[node * 2 + 1]) {
        tree[node].first = tree[node * 2].first;
        tree[node].second = tree[node * 2].second;
    }
    else {
        tree[node].first = tree[node * 2 + 1].first;
        tree[node].second = tree[node * 2 + 1].second;
    }
}

pair<long, long> query(int start, int end, int left, int right, int node) {
    if (left > end || right < start) {
        return { LLONG_MAX,-999999999 };
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    pair<long long, long long> a = query(start, (start + end) / 2, left, right, node * 2);
    pair<long long, long long> b = query((start + end) / 2 + 1, end, left, right, node * 2 + 1);
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    maketree(1, n, 1);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, n, 1, b, c);
        }
        else {
            cout << query(1, n, b, c, 1).first << '\n';
        }

    }
}