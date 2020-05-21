#include<iostream>
#include<stdio.h>
#include"method.h"
#include"linked_list.h"

//若entry在mix与max之间,则返回int型的entry,否则,返回0,传入的是char型数组
int entrycheck(char entry[] , int mix,int max) {
	int result=0;
	int byte = strlen(entry);
	for (int i = 0; i < strlen(entry); i++) {
		if ('0' <= entry[i] && entry[i] <= '9') result = result * 10 + entry[i] - 48;
		else return -1;
	}
	if(mix<=result&&result<=max) return result;
	else return -1;
}

bool file_is_empty(std::string &file_path) {//参数是文件路径
	struct stat buf;
	stat(file_path.c_str(), &buf);
	size_t size = buf.st_size;
	if (size == 0)//若文件为空 ,返回true
		return true;
	else
		return false;
}

void savesituation(int a) {
	FILE *fp;//文件指针
	fp = fopen("setting.txt", "w");
	fprintf(fp, "状态:%d\n", a);
	fclose(fp);
}

int readsituation() {
	FILE *fp;//文件指针
	int a;
	/*文件的打开*/
	fp = fopen("setting.txt", "rt+");//fopen打开文件，这个文件可以是当前不存在的。“w”以写入的形式打开，“r”以读的形式打开
	std::string file_path = "setting.txt";

	if (fp == NULL || file_is_empty(file_path)) {//判断如果文件指针为空
		return -1;
	}
	fscanf_s(fp, "状态:%d\n", &a);
	fclose(fp);
	return a;
}

