#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[10];
	long num;
	float ch,math,en,total;
} STU;

int idx=0;
STU stu[100];

int main(void){
	void cjsr();
	void cjtj();
	void cjpx();
	void cjcx();

	int menu_main;

	while(1){
		system("cls");
		printf("               学生成绩管理系统\n");
		printf("           ----------------------\n");
		printf("              1---学生成绩输入\n");
		printf("              2---学生成绩统计\n");
		printf("              3---学生成绩排序\n");
		printf("              4---学生成绩查询\n");
		printf("              0---退出\n");
		printf("           ----------------------\n");
		printf("           请输入您的选择(0--4)：");
		scanf("%d",&menu_main);
		switch(menu_main){
			case 0: printf("退出系统！\n"); exit(0);
			case 1: cjsr(); break;
			case 2: cjtj(); break;
			case 3: cjpx(); break;
			case 4: cjcx(); break;
			default: printf("菜单选择错误！\n");
		}
	}

}

void cjsr(){
	float ch,math,en;
	char name[10];
    printf("可以输入多位学生的成绩，在一行内输入某一位学生的姓名以及语文、数学、英语的成绩（以姓名输入0 结束输入）：\n");
	while(1){
		printf("%3d号:",idx+1);
		scanf("%s",name);
		if (name[0]=='0')
			break;
		scanf("%f %f %f",&ch ,&math ,&en);
		stu[idx].num=idx+1;
		strcpy(stu[idx].name ,name);
		stu[idx].ch=ch;
		stu[idx].math=math;
		stu[idx].en=en;
		stu[idx].total=ch + math + en;
		idx++;
	}

}

void cjtj(){
	int menuNum;
	while(1){
		system("cls");
		printf("               学生成绩管理系统\n");
		printf("           ----------------------\n");
		printf("              1---统计每位学生总分\n");
		printf("              2---统计每门课的平均分\n");
		printf("              0---返回\n");
		printf("           ----------------------\n");
		printf("           请输入您的选择(0--2)：");
		scanf("%d",&menuNum);
		switch(menuNum){
			case 0: return ;
			case 1: xstj();break;
			case 2: kctj();break;
			default: printf("菜单选择错误！\n");
		}
	}
}
void xstj(){
	int i;
	system("cls");
	printf("编号 姓名 语文 数学 英语 总分\n");
	for(i = 0;i < idx;++i)
		printf("  %02d %4s %4.1f %4.1f %4.1f %4.1f\n",stu[i].num,stu[i].name,stu[i].ch,stu[i].math,stu[i].en,stu[i].total);
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}
void kctj(){
	int i;
	system("cls");
	float Chinese = 0,Math = 0,English = 0;
	for(i = 0;i < idx;++i){
		Chinese += stu[i].ch;
		Math += stu[i].math;
		English += stu[i].en;
	}
	printf("语文:%.2f 数学:%.2f 英语:%.2f\n",Chinese/idx,Math/idx,English/idx);
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}
void cjpx(){
	void px(int);
	int menuNum;
	while(1){
		system("cls");
		printf("               学生成绩管理系统\n");
		printf("           ----------------------\n");
		printf("              1---按语文排序\n");
		printf("              2---按数学排序\n");
		printf("              3---按英语排序\n");
		printf("              4---按总分排序\n");
		printf("              0---返回\n");
		printf("           ----------------------\n");
		printf("           请输入您的选择(0--4)：");
		scanf("%d",&menuNum);
		if(menuNum==0) return ;
		else if(menuNum>=1&&menuNum<=4) px(menuNum);
		else printf("菜单选择错误！\n");
	}
}

