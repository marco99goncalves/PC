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

int bs(int low, int high, int full, int target) {
    if (high - low <= 5) {
        for (int mid = low; mid <= high; mid++) {
            if (full * mid > target)
                return (mid - 1) * full;
        }
    }

    int mid = low + (high - low) / 2;
    if (mid * full > target)
        return bs(low, mid, full, target);
    else
        return bs(mid, high, full, target);
}

void solve() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;

    int full = a + b + c;
    int sum = 0;
    if (full >= n) {
        if (a >= n)
            cout << "1\n";
        else if (a + b >= n)
            cout << "2\n";
        else
            cout << "3\n";
        return;
    }

    int km = bs(0, 2'000'000'000, full, n);
    // cout << "km: " << km << "\n";

    if (km >= n)
        cout << km / (full) * 3 << "\n";
    else if (km + a >= n)
        cout << km / (full) * 3 + 1 << "\n";
    else if (km + a + b >= n)
        cout << km / (full) * 3 + 2 << "\n";
    else
        cout << km / (full) * 3 + 3 << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}