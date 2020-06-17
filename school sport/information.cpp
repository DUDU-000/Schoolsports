#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


void information_game(GameListNode* pnewHead,int situation) {//����ͷ�ڵ�Ͷ�Ӧ��λ��(�ڼ���)

	int sit = readsituation();
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
	printf("�Ա�:%s\n", game.gender/*�Ա�*/);
	printf("����:%d\n", game.number/*��������*/);
	printf("ʱ��:��%d��%d : %d-%d : %d\n",game.starttime.day, game.starttime.hour, game.starttime.minute/*��ʼʱ��*/, game.endtime.hour, game.endtime.minute/*����ʱ��*/);
	printf("������Ա:\n");
	if (game.playerid[0].id == NULL|| game.playerid[0].id<=0) printf("��");
	else 
		for (int j = 0; j < game.number; j++) {
			printf("ID:%d ", game.playerid[j].id);//������Աid
			printf("����:%s    ", game.playerid[j].name);//������Աid
			if ((j+1) % 5 == 0) printf("\n");
		}
	printf("\n\n\n");


	if (sit == 0)//����,�޸Ľ����н���
	{
		printf("����:\n");//����
		printf("1.�޸�\n2.ɾ��\n3.����\n4.����\n");//ѡ��

		int x=entrycheckandreinput(1, 4);

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
			
		}break;//ɾ�� 
		case 3: {
			PlayerListNode* pHead_player = readPlayerlist();
			PlayerListNode* p_player = pHead_player;
			printf("\n�����˶�ԱID���б���\n����0�˳�����\n");
			while (true) {
				int id = -1;
				while (true) {//���벢������Ŀ
					id = entrycheckandreinput(0, 99);
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
					else if (strcmp(p_player->player.gender,game.gender)!=0) {
						printf("�˶�Ա�Ա𲻷��ϣ�����������:");
						id = -1;
					}
					else if (p_player->player.game_number == 3) {
						printf("�˶�Ա�ѱ���3������������������:");
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
		}break;//����
		case 4:break;//����
		}
	}
	else if (sit == 1){//������ֹ����
		printf("����:\n");//����
		printf("1.ȫ�ɼ�¼��\n2.�鿴�ɼ�\n3.�޸ĳɼ�\n4.����\n");//ѡ��

		int x = entrycheckandreinput(1, 4);

		switch (x) {
		case 1: game_score_entry(game); information_game(pnewHead, situation); break;//�ɼ�¼��
		case 2: game_socre_print(game); information_game(pnewHead, situation); break;//����
		case 3:single_player_scorerevise(game); information_game(pnewHead, situation); break;//����
		case 4: break;//����
		}

	}
	else if (sit == 2) {
		printf("����:\n");//����
		printf("1.�ɼ���ѯ\n2.����\n");//ѡ��

		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: game_socre_print(game); information_game(pnewHead, situation); break;//�ɼ���ѯ
		case 2: break;//����
		}
	}
}

void information_player(PlayerListNode* pnewHead, int situation) {
	int sit = readsituation();
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
		if (sit > 0) {
			printf("��Ŀ�ɼ�:%0.2f ", player.score->score);//��Ŀ�ɼ�
			printf("��Ŀ�÷�:%d \n", player.score->point);//��Ŀ�ɼ�
		}
	}
	printf("\n\n\n");


	if (sit == 0) {//����,�޸Ľ����н���
		printf("����:\n");//����
		printf("1.�޸�\n2.ɾ��\n3.����\n4.����\n");//ѡ��
		
		int x = entrycheckandreinput(1, 4);

		switch (x) {
		case 1: revisePlayer(player); break;//�޸�
		case 2: {
			PlayerListNode* pHead = readPlayerlist();
			p = pHead;
			while (p->player.name.id != player.name.id) {//�ҵ���ѡ��Ľڵ�,���������������޸�������;
				p = p->next;
			}
			pHead = deleteNode(pHead, p);
			savePlayerlist(pHead);
			printf("\n\nɾ�����\n");
			system("pause");
		}break;//ɾ��
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
					else if (strcmp(p_game->game.gender,player.gender)!=0) {
						printf("�˶�Ա�Ա𲻷���,����������:");
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
		}break;//����
		case 4:break;

		}
	}
	else if (sit == 1) {//�ɼ�¼��׶�
		printf("����:\n");//����
		printf("1.�ɼ��޸�\n2.����\n");//ѡ��
		
		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: {
			system("CLS");
			printf("������Ŀ:%d\n", player.game_number);//������
			if (player.game_number == 0) printf("��\n");
			else {
				for (int j = 0; j < player.game_number; j++) {
					printf("��ĿID:%d ", player.score[j].name.id);//��Ŀid
					printf("��Ŀ����:%s ", player.score[j].name.name);//��Ŀ����
					printf("��Ŀ�ɼ�:%f ", player.score[j].score);//��Ŀ�ɼ�
					printf("��Ŀ�÷�:%d \n", player.score[j].point);//��Ŀ�ɼ�
				}
				printf("\n��������Ҫ�޸ĵı�����Ŀid:");
				int id, i = 0;
				double chengji;
				scanf_s("%d", &id);
				for (int j = 0; j < player.game_number; j++) {
					if (player.score[j].name.id == id) {
						printf("%s��Ŀȡ�õĳɼ�Ϊ%f\n�����޸ĳɼ�:", player.score[j].name.name, player.score[j].score);
						scanf_s("%f", &chengji);
						player.score[j].score = chengji;
						i = 1;
					}
				}
				if (i == 0)printf("�ڸ���Ŀ��û�гɼ���¼");
				game_score_rank(id);
			}
		}break;
		case 2:break;
		}


	}
	else if (sit == 2) {//�ɼ���ѯ�׶�
		printf("����:\n");//����
		printf("1.�ɼ���ѯ\n2.����\n");//ѡ��

		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1:break;
		case 2:break;
		}
	}
}

void information_group(GroupListNode* pnewHead, int situation) {
	int sit = readsituation();
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
	printf("\n\n\n");

	if (sit == 0) {
		printf("����:\n");//����
		printf("1.��λ��Ա\n2.�޸�����\n3.ɾ��\n4.����\n");//ѡ��
		
		int swi = entrycheckandreinput(1, 4);

		switch (swi)
		{
		case 1: {
			searchGroup_palyer(p,0);
			information_group(pnewHead, situation);

		} break;//��λ��Ա
		case 2:reviseGroup(group); break;//�޸�����
		case 3: {
			GroupListNode* pHead = readGrouplist();
			p = pHead;
			while (p->group.name.id != group.name.id) {
				p = p->next;
			}
			deleteNode(p);
			saveGrouplist(pHead);
			printf("\n\nɾ�����\n");
			system("pause");
		}break;//ɾ��
		case 4:break;//����
		}
	}
	else if (sit == 1) {
		printf("����:\n");//����
		printf("1.��λ��Ա\n2.����\n");//ѡ��
		
		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: {
			searchGroup_palyer(p, 0);
			information_group(pnewHead, situation);
		} break;//��λ��Ա
		case 2:break;
		}
	}
	else if (sit == 2) {
		printf("����:\n");//����
		printf("1.�����˶�Ա�÷�����\n2.����\n");//ѡ��

		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: {
			searchGroup_palyer(p, 1);
			information_group(pnewHead, situation);
		}break;
		case 2:break;
		}
	}
}