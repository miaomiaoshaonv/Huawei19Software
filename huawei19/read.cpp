#include<iostream>
#include"read.h"
#include<string>
#include<fstream>
#include"str2int.h"


int read_car(car * car_ptr)
{
	ifstream icin;
	icin.open("car.txt");
	string temp;
	int car_count = 0;
	// 车辆一共有10240
	//car *car_ptr[10240];
	//car *car_ptr = new car[10250];
	int i = 0;
	string car_number_temp;

	while (getline(icin, temp, ')'))
	{
		car_count++;
		//cout << temp << endl;//读取数据，放入类型为string的temp中
		//(car_ptr+i) = new car();


		string carNmber_tepm;//车辆车号
		for (int car_number_temp = 2; (temp[car_number_temp] != ',') && (temp[car_number_temp] != ' '); car_number_temp++)
			carNmber_tepm.push_back(temp[car_number_temp]);
		(car_ptr + i)->car_number = carNmber_tepm;
		//cout << (car_ptr+i)->car_number << endl;//输出车辆号码测试



		string car_origination_temp;//车辆始发地
		int count_carOrigination = 2;

		for (count_carOrigination;; count_carOrigination++)
		if (temp[count_carOrigination] == ',')
		{
			int cut_count_carOrigination = count_carOrigination + 3;
			for (count_carOrigination; count_carOrigination <= cut_count_carOrigination; count_carOrigination++)
			{
				if ((temp[count_carOrigination] != ',') && (temp[count_carOrigination] != ' '))
					car_origination_temp.push_back(temp[count_carOrigination]);
			}
			break;
		}
		(car_ptr + i)->car_origination = car_origination_temp;
		//cout << (car_ptr+i)->car_origination << endl;//输出车辆出发地测试



		string car_destionation_temp;//车辆目的地
		int count_carDestionation = 2;
		int count_comma = 0;
		for (count_carDestionation;; count_carDestionation++)
		{
			if (temp[count_carDestionation] == ',')
				count_comma++;
			if (count_comma == 2)
			{
				int cut_count_carDestionation = count_carDestionation + 3;
				for (count_carDestionation; count_carDestionation <= cut_count_carDestionation; count_carDestionation++)
				{
					if ((temp[count_carDestionation] != ',') && (temp[count_carDestionation] != ' '))
						car_destionation_temp.push_back(temp[count_carDestionation]);
				}
				break;
			}
		}
		(car_ptr + i)->car_destination = car_destionation_temp;
		//cout << (car_ptr+i)->car_destination << endl;//输出车辆目的地测试


		string car_maxSpeed_temp;//车辆最高速度
		int  count_maxSpeed = 2;
		int count_comma_speed = 0;

		for (count_maxSpeed;; count_maxSpeed++)
		{
			if (temp[count_maxSpeed] == ',')
				count_comma_speed++;
			if (count_comma_speed == 3)
			{
				int cut_count_maxSpeed = count_maxSpeed + 3;
				for (count_maxSpeed; count_maxSpeed <= cut_count_maxSpeed; count_maxSpeed++)
				{
					if ((temp[count_maxSpeed] != ',') && (temp[count_maxSpeed] != ' '))
						car_maxSpeed_temp.push_back(temp[count_maxSpeed]);
				}
				break;
			}
		}
		(car_ptr + i)->car_maxSpeed = car_maxSpeed_temp;
		//cout << (car_ptr+i)->car_maxSpeed << endl;



		string car_planTime_temp;//车辆时间信息
		int count_planTime = 2;
		int count_comma_time = 0;
		for (count_planTime;; count_planTime++)
		{
			if (temp[count_planTime] == ',')
				count_comma_time++;
			if (count_comma_time == 4)
			{
				int cut_count_planTime = count_planTime + 3;
				for (count_planTime; count_planTime <= cut_count_planTime; count_planTime++)
				{
					if ((temp[count_planTime] != ',') && (temp[count_planTime] != ' '))
						car_planTime_temp.push_back(temp[count_planTime]);
				}
				break;
			}
		}
		(car_ptr + i)->car_planTime = car_planTime_temp;
		//cout << (car_ptr+i)->car_planTime << endl;//测试车辆到达时间测试

		i++;
	}

	return car_count;
}


