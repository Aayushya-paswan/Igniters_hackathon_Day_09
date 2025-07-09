#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> Give_coordinates(int a, int b, int x, int y) {
    vector<pair<int,int>> result;
    result.emplace_back(x + a, y + b);
    result.emplace_back(x - a, y + b);
    result.emplace_back(x + a, y - b);
    result.emplace_back(x - a, y - b);
    result.emplace_back(x + b, y - a);
    result.emplace_back(x - b, y - a);
    result.emplace_back(x + b, y + a);
    result.emplace_back(x - b, y + a);
    return result;
}

int count_common_elements(const vector<pair<int, int>>& v1, const vector<pair<int, int>>& v2) {
    set<pair<int, int>> s1(v1.begin(), v1.end());
    set<pair<int, int>> s2(v2.begin(), v2.end());

    int count = 0;
    for (auto& p : s2) {
        if (s1.count(p)) count++;
    }

    return count;
}

int main() {
    int t, a, b, xk, yk, xq, yq;
    cin >> t;
    while(t--) {
        cin >> a >> b >> xk >> yk >> xq >> yq;

        vector<pair<int, int>> Reachable_from_k = Give_coordinates(a, b, xk, yk);
        vector<pair<int, int>> Reachable_from_q = Give_coordinates(a, b, xq, yq);

        int common_coordinates = count_common_elements(Reachable_from_k, Reachable_from_q);
        cout << common_coordinates << endl;
    }
}
