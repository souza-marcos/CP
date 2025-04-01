#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()

void solve(){
    int n, k; cin >> n >> k;

    string res;
    auto get_ans = [&](auto get_ans, int step) -> void{
        int newstep = step - (1 << (31 - __builtin_clz(step)));
        if(newstep == 0){
            res = string(step, 'x');
        }
        else {
            get_ans(get_ans, newstep);

            for(int i = 0; i < step - 2*newstep; i ++)
                res.push_back('0');
            
            for(int i = 0; i < newstep; i ++){
                res.push_back(res[i]);
            }
        }
    };
    get_ans(get_ans, n);

    for(int i = 0; i < sz(res); i ++){
        if(res[i]=='x') cout << k << " ";
        else cout << "0 ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
