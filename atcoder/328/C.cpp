#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f; // -2e9 ... 2e9 
const ll LINF = 0x3f3f3f3f3f3f3f3fll; // -9e18 ... 9e18

const int MAX = 3e5 + 10;

int arr[MAX];
int n, q; 

void build(string s){
    for(int i = 0; i + 1 < n; i ++){
        if(s[i] == s[i + 1]) arr[i] = 1;
    } 

    //building prefix array
    for(int i = 1; i < n - 1; i ++){
        arr[i] += arr[i - 1];
    }

}

int query(int l, int r){
    if(l == r) return 0;
    if(l == 0) return arr[r - 1];
    return arr[r - 1] - arr[l - 1];
}

int main(){ _
    memset(arr, 0, sizeof arr);
    cin >> n >> q;
    string s; cin >> s;
    build(s);
    
    int l, r;
    while(q --){
        cin >> l >> r; l --, r --;
        cout << query(l, r) << endl;
    }

    return 0;
} 
