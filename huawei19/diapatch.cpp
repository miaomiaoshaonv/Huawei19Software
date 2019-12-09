#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"road_int.h"
#include"car.h"
#include"cross.h"
#include"road.h"
#include"getdirection.h"
#include "dispatch.h"
#include"main.h"



dispatch::dispatch() 
{}

dispatch::~dispatch()
{}



void dispatch::dispatchcar(int cross_id, std::vector<car> road_car, std::vector<car> other_road_car)
{
	
	get_road_id(cross_id); //获得该路口到达道路的id，并排序存入road_id

	if (road_id[0].from_to == "from")        //将road_id中的所有车按优先级高低排序
		get_car(road_car_ptr1, road_id[0].road_id);
	else if (road_id[0].from_to == "to")
		get_car1(road_car_ptr1, road_id[0].road_id);

	if (road_id[1].from_to == "from")
		get_car(road_car_ptr2, road_id[0].road_id);
	else if (road_id[1].from_to == "to")
		get_car1(road_car_ptr2, road_id[0].road_id);

	if (road_id[2].from_to == "from")
		get_car(road_car_ptr3, road_id[0].road_id);
	else if (road_id[2].from_to == "to")
		get_car1(road_car_ptr3, road_id[0].road_id);

	if (road_id[3].from_to == "from")
		get_car(road_car_ptr4, road_id[0].road_id);
	else if (road_id[3].from_to == "to")
		get_car1(road_car_ptr4, road_id[0].road_id);

	for (int j = 0; j < road_id.size(); j++)
	{
		if (road_id[j].flag != 1) break;
		for (int i = 0; i < road_car1.size(); i++)
		{
			int Vmax = atoi(((car_ptr + atoi((road_car1[i].car_number).c_str()))->car_maxSpeed).c_str());
			int S1 = (car_ptr + atoi((road_car1[i].car_number).c_str()))->S;
			int V1 = (car_ptr + atoi((road_car1[i].car_number).c_str()))->car_curSpeed;
			int R2 = (road_int_ptr + (car_ptr + atoi((road_car1[i].car_number).c_str()))->car_nextRoad)->road_speed_int;
			int V2 = min(Vmax, R2);
			int S2 = V2 - S1;
			int SV1 = V1;
			int SV2 = V2;
			if ((S1 < SV1) && (S2 < SV2) && (S2 < abs(SV2 - S1)) && (S1 < SV2)) // 能进入下一条车道
			{
				if (road_car1[i].car_turn < road_car2[0].car_turn)
					break;
				if (road_car1[i].car_turn < road_car3[0].car_turn)
					break;
				if (road_car1[i].car_turn < road_car4[0].car_turn)
					break;

				int channel = getChannel(road_car1[i]);
				if (channel == 0) break;
				moveToNextRoad(road_car1[i], channel,  SV2, S1);

			}
		}
		driveAllCarJustOnRoadToEndState(road_id[j]);
	}
	
}
		





