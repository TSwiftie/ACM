/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 10:10:06 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 2e5+10;
int n;
int as[N];
vi edge[N];
int dist[2][N];
int q[N];
void bfs(int *dist,int s){
	fill(dist,dist+n,INF);
	int qh = 0,qt = 0;
	q[qh++] = s;
	dist[s] = 0;
	while(qt < qh){
		int x = q[qt++];
		for(int y : edge[x]){
			if(dist[y]==INF){
				dist[y] = dist[x] + 1;
				q[qh++] = y;
			}
		}
	}
}
signed main(void){
	int m, k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i < k;i++){
		scanf("%d",as+i);
		as[i]--;
	}
	sort(as,as+k);
	for(int i = 0;i < m;i++){
		int x, y;
		scanf("%d%d",&x,&y);
		x--,y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	bfs(dist[0],0);
	bfs(dist[1],n-1);
	vector<pii>data;
	for(int i = 0;i < k;i++)
		data.emplace_back(dist[0][as[i]]-dist[1][as[i]],as[i]);
	sort(all(data));
	int ans = 0;
	int Max = -INF;
	for(auto it : data){
		int a = it.second;
		ans = max(ans,Max + dist[1][a]);
		Max = max(Max,dist[0][a]);
	}
	printf("%d\n",min(dist[0][n-1],ans+1));
	return 0;
}
