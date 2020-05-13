#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"


void information_game(GameListNode* pnewHead,int situation) {//����ͷ�ڵ�Ͷ�Ӧ��λ��(�ڼ���)
	int i = 1;
	GameListNode* p_game=pnewHead;
	Game game;
	

	while (i != situation) {//�ҵ���ѡ��Ľڵ�
		p_game = p_game->next;
		i++;
	}

	system("CLS");
	game = p_game->game;
	printf( "��Ŀ��Ϣ:\n");//��ӡ��Ŀ������Ϣ
	printf("����:%s\n", game.name.name/*����*/);
	printf("����:%s\n", game.type/*����*/);
	printf("�ص�:%s\n", game.place/*�ص�*/);
	printf("����:%d\n", game.number/*��������*/);
	printf("ʱ��:%d��%d��%d : %d-%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/, game.endtime.hour, game.endtime.minute/*����ʱ��*/);
	printf("������Ա:\n");
	if (game.playerid[0].id == NULL|| game.playerid[0].id<=0) printf("��");
	else 
		for (int j = 0; j < game.number; j++) {
			printf("ID:%d ", game.playerid[j].id);//������Աid
			printf("����:%s    ", game.playerid[j].name);//������Աid
			if ((j+1) % 5 == 0) printf("\n");
		}
	printf("\n\n\n");


	if (game.status == 0)//���������н���
	{
		printf("����:\n");//����
		printf("1.�޸�\n2.ɾ��\n3.����\n4.����\n");//ѡ��

		int x = -1;
		char entry_s[99] = { 0 };
		while (x == -1)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			x = entrycheck(entry_s, 1, 5);
			if (x == -1)printf("��������,����������:");
		}
		switch (x) {
		case 1: reviseGame(game); break;//�޸�
		case 2: {
			GameListNode* pHead = readGamelist();
			p_game = pHead;
			while (p_game->game.name.id != game.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
				p_game = p_game->next;
			}
			pHead = deleteNode(pHead, p_game);
			saveGamelist(pHead);
			printf("\n\nɾ�����\n");
			system("pause");
		}
			  break;//ɾ��
		case 3: {
			PlayerListNode* pHead_player = readPlayerlist();
			PlayerListNode* p_player = pHead_player;

			printf("\n�����˶�ԱID���б���\n����0�˳�����\n");

			while (true) {
				printf("����:");
				int id = -1;
				while (true) {//���벢������Ŀ
					while (id == -1)//������
					{
						gets_s(entry_s, 99);
						rewind(stdin);
						id = entrycheck(entry_s, 0, 99);
						if (id == -1)printf("��������,����������:");
					}
					if (id == 0) break;
					p_player = pHead_player;
					while (p_player->player.name.id != id) {
						if (p_player->next == NULL) break;
						p_player = p_player->next;
					}
					if (p_player->player.name.id != id && p_player->next == NULL) {
						printf("�Ҳ������˶�Ա,����������:");
						id = -1;
					}
					else {
						p_player->player.score[p_player->player.game_number].name = game.name;
						p_player->player.score[p_player->player.game_number].point = 0;
						p_player->player.score[p_player->player.game_number].score = 0;
						p_player->player.game_number++;
						game.playerid[game.number] = p_player->player.name;
						game.number++;
						savePlayerlist(pHead_player);
						break;
					}
				}
				if (id == 0) break;
			}
			GameListNode* pHead_game = readGamelist();
			p_game = pHead_game;
			while (p_game->game.name.id != game.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
				p_game = p_game->next;
			}
			p_game->game = game;
			saveGamelist(pHead_game);
			printf("\n\n�������\n");
			system("pause");
		}break;
		case 4:break;//����
		}
	}
	else if (game.status == 1)//������ֹ����
	{
		printf("����:\n");//����
		printf("1.�޸�\n2.ɾ��\n3.�ɼ�¼��\n4.����");//ѡ��

		int x = -1;
		char entry_s[99] = { 0 };
		while (x == -1)//������
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			x = entrycheck(entry_s, 1, 3);
			if (x == -1)printf("��������,����������:");
		}
		switch (x) {
		case 1: reviseGame(game); break;//�޸�
		case 2: {
			GameListNode* pHead = readGamelist();
			p_game = pHead;
			while (p_game->game.name.id != game.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
				p_game = p_game->next;
			}
			pHead = deleteNode(pHead, p_game);
			saveGamelist(pHead);
			printf("\n\nɾ�����\n");
			system("pause");
		}; break;//ɾ��
		case 3: {
			score_entry(game);
		}break;//�ɼ�¼��

		case 4:break;//����
		}
	}
}

