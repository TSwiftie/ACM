/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 23 May 2020 02:53:21 PM CST
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
unordered_map<string,int>mp;
unordered_map<int,string>rmp;
string a,b;
vi G[N];
int in[N];
bool cmp(int a,int b){
	return rmp[a] < rmp[b];
}
signed main(void){
	IOS;
	int t;
	cin >> t;
	for(int cas = 1;cas <= t;cas++){
		int n, m;
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> a;
			mp[a] = i;
			rmp[i] = a;
		}
		for(int i = 1;i <= m;i++){
			cin >> a >> b;
			G[mp[a]].push_back(mp[b]);
			in[mp[b]]++;
		}
		priority_queue<string,vector<string>,greater<string> >q;
		for(int i = 1;i <= n;i++)
			if(!in[i])
				q.push(rmp[i]);
		cout << "Case #" << cas << ":" << endl;
		if(!SZ(q)) cout << "Impossible" << endl;
		else{
			while(q.size()){
				string cur = q.top();
				q.pop();
				cout << cur << endl;
				for(int v : G[mp[cur]]){
					if(!--in[v])
						q.push(rmp[v]);
				}
			}
		}
		mp.clear();rmp.clear();
	}
	return 0;
}
