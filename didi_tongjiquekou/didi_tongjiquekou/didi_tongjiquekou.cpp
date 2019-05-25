// didi_tongjiquekou.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//统计一天中每个时间片的所有区域的缺口，看变化，证明与星期几，时间片，区域相关。
void tongjiquekou(string str1, string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int num[5];
	int count[145] = {0};
	while (!in.eof())
	{
		in >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
		count[num[1]] += num[4];
	}
	for (int i = 1; i < 145; i++)
	{
		out << count[i] << endl;
	}
	in.close();
	out.close();
}

void tongjiquekou_area(string str1, string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int num[5];
	int count[145] = { 0 };
	while (!in.eof())
	{
		in >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
		count[num[1]] += num[4];
	}
	for (int i = 1; i < 145; i++)
	{
		out << count[i] << endl;
	}
	in.close();
	out.close();
}
//训练数据（工作日）的整合，一行为1、i、j、三个天气、四个拥堵、一个缺口标签
void trainzhenghe(string str1, string str2,string str3,string str4)
{
	ifstream in_ij(str1);
	ifstream in_weather(str2);
	ifstream in_yongdu(str3);
	ofstream out(str4);
	int ij[6] = { 0 };
	int ij_num[67][145] = { 0 };
	int ij_num_demand[67][145] = { 0 };
	int ij_num_supply[67][145] = { 0 };
	int wea[5] = { 0 };
	int weather[145][4] = { 0 };
	int yong[7] = { 0 };
	int yongdu[67][145][5] = { 0 };

	int tongjijieguo[67][145][10] = { 0 };
	while (!in_ij.eof())
	{
		in_ij >> ij[1] >> ij[2] >> ij[3] >> ij[4] >> ij[5];
		ij_num[ij[1]][ij[2]] = ij[5];
		 ij_num_demand[ij[1]][ij[2]] = ij[3];
		 ij_num_supply[ij[1]][ij[2]] = ij[4];
		
	}
	while (!in_weather.eof())
	{
		in_weather >> wea[1] >> wea[2] >> wea[3] >> wea[4];
		weather[wea[1]][1] = wea[2];
		weather[wea[1]][2] = wea[3];
		weather[wea[1]][3] = wea[4];
	

	}
	while (!in_yongdu.eof())
	{
		in_yongdu >> yong[1] >> yong[2] >> yong[3] >> yong[4] >> yong[5] >> yong[6];
		 yongdu[yong[1]][yong[2]][1] = yong[3];
		 yongdu[yong[1]][yong[2]][2] = yong[4];
		 yongdu[yong[1]][yong[2]][3] = yong[5];
		 yongdu[yong[1]][yong[2]][4] = yong[6];
	}
	for (int i = 1; i < 67; i++)
	{
		for (int j = 1; j < 145; j++)
		{
			double gailv=0 ;
			if (ij_num_demand[i][j] != 0)
			{
				gailv =double( ij_num[i][j]) / (ij_num_demand[i][j]);
			}


				out << 1 << " " << i << " " << j << " " << weather[j][1] << " " << weather[j][2] << " " << weather[j][3] << " " << yongdu[i][j][1] << " " << yongdu[i][j][2] << " " << yongdu[i][j][3] << " " << yongdu[i][j][4] << " "
					<< ij_num_demand[i][j] << " " << ij_num_supply[i][j] << " " << ij_num[i][j] << " " << gailv << endl;
			
		}
	}


	in_ij.close();
	in_weather.close();
	in_yongdu.close();
	out.close();
}
//节日的整合
void trainzhenghe_jieri(string str1, string str2, string str3, string str4)
{
	ifstream in_ij(str1);
	ifstream in_weather(str2);
	ifstream in_yongdu(str3);
	ofstream out(str4);
	int ij[6] = { 0 };
	int ij_num[67][145] = { 0 };

	int ij_num_demand[67][145] = { 0 };
	int ij_num_supply[67][145] = { 0 };
	int wea[5] = { 0 };
	int weather[145][4] = { 0 };
	int yong[7] = { 0 };
	int yongdu[67][145][5] = { 0 };

	int tongjijieguo[67][145][10] = { 0 };
	while (!in_ij.eof())
	{
		in_ij >> ij[1] >> ij[2] >> ij[3] >> ij[4] >> ij[5];
		ij_num[ij[1]][ij[2]] = ij[5];
		ij_num_demand[ij[1]][ij[2]] = ij[3];
		ij_num_supply[ij[1]][ij[2]] = ij[4];

	}
	while (!in_weather.eof())
	{
		in_weather >> wea[1] >> wea[2] >> wea[3] >> wea[4];
		weather[wea[1]][1] = wea[2];
		weather[wea[1]][2] = wea[3];
		weather[wea[1]][3] = wea[4];


	}
	while (!in_yongdu.eof())
	{
		in_yongdu >> yong[1] >> yong[2] >> yong[3] >> yong[4] >> yong[5] >> yong[6];
		yongdu[yong[1]][yong[2]][1] = yong[3];
		yongdu[yong[1]][yong[2]][2] = yong[4];
		yongdu[yong[1]][yong[2]][3] = yong[5];
		yongdu[yong[1]][yong[2]][4] = yong[6];
	}
	for (int i = 1; i < 67; i++)
	{
		for (int j = 1; j < 145; j++)
		{
			double gailv ;
			if (ij_num_demand[i][j] == 0)
				gailv = 0;
			else
				gailv = double(ij_num[i][j]) / ij_num_demand[i][j];
			out << 0 << " " << i << " " << j << " " << weather[j][1] << " " << weather[j][2] << " " << weather[j][3] << " " << yongdu[i][j][1] << " " << yongdu[i][j][2] << " " << yongdu[i][j][3] << " " << yongdu[i][j][4] << " "
				<< ij_num_demand[i][j] << " " << ij_num_supply[i][j] << " " << ij_num[i][j] << " " << gailv << endl;
		}
	}


	in_ij.close();
	in_weather.close();
	in_yongdu.close();
	out.close();
}