void information_player(PlayerListNode* pnewHead, int situation) {
	int i = 1;
	PlayerListNode* p = pnewHead;
	Player player;
	

	while (i != situation) {//�ҵ���ѡ��Ľڵ�
		p = p->next;
		i++;
	}

	system("CLS");
	player = p->player;
	printf("�˶�Ա��Ϣ:\n");//��ӡ��Ŀ������Ϣ
	printf("ID:%d\n", player.name.id);//id
	printf("����:%s\n", player.name.name);//����
	printf("�Ա�:%s\n", player.gender);//�Ա�
	printf("����:%d\n", player.year);//id
	printf("С��ID:%d\n", player.group_id);//С��ID
	printf("�ܷ���:%d\n", player.fullscore);//�ܷ���
	printf("������:%d\n", player.game_number);//������

	printf("������Ŀ:%d\n", player.game_number);//������
	if (player.game_number == 0) printf("��\n");
	else 
	for (int j = 0; j < player.game_number; j++) {
		printf("��Ŀ����:%s ", player.score->name.name);//��Ŀ����
		printf("��Ŀ�ɼ�:%f ", player.score->score);//��Ŀ�ɼ�
		printf("��Ŀ�÷�:%d \n", player.score->point);//��Ŀ�ɼ�
	}


	printf("\n\n\n");
	printf("����:\n");//����
	printf("1.�޸�\n2.ɾ��\n3.����\n4.����\n");//ѡ��

	int x = -1;
	char entry_s[99];
	while (x == -1)//������
	{
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 4);
		if (x == -1)printf("��������,����������:");
	}
	switch (x){
	case 1: revisePlayer(player); break;//�޸�
	case 2:{
		PlayerListNode* pHead = readPlayerlist();
		p = pHead;
		while (p->player.name.id != player.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
			p = p->next;
		}
		pHead = deleteNode(pHead, p);
		savePlayerlist(pHead);
		printf("\n\nɾ�����\n");
		system("pause");
	}//ɾ��
	break;
	case 3: {
		if (player.game_number < 3) {
			printf("\n\n���������ID:");
			int x = -1;
			char entry_s[99];
			GameListNode* pHead_game = readGamelist();
			GameListNode* p_game;
			while (true) {//���벢������Ŀ
				while (x == -1)//������
				{
					gets_s(entry_s, 99);
					rewind(stdin);
					x = entrycheck(entry_s, 1, 99);
					if (x == -1)printf("��������,����������:");
				}
				p_game = pHead_game;
				while (p_game->game.name.id != x) {
					if (p_game->next == NULL) break;
					p_game = p_game->next;
				}
				if (p_game->game.name.id != x&&p_game->next == NULL) {
					printf("�Ҳ����ñ���,����������:");
					x = -1;
				}
				else break;
			}
			player.score[player.game_number].name = p_game->game.name;
			player.score[player.game_number].point = 0;
			player.score[player.game_number].score = 0;
			player.game_number++;
			p_game->game.playerid[p_game->game.number] = player.name;
			p_game->game.number++;

			saveGamelist(pHead_game);
			
			PlayerListNode* pHead_player = readPlayerlist();
			p = pHead_player;
			while (p->player.name.id != player.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
				p = p->next;
			}
			p->player = player;
			savePlayerlist(pHead_player);
			printf("�����ɹ�\n");
		}
		else {
			printf("�˶�Ա�ѱ���������Ŀ,�����ٱ���\n");
		}
		system("pause");
	}
	break;//����
	case 4:break;

	}
}

void information_group(GroupListNode* pnewHead, int situation) {
	int i = 1;
	GroupListNode* p = pnewHead;
	Group group;
	while (i != situation) {
		p = p->next;
		i++;
	}
	system("CLS");
	group = p->group;
	printf("��λ����:%s\n", group.name.name);
	printf("��λ����:%d\n", group.member_number);
	printf("��λ�ܵ÷�:%d\n", group.fullscore);
	printf("��λ����������:%d\n", group.game_number);
	int swi=-1;
	char entry_str[99] = {0};
	printf("\n\n\n");
	printf("����:\n");//����
	printf("1.�����ɼ��鿴\n2.��λ��Ա\n3.�޸�����\n4.ɾ��\n5.����\n");//ѡ��
	while (swi == -1) {
		gets_s(entry_str, 99);
		rewind(stdin);
		swi = entrycheck(entry_str, 1, 5);
		if (swi == -1)printf("��������,����������:");
	}

	switch (swi)
	{
	case 1: {//�˴�������¼ֻ�ɲ鿴(������޸�?������)
		searchGroup_game(p);
		GroupListNode* pHead = readGrouplist();
		GroupListNode* p_2 = pHead;
		while (p_2->group.name.id != p->group.name.id) {
			p_2 = p_2->next;
		}
		p_2->group = p->group;
		saveGrouplist(pHead); 
	}; break;
	case 2: {
		searchGroup_palyer(p);
		GroupListNode* pHead = readGrouplist();
		GroupListNode* p_2 = pHead;
		while (p_2->group.name.id != p->group.name.id) {
			p_2 = p_2->next;
		}
		p_2->group = p->group;
		saveGrouplist(pHead);
	} break;
	case 3:reviseGroup(group); break;
	case 4: {
		GroupListNode* pHead = readGrouplist();
		p = pHead;
		while (p->group.name.id != group.name.id) {
			p = p->next;
		}
		deleteNode(p);
		saveGrouplist(pHead);
		printf("\n\nɾ�����\n");
		system("pause");
	}break;
	case 5:break;//����
	}
}