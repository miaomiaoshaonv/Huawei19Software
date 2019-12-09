
#ifndef MAIN_H
#define MAIN_H

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
#include"road_int.h"
using namespace std;

road_int *road_int_ptr = new road_int[106];
cross_int *cross_int_ptr = new cross_int[64];
car_int *car_int_ptr = new car_int[10450];

road *road_ptr = new road[106];
car *car_ptr = new car[10250];
cross *cross_ptr = new cross[65];
#endif  
