#include"matrix.h"
#include"str2int.h"


void matrix_m(vector<vector<string>> &m, road *road_ptr, cross *cross_ptr)
{

	string  write_temp[200];//�ȽϾ��� ����ʼ��
	int count_write_temp = 0;

	//string roadNumber_temp[50];
	//string crossNumber_temp[50];

	m[100][100] = (cross_ptr + 1)->cross_number;
	//cout << m[100][100] << endl;

	//auto  ptr_write_temp=write_temp.begin();

	write_temp[count_write_temp].insert(0, m[100][100]);
	count_write_temp++;//�����һ�� ��ʱΪ1

	int gain_count_write = 0;//�����������Ԫ�ظ���

	//cross����>road
	if (((cross_ptr + 1)->cross_roadId1) != "-1")
	{
		m[99][100] = (cross_ptr + 1)->cross_roadId1;
		write_temp[count_write_temp].insert(0, m[100 - 1][100]);
		count_write_temp++;
		gain_count_write++;
	}

	if ((cross_ptr + 1)->cross_roadId2 != "-1")
	{
		m[100][101] = (cross_ptr + 1)->cross_roadId2;
		write_temp[count_write_temp].insert(0, m[100][100 + 1]);
		count_write_temp++;
		gain_count_write++;
	}

	if ((cross_ptr + 1)->cross_roadId3 != "-1")
	{
		m[101][100] = (cross_ptr + 1)->cross_roadId3;
		write_temp[count_write_temp].insert(0, m[100 + 1][100]);
		count_write_temp++;
		gain_count_write++;
	}

	if ((cross_ptr + 1)->cross_roadId4 != "-1")
	{
		m[100][99] = (cross_ptr + 1)->cross_roadId4;
		write_temp[count_write_temp].insert(0, m[100][100 - 1]);
		count_write_temp++;
		gain_count_write++;
	}

	/*
	cout << m[99][100] << endl;
	cout << m[100][101] << endl;
	cout << m[101][100] << endl;
	cout << m[100][99] << endl;
	*/

	//	// cout << "gain_count_write:" << gain_count_write << endl;

	int increa_count_write = count_write_temp - gain_count_write;//�������������increa_count_write������Ԫ��2��
	int i_count_write_temp = count_write_temp;

	while (gain_count_write != 0)
	{
		gain_count_write = 0;
		//i_count_write_temp=count_write_temp,�뻺�����Ԫ�ظ���һ��

		//ѭ����������ʼ������������β�˽���

		//while(gain_count_write!0)
		//int gain_count_write=0;

		for (increa_count_write; increa_count_write < i_count_write_temp; increa_count_write++)
		{
			//cout << write_temp[increa_count_write] << endl;
			//��·���,��Ӧָ������1

			//��·��Ϣ������cross
			if (write_temp[increa_count_write].length() > 3)
			{


				//cout << "write_temp[increa_count_write].length()" << write_temp[increa_count_write].length() << endl;
				string s1_ = (road_ptr + (str2int(write_temp[increa_count_write]) - 5000 + 1))->road_to;
				//cout << s1_ << endl;
				string s2_ = (road_ptr + (str2int(write_temp[increa_count_write]) - 5000 + 1))->road_from;
				//cout << s2_ << endl;
				string s1;
				//string::size_type s1_temp;
				//string::size_type s2_temp;
				int s1_de = 1;
				int s2_de = 1;
				//ѡ��

				//cout << "count_write_temp" << count_write_temp<<endl;
				int s1_int = str2int(s1_);
				int s2_int = str2int(s2_);

				for (int count_ = 0; count_ < count_write_temp; count_++)
				{
					//�ַ���ƥ������

					int count_int = str2int(write_temp[count_]);
					int sub_s1_int = count_int - s1_int;
					int sub_s2_int = count_int - s2_int;

					if (sub_s1_int == 0)//s1���ҵ�
					{
						s1_de++;
						break;
					}
					if (sub_s2_int == 0)//s2���ҵ�
					{
						s2_de++;
						break;
					}
				}
				/*
				s1_temp = write_temp[count_].find(s1_);
				s2_temp = write_temp[count_].find(s2_);
				//�ҵ���һ����
				if ((s1_temp != s1_.npos))
				{
				//cout << "1"<<endl;
				s1_de++;
				break;
				}
				if ((s2_temp != s2_.npos))
				{
				//cout << "2" << endl;
				s2_de++;
				break;
				}
				}
				*/
				if (s1_de == 2)
				{
					s1 = s2_;
				}
				if (s2_de == 2)
				{
					s1 = s1_;
				}

				//cout << s1<<endl;
				//cout << str2int(write_temp[increa_count_write]) << endl;
				//cout << s1 << endl;
				//string::size_type write_temp_position;
				int break_signal = 0;
				//int ttt = 0;

				//���أ��¼ӵ��ǲ������ظ�
				//s1����Ҫ��ӵ�string
				int s1_pick_int = str2int(s1);

				for (int s1_count = 0; s1_count < count_write_temp; s1_count++)
				{
					/*
					//cout << "start:";
					write_temp_position = write_temp[s1_count].find(s1);
					//cout << write_temp[s1_count] << endl;

					while (write_temp_position != write_temp[s1_count].npos)
					{
					break_signal++;
					break;
					}
					*/

					int s1_count_int = str2int(write_temp[s1_count]);
					int s1_count_sub_int = s1_count_int - s1_pick_int;
					if (s1_count_sub_int == 0)
					{
						break_signal++;
						break;
					}


				}
				if (break_signal == 0)
				{
					//cout << "sdf" << endl;
					write_temp[count_write_temp].insert(0, s1);
					count_write_temp++;
					gain_count_write++;
					//�жϲ��������������m�����е�λ��
					//��������2·�ڵ���·��1��id1 �м� �мӣ��Դ˼�����m�е�λ��


					int s_1 = str2int(write_temp[increa_count_write]);
					//��·���
					//string s_2 = (road_ptr + (s_1 - 5000 + 1))->road_from;
					string s_3_string;
					if (s1_ == s1)
					{
						s_3_string = s2_;
					}
					else{
						s_3_string = s1_;
					}
					int  s_3 = str2int(s_3_string);

					//Ѱ��cross��λ��
					int write_row = 0;
					int write_col = 0;

					int i_strart = 0;
					int break_singal = 0;

					for (i_strart; i_strart < 200; i_strart++)
					{
						for (int j_strart = 0; j_strart < 200; j_strart++)
						{
							if (m[i_strart][j_strart] == (cross_ptr + s_3)->cross_number)
							{
								write_row = i_strart;
								write_col = j_strart;
								break_singal++;
								break;
							}
						}
						if (break_singal == 1)
						{
							break;
						}
					}


					//int str2int(s_1);
					string road1 = (cross_ptr + (s_3))->cross_roadId1;
					string road2 = (cross_ptr + (s_3))->cross_roadId2;
					string road3 = (cross_ptr + (s_3))->cross_roadId3;
					string road4 = (cross_ptr + (s_3))->cross_roadId4;
					if (write_temp[increa_count_write] == road1)
						m[write_row - 2][write_col] = s1;
					if (write_temp[increa_count_write] == road2)
						m[write_row][write_col + 2] = s1;
					if (write_temp[increa_count_write] == road3)
						m[write_row + 2][write_col] = s1;
					if (write_temp[increa_count_write] == road4)
						m[write_row][write_col - 2] = s1;
					//cout << "insert" << write_temp[count_write_temp-1] << endl;
				}
			}
			//	cout << "count_write_temp :" << count_write_temp << endl;
			//	cout << write_temp[count_write_temp];


			//·��ָ�룬��1��ʼ��ָ���Ӧ
			if (write_temp[increa_count_write].length() < 3)
			{
				string ss1 = (cross_ptr + (str2int(write_temp[increa_count_write])))->cross_roadId1;
				string ss2 = (cross_ptr + (str2int(write_temp[increa_count_write])))->cross_roadId2;
				string ss3 = (cross_ptr + (str2int(write_temp[increa_count_write])))->cross_roadId3;
				string ss4 = (cross_ptr + (str2int(write_temp[increa_count_write])))->cross_roadId4;

				//	cout << "ss1 ss2 ss3 ss4" << endl;
				//	cout << ss1 << endl << ss2 << endl << ss3 << endl << ss4 << endl;


				//�ж��ĸ�·���Ƿ���-1 
				if (ss1 != "-1")
				{
					//string::size_type write_temp_position1;
					int break_signal1 = 0;
					//���� crossָ���roadnumber

					int ss1_int = str2int(ss1);
					for (int ss1_count = 0; ss1_count < count_write_temp; ss1_count++)
					{

						int write_int = str2int(write_temp[ss1_count]);
						int write_sub_int = ss1_int - write_int;
						if (write_sub_int == 0)
						{
							break_signal1++;
							break;
						}


						/*
						//cout << "start:";
						write_temp_position1 = write_temp[ss1_count].find(ss1);

						while (write_temp_position1 != write_temp[ss1_count].npos)
						{
						break_signal1++;
						break;
						}
						*/
					}
					if (break_signal1 == 0)
					{
						write_temp[count_write_temp].insert(0, ss1);
						count_write_temp++;
						gain_count_write++;
						//��λ

						int write_row_ss1 = 0;
						int write_col_ss2 = 0;
						int ss1_count_i = 0;
						int break_s1 = 0;

						for (ss1_count_i; ss1_count_i < 200; ss1_count_i++)
						{
							for (int ss1_count_j = 0; ss1_count_j < 200; ss1_count_j++)
							{
								if (m[ss1_count_i][ss1_count_j] == write_temp[increa_count_write])
								{
									write_row_ss1 = ss1_count_i;
									write_col_ss2 = ss1_count_j;
									break_s1++;
									break;
								}
							}
							if (break_s1 == 1)
							{
								break;
							}
						}
						//cout << " write_temp[increa_count_write]" << "m[ss1_count_i][ss1_count_j]" << write_temp[increa_count_write] << m[ss1_count_i][ss1_count_j] << endl;
						m[write_row_ss1 - 1][write_col_ss2] = ss1;
					}
				}

				if (ss2 != "-1")
				{
					//	string::size_type write_temp_position2;
					int break_signal2 = 0;
					int ss2_int = str2int(ss2);
					//���� crossָ���roadnumber
					for (int ss2_count = 0; ss2_count < count_write_temp; ss2_count++)
					{

						int write2_int = str2int(write_temp[ss2_count]);
						int write2_sub_int = write2_int - ss2_int;
						if (write2_sub_int == 0)
						{
							break_signal2++;
							break;
						}

						/*

						//cout << "start:";
						write_temp_position2 = write_temp[ss2_count].find(ss2);

						while (write_temp_position2 != write_temp[ss2_count].npos)
						{
						break_signal2++;
						break;
						}
						*/
					}
					if (break_signal2 == 0)
					{
						write_temp[count_write_temp].insert(0, ss2);
						count_write_temp++;
						gain_count_write++;
						//��λ

						int write_row2_ss1 = 0;
						int write_col2_ss2 = 0;
						int ss1_count_i = 0;
						int break_s2 = 0;
						for (ss1_count_i; ss1_count_i < 200; ss1_count_i++)
						{
							for (int ss1_count_j = 0; ss1_count_j < 200; ss1_count_j++)
							{
								if (m[ss1_count_i][ss1_count_j] == write_temp[increa_count_write])
								{
									write_row2_ss1 = ss1_count_i;
									write_col2_ss2 = ss1_count_j;
								}
							}
							if (break_s2 == 1)
							{
								break;
							}
						}
						m[write_row2_ss1][write_col2_ss2 + 1] = ss2;
					}
				}


				if (ss3 != "-1")
				{
					//	string::size_type write_temp_position3;
					int break_signal3 = 0;
					//���� crossָ���roadnumber
					int ss3_int = str2int(ss3);
					for (int ss3_count = 0; ss3_count < count_write_temp; ss3_count++)
					{ /*
					  //cout << "start:";
					  write_temp_position3 = write_temp[ss3_count].find(ss3);

					  while (write_temp_position3 != write_temp[ss3_count].npos)
					  {
					  break_signal3++;
					  break;
					  }
					  */
						int write3_int = str2int(write_temp[ss3_count]);
						int write3_sub_int = write3_int - ss3_int;
						if (write3_sub_int == 0)
						{
							break_signal3++;
							break;
						}

					}
					if (break_signal3 == 0)
					{
						write_temp[count_write_temp].insert(0, ss3);
						count_write_temp++;
						gain_count_write++;
						//��λ
						int write_row_ss1 = 0;
						int write_col_ss2 = 0;
						int ss1_count_i = 0;
						int break_s = 0;

						for (ss1_count_i; ss1_count_i < 200; ss1_count_i++)
						{
							for (int ss1_count_j = 0; ss1_count_j < 200; ss1_count_j++)
							{
								if (m[ss1_count_i][ss1_count_j] == write_temp[increa_count_write])
								{
									write_row_ss1 = ss1_count_i;
									write_col_ss2 = ss1_count_j;

								}
							}
							if (break_s == 1)
							{
								break;
							}
						}
						m[write_row_ss1 + 1][write_col_ss2] = ss3;
					}
				}


				if (ss4 != "-1")
				{
					//	string::size_type write_temp_position4;
					int break_signal4 = 0;
					//���� crossָ���roadnumber
					int ss4_int = str2int(ss4);

					for (int ss4_count = 0; ss4_count < count_write_temp; ss4_count++)
					{


						int write4_int = str2int(write_temp[ss4_count]);
						int write4_sub_int = write4_int - ss4_int;
						if (write4_sub_int == 0)
						{
							break_signal4++;
							break;
						}
						/*
						//cout << "start:";
						write_temp_position4 = write_temp[ss4_count].find(ss4);

						while (write_temp_position4 != write_temp[ss4_count].npos)
						{
						break_signal4++;
						break;
						}*/
					}
					if (break_signal4 == 0)
					{
						write_temp[count_write_temp].insert(0, ss4);
						count_write_temp++;
						gain_count_write++;
						//��λ
						int write_row_ss1 = 0;
						int write_col_ss2 = 0;
						int ss1_count_i = 0;
						int break_s = 0;

						for (ss1_count_i; ss1_count_i < 200; ss1_count_i++)
						{
							for (int ss1_count_j = 0; ss1_count_j < 200; ss1_count_j++)
							{
								if (m[ss1_count_i][ss1_count_j] == write_temp[increa_count_write])
								{
									write_row_ss1 = ss1_count_i;
									write_col_ss2 = ss1_count_j;
									break_s++;
									break;
								}
							}
							if (break_s == 1)
							{
								break;
							}
						}
						m[write_row_ss1][write_col_ss2 - 1] = ss4;
					}//break_signal4==0
				}//ss4!=-1
			}//length<3
		}//for

		increa_count_write = count_write_temp - gain_count_write;
		i_count_write_temp = count_write_temp;


		std::cout << "for ѭ������" << endl;
	}//while
	std::cout << "while ѭ������" << endl;
	std::cout << "count_write_temp :" << count_write_temp << endl;
	for (int it = 0; it < count_write_temp; it++)
		std::cout << write_temp[it] << endl;

}



