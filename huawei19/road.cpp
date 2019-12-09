#include"road.h"
#include"str2int.h"


void road::make_matr(int *a, int channel, int isDuplex, int speed, int leng)
{
	
	(this->a_ptr) = a;
	int channel_ = channel;
	int isDuplex_ = isDuplex;
	int speed_ = speed;
	int leng_ = leng;

	//判断isDuplex是否是1 初始化二维矩阵
	if (isDuplex_ == 1)
	{//先给两个矩阵赋值
		int i = 0;
		//指向第一个矩阵的首from
		this->from = a;
		//指向第二个矩阵的首to
		this->to = a + 10 * 25;
		for (i; i < channel_; i++)
		{
			for (int j = 0; j < leng_; j++)
			{
				*(this->from + 25 * i + j) = 0;
			}
		}
		int i1 = 0;
		for (i1; i1 < channel_; i1++)
		{
			for (int j1 = 0; j1 < leng_; j1++)
			{
				*(this->to + 10 * 25 + i1 * 25 + j1) = 0;
			}
		}
	}
	else
	{
		int i = 0;
		//只把第一个矩阵 置为0 其余置为-1不变from
		this->from = a;
		for (i; i < channel_; i++)
		{
			for (int j = 0; j < leng_; j++)
			{
				*(this->from + 25 * i + j) = 0;
			}
		}
	}
}


int* road_map(int a, road* road_ptr)
{
	int leng = 0, isDuplex = 0, channel = 0;
	leng = atoi(((road_ptr + a - 5000 + 1)->road_length).c_str());
	isDuplex = str2int((road_ptr + a - 5000 + 1)->road_isDuplex);
	channel = str2int((road_ptr + a - 5000 + 1)->road_channel);

	vector< vector<int> > map(channel, vector<int>(leng));
	int i_count = 0;

	for (i_count; i_count < channel; i_count++)
	{
		for (int j_count = 0; j_count < leng; j_count++)
		{
			map[i_count][j_count] = i_count + j_count;
		}

	}
	int* a_ptr = &map[0][0];

	return a_ptr;
}

//道路当前状态 每条车道车辆数 车辆位置 
void road::road_state()
{
	int number=str2int(this->road_number);
	int length = str2int(this->road_length);
	int channel = str2int(this->road_channel);
	int isDuplex = str2int(this->road_isDuplex);
	int speed = str2int(this->road_speed);
	
	int i = 0;

	//状态矩阵的初始化 
	if (isDuplex == 1)
	{
		for (i; i < channel; i++)
	    {
		for (int j=0; j < length; j++)
		 {
			this->state_from[i][j] = 0;
			this->state_to[i][j] = 0;
		 }
	   }
	}
	else
	{
		for(i; i < channel; i++)
		{
			for (int j=0; j < length; j++)
			{
				this->state_from[i][j] = 0;
			}
		}
	
	}
	int i_search_form = 0;
	int cur_channel_count_from = 0;
	int cur_channel_count_to = 0;

	//扫描矩阵 计算当前车辆个数以及位置
	if (isDuplex == 1)
	{
		for (i_search_form; i_search_form < channel; i_search_form++)
		{
			for (int j_search_from = 0; j_search_from < channel; j_search_from++)
			{
				if (*(this->from + i_search_form*length + j_search_from) != 0)
				{
					this->cur_channel_count_from++;
					this->state_from[i_search_form].push_back(j_search_from);
				}
				if (*(this->to + i_search_form*length + j_search_from) != 0)
				{
					this->cur_channel_count_to++;
					this->state_to[i_search_form].push_back(j_search_from);
				}
			}
		}
	}
	else
	{
		for (i_search_form; i_search_form < channel; i_search_form++)
		{
			for (int j_search_from = 0; j_search_from < channel; j_search_from++)
			{
				if (*(this->from + i_search_form*length + j_search_from) != 0)
				{
					this->cur_channel_count_from++;
					this->state_from[i_search_form].push_back(j_search_from);
				}
			}	
		}
	}




}