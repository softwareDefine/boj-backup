#include <iostream>
#include <set>
#include <vector>

int main() {
    // 입출력 속도 향상
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    std::set<int> minsu_cards;

    // 민수의 카드 입력 및 집합에 저장
    for (int i = 0; i < M; ++i) {
        int card;
        std::cin >> card;
        minsu_cards.insert(card);
    }

    // 철수가 낼 카드 입력
    std::vector<int> cheolsu_cards(K);
    for (int i = 0; i < K; ++i) {
        std::cin >> cheolsu_cards[i];
    }

    // 각 게임에서 민수가 낼 카드 결정
    for (int i = 0; i < K; ++i) {
        int cheolsu_card = cheolsu_cards[i];

        // 철수의 카드보다 큰 민수의 카드 중 가장 작은 것 찾기
        auto it = minsu_cards.upper_bound(cheolsu_card);

        // 문제에서 민수가 낼 카드가 없는 경우는 없다고 했으므로 확인 필요 없음
        int minsu_card = *it;

        // 민수가 카드를 내고 버림
        std::cout << minsu_card << '\n';
        minsu_cards.erase(it);
    }

    return 0;
}