vector<vector<string>> cut_m(vector<vector<string>> m, int & add_row_count1, int & add_col_count1)
{
	/*vector<vector<string>> m(200);
	for (int i = 0; i<m.size(); i++)
		m[i].resize(200);

	for (int i = 0; i<m.size(); i++)
	{
		for (int j = 0; j<m[0].size(); j++)
		{
			m[i][j] = "0";
		}
	}
	*/
	int &add_row_count = add_row_count1;
	int &add_col_count = add_col_count1;

	int row_test = 0, col_test = 0, a_test = 100, b_test = 100;
	int break_signal = 0;
	for (a_test;;)
	{
		for (b_test;; b_test++)
		{
			if (m[a_test][b_test] != "0")
			{
				add_col_count++;
			}
			if (m[a_test][b_test] == "0")
			{
				break_signal++;
				break;

			}
		}
		if (break_signal == 1)
		{
			break;
		}

	}

	break_signal = 0;
	b_test = 100;
	a_test = 100;
	for (b_test;; b_test++)
	{
		if (m[a_test][b_test] != "0")
		{
			add_row_count++;
		}
		if (m[a_test][b_test] == "0")
		{
			break;
		}
	}

	vector<vector<string>> m_string(add_row_count);
	for (decltype(m_string.size()) i = 0; i<m_string.size(); i++)
		m_string[i].resize(add_col_count);

	for (decltype(m_string.size()) i = 0; i<m_string.size(); i++)
	{
		for (decltype(m_string[0].size()) j = 0; j< m_string[0].size(); j++)
		{
			m_string[i][j] = m[100 - i][100 + j];
		}
	}

	return m_string;


}


