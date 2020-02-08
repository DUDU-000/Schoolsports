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
};

struct Group//��λ
{
	int fullscore;//�ܵ÷�
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
	int playerid[99];//�����˶�Աid
};
struct Player//�˶�Ա
{
	Name name;//����
	int year;//����
	char gender[3];//�Ա�
	int fullscore;//�ܵ÷�
	BriefGame score[3];//ĳ������÷�
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

void deleteNode(PlayerListNode * p);


GroupListNode * createpHead(Group group);

void addNode(GroupListNode * pHead, Group group);

void insertNode(GroupListNode * p, Group group);

void deleteNode(GroupListNode * p);
