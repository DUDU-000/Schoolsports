#include<iostream>
#include<stdio.h>
#include "linked_list.h"
#include"method.h"
//比赛项目的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
GameListNode* createpHead(Game game) {
	GameListNode* pHeadNode = new GameListNode;//创建一个新的指针节点并分配空间
	if (pHeadNode == NULL) {
		printf("创建链表失败");
		exit(0);
	}
	pHeadNode->game = game;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(GameListNode* pHead, Game game) {
	GameListNode* p = pHead;
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
		p->next = pNewNode;//将最后的节点指针指向新的节点
	}
//p节点后插入值为player的节点
void insertNode(GameListNode *p, Game game) {
	GameListNode* pNewNode = new GameListNode;//创建一个新的指针节点并分配空间
	pNewNode->game = game;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p,pHead是头节点,返回头节点,如果全删除了返回NULL;
GameListNode* deleteNode(GameListNode *pHead, GameListNode *p) {
	if (p->next != NULL) {
		p->game = p->next->game;//将下一个节点的内容放入p中
		GameListNode *p_next = p->next;//记录指针
		p->next = p->next->next;//将下一个节点的next放入p中,
								//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
		free(p_next);//释放无用内存
		p_next = NULL;
		return pHead;
	}
	else if (longNode(pHead) == 1) {//如果只有一个节点
		free(p);
		return NULL;
	}
	else {//p是最后一个节点
		GameListNode *newp = pHead;
		while (newp->next->next != NULL) {
			newp = newp->next;
		}
		newp->next = NULL;
		free(p);
		return pHead;
	}
}
//传入头节点,返回有多少个节点
int longNode(GameListNode *pHead) {
	int i=0;
	GameListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//从文件中读取链表
GameListNode* readGamelist() {
	FILE *fp;//文件指针
	GameListNode* pHead=NULL;
	int line_long;
	Game game;
	/*文件的打开*/
	fp = fopen("game.txt", "rt+");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
	
	std::string file_path = "game.txt";
	if (fp == NULL || file_is_empty(file_path)) {//判断如果文件指针为空
		return NULL;
	}

	fscanf_s(fp, "项目数量:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "ID:%d\n", &game.name.id);//id
		fscanf_s(fp, "名称:%s\n", &game.name.name,99);//名称
		fscanf_s(fp, "类型:%s\n", &game.type,5);//类型
		fscanf_s(fp, "地点:%s\n", &game.place,7);//地点
		fscanf_s(fp, "人数:%d\n", &game.number);//人数
		fscanf_s(fp, "开始时间:%d月%d日%d : %d\n", &game.starttime.month, &game.starttime.date, &game.starttime.hour, &game.starttime.minute);//开始时间
		fscanf_s(fp, "结束时间:%d : %d\n", &game.endtime.hour, &game.endtime.minute);//结束时时间
		for (int j = 0; j < game.number; j++) {
			fscanf_s(fp, "报名人员ID:%d\n", &game.playerid[j].id);//报名人员id
			fscanf_s(fp, "报名人员名称:%s\n", &game.playerid[j].name,99);//报名人名称
		}
		fscanf_s(fp, "报名状态(0:进行中|1:截止):%d\n", & game.status);//报名状态
		if (i == 0) pHead = createpHead(game);
		else addNode(pHead, game);
	}
	fclose(fp);
	return pHead;

}
//把链表存入文件中
void saveGamelist(GameListNode* pHead) {
	FILE *fp;//文件指针
	fp = fopen("game.txt", "w");
	int line_long = longNode(pHead);//该链表有多少个节点
	GameListNode* p = pHead;
	Game game;

	fprintf(fp, "项目数量:%d\n", line_long);//储存有多少个节点
	for (int i = 0; i < line_long; i++,p=p->next) {
		game = p->game;
		fprintf(fp, "ID:%d\n", game.name.id/*id*/);
		fprintf(fp, "名称:%s\n", game.name.name/*名称*/);
		fprintf(fp, "类型:%s\n", game.type/*类型*/);
		fprintf(fp, "地点:%s\n", game.place/*地点*/);
		fprintf(fp, "人数:%d\n", game.number/*报名人数*/);
		fprintf(fp, "开始时间:%d月%d日%d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute/*开始时间*/);
		fprintf(fp, "结束时间:%d : %d\n",  game.endtime.hour, game.endtime.minute/*结束时间*/);
		for (int j = 0; j < game.number; j++){//储存报名人员id
			fprintf(fp, "报名人员ID:%d\n", game.playerid[j].id);
			fprintf(fp, "报名人员名称:%s\n", game.playerid[j].name);//报名人名称
		}
		fprintf(fp, "报名状态(0:进行中|1:截止):%d\n", game.status);//报名状态
	}
	fclose(fp);
}
//打印链表
void printGamelist(GameListNode* pHead)
{
	int line_long = longNode(pHead);
	GameListNode* p = pHead;
	Game game;
	for (int i = 0; i < line_long; i++, p = p->next)
	{
		game = p->game;
		printf("%d.", i + 1/*序号*/);
		printf("名称:%s", game.name.name/*名称*/);
		printf(" ID:%d",game.name.id /*ID*/);
		printf(" 时间:%d月%d日%d : %d - %d : %d\n", game.starttime.month, game.starttime.date, game.starttime.hour, game.starttime.minute, game.endtime.hour, game.endtime.minute/*时间*/);
	}
}


//运动员的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
PlayerListNode* createpHead(Player player) {
	PlayerListNode* pHeadNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pHeadNode->player = player;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(PlayerListNode* pHead, Player player) {
	PlayerListNode* p = pHead;
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	PlayerListNode* pNewNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pNewNode->player = player;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为player的节点
void insertNode(PlayerListNode *p, Player player) {
	PlayerListNode* pNewNode = new PlayerListNode;//创建一个新的指针节点并分配空间
	pNewNode->player = player;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
PlayerListNode* deleteNode(PlayerListNode *pHead, PlayerListNode *p) {
	if (p->next != NULL) {
		p->player = p->next->player;//将下一个节点的内容放入p中
		PlayerListNode *p_next = p->next;//记录指针
		p->next = p->next->next;//将下一个节点的next放入p中,
								//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
		free(p_next);//释放无用内存
		p_next = NULL;
		return pHead;
	}
	else if (longNode(pHead) == 1) {//如果只有一个节点
		free(p);
		return NULL;
	}
	else {//p是最后一个节点
		PlayerListNode *newp = pHead;
		while (newp->next->next != NULL) {
			newp = newp->next;
		}
		newp->next = NULL;
		free(p);
		return pHead;
	}
}
//传入头节点,返回有多少个节点
int longNode(PlayerListNode *pHead) {
	int i = 0;
	PlayerListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

PlayerListNode* readPlayerlist() {
	FILE *fp;//文件指针
	PlayerListNode* pHead = NULL;
	int line_long;
	Player player;

	/*文件的打开*/
	fp = fopen("player.txt", "rt+");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开

	std::string file_path = "player.txt";
	if (fp == NULL || file_is_empty(file_path)) {//判断如果文件指针为空
		return NULL;
	}

	fscanf_s(fp, "运动员数量:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "ID:%d\n", &player.name.id);//id
		fscanf_s(fp, "名称:%s\n", &player.name.name, 99);//名称
		fscanf_s(fp, "性别:%s\n", &player.gender, 3);//性别
		fscanf_s(fp, "年龄:%d\n", &player.year);//年龄
		fscanf_s(fp, "小组ID:%d\n", &player.group_id);//小组ID
		fscanf_s(fp, "总分数:%d\n", &player.fullscore);//总分数
		fscanf_s(fp, "比赛数:%d\n", &player.game_number);//比赛数
		for (int j = 0; j < player.game_number; j++) {
			fscanf_s(fp, "项目ID:%d\n", &player.score[j].name.id);//项目id
			fscanf_s(fp, "项目名称:%s\n", &player.score[j].name.name, 99);//项目名称
			fscanf_s(fp, "项目成绩:%1f\n", &player.score[j].score);//项目成绩
			fscanf_s(fp, "项目得分:%d\n", &player.score[j].point);//项目成绩
		}
		if (i == 0) pHead = createpHead(player);
		else addNode(pHead, player);
	}
	fclose(fp);
	return pHead;
}
//把链表存入文件中
void savePlayerlist(PlayerListNode* pHead) {
	FILE *fp;//文件指针
	fp = fopen("player.txt", "w");
	int line_long = longNode(pHead);//该链表有多少个节点
	PlayerListNode* p = pHead;
	Player player;

	fprintf(fp, "运动员数量:%d\n", line_long);
	for (int i = 0; i < line_long; i++, p = p->next) {
		player = p->player;
		fprintf(fp, "ID:%d\n", player.name.id);//id
		fprintf(fp, "名称:%s\n", player.name.name);//名称
		fprintf(fp, "性别:%s\n", player.gender);//性别
		fprintf(fp, "年龄:%d\n", player.year);//年龄
		fprintf(fp, "小组ID:%d\n", player.group_id);//小组ID
		fprintf(fp, "总分数:%d\n", player.fullscore);//总分数
		fprintf(fp, "比赛数:%d\n", player.game_number);//比赛数
		for (int j = 0; j < player.game_number; j++) {
			fprintf(fp, "项目ID:%d\n", player.score[j].name.id);//项目id
			fprintf(fp, "项目名称:%s\n", player.score[j].name.name);//项目名称
			fprintf(fp, "项目成绩:%lf\n", player.score[j].score);//项目成绩
			fprintf(fp, "项目得分:%d\n", player.score[j].point);//项目成绩
		}
	}
	fclose(fp);
}
//打印链表
void printPlayerlist(PlayerListNode* pHead)
{
	int line_long = longNode(pHead);
	PlayerListNode* p = pHead;
	Player player;
	for (int i = 0; i < line_long; i++, p = p->next){
		player = p->player;
		printf("%d.", i + 1/*序号*/);
		printf(" ID:%d ", player.name.id);
		printf("名称:%s ", player.name.name/*名称*/);
		printf(" 性别:%s ", player.gender);
		printf(" 参加项目:");
		if (player.game_number == 0) printf("无");
		else for (int j = 0; j < player.game_number; j++) printf("%s ", &player.score[j].name.name);//项目名称
		printf("\n");
	}
	
}

//组的链表函数

//创建一个链表的头节点,函数返回值为该节点指针
GroupListNode* createpHead(Group group) {
	GroupListNode* pHeadNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pHeadNode->group = group;//将gmae赋值进改节点中
	pHeadNode->next = NULL;//该节点的next指向NULL
	return pHeadNode;
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(GroupListNode* pHead, Group group) {
	GroupListNode* p = pHead;
	GroupListNode* pNewNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pNewNode->group = group;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//p节点后插入值为player的节点
void insertNode(GroupListNode *p, Group group) {
	GroupListNode* pNewNode = new GroupListNode;//创建一个新的指针节点并分配空间
	pNewNode->group = group;//将gmae赋值进改节点中
	pNewNode->next = p->next;//该新节点的next指向p的下一个节点
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p
void deleteNode(GroupListNode *p) {
	p->group = p->next->group;//将下一个节点的内容放入p中
	GroupListNode *p_next = p->next;//记录指针
	p->next = p->next->next;//将下一个节点的next放入p中,
							//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
	free(p_next);//释放无用内存
	p_next = NULL;
}
//传入头节点，返回有多少个节点
int longNode(GroupListNode* pHead) {
	GroupListNode* p = pHead; 
	int x=0;
	if (p == NULL) return 0;
	else x++;
	while (p->next != NULL) {
		p = p->next;
		x++;
	}
	return x;
}
//传入文件数据至链表
GroupListNode* readGrouplist() {
	FILE *fp;//文件指针
	GroupListNode* pHead = NULL;
	int line_long;
	Group group;
	 /*文件打开*/
	fp = fopen("group.txt", "rt+");

	std::string file_path = "group.txt";
	if (fp == NULL || file_is_empty(file_path)) {//判断如果文件指针为空
		return NULL;
	}

	fscanf_s(fp, "单位数量:%d\n", &line_long);
	for (int i = 0; i < line_long; i++) {
		fscanf_s(fp, "单位ID:%d\n",& group.name.id);/*id*/
		fscanf_s(fp, "单位名称:%s\n",& group.name.name,99);/*名称*/
		fscanf_s(fp, "单位比赛报名数:%d\n", &group.game_number);/*比赛报名数*/
		fscanf_s(fp, "单位总得分:%d\n", &group.fullscore);/*总得分*/
		fscanf_s(fp, "单位人数:%d\n", &group.member_number);/*人数*/
		for (int n = 0; n < group.member_number; n++) {
			fscanf_s(fp, "运动员ID:%d\n", &group.memberid[n]);
		}
		for (int n = 0; n < group.game_number; n++) {
			fscanf_s(fp, "比赛ID:%d\n", &group.score->name.id);
			fscanf_s(fp, "比赛名称:%s\n", &group.score->name.name,99);
			fscanf_s(fp, "该比赛所得积分:%d\n", &group.score->point);
			fscanf_s(fp, "该比赛最佳成绩:%f\n", &group.score->score);
		}
		if (i == 0) pHead = createpHead(group);
		else addNode(pHead, group);
	}
	fclose(fp);
	return pHead;
}
//保存链表
void saveGrouplist(GroupListNode* pHead) {
	FILE* fp;//文件指针
	fp = fopen("group.txt", "w");

	int line_long=longNode(pHead);
	GroupListNode* p = pHead;
	Group group;

	fprintf(fp, "单位数量:%d\n", line_long);
	for (int i = 0; i < line_long; i++,p=p->next) {
		group = p->group;
		fprintf(fp, "单位ID:%d\n", group.name.id);/*id*/
		fprintf(fp, "单位名称:%s\n", group.name.name);/*名称*/
		fprintf(fp, "单位比赛报名数:%d\n", group.game_number);/*报名数*/
		fprintf(fp, "单位总得分:%d\n", group.fullscore);/*总得分*/
		fprintf(fp, "单位人数:%d\n", group.member_number);/*人数*/
	    for (int j = 0; j < group.member_number; j++) {
			fprintf(fp, "运动员ID:%d\n", group.memberid[j]);
		}
		for (int n = 0; n < group.game_number; n++) {
			fprintf(fp, "比赛ID:%d\n", group.score->name.id);
			fprintf(fp, "比赛名称:%s\n", group.score->name.name);
			fprintf(fp, "该比赛所得积分:%d\n", group.score->point);
			fprintf(fp, "该比赛最佳成绩:%f\n", group.score->score);
		}
		

	}
	fclose(fp);
}
//打印链表
void printGrouplist(GroupListNode* pHead) {
	int line_long = longNode(pHead);
	GroupListNode* p = pHead;
	Group group;
	for (int i = 0; i < line_long; i++,p=p->next) {
		group = p->group;
		printf("%d.", i+1);/*序号*/
		printf("ID:%d ", group.name.id);
		printf("名称:%s ", group.name.name);
		printf("人数:%d ", group.member_number);
		printf("比赛报名数:%d \n", group.game_number);
	}
}

//新建简易比赛的链表函数
BriefGame_2ListNode* InipHead() {//初始化简易链表（已排序），每次使用前要调用这个函数
	char name[20];
	double score,id;
	int point;
	GameListNode* p_game = readGamelist();
	PlayerListNode* p_player = readPlayerlist();
	if (p_player == NULL || p_game == NULL)return NULL;
	BriefGame_2ListNode* pHeadNode = new BriefGame_2ListNode;//创建一个新的指针节点并分配空间
	if (pHeadNode == NULL) {
		printf("创建链表失败");
		exit(0);
	}
	BriefGame_2ListNode* p = pHeadNode;
	while (p_game->next) {//以比赛为单位逐个比赛内部排序
		p->briefgame_2.name.id = p_game->game.name.id;
		strcpy(p->briefgame_2.name.name, p_game->game.name.name);
		p->briefgame_2.number = p_game->game.number;
		p_game = p_game->next;
		for (int i = 0; i < p->briefgame_2.number; i++) {//该项目的运动人员循环
			while (p_player->next) {
				for (int x = 0; x < p_player->player.game_number; x++)//运动员本身成绩查询
				{
					if (p_player->player.score[x].name.id == p->briefgame_2.name.id) {//获取运动员在该项目的成绩
						p->briefgame_2.playername[i].id = p_player->player.name.id;
						strcpy(p->briefgame_2.playername[i].name, p_player->player.name.name);
						p->briefgame_2.score[i] = p_player->player.score[x].score;
						p->briefgame_2.point[i] = p_player->player.score[x].point;
					}
				}
			}
		}
		for (int i = 0; i < p->briefgame_2.number - 1; i++) {
			for (int j = 0; j < p->briefgame_2.number -1-i; j++)
			{
				if (p->briefgame_2.score[j] < p->briefgame_2.score[j + 1]) {
					id = p->briefgame_2.playername[j].id;
					p->briefgame_2.playername[j].id = p->briefgame_2.playername[j + 1].id;
					p->briefgame_2.playername[j+1].id =id;//id交换

					strcpy(name, p->briefgame_2.playername[j].name);
					strcpy(p->briefgame_2.playername[j].name, p->briefgame_2.playername[j+1].name);
					strcpy(p->briefgame_2.playername[j+1].name,name);//运动员名称交换

					score = p->briefgame_2.score[j];
					p->briefgame_2.score[j] = p->briefgame_2.score[j + 1];
					p->briefgame_2.score[j + 1] = score;//成绩交换

					point = p->briefgame_2.point[j];
					p->briefgame_2.point[j]= p->briefgame_2.point[j+1];
					p->briefgame_2.point[j + 1] = point;//得分交换
				}
			}
		}
		for (int i = 0; i < p->briefgame_2.number - 1; i++) { p->briefgame_2.rank[i] = i + 1; }
	}
}
//在链表最后面新增一个节点,新增节点的数据为player,pHead为该链表中任一指针节点.
void addNode(BriefGame_2ListNode* pHead, BriefGame_2 BriefGame_2) {
	BriefGame_2ListNode* p = pHead;
	BriefGame_2ListNode* pNewNode = new BriefGame_2ListNode;//创建一个新的指针节点并分配空间
	pNewNode->briefgame_2 = BriefGame_2;//将gmae赋值进改节点中
	pNewNode->next = NULL;//该节点的next指向NULL
	while (p->next != NULL) {//找到最后的节点指针
		p = p->next;
	}
	p->next = pNewNode;//将最后的节点指针指向新的节点
}
//删除节点p,pHead是头节点,返回头节点,如果全删除了返回NULL;
BriefGame_2ListNode* deleteNode(BriefGame_2ListNode* pHead, BriefGame_2ListNode* p) {
	if (p->next != NULL) {
		p->briefgame_2 = p->next->briefgame_2;//将下一个节点的内容放入p中
		BriefGame_2ListNode* p_next = p->next;//记录指针
		p->next = p->next->next;//将下一个节点的next放入p中,
								//相当于丢失了将p下一个节点复制到p中,并丢失了p下一个节点
		free(p_next);//释放无用内存
		p_next = NULL;
		return pHead;
	}
	else if (longNode(pHead) == 1) {//如果只有一个节点
		free(p);
		return NULL;
	}
	else {//p是最后一个节点
		BriefGame_2ListNode* newp = pHead;
		while (newp->next->next != NULL) {
			newp = newp->next;
		}
		newp->next = NULL;
		free(p);
		return pHead;
	}
}
//传入头节点,返回有多少个节点
int longNode(BriefGame_2ListNode* pHead) {
	int i = 0;
	BriefGame_2ListNode* p = pHead;
	if (p == NULL) return 0;
	else i++;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//把链表存入文件中
void saveBriefGame_2list(BriefGame_2ListNode* pHead) {
	FILE* fp;//文件指针
	fp = fopen("BriefGame_2.txt", "w");
	int line_long = longNode(pHead);//该链表有多少个节点
	BriefGame_2ListNode* p = pHead;
	BriefGame_2 BriefGame_2;

	fprintf(fp, "项目数量:%d\n", line_long);//储存有多少个节点
	for (int i = 0; i < line_long; i++, p = p->next) {
		BriefGame_2 = p->briefgame_2;
		fprintf(fp, "ID:%d\n", BriefGame_2.name.id/*id*/);
		fprintf(fp, "名称:%s\n", BriefGame_2.name.name/*名称*/);
		fprintf(fp, "人数:%d\n", BriefGame_2.number/*报名人数*/);
		for (int j = 0; j < BriefGame_2.number; j++) {//储存报名人员id
			fprintf(fp, "报名人员ID:%d ", BriefGame_2.playername[j].id);//
			fprintf(fp, "报名人员名称:%s ", BriefGame_2.playername[j].name);//报名人名称
			fprintf(fp, "报名人员成绩:%f ", BriefGame_2.score[j]);//成绩
			fprintf(fp, "报名人员得分:%d ", BriefGame_2.point[j]);//得分
			fprintf(fp, "报名人员排名:%d\n", BriefGame_2.rank[j]);//排名
		}

	}
	fclose(fp);
}
