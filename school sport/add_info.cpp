#include<iostream>
#include <stdio.h>
#include<string.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"




void add_info(int type) {//type����������,�ֱ���������basic_info.h��ĳ���,��Ӧ�������
	
	switch (type) {
	case type_game: //����һ��������Ŀ
		Game newGame;
		GameListNode* pHead;
		int place_selection,type_selection;

		//��дnewGame������
		system("CLS");
		printf("��Ŀ���ƣ�");
		scanf_s("%s", &newGame.name.name,99);

		printf("��������(1.����  2.����)��");
		scanf_s("%d", &type_selection);//�����������ѵ���ö���������뷽ʽ
		if(type_selection==1) strcpy(newGame.type, Tian);
		else strcpy(newGame.type, Jing);

		printf("�����ص�(1.�ܵ�  2.����  3.��ǹ��  4.��Զ��  5.Ǧ����  6.������)��");
		scanf_s("%d", &place_selection);
		switch (place_selection)
		{
		case 1:strcpy(newGame.place, Runway); break;
		case 2:strcpy(newGame.place, Football); break;
		case 3:strcpy(newGame.place, ShotPut); break;
		case 4:strcpy(newGame.place, LongJump); break;
		case 5:strcpy(newGame.place, Discus); break;
		case 6:strcpy(newGame.place, HighJump); break;
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

		printf("����ʱ�䣺\n");
		printf("���㣺");
		scanf_s("%d", &newGame.endtime.hour);
		printf("���֣�");
		scanf_s("%d", &newGame.endtime.minute);
		newGame.number = 0;




	
		pHead = readGamelist();	//��ȡ�ļ��е�����pHead
		if (pHead == NULL) { //���ļ���������,���½�һ������
			newGame.name.id = 1;
			pHead = createpHead(newGame);
		}
		else { //��������,����pHead�����������һ���ڵ�
			newGame.name.id = longNode(pHead) + 1;//��id,idΪ�����˳��
			addNode(pHead, newGame);
		}
		saveGamelist(pHead);//��������

		break;

	case type_group: //����һ����
		system("CLS");

		break;

	case type_player: //����һ���˶�Ա
		system("CLS");

		break;

	}
	printf("\n\n�������\n");
	system("pause");
}