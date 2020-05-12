#include<iostream>	
#include<cstring>
#include<string>
using namespace std;
class Clock	//时钟类的声明
{
public:	//外部接口，公有成员函数
	void SetTime(string s, int NewH = 0, int NewM = 0, int NewS = 0);
	void ShowTime();
private:	//私有数据成员
	int hp, mp, sp; 
	string a;
};
//时钟类成员函数的具体实现
void Clock::SetTime(string s, int NewH, int NewM, int NewS)
{
	a = s;
	hp = NewH;
	mp = NewM;
	sp = NewS;
}
void Clock::ShowTime()
{
	cout << a << ':' << hp << ":" << mp << ":" << sp << endl;
}
int main(void)
{
	Clock  Clock1, Clock2, Clock3, Clock4;	//定义对象myClock
	Clock1.SetTime("巴黎时间", 7, 34, 12);	
	Clock1.ShowTime();	//显示时间
	Clock2.SetTime("东京时间", 8, 30, 30);  //设置时间为8：30：30
	Clock2.ShowTime();	//显示时间
	Clock3.SetTime("伦敦时间", 12, 54, 33);
	Clock3.ShowTime();
	Clock4.SetTime("纽约时间", 13, 10, 20);
	Clock4.ShowTime();
	return 0;
}

