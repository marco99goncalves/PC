#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define int ll
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int reversePairs(vector<int> &nums){
    int n = nums.size();
    ordered_set<pair<int, int>> os;
    for(int i = 0; i < n; i++)
        os.insert({2*nums[i], i});
    
    int count = 0;
    for(int i = 0; i < n; i++){
        os.erase({nums[i]*2, i});
        count += os.order_of_key({nums[i], -1});
    }
    return count;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &elem : arr)
        cin >> elem;
    cout << reversePairs(arr) << "\n";
}


signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