int read_road(road*road_ptr)
{
	ifstream icin_road;
	icin_road.open("road.txt");

	//cout << "ssdas" << endl;
	string temp_road;

	//road *road_ptr[106];// 路一共105条
	//road *road_ptr = new road[106];
	int count_road = 0;
	int i_road = 0;

	while (getline(icin_road, temp_road, ')'))
	{
		//car_count++;
		//cout << temp_road << endl;//读取数据，放入类型为string的temp_road中

		//(road_ptr+i_road) = new road();
		count_road++;

		string roadNumber_temp;//路号
		for (int road_number_temp = 2; (temp_road[road_number_temp] != ',') && (temp_road[road_number_temp] != ' '); road_number_temp++)
			roadNumber_temp.push_back(temp_road[road_number_temp]);
		(road_ptr + i_road)->road_number = roadNumber_temp;
		//cout << (road_ptr+i_road)->road_number << endl;//测试读取路号



		string road_length_temp;//道路长度
		int count_roadLength = 2;
		for (count_roadLength;; count_roadLength++)
		{
			if (temp_road[count_roadLength] == ',')
			{
				int cut_count_roadLength = count_roadLength + 3;
				for (count_roadLength; count_roadLength <= cut_count_roadLength; count_roadLength++)
				{
					if ((temp_road[count_roadLength] != ',') && (temp_road[count_roadLength] != ' '))
						road_length_temp.push_back(temp_road[count_roadLength]);
				}
				break;
			}

		}
		(road_ptr + i_road)->road_length = road_length_temp;
		//cout << (road_ptr+i_road)->road_length << endl;



		string road_speed_temp;//道路限速
		int count_roadSpeed = 2;
		int count_comma_roadSpeed = 0;
		for (count_roadSpeed;; count_roadSpeed++)
		{
			if (temp_road[count_roadSpeed] == ',')
				count_comma_roadSpeed++;
			if (count_comma_roadSpeed == 2)
			{
				int cut_count_roadSpeed = count_roadSpeed + 3;
				for (count_roadSpeed; count_roadSpeed <= cut_count_roadSpeed; count_roadSpeed++)
				{
					if ((temp_road[count_roadSpeed] != ' ') && (temp_road[count_roadSpeed] != ','))
						road_speed_temp.push_back(temp_road[count_roadSpeed]);
				}
				break;
			}
		}
		(road_ptr + i_road)->road_speed = road_speed_temp;
		//cout << (road_ptr+i_road)->road_speed << endl;


		string road_channel_temp;//道路条数
		int count_roadChannel = 2;
		int count_comma_roadChannel = 0;
		for (count_roadChannel;; count_roadChannel++)
		{

			if (temp_road[count_roadChannel] == ',')
				count_comma_roadChannel++;
			if (count_comma_roadChannel == 3)
			{
				int cut_count_roadChannel = count_roadChannel + 3;
				for (count_roadChannel; count_roadChannel <= cut_count_roadChannel; count_roadChannel++)
				{
					if ((temp_road[count_roadChannel] != ' ') && (temp_road[count_roadChannel] != ','))
					{
						road_channel_temp.push_back(temp_road[count_roadChannel]);
					}
				}
				break;
			}
		}
		(road_ptr + i_road)->road_channel = road_channel_temp;
		//cout << (road_ptr+i_road)->road_channel << endl;



		string road_from_temp;//道路初始点
		int count_roadfrom = 2;
		int count_comma_from = 0;
		for (count_roadfrom;; count_roadfrom++)
		{
			if (temp_road[count_roadfrom] == ',')
				count_comma_from++;
			if (count_comma_from == 4)
			{
				int cut_count_roadfrom = count_roadfrom + 3;
				for (count_roadfrom; count_roadfrom <= cut_count_roadfrom; count_roadfrom++)
				{
					if ((temp_road[count_roadfrom] != ' ') && (temp_road[count_roadfrom] != ','))
						road_from_temp.push_back(temp_road[count_roadfrom]);
				}
				break;
			}
		}
		(road_ptr + i_road)->road_from = road_from_temp;
		//cout << (road_ptr+i_road)->road_from << endl;




		string road_to_temp;//道路终点
		int count_roadTo = 2;
		int count_comma_roadTo = 0;
		for (count_roadTo;; count_roadTo++)
		{
			if (temp_road[count_roadTo] == ',')
				count_comma_roadTo++;
			if (count_comma_roadTo == 5)
			{
				int cut_count_roadTo = count_roadTo + 3;
				for (count_roadTo; count_roadTo <= cut_count_roadTo; count_roadTo++)
				{
					if ((temp_road[count_roadTo] != ' ') && (temp_road[count_roadTo] != ','))
						road_to_temp.push_back(temp_road[count_roadTo]);
				}
				break;
			}
		}
		(road_ptr + i_road)->road_to = road_to_temp;
		//cout << (road_ptr+i_road)->road_to << endl;




		string road_isDuplex_temp;//道路单双向
		int count_isDuplex = 2;
		int count_comma_roadisDuplex = 0;
		for (count_isDuplex;; count_isDuplex++)
		{
			if (temp_road[count_isDuplex] == ',')
			{
				count_comma_roadisDuplex++;
			}
			if (count_comma_roadisDuplex == 6)
			{
				int cut_count_isDuplex = count_isDuplex + 3;
				for (count_isDuplex; count_isDuplex <= cut_count_isDuplex; count_isDuplex++)
				{
					if ((temp_road[count_isDuplex] != ' ') && (temp_road[count_isDuplex] != ','))
						road_isDuplex_temp.push_back(temp_road[count_isDuplex]);
				}
				break;
			}
		}
		(road_ptr + i_road)->road_isDuplex = road_isDuplex_temp;
		//cout << (road_ptr+i_road)->road_isDuplex << endl;


		i_road++;
	}
	return count_road;
}





