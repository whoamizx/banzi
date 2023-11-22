#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e5+10;
int n,m,l=0;
struct Node
{
  Node *next;
  int where;
}head[N+1],a[2*M+1];
void addedge(int x,int y)
{
  a[++l].where=y;
  a[l].next=head[x];
  head[x]=&a[l];
}
int main()
{
   
  return 0;
}