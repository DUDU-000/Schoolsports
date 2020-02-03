#include<stdio.h>
#include<iostream>
#include"scorentry.h"
#include"method.h"

void scorentry() {

	char entry;
	system("CLS");
	printf("成绩录入管理\n");
	printf("1.运动员\n");
	printf("2.运动项目\n");
	printf("3.成绩排名\n");
	printf("4.分数\n");

	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 3);

	switch (swi) {
	case 0: scorentry(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	}
	
}
