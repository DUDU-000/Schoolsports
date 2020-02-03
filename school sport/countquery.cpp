#include<stdio.h>
#include<iostream>
#include"countquery.h"
#include"method.h"

bool countquery() {

	char entry;
	system("CLS");
	printf("成绩录入管理\n");
	printf("1.运动员\n");
	printf("2.运动项目\n");
	printf("3.成绩排名\n");
	printf("4.返回\n");
	entry = getchar();
	rewind(stdin);

	int swi = entrycheck(entry, 1, 4);
	switch (swi) {
	case 0: if (countquery()) return true; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: return true; break;
	}
	return false;
}
