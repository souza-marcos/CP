#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
typedef long long ll;

ll memo[101][101]; // tendo tamanho i e  comeca de j 

int main(){_

    int n, k;
    while(cin >> n >> k and n != 0){
        vector<int> v(n);
        for(int& el: v) cin >> el;

        for(int i = 0; i < n; i++) memo[0][i] = 1;
        for(int i = 1; i < k; i++){
            for(int j = 0; j < n; j++){
                // soma valores maiores que o atual
                memo[i][j] = 0;
                for(int k = j + 1; k < n; k++) if(v[j] < v[k]) memo[i][j] += memo[i - 1][k];
            }
        }

        ll res = 0;
        for(int i = 0; i < n; i++) res += memo[k - 1][i];
        cout << res << endl;
    }
    return 0;
}