void dispatch::get_road_id(int cross_id)
{
	vector<road1> able_road;

	if ((cross_int_ptr + cross_id)->cross_roadId1_int != 0)   //判断第一个方向（上）是否有道路到达
	{
		if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId1_int)->road_to_int == cross_id)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId1_int;
			able_road[able_road.size()].from_to = "from";
		}
		else if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId1_int)->road_isDuplex_int == 1)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId1_int;
			able_road[able_road.size()].from_to = "to";
		}
	}

	if ((cross_int_ptr + cross_id)->cross_roadId2_int != 0)   //判断第2个方向（右）是否有道路到达
	{
		if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId2_int)->road_to_int == cross_id)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId2_int;
			able_road[able_road.size()].from_to = "from";
		}
		else if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId2_int)->road_isDuplex_int == 1)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId2_int;
			able_road[able_road.size()].from_to = "to";
		}
	}

	if ((cross_int_ptr + cross_id)->cross_roadId3_int != 0)   //判断第3个方向（下）是否有道路到达
	{
		if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId3_int)->road_to_int == cross_id)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId3_int;
			able_road[able_road.size()].from_to = "from";
		}
		else if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId3_int)->road_isDuplex_int == 1)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId3_int;
			able_road[able_road.size()].from_to = "to";
		}
	}

	if ((cross_int_ptr + cross_id)->cross_roadId4_int != 0)   //判断第4个方向（左）是否有道路到达
	{
		if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId4_int)->road_to_int == cross_id)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId4_int;
			able_road[able_road.size()].from_to = "from";
		}
		else if ((road_int_ptr + (cross_int_ptr + cross_id)->cross_roadId4_int)->road_isDuplex_int == 1)
		{
			able_road[able_road.size()].road_id = (cross_int_ptr + cross_id)->cross_roadId4_int;
			able_road[able_road.size()].from_to = "to";
		}
	}


	if (able_road.size() == 1) road_id.push_back(able_road[0]); //1的时候直接存入road_id
	if (able_road.size() == 2)                                   //2的时候将小的存入road_id[0],大的存入road_id[1]
	{
		if (able_road[0].road_id < able_road[1].road_id)
		{
			road_id.push_back(able_road[0]);
			road_id.push_back(able_road[1]);
		}
	}

	int temp = 0;                                           //3和4的时候，将able_road按小到大排序，再存入road_id
	for (int i = 0; i < able_road.size(); i++)
		for (int j = i + 1; j < able_road.size(); j++)
		{
			if (able_road[i].road_id > able_road[j].road_id)
			{
				temp = able_road[i].road_id;
				able_road[i].road_id = able_road[j].road_id;
				able_road[j].road_id = temp;
			}
		}

	for (int i = 0; i < able_road.size(); i++)
	{
		road_id.push_back(able_road[i]);
	}
}

void dispatch::get_car (vector<car>* road_car_ptr,int road_id) //将road_id道路上所有的额车按照优先级，存入road_car_ptr所指向的car型向量
{
	vector<int> int_road;
	

	int length = (road_int_ptr + road_id - 5000)->road_length_int;
	int channel= (road_int_ptr + road_id - 5000)->road_channel_int;
	int i = 0;
	int j = 0;
	for (j = 0; j < length; j++)
	{
		for ( i=channel-1;i<=0;i--)
		{
			int car_id = ((*(((road_ptr + road_id - 5000 + 1)->from) + i * 25 + j)));
			if (car_id != 0 &&((car_ptr+ car_id-10000+1)->state )==0 )//加上该车的状态为waiting
			{
				int_road.push_back(*(((road_ptr + road_id - 5000 + 1)->from) + i * 25 + j));
			}
			
		}
	}
	i = int_road.size()-1;
	j = 0;
	for (i; i <= 0; i--)
	{
	j = 0;
	(*(road_car_ptr)) [j].car_number =int_road[i];    //存入车的id，string
	(*(road_car_ptr ))[j].car_maxSpeed = (car_ptr + int_road[i])->car_maxSpeed;//存入车的最大限速，string
	(*(road_car_ptr ))[j].car_curSpeed = (car_ptr + int_road[i])->car_curSpeed;//存入车的当前速度，int
	(*(road_car_ptr ))[j].car_nextRoad = (car_ptr + int_road[i])->car_nextRoad;//存入车的下个路口id，int
	(*(road_car_ptr ))[j].car_turn = (car_ptr + int_road[i])->car_turn;//存入车的下个路口转向优先级，int
	  j++;
	}
}