int read_cross(cross*cross_ptr)
{
	ifstream icin_cross;
	icin_cross.open("cross.txt");
	string temp_cross;
	int cross_count = 0;
	//cross *cross_ptr[65];// 一共65个路口
	//cross *cross_ptr = new cross[65];
	int i_cross = 0;

	while (getline(icin_cross, temp_cross, ')'))
	{
		//cout << temp_cross << endl;//读取数据，放入类型为string的temp_cross中
		//(cross_ptr+i_cross) = new cross();
		cross_count++;

		string cross_number_temp;//路口名称
		int count_crossNumber = 2;
		for (count_crossNumber; temp_cross[count_crossNumber] != ','; count_crossNumber++)
			cross_number_temp.push_back(temp_cross[count_crossNumber]);
		(cross_ptr + i_cross)->cross_number = cross_number_temp;
		//cout << (cross_ptr+i_cross)->cross_number << endl;


		string cross_roadld1_temp;//与路口相交的第一个道路号码
		int count_cross_roadld1 = 2;
		//int count_comma_cross_roadld1 = 0;

		for (count_cross_roadld1;; count_cross_roadld1++)
		{
			if (temp_cross[count_cross_roadld1] == ',')
			{
				if (temp_cross[count_cross_roadld1 + 2] == '-')
				{
					cross_roadld1_temp.push_back('-');
					cross_roadld1_temp.push_back('1');
					break;
				}
				else{
					int cut_count_cross_roadld1 = count_cross_roadld1 + 5;
					for (count_cross_roadld1; count_cross_roadld1 <= cut_count_cross_roadld1; count_cross_roadld1++)
					if ((temp_cross[count_cross_roadld1] != ' ') && (temp_cross[count_cross_roadld1] != ','))
						cross_roadld1_temp.push_back(temp_cross[count_cross_roadld1]);
					break;
				}
				break;
			}

		}
		(cross_ptr + i_cross)->cross_roadId1 = cross_roadld1_temp;
		//cout << (cross_ptr+i_cross)->cross_roadId1 << endl;



		string cross_roadld2_temp;//第二个路口信息
		int count_cross_roadld2 = 2;
		int count_comma_cross_roadld2 = 0;

		for (count_cross_roadld2;; count_cross_roadld2++)
		{
			if (temp_cross[count_cross_roadld2] == ',')
				count_comma_cross_roadld2++;
			if (count_comma_cross_roadld2 == 2)
			{
				if (temp_cross[count_cross_roadld2 + 2] == '-')
				{
					cross_roadld2_temp.push_back('-');
					cross_roadld2_temp.push_back('1');
					break;
				}
				else
				{
					int  cut_count_cross_roadld2 = count_cross_roadld2 + 5;
					for (count_cross_roadld2; count_cross_roadld2 <= cut_count_cross_roadld2; count_cross_roadld2++)
					if ((temp_cross[count_cross_roadld2] != ' ') && (temp_cross[count_cross_roadld2] != ','))
						cross_roadld2_temp.push_back(temp_cross[count_cross_roadld2]);
					break;
				}
				break;
			}
		}
		(cross_ptr + i_cross)->cross_roadId2 = cross_roadld2_temp;
		//cout << (cross_ptr+i_cross)->cross_roadId2 << endl;


		string cross_roadld3_temp;//第三个路口信息
		int count_cross_roadld3 = 2;
		int count_comma_cross_roadld3 = 0;
		for (count_cross_roadld3;; count_cross_roadld3++)
		{
			if (temp_cross[count_cross_roadld3] == ',')
				count_comma_cross_roadld3++;
			if (count_comma_cross_roadld3 == 3)
			{
				if (temp_cross[count_cross_roadld3 + 2] == '-')
				{
					cross_roadld3_temp.push_back('-');
					cross_roadld3_temp.push_back('1');
					break;
				}
				else
				{
					int cut_count_cross_roadld3 = count_cross_roadld3 + 5;
					for (count_cross_roadld3; count_cross_roadld3 <= cut_count_cross_roadld3; count_cross_roadld3++)
					if ((temp_cross[count_cross_roadld3] != ' ') && (temp_cross[count_cross_roadld3] != ','))
						cross_roadld3_temp.push_back(temp_cross[count_cross_roadld3]);
					break;
				}
				break;
			}
		}
		(cross_ptr + i_cross)->cross_roadId3 = cross_roadld3_temp;
		//cout << (cross_ptr+i_cross)->cross_roadId3 << endl;



		string cross_roadld4_temp;//第四个路口信息
		int count_cross_roadld4 = 2;
		int count_comma_cross_roadld4 = 0;
		for (count_cross_roadld4;; count_cross_roadld4++)
		{
			if (temp_cross[count_cross_roadld4] == ',')
				count_comma_cross_roadld4++;
			if (count_comma_cross_roadld4 == 4)
			{
				if (temp_cross[count_cross_roadld4 + 2] == '-')
				{
					cross_roadld4_temp.push_back('-');
					cross_roadld4_temp.push_back('1');
					break;
				}
				else
				{
					int cut_count_cross_roadld4 = count_cross_roadld4 + 5;
					for (count_cross_roadld4; count_cross_roadld4 <= cut_count_cross_roadld4; count_cross_roadld4++)
					if ((temp_cross[count_cross_roadld4] != ' ') && (temp_cross[count_cross_roadld4] != ','))
						cross_roadld4_temp.push_back(temp_cross[count_cross_roadld4]);
					break;
				}
				break;
			}
		}
		(cross_ptr + i_cross)->cross_roadId4 = cross_roadld4_temp;
		//cout << (cross_ptr+i_cross)->cross_roadId4 << endl;

		i_cross++;
	}

	//	//测试任意一条路径输出
	//	//cout << road_ptr[104]->road_number << road_ptr[30]->road_channel << endl;
	//	//cout << cross_ptr[6



	return cross_count;

}


