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


int main()
{ _
    int n; cin >> n;
    int arr[n], soma = 0;
    for(auto& el: arr) {cin >> el; soma += el;}
    int a = 0;
    for(int i=0; i<n; i++){
        if(a == soma) {cout << i << endl; break;}
        a += arr[i];
        soma -= arr[i];
    }
    

    return 0;
} 
