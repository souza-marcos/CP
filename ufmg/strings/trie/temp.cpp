#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)x.size()

struct Trie {
    vector<vector<int>> to; // Main tree
    vector<int> end, pref;  // To indicate how many string, the pref at i is prefix and ended in it;
    int sigma; char norm;

    Trie(int _sigma=26, int _norm = 'a') : sigma(_sigma), norm(_norm) {
        to = {vector<int>(sigma)};
        end = { 0 }, pref = { 0 };
    }

    void insert(string& s){
        int cur = 0;
        for(char c : s){
            int& nxt = to[cur][c-norm];
            if(!nxt) { // New node
                nxt = to.size(); // Pointer to the end of all nodes
                to.push_back(vector<int>(sigma));
                end.push_back(0), pref.push_back(0);
            }
            cur = nxt, pref[cur] ++;
        }
        end[cur] ++, pref[0] ++;
    }

    void erase(string& s){
        int cur = 0;
        for(char c: s){
            cur = to[cur][c-norm];
            pref[cur] --;
        }
        end[cur] --, pref[0]--;
    }

    int find(string& s){
        int cur = 0;
        for(char c: s){
            cur = to[cur][c-norm];
            if(!cur) return -1;
        }
        return cur;
    }

    int count_pref(string& s){
        int idx = find(s);
        return idx >= 0? pref[idx] : 0;
    }

};


int main(){
}