#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge {
    int x1, y1, x2, y2;
    double length;
    double perimeter_start;
    double perimeter_end;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    cin >> N >> P;
    vector<pair<int, int>> posts(P);
    for (int i = 0; i < P; ++i) {
        cin >> posts[i].first >> posts[i].second;
    }

    // Calculate edges and cumulative perimeter lengths
    vector<Edge> edges;
    vector<double> perimeter_positions;
    double total_perimeter = 0.0;
    perimeter_positions.push_back(0.0);

    for (int i = 0; i < P; ++i) {
        int x1 = posts[i].first;
        int y1 = posts[i].second;
        int x2 = posts[(i + 1) % P].first;
        int y2 = posts[(i + 1) % P].second;
        double length = abs(x2 - x1) + abs(y2 - y1);
        edges.push_back({x1, y1, x2, y2, length, total_perimeter, total_perimeter + length});
        total_perimeter += length;
        perimeter_positions.push_back(total_perimeter);
    }

    // Index edges by coordinate for quick lookup
    map<int, vector<Edge>> horizontal_edges; // key: y-coordinate
    map<int, vector<Edge>> vertical_edges;   // key: x-coordinate

    for (const auto& edge : edges) {
        if (edge.y1 == edge.y2) {
            // Horizontal edge
            int y = edge.y1;
            int x_start = min(edge.x1, edge.x2);
            int x_end = max(edge.x1, edge.x2);
            horizontal_edges[y].push_back(edge);
        } else if (edge.x1 == edge.x2) {
            // Vertical edge
            int x = edge.x1;
            int y_start = min(edge.y1, edge.y2);
            int y_end = max(edge.y1, edge.y2);
            vertical_edges[x].push_back(edge);
        }
    }

    // Function to find the position along the perimeter for a point (x, y)
    auto find_position = [&](int x, int y) -> double {
        // Check horizontal edges
        if (horizontal_edges.count(y)) {
            for (const auto& edge : horizontal_edges[y]) {
                int x_start = min(edge.x1, edge.x2);
                int x_end = max(edge.x1, edge.x2);
                if (x_start <= x && x <= x_end) {
                    double proportion = (x - x_start) / (double)(x_end - x_start);
                    return edge.perimeter_start + proportion * edge.length;
                }
            }
        }
        // Check vertical edges
        if (vertical_edges.count(x)) {
            for (const auto& edge : vertical_edges[x]) {
                int y_start = min(edge.y1, edge.y2);
                int y_end = max(edge.y1, edge.y2);
                if (y_start <= y && y <= y_end) {
                    double proportion = (y - y_start) / (double)(y_end - y_start);
                    return edge.perimeter_start + proportion * edge.length;
                }
            }
        }
        // Point not found on any edge
        cerr << "Point (" << x << ", " << y << ") is not on any edge." << endl;
        exit(1);
    };

    // Process each cow
    vector<int> cow_distances(N);
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        double pos_start = find_position(x1, y1);
        double pos_end = find_position(x2, y2);

        // Calculate distances in both directions
        double distance_clockwise = fabs(pos_end - pos_start);
        double distance_counter_clockwise = total_perimeter - distance_clockwise;

        // Choose the minimal distance
        double min_distance = min(distance_clockwise, distance_counter_clockwise);
        cow_distances[i] = (int)round(min_distance);
    }

    // Output the distances
    for (int dist : cow_distances) {
        cout << dist << '\n';
    }

    return 0;
}
