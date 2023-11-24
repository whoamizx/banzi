#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10; // 默认输入字符串数量
// 多组输入记得清零
int cnt = 0;
int nxt[N][27]; // 默认小写字母
bool isend[N];
char str[101]; // 默认最长输入字符串长度100且全为小写字母
char a[101];   //
inline void dfs(int now, int depth)
{
	if (isend[now])
	{
		for (int i = 0; i < depth; i++)
		{
			printf("%c", a[i] + 'a'); // 默认小写字母
		}
		printf("\n");
	}
	for (int i = 0; i < 26; i++)
	{
		if (nxt[now][i])
		{
			a[depth] = i;
			dfs(nxt[now][i], depth + 1);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		int len = strlen(str);
		int now = 0;
		for (int j = 0; j < len; j++)
		{
			int x = str[j] - 'a';
			if (!nxt[now][x])
			{
				nxt[now][x] = ++cnt;
			}
			now = nxt[now][x];
		}
		isend[now] = true;
	}
	dfs(0, 0);
	return 0;
}