#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include"car.h"
#include"road.h"
#include"cross.h"
#include"str2int.h"

#include"car_int.h"
#include"cross_int.h"
#include"road_int.h"
#include"read.h"
#include"matrix.h"


#include<vector>

using namespace std;
//car *car_ptr[10240];
//road *road_ptr[106];
//cross *cross_ptr[65];

int main()
{
	//读取车辆信息 car_ptr
	car *car_ptr = new car[10250];
	int car_count=read_car(car_ptr);
	//读取road信息 road_ptr
	road *road_ptr = new road[106];
	int road_count = read_road(road_ptr);
	//读取路口信息 cross_ptr
	cross *cross_ptr = new cross[65];
	int cross_count = read_cross(cross_ptr);


	//创建地图矩阵m(string 类型)
	vector<vector<string>> m(200);
	for (decltype(m.size()) i = 0; i<m.size(); i++)
		m[i].resize(200);

	for (decltype(m.size()) i = 0; i<m.size(); i++)
	{
		for (decltype(m[0].size()) j = 0; j<m[0].size(); j++)
		{
			m[i][j] = "0";
		}
	}
	matrix_m(m,road_ptr,cross_ptr);

	//自适应截取矩阵m_string
	int add_row_count = 0;
	int add_col_count =0;
	vector<vector<string>> m_string = cut_m(m, add_row_count, add_col_count);

	//int类型m_int矩阵
	vector<vector<int>> m_int = m2int(m_string, add_row_count, add_col_count);

	//car road cross数据     car_int_ptr   roadInt_ptr   crossInt_ptr
		car_int *car_int_ptr = new car_int[10450];
		carInt_ptr(car_ptr,car_int_ptr,car_count);//从0开始 对应10000

		road_int *road_int_ptr = new road_int[106];
		roadInt_ptr(road_ptr,road_int_ptr,road_count);//从0开始 对应5000

		cross_int *cross_int_ptr = new cross_int[64];
		crossInt_ptr(cross_ptr,cross_int_ptr,cross_count);//0对应路口1；

		//cout << (car_int_ptr + 1)->car_number_int<< endl;

		//计算边的条数  添加 lu ru rd
		int edge_count=count_mEdge(cross_ptr, road_ptr, m_int, add_row_count, add_col_count);



	//道路映射矩阵 4维 edge_count，2，10，20
	//四维地图矩阵
			int A_i = 0;
			int ****A = new int ***[edge_count];
			for (A_i = 0; A_i < edge_count; A_i++)
			{
				A[A_i] = new int**[2];
				for (int A_j = 0; A_j < 2; A_j++)
				{
					A[A_i][A_j] = new int *[10];
					for (int A_k = 0; A_k < 10; A_k++)
					{
						A[A_i][A_j][A_k] = new int[25];
					}
				}
			}

			int k_count_i = 0;
			for (k_count_i; k_count_i < edge_count; k_count_i++)
			{
				for (int k_count_j = 0; k_count_j < 2; k_count_j++)
				{
					for (int k_count_k = 0; k_count_k < 10; k_count_k++)
					{

						for (int k_count_m = 0; k_count_m < 20; k_count_m++)
						{
							A[k_count_i][k_count_j][k_count_k][k_count_m] = -1;
						}
					}
				}
			}
			/*cout << A[0][0][0][0] << endl;
			cout << &A[0][0][0][0] << endl;
			cout << &A[0][0][0][1] << endl; */
			//构造road_array,构建道路矩阵 10X20
			road_array(m_int,road_ptr,cross_ptr,A, add_row_count, add_col_count);
		//使用car_array来索引车辆标号
		//cout << "car_count" << car_count;//car从10000开始  car_ptr[1]->10000(第一辆车)
		int *car_array = new int[car_count-1];
		for (int car_index = 0; car_index < car_count - 1; car_index++)
		{
			car_array[car_index] = str2int((car_ptr + car_index+1)->car_number)-10000+1;
		}
		//car_array[0]=1表示的是车辆序号为10000的车

		//车辆调度

		/*
		
		1、每走一个事件片 道路信息刷新

		for(时间片)
		

		//判断car_array（神奇车库）是否为空

		(拿出来车就将元素置位0)

		if(将车放在路上)
		  搜寻车号，将car_array[]置位为0；

		int i_array_count=0;
		for(int i_count_car_array=0;i_count_car_array<car_count - 1;i_count_car_array++)
		 if（car_array[i_count_car_array]！=0）
		 {
			i_array_count++;
		 }
		 //

		car刷新//1 状态（是否出入口） 2下一时间片的速度  3如果到路口，转向？
		{
		1、if加新车到道路上来
			{

			}

		2、移动后 原位置0 新位置 置位为车辆号码car_array[0]=1开始
		
		3、
		
		}

		road_frash(road_ptr,)road刷新

		*/
		delete[]car_int_ptr;
		delete[]road_int_ptr;
		delete[]cross_int_ptr;
		delete car_array;
		delete[]A;
        delete[] car_ptr;
		delete[] road_ptr;
		delete[] cross_ptr;

    //    system("pause");
		return 0;


}