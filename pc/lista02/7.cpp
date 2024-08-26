#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int n;
vector<int> v;
int memo[1001][1001]; // maximo consigo no subarray [l, r];

int main(){_

    while(cin >> n and n != 0){
        n = n * 2;
        v.resize(n);
        
        for(int& el: v) {
            cin >> el;
            el = (el + 1) % 2;
        }

        for(int i = 0; i < n; i++) memo[i][i] = v[i];
        for(int s = 1; s <= n; s++){
            for(int l = 0; l + s < n; l++){
                int r = l + s;
                if(s % 2) memo[l][r] = max(memo[l+1][r] + v[l], memo[l][r - 1] + v[r]);
                else memo[l][r] = min(memo[l+1][r], memo[l][r - 1]);
            }
        }
    
        cout << memo[0][n-1] << endl;
    }

    return 0;
}