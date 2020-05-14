#include<iostream>
#include<math.h>
#include<string.h>
#define max 20
using namespace std;
int flag[max][max]={0};
typedef struct
{
	int x1,y1;
	int x2,y2;
}piont;
int xielv(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}
int Max(int a,int b)
{
	return a>b?a:b;
}
int Min(int a,int b)
{
	return a>b?b:a;
}
int inter(piont A, piont B)
{
	int c[4];
	c[0]=xielv(A.x2-A.x1,A.y2-A.y1,B.x1-A.x1,B.y1-A.y1);
	c[1]=xielv(A.x2-A.x1,A.y2-A.y1,B.x2-A.x1,B.y2-A.y1);
	c[2]=xielv(B.x2-B.x1,B.y2-B.y1,A.x1-B.x1,A.y1-B.y1);
	c[3]=xielv(B.x2-B.x1,B.y2-B.y1,A.x2-B.x1,A.y2-B.y1);
	if(c[0]*c[1]<=0&&c[2]*c[3]<=0) return 1;
	return 0;
}
int main()
{
	piont p[max];
	int n,a,b;
	while(cin>>n)
	{
		memset(flag, 0, sizeof(flag));
		for(int i=1;i<=n;i++)
	    {
		    cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
	    }
	    for(int i=1;i<=n;i++)
	    {
		    flag[i][i]=1;
		    for(int j=i+1;j<=n;j++)
		    {
			    if(inter(p[i],p[j])==1)
			    {
				flag[i][j]=1;
				flag[j][i]=1;
			    }
		    }
	    }
	    for(int i=1;i<=n;i++)
	    {
		    for(int j=1;j<=n;j++)
		    {
			    for(int k=1;k<=n;k++)
			    {
				    if(flag[i][j]==1&&flag[j][k]==1)
				    {
					    flag[i][k]=1;
					    flag[k][i]=1; 
				    }
			    }
		    }
	    }
	    while(cin>>a>>b)
	    {
		    if(a==0&&b==0) break;
		    if(flag[a][b]==1) cout<<"CONNECTED"<<endl;
		    else cout<<"NOT CONNECTED"<<endl;
	    }
	}
	return 0;
}

