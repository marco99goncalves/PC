#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int ll
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<int, int> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x.first * 31 + x.second + FIXED_RANDOM;
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> missing(m);
    for (auto &elem : missing)
        cin >> elem;

    unordered_set<int> known;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        known.insert(num);
    }

    unordered_set<int> bad;
    for (int i = 1; i <= n; i++) {
        if (known.count(i) == 0)
            bad.insert(i);
    }
    string ans = "";
    for (int q : missing) {
        if (known.count(q) > 0) {
            ans += bad.size() == 0 ? "1" : "0";
        } else {
            ans += bad.size() >= 2 ? "0" : "1";
        }
    }
    cout << ans << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}