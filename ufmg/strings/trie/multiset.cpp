#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define sz(x) (int)x.size()

struct Trie {
    vector<vector<int>> to = {vector<int>(2)};
    vector<int> end = {0}, pref = {0};

    void insert(int s){
        int cur = 0;
        for(int i = 31; i >= 0; i --){
            int cur_bit = (s >> i) & 1;
            int& nxt = to[cur][cur_bit];

            if(!nxt) {
                nxt = to.size();
                to.push_back(vector<int>(2));
                end.push_back(0), pref.push_back(0);
            }
            cur = nxt, pref[cur] ++;
        }
        // cout << "inserted: " << cur << endl;
        end[cur] ++, pref[0] ++;
    }

    void erase(int s){
        int cur = 0;
        for(int i = 31; i >= 0; i --){
            int cur_bit = (s >> i) & 1;
            cur = to[cur][cur_bit];
            pref[cur] --;
        }
        end[cur] --, pref[0] --;
    }

    int getBest(int s){
        // cout << s << " => ";
        int cur = 0, res = 0;
        for(int i = 31; i >= 0; i--){
            int cur_bit = (s >> i) & 1;
            int nxt = to[cur][cur_bit ^ 1];
            
            // cout << "CUR: " << cur << " " << to[cur][0] << " " << to[cur][1] << ", " << pref[to[cur][0]] << " " << pref[to[cur][1]] << " " << cur_bit << endl; // 000011, 001000

            if(!nxt or pref[nxt] == 0) 
                nxt = to[cur][cur_bit], 
                res = (res << 1) | cur_bit;
            else res = (res << 1) | (cur_bit ^ 1);
            cur = nxt;
        } 
        
        return res;
    }

};

int main(){
    int q; cin >> q;
    Trie t; t.insert(0);
    while(q --){
        char ty; int val; cin >> ty >> val;
        if(ty == '+') t.insert(val);
        else if (ty == '-')  t.erase(val);
        else cout << (t.getBest(val) ^ val) << endl;
    }
}