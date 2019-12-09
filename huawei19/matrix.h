#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<string>
#include<vector>
#include"car.h"
#include"cross.h"
#include"read.h"

void matrix_m(vector<vector<string>> &m, road *road_ptr, cross *cross_ptr);
vector<vector<string>> cut_m(vector<vector<string>> m,int &a,int& b);

vector<vector<int>> m2int(vector<vector<string>> &m_string,int a,int b);
int count_mEdge(cross* cross_ptr, road*road_ptr, vector<vector<int>>m_int, int add_row_count,int add_col_count);
void road_array(vector<vector<int>> m_int,road* road_ptr, cross*cross_ptr, int**** A, int add_row_count, int add_col_count);


#endif