void px(int flag){
	int ok = 1;
	while(ok){
		ok = 0;
		for(int i = 0;i < idx-1;++i)
			if(flag==1){
				if(stu[i].ch < stu[i+1].ch){
					ok = 1;
					STU tmp = stu[i];
					stu[i] = stu[i+1];
					stu[i+1] = tmp;
				}
			}else if(flag==2){
				if(stu[i].math < stu[i+1].math){
					ok = 1;
					STU tmp = stu[i];
					stu[i] = stu[i+1];
					stu[i+1] = tmp;
				}
			}else if(flag==3){
				if(stu[i].en < stu[i+1].en){
					ok = 1;
					STU tmp = stu[i];
					stu[i] = stu[i+1];
					stu[i+1] = tmp;
				}
			}else if(flag==4){
				if(stu[i].total < stu[i+1].total){
					ok = 1;
					STU tmp = stu[i];
					stu[i] = stu[i+1];
					stu[i+1] = tmp;
				}
			}
	}
	system("cls");
	printf("排名 编号 姓名 语文 数学 英语 总分\n");
	for(int i = 0;i < idx;++i)
		printf("  %02d   %02ld %4s %4.1f %4.1f %4.1f %4.1f\n",i+1,stu[i].num,stu[i].name,stu[i].ch,stu[i].math,stu[i].en,stu[i].total);
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}

void cjcx(){
	int menuNum;
	void kccx(int);
	void xsxhcx();
	void xsxmcx();
	while(1){
		system("cls");
		printf("               学生成绩管理系统\n");
		printf("           ----------------------\n");
		printf("              1---按语文查询\n");
		printf("              2---按数学查询\n");
		printf("              3---按英语查询\n");
		printf("              4---按学生学号查询\n");
		printf("              5---按学生姓名查询\n");
		printf("              0---返回\n");
		printf("           ----------------------\n");
		printf("           请输入您的选择(0--5)：");
		scanf("%d",&menuNum);
		if(menuNum==0) return ;
		else if(menuNum>=1&&menuNum<=3) kccx(menuNum);
		else if(menuNum==4) xsxhcx();
		else if(menuNum==5) xsxmcx();
		else printf("菜单选择错误！\n");
	}
}

void kccx(int flag){
	int ok = 1;
	while(ok){
		ok = 0;
		for(int i = 0;i < idx-1;++i)
			if(stu[i].num > stu[i+1].num){
				ok = 1;
				STU tmp = stu[i];
				stu[i] = stu[i+1];
				stu[i+1] = tmp;
			}
	}
	system("cls");
	if(flag==1) printf("编号 姓名 语文\n");
	else if(flag==2) printf("编号 姓名 数学\n");
	else if(flag==3) printf("编号 姓名 英语\n");
	for(int i = 0;i < idx;++i){
		if(flag==1) printf("  %02ld %4s %4.1f\n",stu[i].num, stu[i].name, stu[i].ch);
		else if(flag==2) printf("  %02ld %4s %4.1f\n",stu[i].num, stu[i].name, stu[i].math);
		else if(flag==3) printf("  %02ld %4s %4.1f\n",stu[i].num, stu[i].name, stu[i].en);
	}
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}

void xsxhcx(){
	system("cls");
	long Num,cnt = 0;
	printf("请输入您想查询的学号:");
	scanf("%ld",&Num);
	for(int i = 0;i < idx;++i)
		if(stu[i].num==Num){
			++cnt;
			printf("编号: %02ld 姓名: %4s 语文: %4.1f 数学: %4.1f 英语: %4.1f 总分: %4.1f\n",stu[i].num,stu[i].name,stu[i].ch,stu[i].math,stu[i].en,stu[i].total);
		}
	if(!cnt) printf("查无此人！\n");
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}

void xsxmcx(){
	system("cls");
	char sh[10];
	int cnt = 0;
	printf("请输入您想查询的学号:");
	scanf("%s",sh);
	for(int i = 0;i < idx;++i)
		if(strcmp(sh,stu[i].name)==0){
			++cnt;
			printf("编号: %02ld 姓名: %4s 语文: %4.1f 数学: %4.1f 英语: %4.1f 总分: %4.1f\n",stu[i].num,stu[i].name,stu[i].ch,stu[i].math,stu[i].en,stu[i].total);
		}
	if(!cnt) printf("查无此人！\n");
	printf("按\"q\"键返回\n");
	char ch;
	while((ch = getchar())!='q') ;
}
