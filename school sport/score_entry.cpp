#include<stdio.h>
#include<iostream>
#include"score_entry.h"
#include"method.h"

void score_entry() {

	char entry[99];
	system("CLS");
	printf("成绩录入管理\n");
	printf("1.运动员\n");
	printf("2.运动项目\n");
	printf("3.成绩排名\n");
	printf("4.分数\n");
	printf("5.返回\n");

	gets_s(entry, 99);
	rewind(stdin);
	int swi = entrycheck(entry, 1, 5);
	switch (swi) {
	case -1: score_entry(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: break;
	case 5: break;
	}
}
