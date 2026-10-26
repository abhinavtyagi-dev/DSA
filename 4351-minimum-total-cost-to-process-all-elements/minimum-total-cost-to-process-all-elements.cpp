class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cnt1 = k;
        long long cnt = 0;
        long long sum = 0;
        const long long mod = 1000000007;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (cnt1 < nums[i]) {
                long long diff = nums[i] - cnt1;
                long long m = (diff + k - 1) / k;

                // AP sum: m * (2*cnt + m + 1) / 2
                long long a = m;
                long long b = 2 * cnt + m + 1;

                if (a % 2 == 0) {
                    a /= 2;
                } else {
                    b /= 2;
                }

                long long cost = ((a % mod) * (b % mod)) % mod;
                sum = (sum + cost) % mod;

                cnt1 += m * k;
                cnt += m;
            }

            cnt1 -= nums[i];
        }

        return (int)sum;
    }
};