#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"


char Runway[7] = " �ܵ� ";
char Football[7] = "����";
char ShotPut[7] = "��ǹ��";
char LongJump[7] = "��Զ��";
char Discus[7] = "Ǧ����";
char HighJump[7] = "������";

const char* kind[] = { "����","����" };

void add_info(int type) {//type����������,�ֱ���������basic_info.h��ĳ���,��Ӧ�������
	FILE* file = fopen("game.txt", "r");
	int test = 0;//���������ļ��ı�־���ж��費��Ҫ����ͷ�ڵ�ı�־��0��Ҫ|1����Ҫ��
	if (file==NULL)//��û������ļ���ʱ�򷵻�ֵ��NULL
	{
		file = fopen("game.txt", "w");
		test = 1;
		
	}
	switch (type) {
	case type_game: //����һ��������Ŀ
		Game newGame;
		int place_selection;
		printf("��Ŀ���ƣ�");
		scanf_s("%s", &newGame.name.name,99);

		printf("��������(1.����  2.����)��");
		scanf_s("%d", &newGame.type);//�����������ѵ���ö���������뷽ʽ
		newGame.type =(Type)( newGame.type - 1);

		printf("�����ص�(1.�ܵ�  2.����  3.��ǹ��  4.��Զ��  5.Ǧ����  6.������)��");
		scanf_s("%d", &place_selection);
		switch (place_selection)
		{
		case 1:strcpy(Runway,newGame.place);break;
		case 2:strcpy(Football,newGame.place); break;
		case 3:strcpy(ShotPut,newGame.place); break;
		case 4:strcpy(LongJump,newGame.place); break;
		case 5:strcpy(Discus,newGame.place); break;
		case 6:strcpy(HighJump,newGame.place); break;
		}

		printf("��ʼʱ�䣺\n");
		printf("�·ݣ�");
		scanf_s("%d", &newGame.starttime.month);
		printf("���ڣ�");
		scanf_s("%d", &newGame.starttime.date);
		printf("���㣺");
		scanf_s("%d", &newGame.starttime.hour);
		printf("���֣�");
		scanf_s("%d", &newGame.starttime.minute);

		printf("������ֹʱ�䣺\n");
		printf("�·ݣ�");
		scanf_s("%d", &newGame.endtime.month);
		printf("���ڣ�");
		scanf_s("%d", &newGame.endtime.date);
		printf("���㣺");
		scanf_s("%d", &newGame.endtime.hour);
		printf("���֣�");
		scanf_s("%d", &newGame.endtime.minute);
		
		newGame.number = 0;
		//ǰ��������������	



		
		if (test == 1) {//û�������ļ�
			file = fopen("game.txt", "a");
			newGame.name.id = 0001;
			fprintf(file, "%d\n%s\n%s\n%s\n��ʼʱ��:%d��%d�� %d:%d\n������ֹʱ��:%d��%d�� %d:%d\n��������:%d\n", newGame.name.id/*id*/, newGame.name.name/*����*/, kind[(int)(newGame.type)]/*����*/, newGame.place/*�ص�*/, newGame.starttime.month, newGame.starttime.date, newGame.starttime.hour, newGame.starttime.minute/*��ʼʱ��*/, newGame.endtime.month, newGame.endtime.date, newGame.endtime.hour, newGame.endtime.minute/*������ֹʱ��*/,newGame.number/*��������*/);
			fclose(file);
		}
		
		//��д ���ļ��ж�ȡ�Ѵ��������,����û������,�򴴽�ͷ�ڵ�,������,����һ���ڵ�

		


		break;

	case type_group: //����һ����
		system("CLS");

		break;

	case type_player: //����һ���˶�Ա
		system("CLS");

		break;

	}
}