void carInt_ptr(car *car_ptr,car_int* car_int_ptr,int a)
{
	int car_count = a;
	for (int car_int_count = 0; car_int_count < car_count - 1; car_int_count++)
	{
		(car_int_ptr + car_int_count)->car_number_int = str2int((car_ptr + car_int_count + 1)->car_number) - 10000;
		(car_int_ptr + car_int_count)->car_destination_int = str2int((car_ptr + car_int_count + 1)->car_destination);
		(car_int_ptr + car_int_count)->car_origination_int = str2int((car_ptr + car_int_count + 1)->car_origination);
		(car_int_ptr + car_int_count)->car_maxSpeed_int = str2int((car_ptr + car_int_count + 1)->car_maxSpeed);
		(car_int_ptr + car_int_count)->car_planTime_int = str2int((car_ptr + car_int_count + 1)->car_planTime);
	}

}
void roadInt_ptr(road*road_ptr,road_int * road_int_ptr, int b)
{
	int road_count = b;
	for (int road_int_count = 0; road_int_count < road_count - 1; road_int_count++)
	{
		(road_int_ptr + road_int_count)->road_number_int = str2int(((road_ptr + road_int_count + 1)->road_number)) - 5000;
		(road_int_ptr + road_int_count)->road_length_int = str2int((road_ptr + road_int_count + 1)->road_length);
		(road_int_ptr + road_int_count)->road_speed_int = str2int((road_ptr + road_int_count + 1)->road_speed);
		(road_int_ptr + road_int_count)->road_channel_int = str2int((road_ptr + road_int_count + 1)->road_channel);
		(road_int_ptr + road_int_count)->road_from_int = str2int((road_ptr + road_int_count + 1)->road_from);
		(road_int_ptr + road_int_count)->road_to_int = str2int((road_ptr + road_int_count + 1)->road_to);
		(road_int_ptr + road_int_count)->road_isDuplex_int = str2int((road_ptr + road_int_count + 1)->road_isDuplex);

	}

}

void crossInt_ptr(cross*cross_ptr,cross_int *cross_int_ptr, int c)
{

	int cross_count = c;
	for (int cross_int_count = 0; cross_int_count < cross_count - 1; cross_int_count++)
	{
		(cross_int_ptr + cross_int_count)->cross_number_int = str2int((cross_ptr + cross_int_count + 1)->cross_number);
		(cross_int_ptr + cross_int_count)->cross_roadId1_int = str2int((cross_ptr + cross_int_count + 1)->cross_roadId1);
		(cross_int_ptr + cross_int_count)->cross_roadId2_int = str2int((cross_ptr + cross_int_count + 1)->cross_roadId2);
		(cross_int_ptr + cross_int_count)->cross_roadId3_int = str2int((cross_ptr + cross_int_count + 1)->cross_roadId3);
		(cross_int_ptr + cross_int_count)->cross_roadId4_int = str2int((cross_ptr + cross_int_count + 1)->cross_roadId4);
	}

}