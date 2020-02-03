#include<iostream>
#include<stdio.h>
#include"method.h"

int entrycheck(char entry,int mix,int max) {

	if (48 + mix <= entry&&entry <= 48 + max)
		return entry - 48;
	else return 0;
}