#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

bool query_player_menu() {
	char entry;
	system("CLS");
	printf("项目查询\n");
	printf("1.名称查询\n");
	printf("2.类型查询\n");
	printf("3.日期查询\n");
	printf("4.所有项目\n");
	printf("5.返回\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: if (query_player_menu()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: return true; break;
	}
	return false;
}

bool player_info() {
	char entry;
	system("CLS");
	printf("运动员信息\n");
	printf("1.增加\n");
	printf("2.查询\n");
	printf("3.返回\n");
	entry = getchar();
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: if (player_info()) return true; break;
	case 1: break;
	case 2: if (query_player_menu()) if (player_info()) return true; break;
	case 3: return true; break;
	}
	return false;
}

