#pragma once
#ifndef DISPATCH_H
#define DISPATCH_H
#include<iostream>
#include<string>
#include<vector>
#include"main.h"
#include"car.h"
#include"cross.h"
#include"road.h"
#include"getdirection.h"

using namespace std;


class dispatch 
{
public:
	dispatch();
	~dispatch();

struct road1
{
	int road_id;
	int flag;
	string from_to;
};

	int cross_id;
	vector<road1> road_id;
	vector<car>* road_car_ptr1 = &road_car1;
	vector<car>* road_car_ptr2 = &road_car2;
	vector<car>* road_car_ptr3 = &road_car3;
	vector<car>* road_car_ptr4 = &road_car4;

	std::vector<car> road_car1;
	std::vector<car> road_car2;
	std::vector<car> road_car3;
	std::vector<car> road_car4;

	std::vector<int> channel;


private:
	void dispatchcar(int cross_id,std::vector<car> road_car, std::vector<car> other_road_car);
	void get_road_id(int cross_id);
	int driveAllCarJustOnRoadToEndState(road1 road_id);
	void get_car(vector<car>* road_car_ptr, int road_id);
	void get_car1(vector<car>* road_car_ptr, int road_id);
	int getChannel(car road_car);
	void moveToNextRoad(car road_car, int channel, int SV2, int S1);



};


#endif //DISPATCH