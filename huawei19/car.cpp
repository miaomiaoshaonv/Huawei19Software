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

void car::cur_car_state(road *road_p )//����Ϊroad��ָ��
{
	(this->pass_road).push_back(road_p->road_number);//���ȥ �����ĵ�·��Ϣ

	road *road_ptr = road_p;
	int road_speed = str2int(road_ptr->road_speed);
	int car_speed = str2int(this->car_maxSpeed);

	int road_channel = str2int(road_ptr->road_channel);
	int road_length = str2int(road_ptr->road_length);

	int i = 0;
	
	//���ĵ�ǰ�ٶ� =min ������ٶ� ��·���� ǰ���ٶ�
	//�Ƚ��ٶ� �õ�car_curSpeed
	for (i; i < road_channel; i++)
	{
		for (int j = 0; j < road_length; j++)
		{
			if ((road_ptr->state_from)[i][j] == str2int(this->car_number))//���ھ����е�λ��
			{
				//getMinspeed(a,b,c);//�����һʱ�̵��ٶ�
			}
			if (((road_ptr->state_to)[i][j] == str2int(this->car_number)))
			{
				//getMinspeed(a,b,c);
			}
		}
	}


	//ת���־ carturn
	//�´�Ҫת���·��number 
	//car_nextRoad


	//�жϳ��ǵȴ�״̬������ֹ״̬




}


