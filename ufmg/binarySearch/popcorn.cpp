#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, c, t;
int sacos[MAX];

bool valid(int times){
    int d = t * times;
    int comp = 1;
    for(int i = 0; i < n; i++){
        if(d >= sacos[i]) d -= sacos[i];
        else { 
            comp ++; d = t * times; i--;
        }

        if(comp > c) return false;
    }
    return true;
}

int main(){ //_
    cin >> n >> c >> t;
    for(int i = 0; i < n; i++) cin >> sacos[i];

    int l = 0, r = INF;
    while(l + 1 < r){
        int m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
} 
