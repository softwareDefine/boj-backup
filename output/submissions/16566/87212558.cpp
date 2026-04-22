#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int N, M, K;

    cin >> N >> M >> K;

    vector<int> minsu_cards(M);

    for (int i = 0; i < M; i++) {

        cin >> minsu_cards[i];

    }

    sort(minsu_cards.begin(), minsu_cards.end());

    vector<pair<int,int>> queries(K);

    for (int i = 0; i < K; i++) {

        int c;

        cin >> c;

        queries[i] = {c, i};

    }

    // 철수가 낼 카드 번호 기준으로 정렬

    sort(queries.begin(), queries.end());

    // 투 포인터 방식

    // queries는 철수 카드 오름차순

    // minsu_cards는 오름차순

    // 각 철수 카드보다 큰 민수 카드 중 가장 작은 카드 선택

    vector<int> ans(K);

    int j = 0; // 민수 카드 포인터

    for (int i = 0; i < K; i++) {

        int c = queries[i].first;

        // c보다 큰 minsu_cards[j] 찾기

        while (j < M && minsu_cards[j] <= c) {

            j++;

        }

        // 문제에서 항상 가능하다고 했으므로 j< M 보장

        ans[queries[i].second] = minsu_cards[j];

        j++;

    }

    for (int i = 0; i < K; i++) {

        cout << ans[i] << "\n";

    }

    return 0;

}