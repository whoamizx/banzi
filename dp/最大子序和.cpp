#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> nums)
{
    if (nums.size() == 0)
        return -1e9;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] > result)
            result = dp[i];
    }
    return result;
}