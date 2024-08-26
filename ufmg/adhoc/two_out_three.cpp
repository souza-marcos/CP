#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n); // Value - Index;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.rbegin(), arr.rend());

    // Find two different tuples 
    int tupl = 0, j = 0, last = 0, i = 0;
    for(; i + 1 < n; i ++){
        if(tupl < 2 && arr[i].f == arr[i+1].f && arr[i].f != last){
            last = arr[i].f;
            tupl ++;
            if(j == 0){
                j ++;
                arr[i].f = 3;
                arr[i + 1].f = 1;
            }
            else {
                arr[i].f = 2;
                arr[i + 1].f = 1;
            }
            ++ i; // Jump a position
            continue;
        }
        else arr[i].f = 1;
    }


    if(tupl < 2) {
        cout << -1 << endl; return;
    }

    sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b ){
        return a.second < b.second;
    });

    for(auto el: arr) cout << el.f << " ";
    cout << endl;

}

int main(){ _
    int t; cin >> t;
    while(t--) solve();

    return 0;
} 
