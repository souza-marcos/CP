#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = acos(-1);
#define sz(x) (int)x.size()

const int MAXN = 301;
int n;
double memo[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];

double dp(int a, int b, int c){
    double& p = memo[a][b][c];
    if(vis[a][b][c]) return p;
    vis[a][b][c] = 1;

    int z = n - (a + b + c);
    
    if(z == n) return p = 0;

    double sum = 0;
    if(c) sum += c/(double)n * dp(a, b + 1, c - 1);
    if(b) sum += b/(double)n * dp(a + 1, b - 1, c);
    if(a) sum += a/(double)n * dp(a - 1, b, c);
    
    return p = (1 + sum) / (1 - z/(double)n); 
}

int main(){ _

    cout << fixed << setprecision(12);
    cin >> n;
    vector<int> cnt(3);
    int el;
    int i  = 0;
    while(i < n) cin >> el, cnt[el-1] ++, i ++;
    cout << dp(cnt[0], cnt[1], cnt[2]) << endl;


    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < n; j ++){
    //         for(int k = 0; k < n; k ++){
    //             cout << i << " " << j << " " << k << " => " << memo[i][j][k] << endl;
    //         }
    //     }
    // }

    return 0;
} 
