#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"

int main() 
{
	int situation = readsituation();//situation ������ 0 1 2,�ֱ�������׶�, �ɼ�¼��׶�, �ɼ���ѯ�׶�
	if (situation == -1) {
		savesituation(0);
		situation = 0;
	}
	int swi;
	system("CLS");
	switch (situation) {
	case 0: {
		printf("�����׶�\n\n");
		printf("��Ϣ����\n");
		printf("1.��λ��Ϣ\n");
		printf("2.�˶�Ա��Ϣ\n");
		printf("3.��Ŀ��Ϣ\n");
		printf("4.����\n");
		printf("\n����\n");
		printf("5.ֹͣ�޸���Ϣ�ͱ���\n");
		printf("6.�˳�\n");
		
	}break;
	case 1: {
		printf("�ɼ�¼��׶�\n\n");
		printf("��Ϣ����\n");
		printf("1.��λ��Ϣ\n");
		printf("2.�˶�Ա��Ϣ\n");
		printf("3.��Ŀ��Ϣ\n");
		printf("\n����\n");
		printf("4.�����ɼ�\n");
		printf("5.�˳�\n");
	}break;
	case 2: {
		printf("�ɼ���ѯ�׶�\n\n");
		printf("��Ϣ����\n");
		printf("1.��λ��Ϣ\n");
		printf("2.�˶�Ա��Ϣ\n");
		printf("3.��Ŀ��Ϣ\n");
		printf("\n����\n");
		printf("4.�˳�\n");
	}break;
	}
	
	if (situation == 0) swi = entrycheckandreinput(1, 6);
	else if (situation == 1) swi = entrycheckandreinput(1, 5);
	else if (situation == 2) swi = entrycheckandreinput(1, 4);

	switch (swi) {
	case -1: main();  break;
	case 1: query_group_menu(); main(); break;
	case 2: query_player_menu(); main(); break;
	case 3: query_game_menu(); main();  break;
	case 4: {
		if (situation == 0) {
			add_menu(); 
			main();
		}
		else if (situation == 1) {
			savesituation(2);
		}
		else if (situation == 2) {
			system("pause");
		}
	} break;
	case 5: {
		if (situation == 0) {
			savesituation(1);
		}
		else if (situation == 1) {
			system("pause");
		}
	} break;
	case 6: system("pause"); break;
	}

	return 0;
}


