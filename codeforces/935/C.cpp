#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl "\n"

const int MAX = 3e5 + 10;
int n; 
int zero_bef[MAX], one_bef[MAX];
bool valid(int pos){
    if(pos < 0 or pos > n) return false;
    
    if(pos == 0) return one_bef[n - 1] >= ceil(n/2.0);
    if(pos == n) return zero_bef[n - 1] >= ceil(n/2.0);

    return (zero_bef[pos - 1] >= ceil(pos/2.0) and one_bef[n -1] - one_bef[pos -1] >= ceil((n - pos)/2.0));
}

void solve(){

    cin >> n;
    string s; cin >> s;

    zero_bef[0] = one_bef[0] = 0;
    if(s[0] == '1') one_bef[0] = 1; 
    else zero_bef[0] = 1;

    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            one_bef[i] = one_bef[i - 1] + 1;
            zero_bef[i] = zero_bef[i - 1];
        }else{
            one_bef[i] = one_bef[i - 1];
            zero_bef[i] = zero_bef[i - 1] + 1;    
        }
    }

    // for(int i = 0; i < n; i++) cout << zero_bef[i] << " \n"[i==n-1];
    // for(int i = 0; i < n; i++) cout << one_bef[i] << " \n"[i==n-1];

    pair<int, double> ans = {0, INF};
    for(int i = 0; i <= n; i++){
        if(valid(i)){
            if(abs(i - n/2.0) < ans.second) ans = {i, abs(i - n/2.0)};
        }
    }

    cout << ans.first << endl;

}

int main(){ _
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
