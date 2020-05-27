#include<iostream>
#include <stdio.h>
#include <string.h>
#include"activity.h"
#include"linked_list.h"
#include"method.h"
#include"menu.h"

void reviseGame(Game game) {
	system("CLS");
	GameListNode* pHead = readGamelist();
	GameListNode* p = pHead;

	while (p->game.name.id != game.name.id) {
		p = p->next;
	}

	printf("项目信息:\n");//打印项目基本信息
	printf("名称:%s\n", game.name.name/*名称*/);
	printf("类型:%s\n", game.type/*类型*/);
	printf("地点:%s\n", game.place/*地点*/);
	printf("人数:%d\n", game.number/*报名人数*/);
	printf("时间:%d月%d日%d : %d-%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*开始时间*/, game.endtime.hour, game.endtime.minute/*结束时间*/);
	printf("报名人员:\n");
	if (game.playerid[0].id == NULL || game.playerid[0].id <= 0) printf("无");
	else
		for (int j = 0; j < game.number; j++) {
			printf("ID:%d ", game.playerid[j].id);//报名人员id
			printf("名称:%s    ", game.playerid[j].name);//报名人员id
			if ((j + 1) % 5 == 0) printf("\n");
		}
	printf("\n\n\n");

	printf("修改内容:\n");
	printf("1.名称\n");
	printf("2.类型\n");
	printf("3.地点\n");
	printf("4.开始时间\n");
	printf("5.结束时间\n");
	printf("6.返回\n");
	
	int x = -1;
	char entry_s[99];
	while (x == -1) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 6);
		if (x == -1)printf("输入有误,请重新输入:");
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
		int n = -1;
		char place_selection[99];
		while (n == -1) {
			gets_s(place_selection, 99);
			rewind(stdin);
			n = entrycheck(place_selection, 1, 6);
			if (n == -1)printf("输入有误,请重新输入:");
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
		int month= -1, date= -1, hour= -1, minute= -1;
		while (month == -1) {//月
			printf("月：");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == -1)printf("输入错误请重新输入：");
		}
		while (date == -1) {//日
			printf("日：");
			gets_s(date_s, 99);
			if((month<=7&&month%2!=0)||(month>=8&&month%2==0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month==2)date = entrycheck(date_s, 1, 29);
			if (date == -1)printf("输入错误请重新输入：");
		}
		while (hour == -1) {//时
			printf("几点：");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == -1)printf("输入错误请重新输入：");
		}
		while (minute == -1) {//分
			printf("几点：");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == -1)printf("输入错误请重新输入：");
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
		int month = -1, date = -1, hour = -1, minute = -1;
		while (month == -1) {//月
			printf("月：");
			gets_s(month_s, 99);
			month = entrycheck(month_s, 1, 12);
			if (month == -1)printf("输入错误请重新输入：");
		}
		while (date == -1) {//日
			printf("日：");
			gets_s(date_s, 99);
			if ((month <= 7 && month % 2 != 0) || (month >= 8 && month % 2 == 0))date = entrycheck(date_s, 1, 31);
			else if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))date = entrycheck(date_s, 1, 30);
			if (month == 2)date = entrycheck(date_s, 1, 29);
			if (date == -1)printf("输入错误请重新输入：");
		}
		while (hour == -1) {//时
			printf("几点：");
			gets_s(hour_s, 99);
			hour = entrycheck(hour_s, 1, 24);
			if (hour == -1)printf("输入错误请重新输入：");
		}
		while (minute == -1) {//分
			printf("几点：");
			gets_s(minute_s, 99);
			minute = entrycheck(minute_s, 1, 24);
			if (minute == -1)printf("输入错误请重新输入：");
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

void revisePlayer(Player player) {
	system("CLS");
	PlayerListNode* pHead = readPlayerlist();
	PlayerListNode* p = pHead;

	while (p->player.name.id != player.name.id) {
		p = p->next;
	}

	printf("运动员信息:\n");//打印项目基本信息
	printf("ID:%d\n", player.name.id);//id
	printf("名称:%s\n", player.name.name);//名称
	printf("性别:%s\n", player.gender);//性别
	printf("年龄:%d\n", player.year);//id
	printf("小组ID:%d\n", player.group_id);//小组ID
	printf("总分数:%d\n", player.fullscore);//总分数
	printf("比赛数:%d\n", player.game_number);//比赛数

	printf("比赛项目:%d\n", player.game_number);//比赛数
	if (player.game_number == 0) printf("无\n");
	else
		for (int j = 0; j < player.game_number; j++) {
			printf("项目名称:%s ", player.score[j].name.name);//项目名称
			printf("项目成绩:%f ", player.score[j].score);//项目成绩
			printf("项目得分:%d \n", player.score[j].point);//项目成绩
		}
	printf("\n\n\n");

	printf("修改内容:\n");
	printf("1.名称\n");
	printf("2.性别\n");
	printf("3.年龄\n");
	printf("4.小组\n");
	printf("5.返回\n");

	int x = -1;
	char entry_s[99];
	while (x == -1) {
		gets_s(entry_s, 99);
		rewind(stdin);
		x = entrycheck(entry_s, 1, 5);
		if (x == -1)printf("输入有误,请重新输入:");
	}
	switch (x)
	{
	case 1: {//修改名称
		system("CLS");
		printf("当前前选定运动员的名称为：%s\n", p->player.name.name);
		printf("姓名:");
		gets_s(p->player.name.name, 99);
		printf("修改成功！修改名称为：%s\n", p->player.name.name);
		system("pause");
	}break;
	case 2: {
		system("CLS");
		printf("当前前选定运动员的性别为：%s\n", p->player.gender);

		printf("性别(1.男  2.女)：");//性别
		int entry_int = -1;//开始输入检测是否是数字,我改了一下entrycheck,参数是一个char数组
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 2);//若是一个数字,则返回int,否则,返回0
			switch (entry_int)
			{
			case -1:printf("输入有误,请重新输入:"); break;
			case 1:strcpy(p->player.gender, "男"); break;
			case 2:strcpy(p->player.gender, "女"); break;
			}
		}//结束检测
		
		printf("修改成功！修改性别为：%s\n", p->player.gender);
		system("pause");
	}break;
	case 3: {
		system("CLS");
		printf("当前前选定运动员的年龄为：%d\n", p->player.year);

		printf("年龄:");
		int entry_int = -1;//开始输入检测是否是数字,我改了一下entrycheck,参数是一个char数组
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 99);//若是一个数字,则返回int,否则,返回0
			if (entry_int == -1) printf("输入有误,请重新输入:");
			else p->player.year = entry_int;

		}//结束检测

		printf("修改成功！修改年龄为：%d\n", p->player.year);
		system("pause");
	}break;
	case 4: {
		system("CLS");
		printf("当前前选定运动员的小组ID为：%d\n", p->player.group_id);

		printf("小组ID:");
		int entry_int = -1;//开始输入检测是否是数字,我改了一下entrycheck,参数是一个char数组
		while (entry_int == -1)
		{
			gets_s(entry_s, 99);
			rewind(stdin);
			entry_int = entrycheck(entry_s, 1, 99);//若是一个数字,则返回int,否则,返回0
			if (entry_int == -1) printf("输入有误,请重新输入:");
			else p->player.year = entry_int;

		}//结束检测

		printf("修改成功！修改年龄为：%d\n", p->player.group_id);
		system("pause");
	}break;
	case 5: query_player_menu(); break;
	}
	savePlayerlist(pHead);

}

void reviseGroup(Group group) {
	GroupListNode* pHead = readGrouplist();
	GroupListNode* p = pHead;
	while (p->group.name.id!=group.name.id)
	{
		p = p->next;
	}
	printf("修改名称为:");
	gets_s(p->group.name.name, 99);
	rewind(stdin);
	printf("修改成功！修改名称为：%s\n",p->group.name.name);
	system("pause");
	saveGrouplist(pHead);


}