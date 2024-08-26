#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll n, x, y;
ll fast, slow;

bool valid(ll t) {
  ll copies = 0;

  // produce first copy
  if (t >= fast) copies++; t -= fast;

  // produces fast copies
  copies += floor(t / fast);

  // produce slow copies
  copies += floor(t / slow);

  return copies >= n;
}

int main() {

  cin >> n >> x >> y;

  fast = min(x,y);
  slow = max(x,y);

  ll l = 0;
  ll r = n * fast;

  while (r > l + 1) {
    ll m = (l + r)/2;

    if (valid(m)) r = m;
    else l = m;
  }

  cout << r << endl;

  return 0;
}
