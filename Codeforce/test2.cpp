#include <bits/stdc++.h>
using namespace std;

// ???????????
double dist_sq(const pair<int, int>& p1, const pair<int, int>& p2) {
    // ????????????????
    return pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
}

// ????????????
double closest_pair_dist_sq(const vector<pair<int, int>>& points_x, const vector<pair<int, int>>& points_y) {
    // ??????????3,??????????
    if (points_x.size() <= 3) {
        double min_dist_sq = numeric_limits<double>::infinity();
        for (size_t i = 0; i < points_x.size(); ++i) {
            for (size_t j = i + 1; j < points_x.size(); ++j) {
                // ?????????????
                double current_dist_sq = dist_sq(points_x[i], points_x[j]);
                // ????????
                min_dist_sq = min(min_dist_sq, current_dist_sq);
            }
        }
        return min_dist_sq;
    }

    // ????x?????????
    int mid = points_x.size() / 2;
    vector<pair<int, int>> points_x_left(points_x.begin(), points_x.begin() + mid);
    vector<pair<int, int>> points_x_right(points_x.begin() + mid, points_x.end());

    // ????x??
    int mid_x = points_x[mid].first;
    vector<pair<int, int>> points_y_left, points_y_right;
    for (const auto& p : points_y) {
        // ????x????????????
        if (p.first <= mid_x) {
            points_y_left.push_back(p);
        } else {
            points_y_right.push_back(p);
        }
    }

    // ??????????????
    double delta_left = closest_pair_dist_sq(points_x_left, points_y_left);
    double delta_right = closest_pair_dist_sq(points_x_right, points_y_right);
    double delta = min(delta_left, delta_right);

    // ??????,??????? sqrt(delta) ???
    vector<pair<int, int>> strip;
    for (const auto& p : points_y) {
        // ????x???????x??????? sqrt(delta),?????strip
        if (abs(p.first - mid_x) < sqrt(delta)) {
            strip.push_back(p);
        }
    }

    // ????????????,??????
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].second - strip[i].second) < sqrt(delta); ++j) {
            // ?????????????
            double current_dist_sq = dist_sq(strip[i], strip[j]);
            // ????????
            delta = min(delta, current_dist_sq);
        }
    }

    return delta;
}

// ??????????????????
double min_distance(const vector<pair<int, int>>& stations, const vector<pair<int, int>>& agents) {
    // ??????????
    vector<pair<int, int>> all_points;
    all_points.insert(all_points.end(), stations.begin(), stations.end());
    all_points.insert(all_points.end(), agents.begin(), agents.end());

    // ?x???y??????
    vector<pair<int, int>> points_x = all_points;
    vector<pair<int, int>> points_y = all_points;
    sort(points_x.begin(), points_x.end());
    sort(points_y.begin(), points_y.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // ??????????,???????
    return sqrt(closest_pair_dist_sq(points_x, points_y));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<double> results;

    // ????????
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        for (int i = 0; i < N; ++i) {
            // ???????
            cin >> stations[i].first >> stations[i].second;
        }
        vector<pair<int, int>> agents(N);
        for (int i = 0; i < N; ++i) {
            // ???????
            cin >> agents[i].first >> agents[i].second;
        }
        double result = min_distance(stations, agents);
        results.push_back(result);
    }

    // ????
    for (const auto& res : results) {
        printf("%.3f\n", res);
    }

    return 0;
}

