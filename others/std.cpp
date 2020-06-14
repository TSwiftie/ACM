#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,vis[N][N],dp[N][N],g[N][N],res;
int dp1[1010][1010][2];
void solve(int k){
	memset(dp,0,sizeof dp);	dp[1][1]=1;
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	
		if(vis[i][j]==res&&(g[i][j]>>k&1))	dp[i][j]|=(dp[i-1][j]|dp[i][j-1]);
	if(!dp[n][m])	return ;
	res|=(1<<k);
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	if(dp[i][j])	vis[i][j]=res;
}
signed main(){
	//cin >> n >> m;
	srand((unsigned)time(nullptr));
	n = 4,m = 4;
	for(int cas = 1;cas <= 1000;++cas){
		for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	g[i][j] = rand()%10+1;
		for(int i=31;i>=0;i--)	if(g[1][1]>>i&1)	solve(i);
		//cout<<res<<endl;
		for(int i=1;i<=n;i++) dp1[i][0][0]=dp1[i][0][1]=1;
		for(int i=1;i<=m;i++) dp1[0][i][0]=dp1[0][i][1]=1;
		dp1[1][1][0]=g[1][1];
		dp1[1][1][1]=g[1][1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
					if(i-1!=0) 
						dp1[i][j][0]=max(g[i][j]&dp1[i-1][j][0],g[i][j]&dp1[i-1][j][1]);
					if(j-1!=0)
						dp1[i][j][1]=max(g[i][j]&dp1[i][j-1][0],g[i][j]&dp1[i][j-1][1]);
			}
		}
		int ans = max(dp1[n][m][1],dp1[n][m][0]);
		//cout << ans << endl;
		if(ans!=res){
			cout << res << " " << ans << endl;
			for(int i = 1;i <= n;++i)
				for(int j = 1;j <= m;++j){
					cout << g[i][j];
					if(j==m) cout << endl;
					else cout << " ";
				}
		}
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		memset(dp1,0,sizeof dp1);
		res = 0;
	}
    return 0;
}

