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

int main(){ _

    int n, m; cin >> n >> m;
    
    int temp, sum = 0, last = 0;
    for(int i = 0; i < n; i ++){
        cin >> temp;
        int mini = min(m - temp, temp);
        int maxi = max(m - temp, temp);
        temp = ((mini < last)? maxi: mini);

        if (temp < last){
            cout << -1 << endl;
            return 0;
        }

        sum += temp;
        last = temp;
    }
    cout << sum << endl;
    return 0;
} 
