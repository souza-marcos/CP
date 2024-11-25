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
        if(end[cur] == 0) end[cur] ++, pref[0] ++;//, cout << s << endl;
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
    string s; cin >> s;
    string aux; cin >> aux;
    int k; cin >> k;
    vector<bool> bad(26);
    for(int i = 0; i < 26; i ++) bad[i] = aux[i] == '0';

    unordered_set<string> mp;

    for(int i = 0; i < sz(s); i ++){
        int cnt = 0;
        for(int j = i; j < sz(s); j ++){
            cnt += (bad[s[j]-'a']);
            if(cnt > k) break;

            // cout << s.substr(i, j - i + 1) << " => " << cnt << ", " << i << " = " << j << endl;;
            string aux = s.substr(i, j - i + 1);
            mp.insert(aux);
        }
    }
    cout << sz(mp) << endl;
}