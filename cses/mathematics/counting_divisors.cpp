#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()
#define endl '\n'

const int MAX = 1e6 + 10;

int main(){ _
    vector<int> gdiv(MAX); // -> gdiv[n] = n quando n eh primo, gdiv[n] < n, eh maior divisor diferente de n.
    iota(gdiv.begin(), gdiv.end(), 0);
    for(int i = 2; i < MAX; i ++){
        if(gdiv[i] == i)
        for(int j = 2*i; j < MAX; j += i){
            gdiv[j] = i;
        }
    }

    auto get = [&](int x) -> int {
        vector<int> divprimo;
        while(x > 1) 
            divprimo.push_back(gdiv[x]), 
            x /= gdiv[x];

        int res = 1;
        int cnt = 0, prev = -1;
        for(int i = 0; i < sz(divprimo); i ++){
            if(divprimo[i] != prev){
                res *= cnt + 1;
                cnt = 0;
            }
            cnt ++, prev = divprimo[i]; 
        }
        res *= cnt + 1;
        return res;
    };

    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << get(x) << endl;
    }

    return 0;
} 
