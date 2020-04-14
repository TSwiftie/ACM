/************************************************************
	> File Name: test.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 14 Apr 2020 03:55:03 PM CST
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
const int N = 1e5+10;
int n,a[N],t[N];
void merge(int ll,int rr){
	if(rr-ll <= 1) return ;
	int mid = ll + (rr-ll>>1);
	merge(ll,mid);
	merge(mid,rr);
	int p = ll,q = mid,s = ll;
	while(s < rr){
		if(p >= mid || (q < rr && a[p] > a[q]))
			t[s++] = a[q++];
		else t[s++] = a[p++];
	}
	for(int i = ll;i < rr;i++) a[i] = t[i];
}
void qsort(int l,int r){
	int mid = a[(l+r)>>1];
	int i = l,j = r;
	do{
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j)
			swap(a[i++],a[j--]);
	}while(i <= j);
	if(l < j) qsort(l,j);
	if(i < r) qsort(i,r);
}
void ts(int ll,int rr){
	if(rr-ll <= 1) return ;
	int mid = ll + (rr-ll>>1);
	ts(ll,mid);
	ts(mid,rr);
	int p = ll,q = mid,s = ll;
	while(s < rr){
		if(p >= mid || (q < rr && a[p] > a[q]))
			t[s++] = a[q++];
		else t[s++] = a[p++];
	}
	for(int i = ll;i < rr;i++) a[i] = t[i];
}
void st(int l,int r){
	int mid = a[(l+r)>>1];
	int i = l,j = r;
	do{
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i <= j) swap(a[i++],a[j--]);
	}while(i <= j);
	if(l < j) st(l,j);
	if(i < r) st(i,r);
}