//测试数据的整合工作日
void testzhenghe_gongzuo( string str2, string str3, string str4)
{
	
	ifstream in_weather(str2);
	ifstream in_yongdu(str3);
	ofstream out(str4);

	int wea[5] = { 0 };
	int weather[145][4] = { 0 };
	int yong[7] = { 0 };
	int yongdu[67][145][5] = { 0 };

	int tongjijieguo[67][145][10] = { 0 };
	
	while (!in_weather.eof())
	{
		in_weather >> wea[1] >> wea[2] >> wea[3] >> wea[4];
		weather[wea[1]][1] = wea[2];
		weather[wea[1]][2] = wea[3];
		weather[wea[1]][3] = wea[4];


	}
	while (!in_yongdu.eof())
	{
		in_yongdu >> yong[1] >> yong[2] >> yong[3] >> yong[4] >> yong[5] >> yong[6];
		yongdu[yong[1]][yong[2]][1] = yong[3];
		yongdu[yong[1]][yong[2]][2] = yong[4];
		yongdu[yong[1]][yong[2]][3] = yong[5];
		yongdu[yong[1]][yong[2]][4] = yong[6];
	}

	for (int j = 1; j < 145; j++)
	{
		for (int i = 1; i < 67; i++)
		{
			if (weather[j][1]&&j!=46 )
			{
				out << 1 << " " << i << " " << j << " " << weather[j][1] << " " << weather[j][2] << " " << weather[j][3] << " " << yongdu[i][j][1] << " " << yongdu[i][j][2] << " " << yongdu[i][j][3] << " " << yongdu[i][j][4] << endl;

			}
		}
	}



	in_weather.close();
	in_yongdu.close();
	out.close();
}
//测试的整合 休息日
void testzhenghe_xiuxi(string str2, string str3, string str4)
{

	ifstream in_weather(str2);
	ifstream in_yongdu(str3);
	ofstream out(str4);

	int wea[5] = { 0 };
	int weather[145][4] = { 0 };
	int yong[7] = { 0 };
	int yongdu[67][145][5] = { 0 };

	int tongjijieguo[67][145][10] = { 0 };

	while (!in_weather.eof())
	{
		in_weather >> wea[1] >> wea[2] >> wea[3] >> wea[4];
		weather[wea[1]][1] = wea[2];
		weather[wea[1]][2] = wea[3];
		weather[wea[1]][3] = wea[4];


	}
	while (!in_yongdu.eof())
	{
		in_yongdu >> yong[1] >> yong[2] >> yong[3] >> yong[4] >> yong[5] >> yong[6];
		yongdu[yong[1]][yong[2]][1] = yong[3];
		yongdu[yong[1]][yong[2]][2] = yong[4];
		yongdu[yong[1]][yong[2]][3] = yong[5];
		yongdu[yong[1]][yong[2]][4] = yong[6];
	}
	for (int j = 1; j < 145; j++)
	
	{
		for (int i = 1; i < 67; i++)
		{
			if (weather[j][1] )
				out << 0 << " " << i << " " << j << " " << weather[j][1] << " " << weather[j][2] << " " << weather[j][3] << " " << yongdu[i][j][1] << " " << yongdu[i][j][2] << " " << yongdu[i][j][3] << " " << yongdu[i][j][4] << endl;
		}
	}



	in_weather.close();
	in_yongdu.close();
	out.close();
}


