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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    unordered_map<int, int> numberOf;
    ordered_set<pair<int, int>> oset;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        numberOf[num]++;
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        oset.insert({arr[i], i});

    int sum = accumulate(arr.begin(), arr.end(), 0);
    // bool print = false;
    int res = 0;
    unordered_set<int> done;
    for (auto elem : arr) {
        if (done.count(elem) > 0)
            continue;

        done.insert(elem);
        // if (print) printf("Fixing %d\n", elem);
        int curSum = sum - elem;
        int lb = max(elem + 1, curSum - y);
        int ub = curSum - x;

        int matches = (((oset.order_of_key({ub + 1, -1}) - oset.order_of_key({lb, -1})))) * numberOf[elem];
        // if (print) printf("\tFound1: %d\n", matches);
        if (matches < 0) {
            continue;
        }

        if (elem >= curSum - y && elem <= ub)
            matches += ((numberOf[elem] - 1) * numberOf[elem]) / 2;
        res += matches;
        // if (print) printf("\tFound: %d\n", matches);
    }
    cout << res << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}