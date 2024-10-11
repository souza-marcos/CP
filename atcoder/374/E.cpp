#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

int n, budget;
struct Machine{
    int units, cost; // cost per unit
};

vector<pair<Machine, Machine>> v;


bool valid(int guess){

    ll costAll = 0;
    for(int i = 0; i < n; i ++){

        // Finding the minimum cost to archive guess units at i process 
        ll cost = LINF;
        for(int j = 0; j <= 100; j ++){
            ll rem = max(0, guess - j * v[i].second.units);
            ll k = ceil(rem/(double)v[i].first.units);
            cost = min(cost, k * v[i].first.cost + j * v[i].second.cost);
        }

        costAll += cost;
        if(costAll > budget) return false; 
    }
    return true;
}


int main(){ _
    cin >> n >> budget;
    v.resize(n);
    for(auto& [fr, sn] : v){
        cin >> fr.units >> fr.cost >> sn.units >> sn.cost;
    
        if(fr.cost/(double)fr.units > sn.cost/(double)sn.units)
            swap(fr, sn);
    }

    int l = 0, r = 1e9 + 1;
    while(l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) l = m;
        else r = m;
    }
    cout << l << endl;

    return 0;
} 
