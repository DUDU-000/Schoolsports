#pragma once
enum gender//�Ա�
{
	��,Ů
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
	int score;//���˶�Ա:���˳ɼ�; �Ե�λ:���ųɼ�
	int point;//�÷�
};

struct Group//��λ
{
	int fullscore;//�ܵ÷�
	Name name;//���Ƽ�ID
	BriefGame score[99];//��λ��ĳ������ĳɼ����÷�
	int memberid[];//��Աid
	
};

struct Game//������Ŀ
{
	Name name;//����
	StartTime starttime;//��ʼʱ��
	EndTime endtime;//����ʱ��
	char place[99];//�����ص�
	int number;//��������
	int playerid[];//�����˶�Աid
};



struct Player//�˶�Ա
{
	Name name;//����
	int year;//����
	gender gender;//�Ա�
	int fullscore;//�ܵ÷�
	BriefGame score[3];//ĳ������÷�
};
