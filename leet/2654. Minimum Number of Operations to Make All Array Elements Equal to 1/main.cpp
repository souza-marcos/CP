#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f first
#define s second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int n = nums.size();

        int qtdone = count(nums.begin(), nums.end(), 1);

        if(qtdone > 0) return n - qtdone;

        // find the shortest subarray with gcd equal to 1

        int min_arr = INF, min_idx = -1;
        for (int i = 0; i < n; i++)
        {
            int aux = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                aux = __gcd(aux, nums[j]);
                if (aux == 1)
                {
                    if (j - i < min_arr)
                    {
                        min_arr = j - i;
                        min_idx = i;
                    }
                    break;
                }
            }
        }

        if (min_idx == -1)
            return -1;

        return n + min_arr - 1;
    }
};

int main()
{
    _ int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &el : arr)
        cin >> el;

    Solution so;
    cout << so.minOperations(arr) << endl;

    return 0;
}
