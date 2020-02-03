#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basicinfo.h"

void basicinfo() {
	char entry;
	system("CLS");
	printf("基本信息管理\n");
	printf("1.单位信息\n");
	printf("2.运动员信息\n");
	printf("3.项目信息\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);
	switch (swi) {
	case 0: basicinfo(); break;
	case 1: groupinfo(); break;
	case 2: playinfo(); break;
	case 3: projetinfo(); break;
	}
}