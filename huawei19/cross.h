#ifndef CROSS_H
#define CROSS_H
#include<iostream>
#include<string>
using namespace std;
class cross
{
public:
	string cross_number;
	string cross_roadId1;
	string cross_roadId2;
	string cross_roadId3;
	string cross_roadId4;

	int *cross_up=NULL;
	int *cross_right = NULL;
	int *cross_down = NULL;
	int *cross_left = NULL;

	int l_u = 0, r_u = 0, r_d = 0, l_d = 0;

	


};







#endif