#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1);
#define endl '\n'
#define sz(x) (int)x.size()

const int MAXN = 101;
int memo[MAXN][MAXN][2];

vector<int> arr;
int n; 

int dp(int el, int i, bool j){
    if(i >= n) return 0;
    if(arr[i] > el and j) return -INF;
    int& p = memo[el][i][j];
    if(p != -1) return p;
    int nexti = dp(el, i + 1, true);
    return p = max(
        j + dp(el, i + 1, false),
        ((j==1)?-INF:nexti)
    );
}

int main(){ _
    int t; cin >> t;
    while(t --){
        memset(memo, -1, sizeof memo);
        cin >> n;
        set<int> diff;
        arr.resize(n); 
        for(auto& el: arr) cin >> el, diff.insert(el);

        int maxv = 0;
        for(auto el: diff){
            maxv = max(maxv, max(dp(el, 0, 0) + el, dp(el, 0, 1)+ el));
        }
        cout << maxv << endl;

        // cout << "____________________\n";
        // for(auto el: diff){
        //     for(int i = 0; i < n; i ++) cout << memo[el][i][0] << " " << memo[el][i][1] << "\n";
        // }
    }


    return 0;
} 
