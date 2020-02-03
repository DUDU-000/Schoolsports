#include<iostream>
#include<stdio.h>
#include"method.h"

//若entry在mix与max之间,则返回int型的entry,否则,返回0
int entrycheck(char entry,int mix,int max) {
	if (48 + mix <= entry&&entry <= 48 + max)
		return entry - 48;
	else return 0;
}