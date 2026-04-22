#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int n,m;

template<class K>
using ordered_set = tree<K, null_type, less<K>, rb_tree_tag,
                         tree_order_statistics_node_update>;
template<class K>
using ordered_set_desc = tree<K, null_type, greater<K>, rb_tree_tag,
                         tree_order_statistics_node_update>;
ordered_set<int> os;
ordered_set_desc<int> os2;
int order[200000];
int order2[200000];
int flag;
vector<int> vc;
int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        order2[b]++;
        order[a]++;
    }
    for(int i=1;i<=n;i++){
        os.insert(i);
    }
    for(int i=1;i<=n;i++){
        int now = *os.find_by_order(order[i]);
        vc.push_back(now);
        os.erase(now);
        os2.insert(now);
        if(os2.order_of_key(now) != order2[i]){
             flag = 1;
             cout << -1;
             break;
        }
    }
    if(!flag){
        for(auto element : vc){
            cout << element <<' ';
        }
    }
}
