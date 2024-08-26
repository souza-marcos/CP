#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n, m; cin >> n >> m;
    int l; cin >> l; 
    bitset<1000> lamps(0);
    int temp;
    for(int i = 0; i < l; i++) {
        cin >> temp; lamps[--temp] = 1;
    }

    vector<vector<int>> interr(n); 
    for(auto& el: interr){
        int k; cin >> k;
        for(int i=0;i<k;i++){
            cin >> temp;
            el.push_back(--temp);
        }
    }

    int cont = 0;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            cont ++;
            for(auto el: interr[i]) lamps.flip(el);
            if(lamps.none()) { cout << cont << endl; return 0; } 
        }
    }
    cout << -1 << endl;
    return 0;
}