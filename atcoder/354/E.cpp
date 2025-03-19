#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

vector<pair<int, int>> cards;
map<int, vector<int>> mpa, mpb; // value to indexs

int n;
vector<int> memo(1 << 18, -1);

bool solve(int mask){

    // cout <<"MASK: ";
    // for(int i = 0; i < n; i ++){
    //     cout << (mask & (1 << i) ? "1" : "0") << " ";
    // }
    // cout << endl;

    if(memo[mask] != -1) return memo[mask];

    bool ok = false;
    for(int i = 0; i < n; i ++){ 
        if(mask & (1 << i)){
            auto card = cards[i];
            auto &cnta = mpa[card.first];
            auto &cntb = mpb[card.second];

            bool res = 0;
            for(int j = 0; j < sz(cnta); j ++){
                if(i == cnta[j]) continue;

               
                if(mask & (1 << cnta[j])){
                    bool val = solve(mask & (~ ((1 << i) | (1 << cnta[j]))));
                    if(val == 0) { 
                        res = 1;
                        break;
                    }
                }
            }

            if(res) return memo[mask] = true;

            for(int j = 0; j < sz(cntb); j ++){
                if(i == cntb[j]) continue;
               
                if(mask & (1 << cntb[j])){
                    bool val = solve(mask & (~ ((1 << i) | (1 << cntb[j]))));
                    if(val == 0) {
                        res = 1;
                        break;
                    }
                }
            }

            if(res) return memo[mask] = true;
        }
    }   
    return memo[mask] = false;
}


int main(){ _
    cin >> n;
    cards.resize(n);
    
    int i = 0;
    for(auto& [a, b] : cards){
        cin >> a >> b;
        mpa[a].push_back(i);
        mpb[b].push_back(i);
        i ++;
    }
    // for(auto &[k, val] : mpa) {
    //     cout << k << " => ";
    //     for(auto it: val) cout << it << " ";
    //     cout << endl;
    // }


    // for(auto &[k, val] : mpb) {
    //     cout << k << " => ";
    //     for(auto it: val) cout << it << " ";
    //     cout << endl;
    // }

    cout << (solve((1 << n)-1) ? "Takahashi\n" : "Aoki\n" );
    return 0;
} 
