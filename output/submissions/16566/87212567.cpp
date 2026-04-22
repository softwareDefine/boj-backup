#include <bits/stdc++.h>

using namespace std;

// Fenwick Tree (BIT) 구현

struct Fenwick {

    int n;

    vector<int> fenw;

    Fenwick(int n): n(n), fenw(n+1, 0){}

    void update(int i, int v) {

        for (; i<=n; i+=i&(-i)) fenw[i]+=v;

    }

    int sum(int i) {

        int s=0;

        for (; i>0; i-=i&(-i)) s+=fenw[i];

        return s;

    }

    int find_next(int start) {

        // start 인덱스부터 사용 가능한(1) 카드 찾기

        // 여기서는 start 위치 자체가 사용 가능한지 확인한 후

        // 불가능하다면 다음 위치로 이동하는 식으로 하면 비효율적일 수 있음

        // 대신 Fenwicksum을 통해 upper_bound 비슷한 연산 가능.

        // 하지만 여기서는 upper_bound를 통해 시작점을 알고 있으므로

        // start 이후로 순차적으로 fenw sum을 확인하여 사용 가능한 카드 인덱스를 찾는다.

        

        // start 위치에서 사용 가능한지 체크

        if (sum(start)-sum(start-1)==1) return start; 

        // 만약 start 카드가 이미 사용되었다면 그 다음 카드들을 Fenwicksum 이진 탐색으로 찾는다.

        

        int left=start+1, right=n;

        int pos=-1;

        while(left<=right){

            int mid=(left+right)/2;

            // mid까지 사용 가능한 카드 수를 fenw sum으로 얻는다.

            int cnt = sum(mid)-sum(start);

            if(cnt>0) {

                // 사용 가능한 카드가 이 구간에 존재

                pos=mid;

                right=mid-1;

            } else {

                left=mid+1;

            }

        }

        return pos; 

    }

};

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int N,M,K; cin>>N>>M>>K;

    vector<int> B(M);

    for(int i=0; i<M; i++) cin>>B[i];

    sort(B.begin(), B.end());

    vector<int> C(K);

    for(int i=0; i<K; i++) cin>>C[i];

    // Fenwicksum 초기화 - 모든 카드 사용 가능 표시

    Fenwick fenw(M);

    for (int i=1; i<=M; i++){

        fenw.update(i,1);

    }

    // 쿼리 처리(주어진 순서대로)

    for (int i=0; i<K; i++){

        int c=C[i];

        // c보다 큰 카드 중 가장 작은 것의 인덱스 찾기

        // B에서 upper_bound

        int idx = (int)(upper_bound(B.begin(), B.end(), c) - B.begin());

        idx++; // Fenwicksum은 1-based, B는 0-based

        // idx부터 Fenwicksum으로 사용 가능한 카드 찾기

        int pos = fenw.find_next(idx);

        // pos에 해당하는 카드 사용

        cout << B[pos-1] << "\n";

        fenw.update(pos,-1); 

    }

    return 0;

}