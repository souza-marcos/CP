#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n, m, l;

int calc(vector<int> &tbs, int x, int y){
    if((x*100)%l != 0) return INF;

    int pars = (x * 100)/ l;
    auto lb = lower_bound(tbs.begin(), tbs.end(), y), up = upper_bound(tbs.begin(), tbs.end(), y);
    int cont = 0, min_long = 0;
    cont = up - lb; 
    // cout << "CONT:" << cont << ", PARS:" << pars << endl;
    if(pars <= cont) min_long = pars;
    else {
        pars -= cont;
        int up_ptr = (lb - tbs.begin()) - 1, down_ptr = 0;

        while(down_ptr < up_ptr and pars > 0){
            if(tbs[down_ptr] + tbs[up_ptr] > y) up_ptr --;
            else if(tbs[down_ptr] + tbs[up_ptr] < y) down_ptr ++;
            else {
                pars --; cont += 2;
                up_ptr --, down_ptr ++;
            }
        }

        if(pars > 0) min_long = INF;
        else min_long = cont;
    }

    return min_long;
}

void solve(){
    cin >> l; // centimeters
    int k; cin >> k;
    vector<int> tbs(k);
    for(auto &el:tbs) cin >> el;

    sort(tbs.begin(), tbs.end());
    // longitutinal
    int min_y = calc(tbs, n, m); 
    int min_x = calc(tbs, m, n);
    int res = min(min_x, min_y);
    if(res == INF) cout << "impossivel\n";
    else cout << res << endl;
}

int main(){_

    while(cin >> n >> m and (n != 0 and m !=0)) solve();

    return 0;
}