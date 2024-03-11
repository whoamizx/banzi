#include <bits/stdc++.h>
using namespace std;
// #define int long long
// 有printf("%d")
struct data
{
    int num[20100];
    int len;
    char op;
    data()
    {
        memset(num, 0, sizeof(num));
        len = 1;
        op = '+';
    }
};

data turn(int b)
{
    int t = 0;
    data c;
    if (b >= 0)
    {
        c.op = '+';
    }
    else
    {
        c.op = '-';
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
bool operator>(data a, data b)
{
    if (a.op == '+' && b.op == '-')
        return 1;
    if (a.op == '-' && b.op == '+')
        return 0;
    if (a.len > b.len)
    {
        if (a.op == '+' && b.op == '+')
            return 1;
        else
            return 0;
    }
    if (a.len < b.len)
    {
        if (a.op == '+' && b.op == '+')
            return 0;
        else
            return 1;
    }
    if (a.op == '-' && b.op == '-')
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
    if (a.op == '+' && b.op == '+')
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

bool operator<(data a, data b)
{
    if (a.op == '+' && b.op == '-')
        return 0;
    if (a.op == '-' && b.op == '+')
        return 1;
    if (a.len < b.len)
    {
        if (a.op == '+' && b.op == '+')
            return 1;
        else
            return 0;
    }
    if (a.len > b.len)
    {
        if (a.op == '+' && b.op == '+')
            return 0;
        else
            return 1;
    }
    if (a.op == '-' && b.op == '-')
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
    if (a.op == '+' && b.op == '+')
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

bool operator==(data a, data b)
{
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

data operator+(data a, data b)
{
    data c;
    c.len = max(a.len, b.len);
    for (int i = 1; i <= c.len; i++)
        c.num[i] = a.num[i] + b.num[i];
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

data operator-(data a, data b)
{
    data c, tmp;
    c.len = max(a.len, b.len);
    if (b > a)
    {
        c.op = '-';
        tmp = a, a = b, b = tmp;
    }
    for (int i = 1; i <= c.len; i++)
        c.num[i] = a.num[i] - b.num[i];
    for (int i = 1; i <= c.len; i++)
    {
        if (c.num[i] < 0)
        {
            c.num[i] += 10;
            c.num[i + 1] -= 1;
        }
    }
    return c;
}

data operator*(data a, data b)
{
    data c;
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

data cpy(data a, int l)
{
    data b;
    for (int i = 1; i <= a.len; i++)
        b.num[i + l - 1] = a.num[i];
    b.len = a.len + l - 1;
    b.op = '+';
    return b;
}

data operator/(data a, data b)
{
    data c;
    c.len = a.len - b.len + 1;
    for (int i = c.len; i >= 1; i--)
    {
        data t = cpy(b, i);
        while (a > t || a == t)
        {
            c.num[i]++;
            a = a - t;
            while (a.len > 0 && !a.num[a.len])
                a.len--;
        }
    }
    while (c.len > 0 && !c.num[c.len])
        c.len--;
    return c;
}

data operator%(data a, data b)
{
    for (int i = a.len - b.len + 1; i >= 1; i--)
    {
        data t = cpy(b, i);
        while (a > t || a == t)
        {
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

void get_data(data &a)
{
    string s1;
    cin >> s1;
    if (s1[0] == '-')
        a.op = '-', s1.erase(0, 1);
    for (int i = 1; i <= s1.size(); i++)
        a.num[i] = s1[s1.size() - i] - '0';
    a.len = s1.size();
}

void print(data c)
{
    if (c.op == '-')
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
    data a, b, c;
    get_data(a);
    get_data(b);
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
}
