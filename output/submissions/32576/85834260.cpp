#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

struct Component {
    int parent;
    ll pigs;
    ll giraffes;
    ll total_noise;
};

int find(int x, vector<Component>& components) {
    if (components[x].parent != x)
        components[x].parent = find(components[x].parent, components);
    return components[x].parent;
}

void unite(int x, int y, vector<Component>& components) {
    int px = find(x, components);
    int py = find(y, components);
    if (px == py) return;
    components[px].parent = py;
    components[py].pigs += components[px].pigs;
    components[py].giraffes += components[px].giraffes;
    components[py].total_noise += components[px].total_noise;
}

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    int N = A + B;
    vector<Component> components(N);
    vector<int> type(N); // 0 for pig, 1 for giraffe
    for (int i = 0; i < A; ++i) {
        components[i].parent = i;
        components[i].pigs = 1;
        components[i].giraffes = 0;
        components[i].total_noise = 0;
        type[i] = 0;
    }
    for (int i = A; i < N; ++i) {
        components[i].parent = i;
        components[i].pigs = 0;
        components[i].giraffes = 1;
        components[i].total_noise = 0;
        type[i] = 1;
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        b += A;
        if (find(a, components) != find(b, components)) {
            ll noise_increase = components[find(a, components)].pigs * components[find(b, components)].giraffes
                              + components[find(a, components)].giraffes * components[find(b, components)].pigs
                              + components[find(a, components)].pigs * components[find(b, components)].pigs * 2
                              + components[find(a, components)].giraffes * components[find(b, components)].giraffes * 2;
            unite(a, b, components);
            components[find(a, components)].total_noise += noise_increase + 1;
        }
    }
    int Q;
    cin >> Q;
    ll total_noise = 0;
    unordered_map<int, int> next_id = {{0, A}, {1, B}};
    for (int i = 0; i < Q; ++i) {
        char X;
        int p, q;
        cin >> X >> p >> q;
        int t = (X == 'A' ? 0 : 1);
        int id = next_id[t]++;
        components.push_back({id, 0, 0, 0});
        type.push_back(t);
        if (t == 0) components[id].pigs = 1;
        else components[id].giraffes = 1;

        vector<int> parents = {p, q};
        for (int parent : parents) {
            if (type[parent] != t) continue;
            // Connect to animals that like to talk to exactly one of its parents
            // For simplicity, connect to the parent directly
            if (find(id, components) != find(parent, components)) {
                ll noise_increase = components[find(id, components)].pigs * components[find(parent, components)].giraffes
                                  + components[find(id, components)].giraffes * components[find(parent, components)].pigs
                                  + components[find(id, components)].pigs * components[find(parent, components)].pigs * 2
                                  + components[find(id, components)].giraffes * components[find(parent, components)].giraffes * 2;
                unite(id, parent, components);
                components[find(id, components)].total_noise += noise_increase + 1;
            }
        }
        total_noise = components[find(id, components)].total_noise;
        cout << total_noise << endl;
    }
    return 0;
}
