#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int& el: a) cin >> el;
    for(int& el: b) cin >> el;

    int j = 0, k = 0;

    ll cont = 0;
    while(j < n and k < m){
        int first_j = j;
        while(j < n and a[j] == a[first_j]) j++;

        while(k < m and b[k] < a[j - 1]) k ++;

        if(a[j - 1] == b[k]){

            int first_k = k;
            while(k < m and b[k] == b[first_k]) k++;
            
            cont += (k - first_k) * (j - first_j);
        }
        // cout << j << " " << k << endl;

    }


    cout << cont << endl;

    return 0;
} 