void dispatch::get_car1(vector<car>* road_car_ptr, int road_id) //将road_id道路上所有的额车按照优先级，存入road_car_ptr所指向的car型向量
{
	vector<int> int_road;


	int length = (road_int_ptr + road_id - 5000)->road_length_int;
	int channel = (road_int_ptr + road_id - 5000)->road_channel_int;
	int i = 0;
	int j = 0;
	for (j = 0; j < length; j++)
	{
		for (i = channel - 1; i <= 0; i--)
		{
			int car_id = (*(((road_ptr + road_id - 5000 + 1)->to) + i * 25 + j));
			if (car_id != 0 && ((car_ptr + car_id - 10000 + 1)->state) == 0)//加上该车的状态为waiting
			{
				int_road.push_back(*(((road_ptr + road_id - 5000 + 1)->to) + i * 25 + j));
			}

		}
	}
	i = int_road.size() - 1;
	j = 0;
	for (i; i <= 0; i--)
	{
		j = 0;
		(*(road_car_ptr))[j].car_number = int_road[i];    //存入车的id，string
		(*(road_car_ptr))[j].car_maxSpeed = (car_ptr + int_road[i])->car_maxSpeed;//存入车的最大限速，string
		(*(road_car_ptr))[j].car_curSpeed = (car_ptr + int_road[i])->car_curSpeed;//存入车的当前速度，int
		(*(road_car_ptr))[j].car_nextRoad = (car_ptr + int_road[i])->car_nextRoad;//存入车的下个路口id，int
		(*(road_car_ptr))[j].car_turn = (car_ptr + int_road[i])->car_turn;//存入车的下个路口转向优先级，int
		j++;
	}
}


int dispatch::getChannel(car road_car) 
{
	int channel_num = (road_int_ptr + road_car.car_nextRoad)->road_channel_int;
	int channel = 0;
	for (int i = 0; i < channel_num; i++)
	{
		for (int j = 0; j < (road_int_ptr + road_car.car_nextRoad - 5000 + 1)->road_length_int; j++)
			if (*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->to) + i * 25 + j)==0)
				 channel = i;
		break;
	}
	return channel;
}

void dispatch::moveToNextRoad(car road_car, int channel, int SV2, int S1)
{
	(car_ptr + atoi((road_car.car_number).c_str()))->car_curSpeed = SV2; //将车的速度更新为SV2
	int S1 = min(SV2, abs(SV2 - S1));    //计算到下一条道路上的位移S1
	for (int j = 0; j < S1; j++)
	{
		if ((road_int_ptr + road_car.car_nextRoad - 5000 + 1)->road_from_int == cross_id) //如果下一条道路为from方向
		{
			if (*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->from) + (channel - 1) * 25 + j) != 0)
			{
			}*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->from) + (channel - 1) * 25 + (j - 1)) =
				atoi(((car_ptr + atoi((road_car.car_number).c_str()))->car_number).c_str());//更新下一条道路的from矩阵

		}
		else //下一条道路为to方向
		{
			if (*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->to) + (channel - 1) * 25 + j) != 0)
				*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->to) + (channel - 1) * 25 + (j - 1)) =
				atoi(((car_ptr + atoi((road_car.car_number).c_str()))->car_number).c_str());////更新下一条道路的to矩阵
		}
	}
}


int dispatch::driveAllCarJustOnRoadToEndState(road1 road_id)
{
	if (road_id.from_to == "from")
	{
		std::vector<int> last_car;

		int length = (road_int_ptr + road_id.road_id - 5000)->road_length_int;
		int channel = (road_int_ptr + road_id.road_id - 5000)->road_channel_int;
		int i = 0;
		int j = 0;
		for (j = 0; j < length; j++)
		{
			for (i = channel - 1; i <= 0; i--)
			{
				int car_id = ((*(((road_ptr + road_id.road_id - 5000 + 1)->from) + i * 25 + j)));
				if (car_id != 0)//如果该位置有车，则把车辆ID存入last_car
					last_car.push_back(*(((road_ptr + road_id.road_id - 5000 + 1)->from) + i * 25 + j));
			}
		}
		i = 0;
		for (i = 0; i < last_car.size(); i++)
		{
			if (((car_ptr + last_car[i])->S > (car_ptr + last_car[i])->car_curSpeed)||
				((car_ptr + last_car[i])->S > atoi(((road_ptr + (car_ptr + last_car[i])->car_nextRoad - 5000 + 1)->road_speed).c_str()))) //S1>V1,或者S1>R2,均不能通过路口，判定为终止状态
			{
				(car_ptr + last_car[i])->state = 1;  //将状态判为终止
				(car_ptr + last_car[i])->S= ((car_ptr + last_car[i])->S)- ((car_ptr + last_car[i])->car_curSpeed); //更改车的位移
			}
		}
	}
}

