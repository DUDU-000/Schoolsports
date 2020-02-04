#include<iostream>
#include<stdio.h>
#include"method.h"
#include"basic_info.h"
#include"linked_list.h"

void add_info(int type) {//type有三种类型,分别是三个在basic_info.h里的常数,对应三种情况
	switch (type) {
	case type_game: //增加一个比赛项目

		//待写 从文件中读取已储存的链表,若是没有数据,则创建头节点,若已有,接入一个节点

		


		break;

	case type_group: //增加一个组
		system("CLS");

		break;

	case type_player: //增加一个运动员
		system("CLS");

		break;

	}
}