#include<iostream>
#include<stdio.h>
#include"method.h"
#include"activity.h"

int main() 
{
	int situation = readsituation();//situation 有三个 0 1 2,分别代表报名阶段, 成绩录入阶段, 成绩查询阶段
	if (situation == -1) {
		savesituation(0);
		situation = 0;
	}
	int swi;
	system("CLS");
	switch (situation) {
	case 0: {
		printf("报名阶段\n\n");
		printf("信息管理\n");
		printf("1.单位信息\n");
		printf("2.运动员信息\n");
		printf("3.项目信息\n");
		printf("4.增加\n");
		printf("\n设置\n");
		printf("5.停止修改信息和报名\n");
		printf("6.退出\n");
		
	}break;
	case 1: {
		printf("成绩录入阶段\n\n");
		printf("信息管理\n");
		printf("1.单位信息\n");
		printf("2.运动员信息\n");
		printf("3.项目信息\n");
		printf("\n设置\n");
		printf("4.发布成绩\n");
		printf("5.退出\n");
	}break;
	case 2: {
		printf("成绩查询阶段\n\n");
		printf("信息管理\n");
		printf("1.单位信息\n");
		printf("2.运动员信息\n");
		printf("3.项目信息\n");
		printf("\n设置\n");
		printf("4.退出\n");
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


