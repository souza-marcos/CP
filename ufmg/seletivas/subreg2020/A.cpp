#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const long double PI = 3.141592653589793238462643383279502884L;

#define sz(x) (int)x.size()

const int MAX = 1e6 + 10;
double sum[MAX];
int main(){ _
    cout << fixed << setprecision(8);
    int n, a, b; cin >> n >> a >> b;

    // Ex = 1 + 1/L * (summ [Ex-a..Ex-b])

    double memo[n + 1]; memo[0] = 0;
    double prob = 1/((double)b-a+1);

    if(a != 0){
        for(int i = 1; i <= a; i++) memo[i] = 1, sum[i] += sum[i-1] + 1;
        for(int i = a+1; i <= n; i++){
            memo[i] = 1 + prob * (sum[i-a]-(i-b-1>=0?sum[i-b-1]:0));
            sum[i] = sum[i-1] + memo[i];
        }
    }
    else{
        a ++;
        for(int i = a; i <= n; i++){
            memo[i] = 1 + prob * (sum[i-a]-(i-b-1>=0?sum[i-b-1]:0));
            memo[i] = memo[i] / (1-prob);
            sum[i] = sum[i-1] + memo[i];
        }
    }

    cout << memo[n] << endl;
    return 0;
} 
