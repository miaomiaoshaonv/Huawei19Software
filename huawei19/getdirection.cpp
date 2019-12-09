#include<iostream>
#include<string>
#include <vector> 
#include"main.h"
#include"getdirection.h"

getdirection::getdirection() : dir(0),open({ 0 }), lenth({ 0 }), road({ 0 }), cost({0}), turn_cost_sum(0),
num_cost_sum(0), speed_cost_sum(0), plan_cost_sum(0)
{
}

getdirection::~getdirection() {};

int getdirection::get_direction(int car_id, int cross_id, int road_id)
{
	int size_open = 0;
	int cross_x = 0;
	int cross_y = 0;
	int goal_x = 0;
	int goal_y = 0;
	int dir_from = 0;
	/*将当前路口的道路ID存进向量road*/
	road[0] = atoi(((cross_ptr + cross_id)->cross_roadId1).c_str());
	road[1] = atoi(((cross_ptr + cross_id)->cross_roadId2).c_str());
	road[2] = atoi(((cross_ptr + cross_id)->cross_roadId3).c_str());
	road[3] = atoi(((cross_ptr + cross_id)->cross_roadId4).c_str());

	/*将来处路口对应方向的向量设为0*/
	for (int i = 0; i < 4; i++)
	{
		if (road_id == atoi(((cross_ptr + cross_id)->cross_roadId1).c_str()) ||
			road_id == atoi(((cross_ptr + cross_id)->cross_roadId2).c_str()) ||
			road_id == atoi(((cross_ptr + cross_id)->cross_roadId3).c_str()) ||
			road_id == atoi(((cross_ptr + cross_id)->cross_roadId4).c_str()))
		{
			road[i] = 0;
			dir_from = i;
			break;
		}
	}

	/*排除由于单行道导致不通的情况*/
	for (int i = 0; i < 4; i++)  //
	{
		bool roadflag = checkroad(road[i], cross_id);
		if (roadflag == false) { road[i] = 0; }
	}

	/*将当前路口的道路的长度存入向量length*/
	lenth[0] = atoi(((road_ptr + road[0] - 5000)->road_length).c_str());
	lenth[1] = atoi(((road_ptr + road[1] - 5000)->road_length).c_str());
	lenth[2] = atoi(((road_ptr + road[2] - 5000)->road_length).c_str());
	lenth[3] = atoi(((road_ptr + road[3] - 5000)->road_length).c_str());

	for (int j = 0; j < 4; j++)  //当前路口可连接的道路
	{
		if (road[j] != 0)
		{
			open[size_open].id = road[j];
			open[size_open].len = lenth[j];
			open[size_open].dir1 = dir_from;
			open[size_open].dir2 = j;
			size_open++;
		}
	}

	int cross_z = get_xy(cross_id, m_int, add_row_count, add_col_count);//得到x_goal,x_cur，y_goal,y_cur，
	cross_x = cross_z / 100;
	cross_y = cross_z % 100;
	int goal_z = get_xy(cross_id, m_int, add_row_count, add_col_count);
	goal_x = goal_z / 100;
	goal_y = goal_z % 100;

	if (size_open == 1)
	{
		dir = open[size_open].dir2;
	}
	else
	{
		for (int m = 0; m < size_open; m++)
		{
			cost[m] = get_cost(open[m], cross_x, cross_y, goal_x,goal_y);
			turn_cost_sum = turn_cost_sum + cost[m].turn_cost;
			num_cost_sum = num_cost_sum + cost[m].num_cost;
			speed_cost_sum = speed_cost_sum + cost[m].speed_cost;
		}
		double cost_min = cost[0].cost;
		for (int m = 0; m < size_open; m++)
		{
			cost[m].turn_cost = cost[m].turn_cost / (turn_cost_sum / size_open);
			cost[m].num_cost = cost[m].num_cost / (num_cost_sum / size_open);
			cost[m].speed_cost = cost[m].speed_cost / (speed_cost_sum / size_open);
			cost[m].cost = (0.25*cost[m].turn_cost) + (0.25*cost[m].num_cost) +
				           (0.25*cost[m].speed_cost) + (0.25*cost[m].plan_cost);//权值需要根据实际情况调整
			if (cost[m].cost <= cost_min) 
			{ 
				cost_min = cost[m].cost;
				dir = open[m].dir2;
			}
		}
	}
	return dir;
};


int getdirection::get_xy(int cross_id, std::vector<vector<int>> m_int,
	int add_row_count, int add_col_count)
{
	int i_count = 0;
	int j_count = 0;
	int break_siganl = 0;
	for (i_count; i_count < add_row_count; i_count++)
	{
		for (j_count; j_count < add_col_count; j_count++)
		{
			if (m_int[i_count][j_count] == cross_id)
			{
				break_siganl = 1;
				break;
			}
		}
		if (break_siganl == 1)
		{
			break;
		}
	}
	return i_count * 100 + j_count;
}

struct cost getdirection::get_cost(struct point road, int cur_x, int cur_y, int goa_x, int goa_y)
{
	struct cost cost;

	if (road.dir1 == road.dir2) cost.turn_cost = 3; 
	else if (road.dir2 - road.dir1 == 1 || (road.dir1 == 3 && road.dir2 == 0))
	{
		cost.turn_cost = 2;
	}
	else if(road.dir1 - road.dir2 == 1 || (road.dir1 == 0 && road.dir2 == 3))
	{ 
		cost.turn_cost = 1;
	}
	else std::cout << "road" << road.id << "can not turn";

	cost.num_cost = road.car_number;
	cost.speed_cost = road.speed_cost;

	if (cur_x <= goa_x && cur_y <= goa_y)//终点在起点的右上
	{
		if(cross->r_u == road.dir1) cost.plan_cost = 1;
		else cost.plan_cost = 0;
	}

	if (cur_x >= goa_x && cur_y <= goa_y) ////终点在起点的右下
	{
		if (cross->r_d == road.dir1) cost.plan_cost = 1;
		else cost.plan_cost = 0;
	}

	if (cur_x <= goa_x && cur_y >= goa_y) ////终点在起点的左上
	{
		if (cross->l_u == road.dir1) cost.plan_cost = 1;
		else cost.plan_cost = 0;
	}

	if (cur_x >= goa_x && cur_y >= goa_y) ////终点在起点的左下
	{
		if (cross->l_d == road.dir1) cost.plan_cost = 1;
		else cost.plan_cost = 0;
	}
	return cost;
};


bool  getdirection::checkroad(int road_id, int cross_id)
{
	bool road_flag = 0;
	if ((atoi((road_ptr + road_id - 5000)->road_from.c_str()) != cross_id) &&
		atoi((road_ptr + road_id - 5000)->road_isDuplex.c_str()) == 0)
	{
		return road_flag = false;
	}
	return road_flag = true;
}