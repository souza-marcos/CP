#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()
#define int ll

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    

    for(int t = n; t >= 2; t --){
        string news = s;

        vector<int> update(n+1);
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += update[i];
            if(sum % 2 == 1) news[i] = (news[i] == '1' ? '0' : '1'); 
            if(news[i] == '0'){
                if(i + t > n) break;
                sum += 1;
                update[i + t] -= 1;
            }
            if(i == n-1 and news[i] == '1') return void(cout << t << endl);
        }
    }
    cout << 1 << endl;
}

int32_t main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