vector<vector<int>> m2int(vector<vector<string>> &m_string, int a, int b)
{
	int add_row_count = a;
	int add_col_count = b;

	vector<vector<int>> m_int(add_row_count);

	for (decltype(m_int.size()) i = 0; i<m_int.size(); i++)
		m_int[i].resize(add_col_count);

	for (decltype(m_int.size()) i = 0; i<m_int.size(); i++)
	{
		for (decltype(m_int[0].size()) j = 0; j<m_int[0].size(); j++)
		{
			m_int[i][j] = 0;
		}
	}//����int�;���

	int i = 0;
	for (i; i < add_row_count; i++)
	{
		for (int j = 0; j < add_col_count; j++)
		{
			m_int[i][j] = str2int(m_string[i][j]);
		}
	}
	return m_int;

}



int count_mEdge(cross* cross_ptr, road*road_ptr, vector<vector<int>>m_int, int add_row_count, int add_col_count)
{

	//���ýڵ���crossʱ ��� lu ru rd �Լ�����edge_count

	//��·ӳ�����
	int i_count_cross = 0;
	int count_cross_number = 0;

	int search_edge_i = 0, edge_count = 0;
	int a_cross[4];
	for (int i_cross_temp = 0; i_cross_temp < 4; i_cross_temp++)
		a_cross[i_cross_temp] = 0;

	int a_cross_position[4];
	for (int j_cross_temp = 0; j_cross_temp < 4; j_cross_temp++)
		a_cross_position[j_cross_temp] = -1;


	//vector<string> temp[4];
	/*for (int string_int = 0; string_int < 4; string_int++)
	{
	temp[string_int] = 1011;
	}*/

	string temp1, temp2, temp3, temp4;
	int i_temp = 0;
	int i_count_road1 = 0;
	int i_count_roadSum = 0;


	//��ȡ��·���� edge_count
	for (search_edge_i; search_edge_i < add_row_count; search_edge_i++)
	{
		for (int search_edge_j = 0; search_edge_j < add_col_count; search_edge_j++)
		{
			if (m_int[search_edge_i][search_edge_j]>100)
			{
				edge_count++;
			}

			//���ýڵ���crossʱ ��� lu ru rd ld
			//lu ru rd ld
			if ((m_int[search_edge_i][search_edge_j] < 100) && (m_int[search_edge_i][search_edge_j]) != 0)
			{
				i_count_cross++;
				i_count_road1 = 0;

				temp1 = (cross_ptr + m_int[search_edge_i][search_edge_j])->cross_roadId1;
				temp2 = (cross_ptr + m_int[search_edge_i][search_edge_j])->cross_roadId2;
				temp3 = (cross_ptr + m_int[search_edge_i][search_edge_j])->cross_roadId3;
				temp4 = (cross_ptr + m_int[search_edge_i][search_edge_j])->cross_roadId4;

				a_cross[0] = str2int(temp1);
				a_cross[1] = str2int(temp2);
				a_cross[2] = str2int(temp3);
				a_cross[3] = str2int(temp4);

				for (i_count_road1; i_count_road1 < 4; i_count_road1++)
				{
					if (a_cross[i_count_road1]>0)
					{
						a_cross_position[i_count_road1] = 0;
						i_count_roadSum++;
					}
				}
				if (i_count_roadSum == 2)
				{
					if ((a_cross_position[0] == 0 && a_cross_position[2] == 0) || (a_cross_position[1] == 0 && a_cross_position[3] == 0))
					{
						if (a_cross_position[0] == 0)
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
						}
						if ((a_cross_position[1] == 0))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;

						}
					}//�Խ��ϵ����

					if (a_cross_position[0] == 0)
					{
						if (a_cross_position[1] == 0)
						{
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)>str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
							}
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)<str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
							}
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)==str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 5;
							}

							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 0;
						}
						if (a_cross_position[3] == 0)
						{
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)>str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
							}
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)<str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
							}
							if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 5;
							}

							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 0;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
						}
					}//0����



					if (a_cross_position[2] == 0)
					{
						if (a_cross_position[1] == 0)
						{
							if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length)>str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
								{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
								}
							if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length)<str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
							    {
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
								}
							if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length)==str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
							   {
								(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 5;
								}
						//(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 0;
						}
						if (a_cross_position[3] == 0)
						{
							if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length)>str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
							}
							if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length)<str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
							}
							if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
							{
								(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 5;
							}
							//(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 0;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
						}
					}
				}

				if (i_count_roadSum == 3)
				{
					if (a_cross_position[0] != 0)
					{
						(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
						(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) >str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
						}
						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
						}
						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 5;
						}

						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) >str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
						}
						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) <str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
						}
						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) >str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 5;
						}
					}
					if (a_cross_position[1] != 0)
					{
						(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
						(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) >str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) <str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length)==str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 5;
						}

						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) >str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
						}
						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
						}
						if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 5;
						}
					}

					if (a_cross_position[2] != 0)
					{
						(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
						(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 5;
						}

						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 5;
						}
					}

					if (a_cross_position[3] != 0)
					{
						(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
						(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
						}
						if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 5;
						}


						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
						}
						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
						}
						if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
						{
							(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 5;
						}
					}

				}

			}
			if (i_count_roadSum == 4)
			{
				if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 2;
				}
				if(str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u = 1;
				}
				if(str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) ==str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_u =5;
				}

				if(str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 3;
				}
				if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 2;
				}
				if (str2int((road_ptr + a_cross[1] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->r_d = 5;
				}

				if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 4;
				}
				if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 3;
				}
				if (str2int((road_ptr + a_cross[2] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_d = 5;
				}

				if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) > str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 4;
				}
				if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) < str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 1;
				}
				if (str2int((road_ptr + a_cross[0] - 5000 + 1)->road_length) == str2int((road_ptr + a_cross[3] - 5000 + 1)->road_length))
				{
					(cross_ptr + m_int[search_edge_i][search_edge_j])->l_u = 5;
				}
			}
		}//
	 }
	
	return edge_count;
}




