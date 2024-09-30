#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(a) (int)(a).size()
const int MAXN = 1e6 + 10;
double memo[MAXN], sum[MAXN];

int main(){ _
    cout << fixed << setprecision(7);
    int n, a, b; cin >> n >> a >> b;
    double prob = 1/(double)(b-a+1);

    memo[0] = sum[0] = 0;

    if(a != 0){
        for(int i = 1; i <= a; i++) memo[i] = 1, sum[i] += sum[i-1] + 1;
        for(int i = a+1; i <= n; i++){
            memo[i] = 1 + prob * (sum[i-a]-sum[max(i-b-1, 0)]);
            sum[i] = sum[i-1] + memo[i];
        }
    }
    else{
        a ++;
        for(int i = a; i <= n; i++){
            memo[i] = 1 + prob * (sum[i-a]-sum[max(0, i-b-1)]);
            memo[i] = memo[i] / (1-prob);
            sum[i] = sum[i-1] + memo[i];
        }
    }
    cout << memo[n] << endl;
    // for(int i = 0; i <= n; i ++) cout << memo[i] << " ";
    // cout << endl;

    // for(int i = 0; i <= n; i ++) cout << sum[i] << " ";
    // cout << endl;

    return 0;
} 
