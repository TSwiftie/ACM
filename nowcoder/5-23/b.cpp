/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 09:23:46 AM CST
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
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 3e4+10;
struct node{
	string sof;
	int id;
	node(){}
	node(string _sof,int _id): sof(_sof),id(_id){}
	bool operator<(const node & a) const{
		return sof > a.sof;
	}
};
map<string,int>mp;
string str[N],a,b;
int in[N];
vi G[N];
signed main(void){
	IOS;
	int t;
	cin >> t;
	for(int cas = 1;cas <= t;cas++){
		int n,m;
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> str[i];
			mp[str[i]] = i;
		}
		for(int i = 1;i <= m;i++){
			cin >> a >> b;
			G[mp[a]].push_back(mp[b]);
			in[mp[b]]++;
		}
		priority_queue<node>q;
		for(int i = 1;i <= n;i++)
			if(!in[i])
				q.push(node(str[i],i));
		cout << "Case #" << cas << ":" << endl;
		int cnt = 0;
		vector<string>ans;
		while(q.size()){
				node cur = q.top();
				q.pop();
				ans.push_back(cur.sof);
				cnt++;
				for(int v : G[cur.id])
					if(!--in[v])
						q.push(node(str[v],v));
		}
		if(cnt < n) cout << "Impossible" << endl;
		else{
			for(string v : ans)
				cout << v << endl;
		}
		for(int i = 1;i <= n;i++) G[i].clear(),in[i] = 0;
		mp.clear();
	}
	return 0;
}
