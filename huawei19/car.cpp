#include"car.h"
#include"str2int.h"
int str2int(string s)
{
	int a = atoi(s.c_str());
	return a;
}

int getMinspeed(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b <= c)
		{
			return b;
		}
		else{ return c; }
	}




}

void car::cur_car_state(road *road_p )//参数为road型指针
{
	(this->pass_road).push_back(road_p->road_number);//存进去 经过的道路信息

	road *road_ptr = road_p;
	int road_speed = str2int(road_ptr->road_speed);
	int car_speed = str2int(this->car_maxSpeed);

	int road_channel = str2int(road_ptr->road_channel);
	int road_length = str2int(road_ptr->road_length);

	int i = 0;
	
	//车的当前速度 =min 车最高速度 道路限速 前车速度
	//比较速度 得到car_curSpeed
	for (i; i < road_channel; i++)
	{
		for (int j = 0; j < road_length; j++)
		{
			if ((road_ptr->state_from)[i][j] == str2int(this->car_number))//车在矩阵中的位置
			{
				//getMinspeed(a,b,c);//获得下一时刻的速度
			}
			if (((road_ptr->state_to)[i][j] == str2int(this->car_number)))
			{
				//getMinspeed(a,b,c);
			}
		}
	}


	//转弯标志 carturn
	//下次要转向的路口number 
	//car_nextRoad


	//判断车是等待状态还是终止状态




}


