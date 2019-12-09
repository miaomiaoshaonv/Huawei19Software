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
	
	get_road_id(cross_id); //��ø�·�ڵ����·��id�����������road_id

	if (road_id[0].from_to == "from")        //��road_id�е����г������ȼ��ߵ�����
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
			if ((S1 < SV1) && (S2 < SV2) && (S2 < abs(SV2 - S1)) && (S1 < SV2)) // �ܽ�����һ������
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

	if ((cross_int_ptr + cross_id)->cross_roadId1_int != 0)   //�жϵ�һ�������ϣ��Ƿ��е�·����
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

	if ((cross_int_ptr + cross_id)->cross_roadId2_int != 0)   //�жϵ�2�������ң��Ƿ��е�·����
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

	if ((cross_int_ptr + cross_id)->cross_roadId3_int != 0)   //�жϵ�3�������£��Ƿ��е�·����
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

	if ((cross_int_ptr + cross_id)->cross_roadId4_int != 0)   //�жϵ�4���������Ƿ��е�·����
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


	if (able_road.size() == 1) road_id.push_back(able_road[0]); //1��ʱ��ֱ�Ӵ���road_id
	if (able_road.size() == 2)                                   //2��ʱ��С�Ĵ���road_id[0],��Ĵ���road_id[1]
	{
		if (able_road[0].road_id < able_road[1].road_id)
		{
			road_id.push_back(able_road[0]);
			road_id.push_back(able_road[1]);
		}
	}

	int temp = 0;                                           //3��4��ʱ�򣬽�able_road��С���������ٴ���road_id
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

void dispatch::get_car (vector<car>* road_car_ptr,int road_id) //��road_id��·�����еĶ�������ȼ�������road_car_ptr��ָ���car������
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
			if (car_id != 0 &&((car_ptr+ car_id-10000+1)->state )==0 )//���ϸó���״̬Ϊwaiting
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
	(*(road_car_ptr)) [j].car_number =int_road[i];    //���복��id��string
	(*(road_car_ptr ))[j].car_maxSpeed = (car_ptr + int_road[i])->car_maxSpeed;//���복��������٣�string
	(*(road_car_ptr ))[j].car_curSpeed = (car_ptr + int_road[i])->car_curSpeed;//���복�ĵ�ǰ�ٶȣ�int
	(*(road_car_ptr ))[j].car_nextRoad = (car_ptr + int_road[i])->car_nextRoad;//���복���¸�·��id��int
	(*(road_car_ptr ))[j].car_turn = (car_ptr + int_road[i])->car_turn;//���복���¸�·��ת�����ȼ���int
	  j++;
	}
}



void dispatch::get_car1(vector<car>* road_car_ptr, int road_id) //��road_id��·�����еĶ�������ȼ�������road_car_ptr��ָ���car������
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
			if (car_id != 0 && ((car_ptr + car_id - 10000 + 1)->state) == 0)//���ϸó���״̬Ϊwaiting
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
		(*(road_car_ptr))[j].car_number = int_road[i];    //���복��id��string
		(*(road_car_ptr))[j].car_maxSpeed = (car_ptr + int_road[i])->car_maxSpeed;//���복��������٣�string
		(*(road_car_ptr))[j].car_curSpeed = (car_ptr + int_road[i])->car_curSpeed;//���복�ĵ�ǰ�ٶȣ�int
		(*(road_car_ptr))[j].car_nextRoad = (car_ptr + int_road[i])->car_nextRoad;//���복���¸�·��id��int
		(*(road_car_ptr))[j].car_turn = (car_ptr + int_road[i])->car_turn;//���복���¸�·��ת�����ȼ���int
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
	(car_ptr + atoi((road_car.car_number).c_str()))->car_curSpeed = SV2; //�������ٶȸ���ΪSV2
	int S1 = min(SV2, abs(SV2 - S1));    //���㵽��һ����·�ϵ�λ��S1
	for (int j = 0; j < S1; j++)
	{
		if ((road_int_ptr + road_car.car_nextRoad - 5000 + 1)->road_from_int == cross_id) //�����һ����·Ϊfrom����
		{
			if (*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->from) + (channel - 1) * 25 + j) != 0)
			{
			}*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->from) + (channel - 1) * 25 + (j - 1)) =
				atoi(((car_ptr + atoi((road_car.car_number).c_str()))->car_number).c_str());//������һ����·��from����

		}
		else //��һ����·Ϊto����
		{
			if (*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->to) + (channel - 1) * 25 + j) != 0)
				*(((road_ptr + road_car.car_nextRoad - 5000 + 1)->to) + (channel - 1) * 25 + (j - 1)) =
				atoi(((car_ptr + atoi((road_car.car_number).c_str()))->car_number).c_str());////������һ����·��to����
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
				if (car_id != 0)//�����λ���г�����ѳ���ID����last_car
					last_car.push_back(*(((road_ptr + road_id.road_id - 5000 + 1)->from) + i * 25 + j));
			}
		}
		i = 0;
		for (i = 0; i < last_car.size(); i++)
		{
			if (((car_ptr + last_car[i])->S > (car_ptr + last_car[i])->car_curSpeed)||
				((car_ptr + last_car[i])->S > atoi(((road_ptr + (car_ptr + last_car[i])->car_nextRoad - 5000 + 1)->road_speed).c_str()))) //S1>V1,����S1>R2,������ͨ��·�ڣ��ж�Ϊ��ֹ״̬
			{
				(car_ptr + last_car[i])->state = 1;  //��״̬��Ϊ��ֹ
				(car_ptr + last_car[i])->S= ((car_ptr + last_car[i])->S)- ((car_ptr + last_car[i])->car_curSpeed); //���ĳ���λ��
			}
		}
	}
}

