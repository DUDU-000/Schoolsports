#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"

void query_group_menu() {
	char entry[99];
	system("CLS");
	printf("���ѯ\n");
	printf("1.���Ʋ�ѯ\n");
	printf("2.���е�λ\n");
	printf("3.����\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case 0: query_group_menu(); break;
	case 1:searchGroup_name();break;
	case 2:searchGroup_all;break;
	case 3:break;
	}
}

void group_info() {
	char entry[99];
	system("CLS");
	printf("����Ϣ\n");
	printf("1.����\n");
	printf("2.��ѯ\n");
	printf("3.����\n");
	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: group_info(); break;
	case 1: addGroupNode(); group_info(); break;
	case 2: query_group_menu(); group_info(); break;
	case 3: break;
	}
}
