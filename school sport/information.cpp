#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"


void information_game(GameListNode* pnewHead,int situation) {//输入头节点和对应的位置(第几个)

	int sit = readsituation();
	int i = 1;
	GameListNode* p_game=pnewHead;
	Game game;
	while (i != situation) {//找到所选择的节点
		p_game = p_game->next;
		i++;
	}

	system("CLS");
	game = p_game->game;
	printf( "项目信息:\n");//打印项目基本信息
	printf("名称:%s\n", game.name.name/*名称*/);
	printf("类型:%s\n", game.type/*类型*/);
	printf("地点:%s\n", game.place/*地点*/);
	printf("性别:%s\n", game.gender/*性别*/);
	printf("人数:%d\n", game.number/*报名人数*/);
	printf("时间:第%d日%d : %d-%d : %d\n",game.starttime.day, game.starttime.hour, game.starttime.minute/*开始时间*/, game.endtime.hour, game.endtime.minute/*结束时间*/);
	printf("报名人员:\n");
	if (game.playerid[0].id == NULL|| game.playerid[0].id<=0) printf("无");
	else 
		for (int j = 0; j < game.number; j++) {
			printf("ID:%d ", game.playerid[j].id);//报名人员id
			printf("名称:%s    ", game.playerid[j].name);//报名人员id
			if ((j+1) % 5 == 0) printf("\n");
		}
	printf("\n\n\n");


	if (sit == 0)//报名,修改进行中界面
	{
		printf("操作:\n");//操作
		printf("1.修改\n2.删除\n3.报名\n4.返回\n");//选项

		int x=entrycheckandreinput(1, 4);

		switch (x) {
		case 1: reviseGame(game); break;//修改
		case 2: {
			GameListNode* pHead = readGamelist();
			p_game = pHead;
			while (p_game->game.name.id != game.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
				p_game = p_game->next;
			}
			pHead = deleteNode(pHead, p_game);
			saveGamelist(pHead);
			printf("\n\n删除完成\n");
			system("pause");
			
		}break;//删除 
		case 3: {
			PlayerListNode* pHead_player = readPlayerlist();
			PlayerListNode* p_player = pHead_player;
			printf("\n输入运动员ID进行报名\n输入0退出报名\n");
			while (true) {
				int id = -1;
				while (true) {//输入并查找项目
					id = entrycheckandreinput(0, 99);
					if (id == 0) break;
					p_player = pHead_player;

					while (p_player->player.name.id != id) {
						if (p_player->next == NULL) break;
						p_player = p_player->next;
					}
					if (p_player->player.name.id != id && p_player->next == NULL) {
						printf("找不到该运动员,请重新输入:");
						id = -1;
					}
					else if (strcmp(p_player->player.gender,game.gender)!=0) {
						printf("运动员性别不符合，请重新输入:");
						id = -1;
					}
					else if (p_player->player.game_number == 3) {
						printf("运动员已报名3个比赛，请重新输入:");
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
			while (p_game->game.name.id != game.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
				p_game = p_game->next;
			}
			p_game->game = game;
			saveGamelist(pHead_game);
			printf("\n\n报名完成\n");
			system("pause");
		}break;//报名
		case 4:break;//返回
		}
	}
	else if (sit == 1){//报名截止界面
		printf("操作:\n");//操作
		printf("1.全成绩录入\n2.查看成绩\n3.修改成绩\n4.返回\n");//选项

		int x = entrycheckandreinput(1, 4);

		switch (x) {
		case 1: game_score_entry(game); information_game(pnewHead, situation); break;//成绩录入
		case 2: game_socre_print(game); information_game(pnewHead, situation); break;//返回
		case 3:single_player_scorerevise(game); information_game(pnewHead, situation); break;//返回
		case 4: break;//返回
		}

	}
	else if (sit == 2) {
		printf("操作:\n");//操作
		printf("1.成绩查询\n2.返回\n");//选项

		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: game_socre_print(game); information_game(pnewHead, situation); break;//成绩查询
		case 2: break;//返回
		}
	}
}

void information_player(PlayerListNode* pnewHead, int situation) {
	int sit = readsituation();
	int i = 1;
	PlayerListNode* p = pnewHead;
	Player player;
	
	while (i != situation) {//找到所选择的节点
		p = p->next;
		i++;
	}

	system("CLS");
	player = p->player;
	printf("运动员信息:\n");//打印项目基本信息
	printf("ID:%d\n", player.name.id);//id
	printf("名称:%s\n", player.name.name);//名称
	printf("性别:%s\n", player.gender);//性别
	printf("年龄:%d\n", player.year);//id
	printf("小组ID:%d\n", player.group_id);//小组ID
	printf("总分数:%d\n", player.fullscore);//总分数
	printf("比赛数:%d\n", player.game_number);//比赛数

	printf("比赛项目:%d\n", player.game_number);//比赛数
	if (player.game_number == 0) printf("无\n");
	else 
	for (int j = 0; j < player.game_number; j++) {
		printf("项目名称:%s ", player.score->name.name);//项目名称
		if (sit > 0) {
			printf("项目成绩:%0.2f ", player.score->score);//项目成绩
			printf("项目得分:%d \n", player.score->point);//项目成绩
		}
	}
	printf("\n\n\n");


	if (sit == 0) {//报名,修改进行中界面
		printf("操作:\n");//操作
		printf("1.修改\n2.删除\n3.报名\n4.返回\n");//选项
		
		int x = entrycheckandreinput(1, 4);

		switch (x) {
		case 1: revisePlayer(player); break;//修改
		case 2: {
			PlayerListNode* pHead = readPlayerlist();
			p = pHead;
			while (p->player.name.id != player.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
				p = p->next;
			}
			pHead = deleteNode(pHead, p);
			savePlayerlist(pHead);
			printf("\n\n删除完成\n");
			system("pause");
		}break;//删除
		case 3: {
			if (player.game_number < 3) {
				printf("\n\n请输入比赛ID:");
				int x = -1;
				char entry_s[99];
				GameListNode* pHead_game = readGamelist();
				GameListNode* p_game;
				while (true) {//输入并查找项目
					while (x == -1)//输入检测
					{
						gets_s(entry_s, 99);
						rewind(stdin);
						x = entrycheck(entry_s, 1, 99);
						if (x == -1)printf("输入有误,请重新输入:");
					}
					p_game = pHead_game;
					while (p_game->game.name.id != x) {
						if (p_game->next == NULL) break;
						p_game = p_game->next;
					}
					if (p_game->game.name.id != x&&p_game->next == NULL) {
						printf("找不到该比赛,请重新输入:");
						x = -1;
					}
					else if (strcmp(p_game->game.gender,player.gender)!=0) {
						printf("运动员性别不符合,请重新输入:");
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
				while (p->player.name.id != player.name.id) {//找到所选择的节点,这个代码你可以在修改那里用;
					p = p->next;
				}
				p->player = player;
				savePlayerlist(pHead_player);
				printf("报名成功\n");
			}
			else {
				printf("运动员已报名三个项目,不可再报名\n");
			}
			system("pause");
		}break;//报名
		case 4:break;

		}
	}
	else if (sit == 1) {//成绩录入阶段
		printf("操作:\n");//操作
		printf("1.成绩修改\n2.返回\n");//选项
		
		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: {
			system("CLS");
			printf("比赛项目:%d\n", player.game_number);//比赛数
			if (player.game_number == 0) printf("无\n");
			else {
				for (int j = 0; j < player.game_number; j++) {
					printf("项目ID:%d ", player.score[j].name.id);//项目id
					printf("项目名称:%s ", player.score[j].name.name);//项目名称
					printf("项目成绩:%f ", player.score[j].score);//项目成绩
					printf("项目得分:%d \n", player.score[j].point);//项目成绩
				}
				printf("\n请输入需要修改的比赛项目id:");
				int id, i = 0;
				double chengji;
				scanf_s("%d", &id);
				for (int j = 0; j < player.game_number; j++) {
					if (player.score[j].name.id == id) {
						printf("%s项目取得的成绩为%f\n输入修改成绩:", player.score[j].name.name, player.score[j].score);
						scanf_s("%f", &chengji);
						player.score[j].score = chengji;
						i = 1;
					}
				}
				if (i == 0)printf("在该项目中没有成绩记录");
				game_score_rank(id);
			}
		}break;
		case 2:break;
		}


	}
	else if (sit == 2) {//成绩查询阶段
		printf("操作:\n");//操作
		printf("1.成绩查询\n2.返回\n");//选项

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
	printf("单位名称:%s\n", group.name.name);
	printf("单位人数:%d\n", group.member_number);
	printf("单位总得分:%d\n", group.fullscore);
	printf("\n\n\n");

	if (sit == 0) {
		printf("操作:\n");//操作
		printf("1.单位成员\n2.修改名称\n3.删除\n4.返回\n");//选项
		
		int swi = entrycheckandreinput(1, 4);

		switch (swi)
		{
		case 1: {
			searchGroup_palyer(p,0);
			information_group(pnewHead, situation);

		} break;//单位成员
		case 2:reviseGroup(group); break;//修改名称
		case 3: {
			GroupListNode* pHead = readGrouplist();
			p = pHead;
			while (p->group.name.id != group.name.id) {
				p = p->next;
			}
			deleteNode(p);
			saveGrouplist(pHead);
			printf("\n\n删除完成\n");
			system("pause");
		}break;//删除
		case 4:break;//返回
		}
	}
	else if (sit == 1) {
		printf("操作:\n");//操作
		printf("1.单位成员\n2.返回\n");//选项
		
		int x = entrycheckandreinput(1, 2);

		switch (x) {
		case 1: {
			searchGroup_palyer(p, 0);
			information_group(pnewHead, situation);
		} break;//单位成员
		case 2:break;
		}
	}
	else if (sit == 2) {
		printf("操作:\n");//操作
		printf("1.组内运动员得分排名\n2.返回\n");//选项

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