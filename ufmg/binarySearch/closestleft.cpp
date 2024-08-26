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


    int n, k; cin >> n >> k;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i<k; i++){
        int x; cin >> x;
        int l = -1, r = n;
        while(r > l+1){
            int m = (l+r)/2;
            if(arr[m] < x) l = m;  // 1 2 3 4 5 6 7
            else r = m;
        }
        cout << r + 1 << endl;
    }

    return 0;
} 
