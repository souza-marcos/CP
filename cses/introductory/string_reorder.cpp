#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _

    string s; cin >> s;
    
    vector<int> cnt(26);
    map<int, set<int>> mp;
    for(auto ch : s){
        cnt[ch-'A']++;
    }

    for(int i = 0; i < 26; i ++){
        if(cnt[i]) mp[cnt[i]].insert(i);
    }

    int n = sz(s);
    if(mp.rbegin()->first > (n/2 + n%2)){
        cout << -1 << endl;
        return 0;
    }

    string res;
    while(n){
        // Eu preciso remover os menores enquanto for possivel,
        // isto eh, enquanto nao tiver um caracter com cnt igual a 
        // n/2 + n%2
        while(sz(mp.rbegin()->second) == 0) 
            mp.erase(mp.rbegin()->first);

        int to_remove = -1;
        if(mp.rbegin()->first > n/2 /*+ n%2*/){
            to_remove = *mp.rbegin()->second.begin();
        } else {
            for(int i = 0; i < 26; i ++){
                if(cnt[i] and (sz(res)==0 or res.back() != i)){
                    to_remove = i;
                    break;
                }
            }
        }

        mp[cnt[to_remove]].erase(to_remove);
        res.push_back(to_remove);
        cnt[to_remove] -= 1;

        if(cnt[to_remove]){
            mp[cnt[to_remove]].insert(to_remove);
        }
        n--;
    }

    for(auto el : res)
        cout << (char)(el+'A'); 
    cout << endl;

    return 0;
} 
