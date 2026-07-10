#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    long long Omega;
    cin >> n >> Omega;
 
    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }
 
    sort(a.begin(), a.end());
 
    vector<int> ans;
    long long cur = Omega;
 
    for (auto &p : a) {
        if (p.first < cur) {
            cur += p.first;
            ans.push_back(p.second);
        } else {
            cout << "NO\n";
            return 0;
        }
    }
 
    cout << "YES\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
 
    return 0;
}