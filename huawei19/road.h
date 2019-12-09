#ifndef ROAD_H
#define ROAD_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class road
{
public:
	string road_number;
	string road_length;
	string road_speed;
	string road_channel;
	string road_from;
	string road_to;
	string road_isDuplex;

	void make_matr(int *a, int channel, int isDuplex, int speed, int leng);

	int *a_ptr;
	int *from=NULL;
	int *to=NULL;

	vector< vector<int> > state_from;
	vector< vector<int> > state_to;
	
	int cur_channel_count_from=0;
	int cur_channel_count_to = 0;

	void road_state();//道路当前状态 每条车道车辆数 车辆位置 

	vector<int> isRoadFull_from;//初始化为0 满了就置为1
	vector<int> isRoadFull_to;
	int isRoadFull();//判断某条路是不是满的

};
int* road_map(int a, road* road_ptr);

int ** road_channel_array(string a, string b);



#endif		