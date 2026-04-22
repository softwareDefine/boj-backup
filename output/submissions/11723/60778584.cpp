#include <iostream>
#define endl '\n'
using namespace std;

// 0b 0011 1010
//    
// bool arr[32]-> int bit; // = bool[32]
// 0, 1, 0, 1, 1, 1, 0, 0
// -> 0b 0011 1010
// 0b 0001 0000, 1 << 4
// 0, 1, 1, 0, 1, 0, 0, 1 [3]
// 0b 1001 0110
//            1
//         1<<<
//    0000 1000, 1 << 3
//  & 0000 0000
// 0 -> 1, 1 -> 0
// 0 xor 1 = 1, 1 xor 1 = 0
// 0b 0011 1010
// 0b      0011 (bit >> 4) & 1
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int bit = 0;
    int q; 
    cin >> q; 
    for(int i=0;i<q;i++){
        string s; 
        cin >> s;
        if (s == "add") {
            int x; cin >> x; //arr[x] = 1;
            bit |= 1 << x;
        }
        else if (s == "remove") {
            int x; cin >> x; //arr[x] = 0;
            bit &= ~(1 << x);
        }
        else if (s == "check") {
            int x; cin >> x; //cout << arr[x];
            cout << (bit >> x & 1) << endl;
        }
        else if (s == "toggle") {
            int x; cin >> x; //arr[x] ^= 1;
            bit ^= 1 << x;
        }
        else if (s == "all") {
            //for (int i = 1; i <= n; i++){ arr[i] = 1; }
            bit = 0xffffffff;
            // 0b 1111 1111 1111 1111 1111 1111 1111 1111
        }
        else if (s == "empty") {
            //for (int i = 1; i <= n; i++){ arr[i] = 0; }
            bit = 0;
            // 0b 0000 0000 0000 0000 0000 0000 0000 0000
        }
    }
}