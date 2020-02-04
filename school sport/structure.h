#pragma once
enum gender//性别
{
	男,女
};
struct Name//称呼加ID
{
	int id;
	char name[99];
};

struct StartTime//时间（xx年xx月xx日 xx : xx ）
{
	int date;//日
	int month;//月
	int hour;//几点
	int minute;//几分
};

struct EndTime//时间（xx年xx月xx日 xx : xx ）
{
	int date;//日
	int month;//月
	int hour;//几点
	int minute;//几分
};

struct BriefGame//简略版记录
{
	Name name;//项目名称
	int score;//对运动员:个人成绩; 对单位:最优成绩
	int point;//得分
};

struct Group//单位
{
	int fullscore;//总得分
	Name name;//名称及ID
	BriefGame score[99];//单位内某项比赛的成绩及得分
	int memberid[];//成员id
	
};

struct Game//比赛项目
{
	Name name;//名称
	StartTime starttime;//开始时间
	EndTime endtime;//结束时间
	char place[99];//比赛地点
	int number;//报名人数
	int playerid[];//报名运动员id
};



struct Player//运动员
{
	Name name;//名称
	int year;//年龄
	gender gender;//性别
	int fullscore;//总得分
	BriefGame score[3];//某项比赛得分
};
