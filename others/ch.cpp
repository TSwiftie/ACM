/************************************************************
	> File Name: ch.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 06 May 2020 07:59:48 PM CST
************************************************************/

#include <stdio.h>
#include <string.h>
int main(void){
	int i, j, N;
	printf("Name numbers:");
	scanf("%d",&N);
	getchar();
	char k,a[N+10];
	printf("Please input %d names:",N);
	for(int i = 0;i < N;i++)
		scanf("%c",&a[i]);
	bool ok = true;
	while(ok){
		ok = false;
		for(int i = 0;i < N-1;i++)
			if(a[i] > a[i+1]){
				k = a[i];
				a[i] = a[i+1];
				a[i+1] = k;
			}
	}
	printf("Names list:\n");
	for(int i = 0;i < N;i++)
		printf("%c",a[i]);
	puts("");
	return 0;
}