//测试的拥堵值给了前三个时间，取最近的当做第四个时间的
void traffic3he1(string str1, string str2)
{
	ifstream in(str1);
	ofstream out(str2);
	int yongdu[67][145][5] = { 0 };
	
	int yong[7] = { 0 };
	while (!in.eof())
	{
		in >> yong[1] >> yong[2] >> yong[3] >> yong[4] >> yong[5] >> yong[6];
		yongdu[yong[1]][yong[2]][1] = yong[3];
		yongdu[yong[1]][yong[2]][2] = yong[4];
		yongdu[yong[1]][yong[2]][3] = yong[5];
		yongdu[yong[1]][yong[2]][4] = yong[6];
	}
	for (int i = 1; i < 67; i++)
	{
		//46
		if (yongdu[i][45][1] && yongdu[i][45][2] && yongdu[i][45][3] && yongdu[i][45][4])
		{
			yongdu[i][46][1] = yongdu[i][45][1];
			yongdu[i][46][2] = yongdu[i][45][2];
			yongdu[i][46][3] = yongdu[i][45][3];
			yongdu[i][46][4] = yongdu[i][45][4];
		}
		else if (yongdu[i][44][1] && yongdu[i][44][2] && yongdu[i][44][3] && yongdu[i][44][4])
		{
			yongdu[i][46][1] = yongdu[i][44][1];
			yongdu[i][46][2] = yongdu[i][44][2];
			yongdu[i][46][3] = yongdu[i][44][3];
			yongdu[i][46][4] = yongdu[i][44][4];
		}
		else 
		{
			yongdu[i][46][1] = yongdu[i][43][1];
			yongdu[i][46][2] = yongdu[i][43][2];
			yongdu[i][46][3] = yongdu[i][43][3];
			yongdu[i][46][4] = yongdu[i][43][4];
		}

		//58
		if (yongdu[i][57][1] && yongdu[i][57][2] && yongdu[i][57][3] && yongdu[i][57][4])
		{
			yongdu[i][58][1] = yongdu[i][57][1];
			yongdu[i][58][2] = yongdu[i][57][2];
			yongdu[i][58][3] = yongdu[i][57][3];
			yongdu[i][58][4] = yongdu[i][57][4];
		}
		else if (yongdu[i][56][1] && yongdu[i][56][2] && yongdu[i][56][3] && yongdu[i][56][4])
		{
			yongdu[i][58][1] = yongdu[i][56][1];
			yongdu[i][58][2] = yongdu[i][56][2];
			yongdu[i][58][3] = yongdu[i][56][3];
			yongdu[i][58][4] = yongdu[i][56][4];
		}
		else
		{
			yongdu[i][58][1] = yongdu[i][55][1];
			yongdu[i][58][2] = yongdu[i][55][2];
			yongdu[i][58][3] = yongdu[i][55][3];
			yongdu[i][58][4] = yongdu[i][55][4];
		}
		//70
		if (yongdu[i][69][1] && yongdu[i][69][2] && yongdu[i][69][3] && yongdu[i][69][4])
		{
			yongdu[i][70][1] = yongdu[i][69][1];
			yongdu[i][70][2] = yongdu[i][69][2];
			yongdu[i][70][3] = yongdu[i][69][3];
			yongdu[i][70][4] = yongdu[i][69][4];
		}
		else if (yongdu[i][68][1] && yongdu[i][68][2] && yongdu[i][68][3] && yongdu[i][68][4])
		{
			yongdu[i][70][1] = yongdu[i][68][1];
			yongdu[i][70][2] = yongdu[i][68][2];
			yongdu[i][70][3] = yongdu[i][68][3];
			yongdu[i][70][4] = yongdu[i][68][4];
		}
		else
		{
			yongdu[i][70][1] = yongdu[i][67][1];
			yongdu[i][70][2] = yongdu[i][67][2];
			yongdu[i][70][3] = yongdu[i][67][3];
			yongdu[i][70][4] = yongdu[i][67][4];
		}
		//82
		if (yongdu[i][81][1] && yongdu[i][81][2] && yongdu[i][81][3] && yongdu[i][81][4])
		{
			yongdu[i][82][1] = yongdu[i][81][1];
			yongdu[i][82][2] = yongdu[i][81][2];
			yongdu[i][82][3] = yongdu[i][81][3];
			yongdu[i][82][4] = yongdu[i][81][4];
		}
		else if (yongdu[i][80][1] && yongdu[i][80][2] && yongdu[i][80][3] && yongdu[i][80][4])
		{
			yongdu[i][82][1] = yongdu[i][80][1];
			yongdu[i][82][2] = yongdu[i][80][2];
			yongdu[i][82][3] = yongdu[i][80][3];
			yongdu[i][82][4] = yongdu[i][80][4];
		}
		else
		{
			yongdu[i][82][1] = yongdu[i][79][1];
			yongdu[i][82][2] = yongdu[i][79][2];
			yongdu[i][82][3] = yongdu[i][79][3];
			yongdu[i][82][4] = yongdu[i][79][4];
		}
		//94
		if (yongdu[i][93][1] && yongdu[i][93][2] && yongdu[i][93][3] && yongdu[i][93][4])
		{
			yongdu[i][94][1] = yongdu[i][93][1];
			yongdu[i][94][2] = yongdu[i][93][2];
			yongdu[i][94][3] = yongdu[i][93][3];
			yongdu[i][94][4] = yongdu[i][93][4];
		}
		else if (yongdu[i][92][1] && yongdu[i][92][2] && yongdu[i][92][3] && yongdu[i][92][4])
		{
			yongdu[i][94][1] = yongdu[i][92][1];
			yongdu[i][94][2] = yongdu[i][92][2];
			yongdu[i][94][3] = yongdu[i][92][3];
			yongdu[i][94][4] = yongdu[i][92][4];
		}
		else
		{
			yongdu[i][94][1] = yongdu[i][91][1];
			yongdu[i][94][2] = yongdu[i][91][2];
			yongdu[i][94][3] = yongdu[i][91][3];
			yongdu[i][94][4] = yongdu[i][91][4];
		}
		//106
		if (yongdu[i][105][1] && yongdu[i][105][2] && yongdu[i][105][3] && yongdu[i][105][4])
		{
			yongdu[i][106][1] = yongdu[i][105][1];
			yongdu[i][106][2] = yongdu[i][105][2];
			yongdu[i][106][3] = yongdu[i][105][3];
			yongdu[i][106][4] = yongdu[i][105][4];
		}
		else if (yongdu[i][104][1] && yongdu[i][104][2] && yongdu[i][104][3] && yongdu[i][104][4])
		{
			yongdu[i][106][1] = yongdu[i][104][1];
			yongdu[i][106][2] = yongdu[i][104][2];
			yongdu[i][106][3] = yongdu[i][104][3];
			yongdu[i][106][4] = yongdu[i][104][4];
		}
		else
		{
			yongdu[i][106][1] = yongdu[i][103][1];
			yongdu[i][106][2] = yongdu[i][103][2];
			yongdu[i][106][3] = yongdu[i][103][3];
			yongdu[i][106][4] = yongdu[i][103][4];
		}
		//118
		if (yongdu[i][117][1] && yongdu[i][117][2] && yongdu[i][117][3] && yongdu[i][117][4])
		{
			yongdu[i][118][1] = yongdu[i][117][1];
			yongdu[i][118][2] = yongdu[i][117][2];
			yongdu[i][118][3] = yongdu[i][117][3];
			yongdu[i][118][4] = yongdu[i][117][4];
		}
		else if (yongdu[i][116][1] && yongdu[i][116][2] && yongdu[i][116][3] && yongdu[i][116][4])
		{
			yongdu[i][118][1] = yongdu[i][116][1];
			yongdu[i][118][2] = yongdu[i][116][2];
			yongdu[i][118][3] = yongdu[i][116][3];
			yongdu[i][118][4] = yongdu[i][116][4];
		}
		else
		{
			yongdu[i][118][1] = yongdu[i][115][1];
			yongdu[i][118][2] = yongdu[i][115][2];
			yongdu[i][118][3] = yongdu[i][115][3];
			yongdu[i][118][4] = yongdu[i][115][4];
		}
		//130
		if (yongdu[i][129][1] && yongdu[i][129][2] && yongdu[i][129][3] && yongdu[i][129][4])
		{
			yongdu[i][130][1] = yongdu[i][129][1];
			yongdu[i][130][2] = yongdu[i][129][2];
			yongdu[i][130][3] = yongdu[i][129][3];
			yongdu[i][130][4] = yongdu[i][129][4];
		}
		else if (yongdu[i][128][1] && yongdu[i][128][2] && yongdu[i][128][3] && yongdu[i][128][4])
		{
			yongdu[i][130][1] = yongdu[i][128][1];
			yongdu[i][130][2] = yongdu[i][128][2];
			yongdu[i][130][3] = yongdu[i][128][3];
			yongdu[i][130][4] = yongdu[i][128][4];
		}
		else
		{
			yongdu[i][130][1] = yongdu[i][127][1];
			yongdu[i][130][2] = yongdu[i][127][2];
			yongdu[i][130][3] = yongdu[i][127][3];
			yongdu[i][130][4] = yongdu[i][127][4];
		}
		//142
		if (yongdu[i][141][1] && yongdu[i][141][2] && yongdu[i][141][3] && yongdu[i][141][4])
		{
			yongdu[i][142][1] = yongdu[i][141][1];
			yongdu[i][142][2] = yongdu[i][141][2];
			yongdu[i][142][3] = yongdu[i][141][3];
			yongdu[i][142][4] = yongdu[i][141][4];
		}
		else if (yongdu[i][140][1] && yongdu[i][140][2] && yongdu[i][140][3] && yongdu[i][140][4])
		{
			yongdu[i][142][1] = yongdu[i][140][1];
			yongdu[i][142][2] = yongdu[i][140][2];
			yongdu[i][142][3] = yongdu[i][140][3];
			yongdu[i][142][4] = yongdu[i][140][4];
		}
		else
		{
			yongdu[i][142][1] = yongdu[i][139][1];
			yongdu[i][142][2] = yongdu[i][139][2];
			yongdu[i][142][3] = yongdu[i][139][3];
			yongdu[i][142][4] = yongdu[i][139][4];
		}


	}

	int timedian[9] = {46,58,70,82,94,106,118,130,142};
	for (int i = 1; i < 67; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			out << i << " " << timedian[j] << " " << yongdu[i][timedian[j]][1] << " " << yongdu[i][timedian[j]][2]
				<< " " << yongdu[i][timedian[j]][3] << " " << yongdu[i][timedian[j]][4] << endl;
		}
		
	}
	in.close();
	out.close();
}

