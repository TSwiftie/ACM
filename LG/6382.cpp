/************************************************************
	> File Name: 6382.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 11:19:00 AM CST
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
string str;
signed main(void){
	IOS;
	cin >> str;
	if(str.substr(0,3)!="MDA") cout << "1 1 1 1 1" << endl;
	else{
		int wei = 0;
		for(int i = 7;i > 2;i--)
			if(str[i]>='0'&&str[i]<='9'){
				wei = str[i]-'0';
				break;
			}
		for(int i = 1;i <= 5;i++){
			if(i==1&&(wei==1||wei==9)) cout << 1;
			else if(i==2&&(wei==2||wei==8)) cout << 1;
			else if(i==3&&(wei==3||wei==7)) cout << 1;
			else if(i==4&&(wei==4||wei==6)) cout << 1;
			else if(i==5&&(wei==5||wei==0)) cout << 1;
			else cout << 0;
			if(i==5) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}
