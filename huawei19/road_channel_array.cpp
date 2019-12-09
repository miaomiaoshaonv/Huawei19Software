#include<iostream>
#include<string>
#include"road.h"
#include"str2int.h"
using namespace std;


int ** road_channel_array(string a, string b)
{

	int a_array = str2int(a);
	int b_array = str2int(b);
	
	//cout << "a_array:" << a_array << endl;
	//cout << "b_array:" << b_array<<endl;


	int **A;
	A = new int*[a_array];
	int i = 0;
	for (i; i < a_array; i++)
	{
		A[i] = new int[b_array];
	}   

	int i_count = 0;
	for (i_count; i_count < a_array; i_count++)
	{
		for (int j_count = 0; j_count < b_array; j_count++)
			A[i_count][j_count] = 0;
	}
		
	return A;

}
