#pragma once
#ifndef CAR_H
#define CAR_H
#include<iostream>
#include<string>
#include"road.h"

using namespace std;

class car
{
public:
	string car_number;
	string car_origination;
	string car_destination;
	string car_maxSpeed;
	string car_planTime;

	int car_curSpeed = 0;
	int car_turn = 0;
	int car_nextRoad = 0;

	//��һʱ���ܲ��ܹ�·�ڵı�־
	int isend = 0;
	int iswait = 0;


	vector<string> pass_road;//������·��

	void cur_car_state(road *road_ptr);
}
;

int*  car_str2int(car *car_ptr,int i );
int getMinspeed(int a, int b, int c);


#endif