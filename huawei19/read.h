#ifndef READ_H
#define READ_H

#include"road.h"
#include"cross.h"
#include"car.h"
#include"road_int.h"
#include"cross_int.h"
#include"car_int.h"

int  read_car(car * car_ptr);
int read_road(road *road_ptr);
int read_cross(cross* cross_ptr);


void carInt_ptr(car *car_ptr,car_int* car_int_ptr,int a);
void roadInt_ptr(road *road_ptr,road_int * road_int_ptr,int b);
void crossInt_ptr(cross *coss_ptr,cross_int *cross_int_ptr,int c);

#endif