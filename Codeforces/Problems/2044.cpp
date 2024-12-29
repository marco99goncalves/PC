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
        return x.first* 31 + x.second + FIXED_RANDOM;
    }
};

void get_divisors(int target, vector<pair<int, int>> &divs){
    for(int i = 1; i*i <= target; i++){
        if(target % i == 0){
            divs.push_back({i, target/i});
            if(i != target/i){
                divs.push_back({target/i, i});
            }
        }
    }
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    unordered_set<int, custom_hash> set_a;    
    unordered_set<int> set_b;
    
    int sa = 0, sb = 0;
    for(int i = 0; i < n; i++){
        int elem; cin >> elem;
        sa += elem;
        set_a.insert(elem);
    }
    
    for(int i = 0; i < m; i++){
        int elem; cin >> elem;
        sb += elem;
        set_b.insert(elem);
    }
    while(q--){
        int target; cin >> target;
        bool found = false;
        // vector<pair<int, int>> divs; 
        // get_divisors(abs(target), divs);
        // for(auto &[f, s] : divs){
        for(int i = 1; i*i <= abs(target); i++){
            if(target % i != 0)
                continue;
                
            int f = i, s = target/i;
            if(((set_a.count(sa-f) && set_b.count(sb-s)) || (set_a.count(sa+f) && set_b.count(sb+s)))){
                found = true;
                break;
            }                
            
            if((set_a.count(sa-s) && set_b.count(sb-f)) ||(set_a.count(sa+s) && set_b.count(sb+f))){
                found = true;
                break;
            }      
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    
}

signed main(){
    int t; t = 1;
    while(t--){
        solve();
    }
}