void road_array(vector<vector<int>> m_int,road* road_ptr, cross*cross_ptr, int**** A, int add_row_count, int add_col_count)
{

	int channel = 0;
	int isDuplex = 0;
	int speed = 0;
	int leng = 0;

	int mi_int_map = 0;
	int i_copy = 0;//edge_count�ı仯
	int * i_receive;

	int crossFrom_position = 0;
	int crossTo_position = 0;

	for (mi_int_map; mi_int_map < add_row_count; mi_int_map++)
	{
		for (int mj_int_map = 0; mj_int_map < add_col_count; mj_int_map++)
		{
			
			if (m_int[mi_int_map][mj_int_map]>100)
			{
				channel = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_channel);
				isDuplex = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_isDuplex);
				speed = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_speed);
				leng = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_length);
				i_receive = &A[i_copy][0][0][0];
				//����·���󣬲�����ֵΪ0
				((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1)))->make_matr(i_receive, channel, isDuplex, speed, leng);

				//��ֵcross��ָ�뺯��
				if (isDuplex == 1)
				{
					//crossFrom_position = 0;
					//crossTo_position = 0;
					//�ж�·��·�ڵ�λ��
					///�ȷ�������·�ڵ�λ��
					crossFrom_position = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_from);
					crossTo_position = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_to);

					//�ж�cross�Ƿ��ڱ߱�
					if ((mi_int_map == 0) || (mi_int_map == add_row_count - 1))//������λ����ĩβ
					{
						if ((m_int[mi_int_map][mj_int_map - 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}
						if ((m_int[mi_int_map][mj_int_map + 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);

						}

					}
					if ((mj_int_map == 0) || (mj_int_map == add_col_count - 1))//������λ����ĩβ
					{
						if ((m_int[mi_int_map - 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}
						if ((m_int[mi_int_map + 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}

					}
					//�������
					if ((mi_int_map != 0) && (mi_int_map != add_row_count - 1) && (mj_int_map != 0) && (mj_int_map != add_col_count - 1))
					{
						if ((m_int[mi_int_map - 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}
						if ((m_int[mi_int_map + 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}

						if ((m_int[mi_int_map][mj_int_map - 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);
						}
						if ((m_int[mi_int_map][mj_int_map + 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
							((cross_ptr + crossTo_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->to);

						}
					}


				}
				else//���е�
				{
					crossFrom_position = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_from);
					crossTo_position = str2int((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->road_to);

					if ((mi_int_map == 0) || (mi_int_map == add_row_count - 1))//������λ����ĩβ
					{
						if ((m_int[mi_int_map][mj_int_map - 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
						}
						if ((m_int[mi_int_map][mj_int_map + 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
						}
					}
					if ((mj_int_map == 0) || (mj_int_map == add_col_count - 1))//������λ����ĩβ
					{
						if ((m_int[mi_int_map - 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
						}
						if ((m_int[mi_int_map + 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);

						}

					}
					if ((mi_int_map != 0) && (mi_int_map != add_row_count - 1) && (mj_int_map != 0) && (mj_int_map != add_col_count - 1))
					{
						if ((m_int[mi_int_map - 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_down) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);

						}
						if ((m_int[mi_int_map + 1][mj_int_map]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_up) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);

						}

						if ((m_int[mi_int_map][mj_int_map - 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_right) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);

						}
						if ((m_int[mi_int_map][mj_int_map + 1]) == crossFrom_position)
						{
							((cross_ptr + crossFrom_position)->cross_left) = ((road_ptr + (m_int[mi_int_map][mj_int_map] - 5000 + 1))->from);
						}
					}
				}
				i_copy++;
			}
		}
	}




}





