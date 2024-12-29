
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int ll
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        return x.first*31 + x.second + FIXED_RANDOM;
    }
};

vector<int> get_subarray(const vector<int>& vec, int I, int k) {
    if (I < 0 || I >= vec.size()) {
        return {}; // Return empty vector or handle error as needed
    }
    // Ensure we don't go out of bounds
    int end = min(static_cast<int>(vec.size()), I + k);
    return vector<int>(vec.begin() + I, vec.begin() + end);
}

int get_min(vector<int> &arr, int k){
    int sum = 0;
    for(int i = 0; i < arr.size() && i+k-1 < arr.size(); i++){
        int m = INT_MAX;
        vector<int> sub = get_subarray(arr, i, k);
        if(sub.size() == k){
            // cout << "\t";
            // for(auto &elem : sub)
            //     cout << elem << " ";
            // cout << "\n";
            for(auto &elem : sub)
                m = min(m, elem);
            // cout << "\tmin: " << m << "\n";
        }
        
        sum += m;
    }
    return sum;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> sol(n, -1);
    int counter = 1;
    for(int i = k-1; i < n; i+=k){
        sol[i] = counter++;
    }
    
    for(int i = 0; i < n; i++){
        if(sol[i] == -1)
            sol[i] = counter++;
    }
    
    for(auto &elem : sol)
        cout << elem << " ";
    cout << "\n";
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}