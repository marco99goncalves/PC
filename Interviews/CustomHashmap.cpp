#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
    vector<pair<int, int>> hm[1'000'100];
    
    MyHashMap() {

    }

    void put(int key, int value) {
        int hashed = hash(key);
        for(auto &[k, v] : hm[hashed]){
            if(key == k){
                v = value;
                return;
            }
        }
        hm[hashed].push_back({key, value});
    }

    int hash(int key){
        return key;
    }
    
    int get(int key) {
        int hashed = hash(key);
        for(auto &[k, v] : hm[hashed]){
            if(k == key){
                return v;
            }
        }
        return -1;
    }

    void remove(int key) {
        int hashed = hash(key);
        int i = 0;
        for(; i < hm[hashed].size(); i++){
            if(hm[hashed][i].first == key){
                int n = hm[hashed].size();
                swap(hm[hashed][i], hm[hashed][n-1]);
                hm[hashed].pop_back();
            }
        }            
    }
};