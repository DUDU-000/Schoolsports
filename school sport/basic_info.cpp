#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

bool basic_info() {
	char entry;
	system("CLS");
	printf("基本信息管理\n");
	printf("1.单位信息\n");
	printf("2.运动员信息\n");
	printf("3.项目信息\n");
	printf("4.返回\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: if (basic_info()) return true; break;
	case 1: if (group_info()) if (basic_info()) return true; break;
	case 2: if (player_info()) if (basic_info()) return true; break;
	case 3: if (game_info()) if (basic_info()) return true; break;
	case 4: return true; break;
	}
	return false;
}
