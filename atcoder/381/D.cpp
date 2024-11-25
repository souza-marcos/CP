#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int main(){ _
    int n; cin >> n;
    vector<int> arr(n); for(auto& el: arr) cin >> el;
    map<char, pair<int, int>> lastOccur;
    auto pushOccur = [&](char el, int i){
        auto [fr, sn] = lastOccur[el];
        lastOccur[el] = {i, fr}; 
    };

    // DP => Ideia eh manter o melhor que consigo ir a partir do indice 
    // e ver se tem participação do atual no array seguinte e pegar 
    // a maximo que dá pra aproveitar

    int maxv = 0;
    pair<int, int> best = {0, 0};
    for(int i = 1; i < n; i ++){
        // cout << best.first << " " << best.second << endl;
        if(arr[i] == arr[i-1]) {
            auto [fr, sn] = best;
            int nextbest = sn, last = lastOccur[arr[i]].second;
            
            if( last > 0){
                nextbest = min(sn, i - last);
            }
            if(nextbest & 1) nextbest --;
            nextbest += 2;
            maxv = max(nextbest, maxv);
            best = {nextbest, fr};
        }
        else { 
            auto [fr, sn] = best;
            best = {0, fr};
        }
        pushOccur(arr[i], i + 1);
    }
    // cout << best.first << " " << best.second << endl << endl;
    cout << maxv << endl;


    return 0;
} 
