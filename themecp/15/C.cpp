#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define endl '\n'
#define sz(x) (int)x.size()



void solve(){
    int n; cin >> n;
    vector<int> arr(n), cnt(n, 0);
    for(auto& el: arr) cin >> el, cnt[el-1]++;

    bool ok = true; int a;
    
    int first=-1, last=-1;
    for(int i = 0; i < n; i ++){
        if(arr[i] == 1) first = i + 1;
        if(arr[i] == n) last = i + 1;
        
        if(cnt[i] == 0) {
            ok = false;
            a = i + 1;
        }
    }

    if(!ok){

        cout << "? " << a << " " << (a + 1)%n + 1 << endl;
        cout.flush();
        int res; cin >> res;
        if(res == 0){
            cout << "! A\n";
            cout.flush();
        }else{
            cout << "! B\n";
            cout.flush();
        }
    }
    else{

        cout << "? "<< first << " " << last << endl;
        cout.flush();

        int res1, res2; cin >> res1;

        cout << "? "<< last << " " << first << endl;
        cout.flush();
        cin >> res2;

        if(res1 == res2 and res1 >= n-1){
            cout << "! B\n";
            cout.flush();
        }else{
            cout << "! A\n";
            cout.flush();
        }

    }
}

int main(){ //_
    int t; cin >> t;
    while(t --) solve();
    return 0;
} 
