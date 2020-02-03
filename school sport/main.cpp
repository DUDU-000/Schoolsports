#include<iostream>
#include<stdio.h>

void esinforma() {
	int a;
	system("CLS");
	printf("1.单位信息\n");
	printf("2.运动员信息\n");
	printf("3.项目信息\n");

	scanf_s("%d", &a);

	switch (a) {
	case 1: break;
	case 2: break;
	case 3: break;
	}
}

void main() {
	int a;
	system("CLS");
	printf("1.基本信息管理\n");
	printf("2.成绩录入管理\n");
	printf("3.冬季查询管理\n");

	scanf_s("%d", &a);

	switch (a) {
	case 1: esinforma(); break;
	case 2: break;
	case 3: break;
	}
}


