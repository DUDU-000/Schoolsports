#include<iostream>
#include <stdio.h>
#include <string.h>
#include "basic_info.h"
#include"linked_list.h"
#include"method.h"

void revise_info(GameListNode* p,Game game) {
	system("CLS");
	GameListNode* pHead = readGamelist();
	p = pHead;
	while (p->game.name.id != game.name.id) {
		p = p->next;
	}
	printf("1.名称\n");
	printf("2.类型\n");
	printf("3.地点\n");
	printf("4.开始时间\n");
	printf("5.结束时间\n");
	printf("6.返回\n");
	
	int x = 0;
	char entry_s[99];
	while (x == 0) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 6);
		if (x == 0)printf("输入有误,请重新输入:");
	}
	switch (x)
	{
	case 1: {//修改名称
		system("CLS");
		printf("当前前选定项目的名称为：%s\n请输入修改内容：", p->game.name.name);
		gets_s(p->game.name.name, 99);
		printf("修改成功！修改名称为：%s\n",p->game.name.name);
		saveGamelist(pHead);
		system("pause");
	}break;
	case 2: {//修改类型
		system("CLS");
		printf("当前选定项目的类型为：%s\n请输入修改内容(1.田赛 2.竞赛)：", p->game.type);
		int i = 0;
		while (i == 0) {//判断输入
			int x;
			scanf_s("%d", &x);
			if (x == 1) {
				i = 1;
				strcpy(p->game.type, Tian);
			}
			else if (x == 2) {
				i = 1;
				strcpy(p->game.type, Jing);
			}
			else printf("输入错误请重新输入：");
		}
		saveGamelist(pHead);
		printf("修改成功！修改类型为：%s\n",p->game.type);
		system("pause");
	}break;
	case 3: {//修改地点
		system("CLS");
		printf("当前选定项目的地点为：%s\n请输入修改内容(1.跑道  2.足球场  3.标枪区  4.跳远区  5.铅球区  6.跳高区)：", p->game.place);
		int n = 0;
		char place_selection[99];
		while (n == 0) {
			gets_s(place_selection, 99);
			rewind(stdin);
			n = entrycheck(place_selection, 1, 6);
			if (n == 0)printf("输入有误,请重新输入:");
		}
		switch (n)
		{
		case 1:strcpy(p->game.place, Runway); break;
		case 2:strcpy(p->game.place, Football); break;
		case 3:strcpy(p->game.place, ShotPut); break;
		case 4:strcpy(p->game.place, LongJump); break;
		case 5:strcpy(p->game.place, Discus); break;
		case 6:strcpy(p->game.place, HighJump); break;
		}
		saveGamelist(pHead);
		printf("修改成功!修改地点为：%s\n",p->game.place);
		system("pause");
	}break;
	case 4: {//开始时间
		system("CLS");
		printf("目前选定项目的开始时间为：%d月%d日%d : %d\n请输入修改内容：\n", p->game.starttime.month, p->game.starttime.date, p->game.starttime.hour, p->game.starttime.minute);
		char month_s[99], date_s[99], hour_s[99], minute_s[99];
		int month=0, date=0, hour=0, minute=0;
		while (month == 0) {//月
			printf("月：");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == 0)printf("输入错误请重新输入：");
		}
		while (date == 0) {//日
			printf("日：");
			gets_s(date_s, 99);
			if((month<=7&&month%2!=0)||(month>=8&&month%2==0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month==2)date = entrycheck(date_s, 1, 29);
			if (date == 0)printf("输入错误请重新输入：");
		}
		while (hour == 0) {//时
			printf("几点：");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == 0)printf("输入错误请重新输入：");
		}
		while (minute == 0) {//分
			printf("几点：");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == 0)printf("输入错误请重新输入：");
		}
		p->game.starttime.month = month;
		p->game.starttime.date = date;
		p->game.starttime.hour = hour;
		p->game.starttime.minute = minute;
		saveGamelist(pHead);
		printf("修改成功\n目前选定项目的开始时间为：%d月%d日%d : %d\n", p->game.starttime.month, p->game.starttime.date, p->game.starttime.hour, p->game.starttime.minute);
		system("pause");
	}break;
	case 5: {//结束时间
		system("CLS");
		printf("目前选定项目的结束时间为：%d月%d日%d : %d\n请输入修改内容：\n", p->game.starttime.month, p->game.starttime.date, p->game.endtime.hour, p->game.endtime.minute);
		char month_s[99], date_s[99], hour_s[99], minute_s[99];
		int month = 0, date = 0, hour = 0, minute = 0;
		while (month == 0) {//月
			printf("月：");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == 0)printf("输入错误请重新输入：");
		}
		while (date == 0) {//日
			printf("日：");
			gets_s(date_s, 99);
			if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month == 2)date = entrycheck(date_s, 1, 29);
			if (date == 0)printf("输入错误请重新输入：");
		}
		while (hour == 0) {//时
			printf("几点：");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == 0)printf("输入错误请重新输入：");
		}
		while (minute == 0) {//分
			printf("几点：");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == 0)printf("输入错误请重新输入：");
		}
		p->game.starttime.month = month;
		p->game.starttime.date = date;
		p->game.endtime.hour = hour;
		p->game.endtime.minute = minute;
		saveGamelist(pHead);
		printf("修改成功\n目前选定项目的开始时间为：%d月%d日%d : %d\n", p->game.starttime.month, p->game.starttime.date, p->game.endtime.hour, p->game.endtime.minute);
		system("pause");
	}break;
	case 6: query_game_menu(); break;
	}

}