void testdemand(string str1,string str2,string str3, string str4)
{
	ifstream in(str1);
	ofstream out(str2);
	double demand[67][145] = { 0 };

	int de[6] = { 0 };
	while (!in.eof())
	{
		in >> de[1] >> de[2] >> de[3] >> de[4] >> de[5] ;
		demand[de[1]][de[2]] = de[3];
	}

	ifstream in8(str3);
	ifstream in15(str4);
	double demand8[67][145] = { 0 };

	int de8[6] = { 0 };
	while (!in8.eof())
	{
		in8 >> de8[1] >> de8[2] >> de8[3] >> de8[4] >> de8[5];
		demand8[de8[1]][de8[2]] = de8[3];
	}
	double demand15[67][145] = { 0 };

	int de15[6] = { 0 };
	while (!in15.eof())
	{
		in15 >> de15[1] >> de15[2] >> de15[3] >> de15[4] >> de15[5];
		demand15[de15[1]][de15[2]] = de15[3];
	}
	in8.close();
	in15.close();

	int timedian[9] = { 46, 58, 70, 82, 94, 106, 118, 130, 142 };
	for (int i = 1; i < 67; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			double a = demand[i][timedian[j] - 1];
			double b = demand[i][timedian[j] - 2];
			double c = demand[i][timedian[j] - 3];
			double zonghe = a + b + c;
			if (a&&b&&c)
			    demand[i][timedian[j]] = zonghe/3;
			if ((a&&b&&!c)||(a&&!b&&c)||(!a&&b&&c))
				demand[i][timedian[j]] = zonghe/2;
			if ((!a&&b&&!c) || (a&&!b&&!c) || (!a&&!b&&c))
				demand[i][timedian[j]] = zonghe;
			if (!a && !b && !c)
				demand[i][timedian[j]] = (demand8[i][timedian[j]] + demand15[i][timedian[j]]) / 2;
		 }
     }


	for (int j = 0; j < 9; j++)
	
	{
		for (int i = 1; i < 67; i++)
		{
			out << i << " " << timedian[j] << " " << demand[i][timedian[j]] << endl;
		}

	}
	in.close();
	out.close();
}



