#pragma once
#ifndef GETDIRECTION_H
#define GETDIRECTION_H
#include<iostream>
#include<string>
#include <vector> 
#include"main.h"
using namespace std;

struct point {
	int id;
	int len;
	int dir1;
	int dir2;
	int car_number;
	int speed_cost;
};

struct cost {
	double turn_cost;
	double num_cost;
	double speed_cost;
	double plan_cost;
	double cost;
};
class getdirection
{
public:

	getdirection() {};
	~getdirection() {};
	int dir = 0;

private:
	struct cost get_cost(struct point road, int cur_x, int cur_y, int goa_x, int goa_y);
	int get_xy(int cross_id, std::vector<vector<int>> m_int, int add_row_count, int add_col_count);  //获取当前车辆的的目的地x坐标
	int get_direction(int car_id, int cross_id,int road_id);
	bool checkroad(int road_id, int cross_id);

	std::vector<point> open;
	std::vector<int> lenth;
	std::vector<int> road;
	std::vector<cost> cost;
	double turn_cost_sum;
	double num_cost_sum;
	double speed_cost_sum;
	double plan_cost_sum;
};





#endif //GETDIRECTION