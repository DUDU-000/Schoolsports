#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

void basic_info() {
	char entry[99];
	system("CLS");
	printf("基本信息管理\n");
	printf("1.单位信息\n");
	printf("2.运动员信息\n");
	printf("3.项目信息\n");
	printf("4.返回\n");

	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 4);

	switch (swi) {
	case 0: basic_info(); break;
	case 1: group_info(); basic_info(); break;
	case 2: player_info(); basic_info(); break;
	case 3: game_info(); basic_info(); break;
	case 4: break;
	}
}
