#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10;
int n, k;
int arr[MAX];

bool valid(ll max_sum){

    int segs = 1;
    ll prev_sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > max_sum) return false;
        if(prev_sum + arr[i] > max_sum) {
            segs ++; prev_sum = arr[i];
        } 
        else prev_sum += arr[i];
    
        if(segs > k) return false;
    }
    return true;
}

int main(){ _
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    // chutando o soma maxima
    ll l = 0, r = LINF;
    while(l + 1 < r){
        ll m = (l + r)/2;
        if(valid(m)) r = m;
        else l = m;
    } 
    cout << r << endl;

    return 0;
} 