void jieguoshuchu()
{
	
	ofstream out("G:/botest/zhangbo");
	for (int i = 1; i < 67; i++)
	{
		out << i << ",2016-01-22-46," << endl;
		out << i << ",2016-01-22-58," << endl;
		out << i << ",2016-01-22-70," << endl;
		out << i << ",2016-01-22-82," << endl;
		out << i << ",2016-01-22-94," << endl;
		out << i << ",2016-01-22-106," << endl;
		out << i << ",2016-01-22-118," << endl;
		out << i << ",2016-01-22-130," << endl;
		out << i << ",2016-01-22-142," << endl;
	}
	for (int i = 1; i < 67; i++)
	{
		//out << i << ",2016-01-24-46," << endl;
		out << i << ",2016-01-24-58," << endl;
		out << i << ",2016-01-24-70," << endl;
		out << i << ",2016-01-24-82," << endl;
		out << i << ",2016-01-24-94," << endl;
		out << i << ",2016-01-24-106," << endl;
		out << i << ",2016-01-24-118," << endl;
		out << i << ",2016-01-24-130," << endl;
		out << i << ",2016-01-24-142," << endl;
	}
	for (int i = 1; i < 67; i++)
	{
		out << i << ",2016-01-26-46," << endl;
		out << i << ",2016-01-26-58," << endl;
		out << i << ",2016-01-26-70," << endl;
		out << i << ",2016-01-26-82," << endl;
		out << i << ",2016-01-26-94," << endl;
		out << i << ",2016-01-26-106," << endl;
		out << i << ",2016-01-26-118," << endl;
		out << i << ",2016-01-26-130," << endl;
		out << i << ",2016-01-26-142," << endl;
	}
	for (int i = 1; i < 67; i++)
	{
		//out << i << ",2016-01-28-46," << endl;
		out << i << ",2016-01-28-58," << endl;
		out << i << ",2016-01-28-70," << endl;
		out << i << ",2016-01-28-82," << endl;
		out << i << ",2016-01-28-94," << endl;
		out << i << ",2016-01-28-106," << endl;
		out << i << ",2016-01-28-118," << endl;
		out << i << ",2016-01-28-130," << endl;
		out << i << ",2016-01-28-142," << endl;
	}
	for (int i = 1; i < 67; i++)
	{
		out << i << ",2016-01-30-46," << endl;
		out << i << ",2016-01-30-58," << endl;
		out << i << ",2016-01-30-70," << endl;
		out << i << ",2016-01-30-82," << endl;
		out << i << ",2016-01-30-94," << endl;
		out << i << ",2016-01-30-106," << endl;
		out << i << ",2016-01-30-118," << endl;
		out << i << ",2016-01-30-130," << endl;
		out << i << ",2016-01-30-142," << endl;
	}

	out.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*tongjiquekou("G:/ij_num/ij_num_01","G:/yitiandezongquekou/count01");
	tongjiquekou("G:/ij_num/ij_num_02", "G:/yitiandezongquekou/count02");
	tongjiquekou("G:/ij_num/ij_num_03", "G:/yitiandezongquekou/count03");
	tongjiquekou("G:/ij_num/ij_num_04", "G:/yitiandezongquekou/count04");
	tongjiquekou("G:/ij_num/ij_num_05", "G:/yitiandezongquekou/count05");
	tongjiquekou("G:/ij_num/ij_num_06", "G:/yitiandezongquekou/count06");
	tongjiquekou("G:/ij_num/ij_num_07", "G:/yitiandezongquekou/count07");
	tongjiquekou("G:/ij_num/ij_num_08", "G:/yitiandezongquekou/count08");
	tongjiquekou("G:/ij_num/ij_num_09", "G:/yitiandezongquekou/count09");
	tongjiquekou("G:/ij_num/ij_num_10", "G:/yitiandezongquekou/count10");
	tongjiquekou("G:/ij_num/ij_num_11", "G:/yitiandezongquekou/count11");
	tongjiquekou("G:/ij_num/ij_num_12", "G:/yitiandezongquekou/count12");
	tongjiquekou("G:/ij_num/ij_num_13", "G:/yitiandezongquekou/count13");
	tongjiquekou("G:/ij_num/ij_num_14", "G:/yitiandezongquekou/count14");
	tongjiquekou("G:/ij_num/ij_num_15", "G:/yitiandezongquekou/count15");
	tongjiquekou("G:/ij_num/ij_num_16", "G:/yitiandezongquekou/count16");
	tongjiquekou("G:/ij_num/ij_num_17", "G:/yitiandezongquekou/count17");
	tongjiquekou("G:/ij_num/ij_num_18", "G:/yitiandezongquekou/count18");
	tongjiquekou("G:/ij_num/ij_num_19", "G:/yitiandezongquekou/count19");
	tongjiquekou("G:/ij_num/ij_num_20", "G:/yitiandezongquekou/count20");
	tongjiquekou("G:/ij_num/ij_num_21", "G:/yitiandezongquekou/count21");*/
	
	/*trainzhenghe("G:/trainzhenghe/ij_num_04","G:/trainzhenghe/weather_04","G:/trainzhenghe/yongdu_04","G:/trainzhenghe/gailujieguo_04");
	trainzhenghe("G:/trainzhenghe/ij_num_05", "G:/trainzhenghe/weather_05", "G:/trainzhenghe/yongdu_05", "G:/trainzhenghe/gailujieguo_05");
	trainzhenghe("G:/trainzhenghe/ij_num_06", "G:/trainzhenghe/weather_06", "G:/trainzhenghe/yongdu_06", "G:/trainzhenghe/gailujieguo_06");
	trainzhenghe("G:/trainzhenghe/ij_num_07", "G:/trainzhenghe/weather_07", "G:/trainzhenghe/yongdu_07", "G:/trainzhenghe/gailujieguo_07");
	trainzhenghe("G:/trainzhenghe/ij_num_08", "G:/trainzhenghe/weather_08", "G:/trainzhenghe/yongdu_08", "G:/trainzhenghe/gailujieguo_08");
	trainzhenghe("G:/trainzhenghe/ij_num_11", "G:/trainzhenghe/weather_11", "G:/trainzhenghe/yongdu_11", "G:/trainzhenghe/gailujieguo_11");
	trainzhenghe("G:/trainzhenghe/ij_num_12", "G:/trainzhenghe/weather_12", "G:/trainzhenghe/yongdu_12", "G:/trainzhenghe/gailujieguo_12");
	trainzhenghe("G:/trainzhenghe/ij_num_13", "G:/trainzhenghe/weather_13", "G:/trainzhenghe/yongdu_13", "G:/trainzhenghe/gailujieguo_13");
	trainzhenghe("G:/trainzhenghe/ij_num_14", "G:/trainzhenghe/weather_14", "G:/trainzhenghe/yongdu_14", "G:/trainzhenghe/gailujieguo_14");
	trainzhenghe("G:/trainzhenghe/ij_num_15", "G:/trainzhenghe/weather_15", "G:/trainzhenghe/yongdu_15", "G:/trainzhenghe/gailujieguo_15");
	trainzhenghe("G:/trainzhenghe/ij_num_18", "G:/trainzhenghe/weather_18", "G:/trainzhenghe/yongdu_18", "G:/trainzhenghe/gailujieguo_18");
	trainzhenghe("G:/trainzhenghe/ij_num_19", "G:/trainzhenghe/weather_19", "G:/trainzhenghe/yongdu_19", "G:/trainzhenghe/gailujieguo_19");
	trainzhenghe("G:/trainzhenghe/ij_num_20", "G:/trainzhenghe/weather_20", "G:/trainzhenghe/yongdu_20", "G:/trainzhenghe/gailujieguo_20");
	trainzhenghe("G:/trainzhenghe/ij_num_21", "G:/trainzhenghe/weather_21", "G:/trainzhenghe/yongdu_21", "G:/trainzhenghe/gailujieguo_21");

	trainzhenghe_jieri("G:/trainzhenghe/ij_num_02", "G:/trainzhenghe/weather_02", "G:/trainzhenghe/yongdu_02", "G:/trainzhenghe/gailujieguo_02");
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_03", "G:/trainzhenghe/weather_03", "G:/trainzhenghe/yongdu_03", "G:/trainzhenghe/gailujieguo_03");
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_09", "G:/trainzhenghe/weather_09", "G:/trainzhenghe/yongdu_09", "G:/trainzhenghe/gailujieguo_09");
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_10", "G:/trainzhenghe/weather_10", "G:/trainzhenghe/yongdu_10", "G:/trainzhenghe/gailujieguo_10");
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_16", "G:/trainzhenghe/weather_16", "G:/trainzhenghe/yongdu_16", "G:/trainzhenghe/gailujieguo_16");
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_17", "G:/trainzhenghe/weather_17", "G:/trainzhenghe/yongdu_17", "G:/trainzhenghe/gailujieguo_17");
	*/
	trainzhenghe_jieri("G:/trainzhenghe/ij_num_01", "G:/trainzhenghe/weather_01", "G:/trainzhenghe/yongdu_01", "G:/trainzhenghe/gailujieguo_01");
	/*traffic3he1("G:/zhangtest/testtraffic22", "G:/zhangtest/jutitra22");
	traffic3he1("G:/zhangtest/testtraffic24", "G:/zhangtest/jutitra24");
	traffic3he1("G:/zhangtest/testtraffic26", "G:/zhangtest/jutitra26");
	traffic3he1("G:/zhangtest/testtraffic28", "G:/zhangtest/jutitra28");
	traffic3he1("G:/zhangtest/testtraffic30", "G:/zhangtest/jutitra30");*/
	//testzhenghe_gongzuo("G:/zhangtest/weather_gouzao22","G:/zhangtest/jutitra22","G:/zhangtest/testzhenghe22");
	//testzhenghe_xiuxi("G:/zhangtest/weather_gouzao24", "G:/zhangtest/jutitra24", "G:/zhangtest/testzhenghe24");
	//testzhenghe_gongzuo("G:/zhangtest/weather_gouzao26", "G:/zhangtest/jutitra26", "G:/zhangtest/testzhenghe26");
	//testzhenghe_gongzuo("G:/zhangtest/weather_gouzao28", "G:/zhangtest/jutitra28", "G:/zhangtest/testzhenghe28");
	//testzhenghe_xiuxi("G:/zhangtest/weather_gouzao30", "G:/zhangtest/jutitra30", "G:/zhangtest/testzhenghe30");


	//jieguoshuchu();


	//testdemand("G:/zhangtest/test_write03","G:/zhangtest/testdemand26","G:/ij_num/ij_num_12","G:/ij_num/ij_num_19");

	return 0;
}

