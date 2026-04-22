#include <iostream>
#include <algorithm>

using namespace std;

int n, q;
int arr[300010];
int prefix[300010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = 0; i < q; i++) {
		int a,b;
		cin >> a >> b;
		cout << prefix[b-1] - prefix[a- 2] << '\n';
		
	}
}