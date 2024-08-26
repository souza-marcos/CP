#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<int> arr(n);
    for(auto &el: arr) cin >> el;

    //find size of subarray
    
    int last = arr[0], cont = 1;
    int total = 0;
    for(int i = 1; i < n; i++){
        if(last == arr[i]){
            if(cont == 0) cont = 2;
            else{
                cont ++;
            }
        }
        else{
            total += cont;
            cont = 1;
        }
    }

    return 0;
} 
