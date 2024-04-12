void catalan(int n)
{
    f[0] = f[1] = 1;
    for (int i = 1; i <= 2 * n; ++i)
    {
        f[i] = (f[i - 1] * (4 * i - 2) / (i + 1));
        f[i] = f[i] % 100; // 取模除法会出问题
    }
}