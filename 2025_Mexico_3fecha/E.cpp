#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

// GEPETO CODE

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    if (!(cin >> n >> k >> m)) return 0;

    vector<vector<ll>> C(n, vector<ll>(k));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j)
            cin >> C[i][j];

    // adjacency masks from floor i to floor i+1: adj[i][u] is bitmask of v on floor i+1
    vector<vector<int>> adj(n, vector<int>(k, 0));
    for (int e = 0; e < m; ++e) {
        int fi, ui, vi;
        cin >> fi >> ui >> vi;
        --fi; --ui; --vi;
        // stair from room ui on floor fi to room vi on floor fi+1
        adj[fi][ui] |= (1 << vi);
    }

    int ALL = 1 << k;
    // dp masks for current floor (minimal cut cost up to this floor with in-nodes = mask)
    vector<ll> dp(ALL, INF), dp_next(ALL, INF);

    // initial: floor 1's in-nodes must be on source-side => mask = ALL-1; cost 0
    dp[ALL-1] = 0;

    // helper arrays reused per layer
    vector<ll> sumC(ALL);   // sum of capacities on current floor for a mask
    vector<int> reach(ALL); // reach[U] for subsets U on current floor -> mask on next floor
    vector<ll> W(ALL);      // same as sumC (for convenience)
    vector<ll> A(ALL);      // A[U] = min over supersets of (dp + sumC(super))
    vector<ll> min_val(ALL); // temporary for grouping by reach
    vector<ll> ans(n, 0);

    // compute answer for t=1..n iteratively
    for (int floor = 0; floor < n; ++floor) {
        // precompute sumC for this floor
        sumC[0] = 0;
        for (int mask = 1; mask < ALL; ++mask) {
            int lsb = __builtin_ctz(mask);
            int prev = mask ^ (1 << lsb);
            sumC[mask] = sumC[prev] + C[floor][lsb];
        }
        // W equals sumC for subsets on this floor
        for (int mask = 0; mask < ALL; ++mask) W[mask] = sumC[mask];

        // compute answer for this floor (t = floor+1)
        ll best = INF;
        for (int mask = 0; mask < ALL; ++mask) {
            if (dp[mask] >= INF) continue;
            best = min(best, dp[mask] + sumC[mask]);
        }
        if (best >= INF) best = 0; // if unreachable, 0 survivors (but usually dp[full] exists)
        ans[floor] = best;

        // if this is the last floor, break (no transition needed)
        if (floor == n-1) break;

        // compute reach[U] for all U subsets on this floor (to next floor)
        reach[0] = 0;
        for (int mask = 1; mask < ALL; ++mask) {
            int lsb = __builtin_ctz(mask);
            int prev = mask ^ (1 << lsb);
            reach[mask] = reach[prev] | adj[floor][lsb];
        }

        // Compute A0[mask] = dp[mask] + sumC(mask) for current floor masks (dp may be INF)
        for (int mask = 0; mask < ALL; ++mask) {
            if (dp[mask] >= INF) A[mask] = INF;
            else A[mask] = dp[mask] + sumC[mask];
        }
        // We need A[U] = min over supersets S ⊇ U of A0[S].
        // Do SOS DP for min over supersets:
        for (int bit = 0; bit < k; ++bit) {
            for (int mask = 0; mask < ALL; ++mask) {
                if (!(mask & (1 << bit))) {
                    A[mask] = min(A[mask], A[mask | (1 << bit)]);
                }
            }
        }

        // min_val[R] = min over U with reach(U)==R of (A[U] - W[U])
        for (int r = 0; r < ALL; ++r) min_val[r] = INF;
        for (int U = 0; U < ALL; ++U) {
            if (A[U] >= INF) continue;
            int R = reach[U];
            ll val = A[U] - W[U];
            if (val < min_val[R]) min_val[R] = val;
        }

        // For each mask2, we need min over R subset mask2 of min_val[R]
        // So do subset SOS min on min_val to propagate minima to supersets:
        // after this, min_val[mask2] = min_{R subset mask2} min_val[R]
        for (int bit = 0; bit < k; ++bit) {
            for (int mask = 0; mask < ALL; ++mask) {
                if (mask & (1 << bit)) {
                    if (min_val[mask ^ (1 << bit)] < min_val[mask])
                        min_val[mask] = min_val[mask ^ (1 << bit)];
                }
            }
        }

        // dp_next[mask2] = min_val[mask2]  (may be INF)
        for (int mask = 0; mask < ALL; ++mask) dp_next[mask] = min_val[mask];

        // swap dp arrays and continue
        dp.swap(dp_next);
        fill(dp_next.begin(), dp_next.end(), INF);
    }

    // print answers
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
