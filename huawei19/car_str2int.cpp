#include<iostream>
#include<string>
#include"car.h"
#include"str2int.h"

using namespace std;

int* car_str2int(car *car_ptr,int count)
{
	
	int *car_int = new int[count];
	int i = 1;
	for (i; i < count; i++)
		car_int[i-1]=str2int((car_ptr + i)->car_number)-10000;

  return car_int; 
}