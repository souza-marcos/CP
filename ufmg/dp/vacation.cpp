#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;
    int p[n][3], memo[3];
    for(int i = 0; i < n; i++) cin >> p[i][0] >> p[i][1] >> p[i][2];

    for(int i = 0; i < 3; i++) memo[i] = p[0][i];

    int aux[3];
    for(int i = 1; i < n; i++){
        for(int j = 0;j < 3; j++){
            int maxv = 0;
            for(int k = 0; k <3; k++){
                if(j == k) continue;
                maxv = max(maxv, memo[k]);
            }
            aux[j] = maxv + p[i][j];
        }
        for(int j = 0; j < 3; j++) memo[j] = aux[j];
    }

    cout << max(memo[0], max(memo[1], memo[2])) << endl;

    return 0;
} 
