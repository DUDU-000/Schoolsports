#pragma once


enum Gender//性别
{
	男, 女
};
enum Type//项目类型 田赛或竞赛
{
	田赛, 竞赛
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
	double score;//对运动员:个人成绩; 对单位:最优成绩
	int point;//得分
};

struct Group//单位
{
	int fullscore;//总得分
	Name name;//名称及ID
	BriefGame score[99];//单位内某项比赛的成绩及得分
	int memberid[99];//成员id

};
struct Game//比赛项目
{
	Name name;//名称
	StartTime starttime;//开始时间
	EndTime endtime;//结束时间
	Type type;//比赛类型 田赛或竞赛
	char place[99];//比赛地点
	int number;//报名人数
	int playerid[99];//报名运动员id
};
struct Player//运动员
{
	Name name;//名称
	int year;//年龄
	Gender gender;//性别
	int fullscore;//总得分
	BriefGame score[3];//某项比赛得分
};



//链表的节点

struct GameListNode {//比赛的链表节点
	Game game;
	GameListNode* next;
};

struct PlayerListNode {//运动员的链表节点
	Player player;
	PlayerListNode* next;
};

struct GroupListNode {//组的链表节点
	Group group;
	GroupListNode* next;
};


//链表的函数声明

GameListNode * createpHead(Game game);

void addNode(GameListNode * pHead, Game game);

void insertNode(GameListNode * p, Game game);

void deleteNode(GameListNode * p);


PlayerListNode * createpHead(Player player);

void addNode(PlayerListNode * pHead, Player player);

void insertNode(PlayerListNode * p, Player player);

void deleteNode(PlayerListNode * p);


GroupListNode * createpHead(Group group);

void addNode(GroupListNode * pHead, Group group);

void insertNode(GroupListNode * p, Group group);

void deleteNode(GroupListNode * p);
