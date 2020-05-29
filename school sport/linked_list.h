#pragma once
//

const char Runway[]= "跑道";
const char Football[] = "足球场";
const char ShotPut[] = "标枪区";
const char LongJump[] = "跳远区";
const char Discus[] = "铅球区";
const char HighJump[] = "跳高区";
const char Tian[] = "田赛";
const char Jing[] = "竞赛";


//基本的结构体
enum Gender//性别
{
	男, 女
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

struct EndTime//时间（ xx : xx ）
{
	
	int hour;//几点
	int minute;//几分
};

struct BriefGame_2//简略版记录
{
	Name name;//项目名称
	int number;//报名人数
	Name playername[99];
	double score[99];//对运动员:个人成绩; 对单位:最优成绩
	int point[99];//得分
	int rank[99];//排名
};

struct BriefGame//简略版记录
{
	Name name;//项目名称
	double score;//对运动员:个人成绩; 对单位:最优成绩
	int point;//得分
	int rank;//排名
};

struct Group//单位
{
	int fullscore;//总得分
	int member_number;//人数
	Name name;//名称及ID
	int point[99];//单位内相应成员的总得分
	Name memberid[99];//成员id

};
struct Game//比赛项目
{
	Name name;//名称
	StartTime starttime;//开始时间
	EndTime endtime;//结束时间
	char type[5];//比赛类型 田赛或竞赛
	char place[7];//比赛地点
	int number;//报名人数
	Name playerid[99];//报名运动员id
};
struct Player//运动员
{
	Name name;//名称
	int year;//年龄
	char gender[3];//性别
	int group_id;
	int fullscore;//总得分
	int game_number;
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

struct BriefGame_2ListNode {//新建简易比赛的链表节点
BriefGame_2 briefgame_2;
BriefGame_2ListNode* next;
};


//链表的函数声明

GameListNode * createpHead(Game game);

void addNode(GameListNode * pHead, Game game);

void insertNode(GameListNode * p, Game game);

GameListNode * deleteNode(GameListNode * pHead, GameListNode * p);

int longNode(GameListNode * pHead);

GameListNode * readGamelist();

void printGamelist(GameListNode * pHead);

void saveGamelist(GameListNode * pHead);




PlayerListNode * createpHead(Player player);

void addNode(PlayerListNode * pHead, Player player);

void insertNode(PlayerListNode * p, Player player);

PlayerListNode * deleteNode(PlayerListNode * pHead, PlayerListNode * p);

int longNode(PlayerListNode * pHead);

PlayerListNode* readPlayerlist();

void savePlayerlist(PlayerListNode* pHead);

void printPlayerlist(PlayerListNode * pHead);


GroupListNode * createpHead(Group group);

GroupListNode* readGrouplist();

void addNode(GroupListNode * pHead, Group group);

void insertNode(GroupListNode * p, Group group);

void deleteNode(GroupListNode * p);
int longNode(GroupListNode* pHead);
void saveGrouplist(GroupListNode* pHead);
void printGrouplist(GroupListNode* pHead);

//5.17新建简易运动员

BriefGame_2ListNode * InipHead();
void addNode(BriefGame_2ListNode * pHead, BriefGame_2 briefplayer);
int longNode(BriefGame_2ListNode* pHead);
void saveBriefGame_2list(BriefGame_2ListNode* pHead);
BriefGame_2ListNode* deleteNode(BriefGame_2ListNode* pHead, BriefGame_2ListNode* p);