#include <bits/stdc++.h>

using namespace std;

struct Fenwick {

    int n;

    vector<long long> fenw;

    Fenwick(int n):n(n),fenw(n+1,0){}

    void update(int i, long long v) {

        for(; i<=n; i+=i&(-i)) fenw[i]+=v;

    }

    long long query(int i) {

        long long s=0;

        for(; i>0; i-=i&(-i)) s+=fenw[i];

        return s;

    }

    long long range_query(int l,int r) {

        return query(r)-query(l-1);

    }

};

int main(){

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int N,P;

    cin>>N>>P;

    vector<pair<long long,long long>> posts(P);

    for (int i=0; i<P; i++){

        cin>>posts[i].first>>posts[i].second;

    }

    // 1. 다각형 복원 (이 부분은 문제에서 가장 어려운 부분 중 하나이며, 여기서는 가상의 로직)

    // 실제로는 posts를 이용해 다각형을 형성하는 순서를 찾아야 함.

    // 정답 코드에서는 posts를 다각형 순서대로 정렬했다고 가정.

    // 아래에서는 이미 올바른 순서라고 가정 (실제 문제 해결시 추가 구현 필요)

    // 2. 다각형 둘레 계산 및 prefix sum

    vector<long long> dist(P+1,0); // dist[i]: 0번 꼭짓점부터 i-1번 꼭짓점까지의 둘레 거리

    long long perimeter=0;

    for (int i=0; i<P; i++){

        int j=(i+1)%P;

        long long dx = llabs(posts[i].first - posts[j].first);

        long long dy = llabs(posts[i].second - posts[j].second);

        perimeter += (dx+dy);

        dist[i+1]=perimeter;

    }

    // 쿼리 입력

    // 각 쿼리: (x1,y1)에서 시작 -> (x2,y2)에서 끝

    // 소의 경로: 더 짧은 방향 선택

    // N개 쿼리

    vector<array<long long,4>> queries(N);

    for (int i=0; i<N; i++){

        for (int k=0; k<4; k++) cin>>queries[i][k];

    }

    // 3. (x1,y1), (x2,y2)가 어떤 에지 위에 있는지 찾고, 그 둘레상 위치를 s_pos, e_pos로 계산

    // 여기서도 실제 구현 복잡. 이진 탐색이나 map을 사용해 에지를 빠르게 찾는 과정을 생략.

    // 구현 예시에선 이 부분 또한 가상의 함수 호출이라 가정.

    auto getPerimeterPos=[&](long long x,long long y)->long long {

        // (x,y)가 다각형의 어느 에지 위에 있는 점이라 가정

        // 해당 점의 둘레상 거리 계산 로직 필요

        // 여기서는 가상 로직

        return 0LL; // TODO: 실제 구현 필요

    };

    // 4. Fenwicksum을 이용한 구간 업데이트

    Fenwick fenw(P);

    // 모든 꼭짓점의 둘레상 위치(정점)는 dist 배열을 통해 알 수 있음

    // posts[i]의 둘레 위치는 dist[i] (i번 꼭짓점 시작점)

    // 정점에 대한 Fenwicksum 업데이트 위해 정점 인덱스 사용

    // posts는 0-based, fenw 업데이트 또한 1-based 인덱스로 처리할 것

    // 정점 번호 <-> fenw 인덱스 매핑: fenw에서 1~P 사용

    auto increment_arc=[&](long long s_pos, long long e_pos){

        // s_pos에서 e_pos로 가는 "짧은" 방향 구간에 대해 정점 터치 횟수 +1

        // 정점들의 둘레 위치 dist[i]: i번 정점의 위치

        // dist는 오름차순 정렬, dist[0]=0, dist[P]=perimeter

        // 둘레상 정점 위치 dist[i]가 s_pos~e_pos 사이에 있으면 fenw update

        // 이를 위해 dist 배열과 s_pos,e_pos를 이용해 lower_bound 등 사용

        // 예시(단순화):

        // 실제로는 s_pos < e_pos인지, 아니면 원을 넘어가는지 판단 후

        // 해당 구간에 속한 정점 인덱스 찾고 fenw.update로 +1

        // TODO: 실제로는 이곳에서 이진 탐색으로 구간에 해당하는 정점 범위를 찾아 fenw.update

    };

    for (auto &q: queries){

        long long x1=q[0],y1=q[1],x2=q[2],y2=q[3];

        long long s_pos = getPerimeterPos(x1,y1);

        long long e_pos = getPerimeterPos(x2,y2);

        // 두 방향 거리

        long long d1 = (e_pos - s_pos + perimeter)%perimeter;

        long long d2 = perimeter - d1;

        bool forward = (d1<d2); // d1이 더 짧으면 s->e 방향, 아니면 e->s 반대방향

        if (!forward) {

            // swap해서 항상 forward처럼 처리

            swap(s_pos,e_pos);

        }

        // s_pos->e_pos 구간에 해당하는 정점들 +1

        increment_arc(s_pos,e_pos);

        // 시작점, 끝점이 정확히 정점이면 해당 정점도 터치

        // 이는 increment_arc 과정에서 자연스레 포함되거나,

        // 별도 처리 필요할 수도 있음 (정확한 구현 필요)

    }

    // 모든 쿼리 처리 후 fenw에서 각 정점 터치 횟수 추출

    // fenw.query(i) - fenw.query(i-1)로 i번 정점 터치 횟수 얻기

    for (int i=1; i<=P; i++){

        long long val = fenw.query(i)-fenw.query(i-1);

        cout<<val<<"\n";

    }

    return 0;

}