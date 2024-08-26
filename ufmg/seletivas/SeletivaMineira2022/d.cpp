#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;

bool verify(int i, int j){

    if(i != 0){

    } 

}

int main(){ _
    cin >> n >> m;
    int campo[n][m];


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char temp; cin >> temp;
            int res = 0;
            if(temp == 'P') res = 1;
            else if(temp == 'W') res = 2;
            campo[i][j] = res;
        }
    }

    return 0;
} 
