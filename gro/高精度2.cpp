#include <bits/stdc++.h>
using namespace std;
// #define int long long
// 有printf("%d")
const int N = 2e4 + 10;
struct BigNum
{
    int num[N];
    int len;
    int op;
    BigNum()
    {
        memset(num, 0, sizeof(num));
        len = 1;
        op = 1;
    }
};

BigNum turn(int b)
{
    int t = 0;
    BigNum c;
    if (b >= 0)
    {
        c.op = 1;
    }
    else
    {
        c.op = -1;
    }
    while (b)
    {
        t++;
        c.num[t] = b % 10;
        b /= 10;
    }
    c.len = t;
    return c;
}
bool operator>(BigNum a, BigNum b)
{
    if (a.op == 1 && b.op == -1)
        return 1;
    if (a.op == -1 && b.op == 1)
        return 0;
    if (a.len > b.len)
    {
        if (a.op == 1 && b.op == 1)
            return 1;
        else
            return 0;
    }
    if (a.len < b.len)
    {
        if (a.op == 1 && b.op == 1)
            return 0;
        else
            return 1;
    }
    if (a.op == -1 && b.op == -1)
    {
        for (int i = a.len; i >= 1; i--)
        {
            if (a.num[i] > b.num[i])
                return 0;
            else if (a.num[i] < b.num[i])
                return 1;
            else
                continue;
        }
    }
    if (a.op == 1 && b.op == 1)
    {
        for (int i = a.len; i >= 1; i--)
        {
            if (a.num[i] > b.num[i])
                return 1;
            else if (a.num[i] < b.num[i])
                return 0;
            else
                continue;
        }
    }
    return 0;
}
bool operator<(BigNum a, BigNum b)
{
    // 判符号
    if (a.op == 1 && b.op == -1)
        return 0;
    if (a.op == -1 && b.op == 1)
        return 1;
    if (a.len < b.len)
    {
        if (a.op == 1 && b.op == 1)
            return 1;
        else
            return 0;
    }
    // 判长度
    if (a.len > b.len)
    {
        if (a.op == 1 && b.op == 1)
            return 0;
        else
            return 1;
    }
    // 根据正负,在判每个位
    if (a.op == -1 && b.op == -1)
    {
        for (int i = a.len; i >= 1; i--)
        {
            if (a.num[i] > b.num[i])
                return 1;
            else if (a.num[i] < b.num[i])
                return 0;
            else
                continue;
        }
    }
    if (a.op == 1 && b.op == 1)
    {
        for (int i = a.len; i >= 1; i--)
        {
            if (a.num[i] > b.num[i])
                return 0;
            else if (a.num[i] < b.num[i])
                return 1;
            else
                continue;
        }
    }
    return 0;
}

bool operator==(BigNum a, BigNum b)
{
    // 看符号和位数,全相等在逐位比较
    if (a.len == b.len && a.op == b.op)
    {
        for (int i = a.len; i >= 1; i--)
        {
            if (a.num[i] != b.num[i])
                return 0;
        }
        return 1;
    }
    return 0;
}
BigNum operator+(BigNum a, BigNum b)
{
    BigNum c, temp;
    // 确定长度
    c.len = max(a.len, b.len);
    // 确定符号,如果两个加数的符号不相等,还看要不要换位置,把绝对值大的放到前面
    int flag = -1;
    BigNum tempa = a, tempb = b;
    tempa.op = tempa.op * tempa.op;
    tempb.op = tempb.op * tempb.op;
    c.op = a.op;
    if (tempa < tempb)
    {
        c.op = b.op;
        temp = a;
        a = b;
        b = temp;
    }
    // 确定符号,如果两个加数的符号相等
    if (a.op == 1 && b.op == 1)
    {
        c.op = 1;
        flag = 1;
    }
    if (a.op == -1 && b.op == -1)
    {
        c.op = -1;
        flag = 1;
    }
    // 逐位操作,符号不同flag=-1,相当于-
    for (int i = 1; i <= c.len; i++)
        c.num[i] = a.num[i] + flag * b.num[i];
    for (int i = 1; i <= c.len; i++)
    {
        if (c.num[i] >= 10)
        {
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
            // 看会不会进一位
            c.len = max(c.len, i + 1);
        }
        if (c.num[i] < 0)
        {
            c.num[i + 1] -= 1;
            c.num[i] += 10;
        }
    }
    return c;
}

BigNum operator-(BigNum a, BigNum b)
{
    if (b.op == 1)
    {
        b.op = -1;
    }
    else
    {
        b.op = 1;
    }
    return a + b;
}

BigNum operator*(BigNum a, BigNum b)
{
    BigNum c;
    if (a.op == -1 && b.op == 1 || a.op == 1 && b.op == -1)
    {
        c.op = -1;
    }
    c.len = a.len + b.len + 1;
    for (int i = 1; i <= a.len; i++)
    {
        for (int j = 1; j <= b.len; j++)
        {
            c.num[i + j - 1] += a.num[i] * b.num[j];
        }
    }
    for (int i = 1; i <= c.len; i++)
    {
        if (c.num[i] >= 10)
        {
            c.num[i + 1] += c.num[i] / 10;
            c.num[i] %= 10;
            c.len = max(c.len, i + 1);
        }
    }
    return c;
}

BigNum cpy(BigNum a, int l)
{
    BigNum b;
    for (int i = 1; i <= a.len; i++)
        b.num[i + l - 1] = a.num[i];
    b.len = a.len + l - 1;
    b.op = 1;
    return b;
}

BigNum operator/(BigNum a, BigNum b)
{
    BigNum c;
    c.len = a.len - b.len + 1;
    if (a.op == -1 && b.op == 1 || a.op == 1 && b.op == -1)
    {
        c.op = -1;
    }
    for (int i = c.len; i >= 1; i--)
    {
        BigNum t = cpy(b, i);
        while (a > t || a == t)
        {
            c.num[i]++;
            a = a - t;
            // 减一次就会少一个或者多个最高位,len就会减少,
            // 因为最高位在最右边,len减少就可以把产生的前导0去掉
            while (a.len > 0 && !a.num[a.len])
                a.len--;
        }
    }
    // 去前导0
    while (c.len > 0 && !c.num[c.len])
        c.len--;
    return c;
}

BigNum operator%(BigNum a, BigNum b)
{
    for (int i = a.len - b.len + 1; i >= 1; i--)
    {
        BigNum t = cpy(b, i);
        while (a > t || a == t)
        {
            // 因为如果减到0,会被当成前导0去掉
            if (a == t)
                break;
            a = a - t;
            while (a.len > 0 && !a.num[a.len])
                a.len--;
        }
    }
    if (a == b)
        return turn(0);
    else
        return a;
}

void get_BigNum(BigNum &a)
{
    string s1;
    cin >> s1;
    if (s1[0] == '-')
        a.op = -1, s1.erase(0, 1);
    for (int i = 1; i <= s1.size(); i++)
        a.num[i] = s1[s1.size() - i] - '0';
    a.len = s1.size();
}

void print(BigNum c)
{
    if (c.op == -1)
        printf("-");
    bool flag = 0;
    for (int i = c.len; i >= 1; i--)
    {
        if (c.num[i] != 0 || flag == 1)
        {
            printf("%d", c.num[i]);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("0");
    printf("\n");
}

signed main()
{
    BigNum a;
    BigNum b;
    get_BigNum(a);
    get_BigNum(b);
    BigNum c;
    c = a + b;
    print(c);
    c = a - b;
    print(c);
    c = a * b;
    print(c);
    c = a / b;
    print(c);
    c = a % b;
    print(c);
    return 0;
}
