#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

void query_group_menu() {
	char entry[99];
	system("CLS");
	printf("组查询\n");
	printf("1.名称查询\n");
	printf("2.类型查询\n");
	printf("3.日期查询\n");
	printf("4.所有项目\n");
	printf("5.返回\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: query_group_menu(); break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5: break;
	}
}

void group_info() {
	char entry[99];
	system("CLS");
	printf("组信息\n");
	printf("1.增加\n");
	printf("2.查询\n");
	printf("3.返回\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: group_info(); break;
	case 1: break;
	case 2: query_group_menu(); group_info(); break;
	case 3: break;
	}
}
