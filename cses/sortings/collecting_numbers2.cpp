#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

int main(){ _

    int n, q; cin >> n >> q;
    vector<int> pos(n + 1), arr(n + 1); 
    for(int i =0; i < n; i ++){
        int a; cin >> a;
        pos[a] = i+1;
        arr[i+1] = a;
    }

    int cnt= 1;
    for(int i = 2; i <= n; i ++){
        if(pos[i] < pos[i-1]) cnt ++;
    }

    cout << cnt << endl;

    while(q--){
        int a, b; cin >> a >> b;
        int val_left = arr[a], val_right = arr[b];
        {
            int bef = pos[val_left-1], after = val_left < n ? pos[val_left + 1] : INF;
            int next = 
        }
        
        cnt -= (pos[val_left] < pos[val_left-1]) + (val_left < n? pos[val_left] > pos[val_left + 1] : 0);
        cnt -= (pos[val_right] < pos[val_right-1]) + (val_right < n? pos[val_right] > pos[val_right + 1] : 0);
        
        arr[a] = val_right, arr[b] = val_left;
        pos[val_left] = b, pos[val_right] = a;

        cnt += (pos[val_left] < pos[val_left-1]) + (val_left < n? pos[val_left] > pos[val_left + 1] : 0);
        cnt += (pos[val_right] < pos[val_right-1]) + (val_right < n? pos[val_right] > pos[val_right + 1] : 0);

        cout << cnt << endl;
    }
    
    return 0;   
} 
