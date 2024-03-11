int calc(int l1, int r1, int l2, int r2)
{
    int L = 0, R = r1 - l1 + 2; // 左边右边都扩展一个
    int ans = 0;
    while (L + 1 < R)
    {
        int M = (L + R) / 2;
        if (check(M, l1, r1, l2, r2))
        {
            L = M;
            ans = M;
        }
        else
        {
            R = M;
        }
    }
    return ans; // 返回mid,就是返回中间值就不会因为之前的扩展越界
}