// https://codeforces.com/gym/348180/problem/E
#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()
const int MAX = 1e6 + 10;
bool eh_primo[MAX];

int main(){ _

    int n; cin >> n;
    memset(eh_primo, 1, sizeof(bool) * (n+10));
    vector<int> factors, exps; 
    
    int nnew = n;
    for(ll i = 2; i <= n; i ++){
        if(eh_primo[i]){
            for(ll j = i * i; j <= n; j += i)
                eh_primo[j] = false;


            if(n % i == 0){
                int cur = 0;
                while(nnew % i == 0) nnew /= i, cur ++;
                factors.push_back(i), exps.push_back(cur);
            }
        }
    }

    int res = 1;
    for(auto el: factors) res *= el;
    cout << res << " ";
    
    bool ok = true;
    for(auto el : exps) if(el > 1) ok = false;

    if(ok){
        cout << 0 << endl;
        return 0;
    }

    int maxd = 0;
    bool allPower = true;

    int maxj = 1;
    for(int i = 0; i < sz(exps); i ++){
        for(int j = 1; j < 32; j ++){
            if(exps[i] <= (1ll << j)) { 
                maxj = max(maxj, j);
                break;
            }
        }
    }

    for(int i = 0; i < sz(exps); i ++){
        if(exps[i] < (1ll << maxj)) { 
            allPower = false;
            exps[i] = (1ll << maxj);
        }
    }   

    cout << (!allPower) + maxj << endl;

    return 0;
}
