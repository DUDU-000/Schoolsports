#pragma once
enum Gender//�Ա�
{
	��,Ů
};
enum Type//��Ŀ���� ��������
{
	����, ����
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

struct EndTime//ʱ�䣨xx��xx��xx�� xx : xx ��
{
	int date;//��
	int month;//��
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
	Type type;//�������� ��������
	char place[99];//�����ص�
	int number;//��������
	int playerid[99];//�����˶�Աid
};
struct Player//�˶�Ա
{
	Name name;//����
	int year;//����
	Gender gender;//�Ա�
	int fullscore;//�ܵ÷�
	BriefGame score[3];//ĳ������÷�
};


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