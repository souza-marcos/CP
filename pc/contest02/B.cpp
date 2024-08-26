#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

int main(){_

    int n; cin >> n;
    vector<int> arr(n), vis(n, 0);
    for(int& el: arr) cin >> el;

    sort(arr.rbegin(), arr.rend());

    int a = arr[0], b = 1; vis[0] = 1;

    set<int> comp;

    comp.insert(a);
    for(int i = 1; i < n; i++){
        if(a % arr[i] != 0) {
            b = arr[i];
            break;
        }
        
        if(comp.count(arr[i]) != 0){
            b = arr[i];
            break;
        }

        comp.insert(arr[i]);
    }

    cout << a << " " << b << endl;

    return 0;
}