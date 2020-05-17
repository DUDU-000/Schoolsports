#pragma once
//

const char Runway[]= "�ܵ�";
const char Football[] = "����";
const char ShotPut[] = "��ǹ��";
const char LongJump[] = "��Զ��";
const char Discus[] = "Ǧ����";
const char HighJump[] = "������";
const char Tian[] = "����";
const char Jing[] = "����";


//�����Ľṹ��
enum Gender//�Ա�
{
	��, Ů
};
struct Name//�ƺ���ID
{
	int id;
	char name[99];
};
struct StartTime//ʱ�䣨xx��xx��xx�� xx : xx ��
{
	int date;//��
	int month;//��
	int hour;//����
	int minute;//����
};

struct EndTime//ʱ�䣨 xx : xx ��
{
	
	int hour;//����
	int minute;//����
};

struct BriefGame//���԰��¼
{
	Name name;//��Ŀ����
	double score;//���˶�Ա:���˳ɼ�; �Ե�λ:���ųɼ�
	int point;//�÷�
	int rank;//����
};

struct Group//��λ
{
	int fullscore;//�ܵ÷�
	int member_number;//����
	int game_number;//����������
	Name name;//���Ƽ�ID
	BriefGame score[99];//��λ��ĳ������ĳɼ����÷�
	int memberid[99];//��Աid

};
struct Game//������Ŀ
{
	Name name;//����
	StartTime starttime;//��ʼʱ��
	EndTime endtime;//����ʱ��
	char type[5];//�������� ��������
	char place[7];//�����ص�
	int number;//��������
	Name playerid[99];//�����˶�Աid
	int status=0;//0��ʾ���������� 1��ʾ������ֹ
};
struct Player//�˶�Ա
{
	Name name;//����
	int year;//����
	char gender[3];//�Ա�
	int group_id;
	int fullscore;//�ܵ÷�
	int game_number;
	BriefGame score[3];//ĳ������÷�
};
struct BriefPlayer //�½������˶�Ա
{
	Name name; //����
	int year; //����
	BriefGame score[3];//ĳ������÷�
	int rank;//����
};



//����Ľڵ�

struct GameListNode {//����������ڵ�
	Game game;
	GameListNode* next;
};

struct PlayerListNode {//�˶�Ա������ڵ�
	Player player;
	PlayerListNode* next;
};

struct GroupListNode {//�������ڵ�
	Group group;
	GroupListNode* next;
};

struct BriefPlayerListNode {//�½��˶�Ա������ڵ�
BriefPlayer briefplayer;
BriefPlayerListNode* next;
};


//����ĺ�������

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

//5.17�½������˶�Ա

BriefPlayerListNode * createpHead(BriefPlayer briefplayer);

void addNode(BriefPlayerListNode * pHead, BriefPlayer briefplayer);

void insertNode(BriefPlayerListNode * p, BriefPlayer briefplayer);

BriefPlayerListNode* readBriefplayerlist();