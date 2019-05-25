
#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//切割拥堵字符串，返回拥堵路段值
int splittraffic(string traffic)
{
	string count, traffic_numstr;
	int flag = 0;
	for each (char c in traffic)
	{
		if (flag == 0)
		{
			if (c != ':')
				count += c;
			else
			{
				flag++;
				continue;
			}
		}
		if (flag == 1)
		{
			if (c != ':')
				traffic_numstr += c;
			else
			{
				flag++;
				continue;
			}
		}
	}
	
	int traffic_num = atoi(traffic_numstr.c_str());
	return traffic_num;
}
///23：45：33时间 字符串的分割，返回1~144时间片
int splittime(string time)
{
	string hour, second;
	int flag = 0;
	for each (char c in time)
	{
		if (flag == 0)
		{
			if (c != ':')
				hour += c;
			else
			{
				flag++;
				continue;
			}
		}
		if (flag == 1)
		{
			if (c != ':')
				second += c;
			else
			{
				flag++;
				continue;
			}
		}
	}

	int hournum = atoi(hour.c_str());
	int secondnum = atoi(second.c_str());
	return (6*hournum+secondnum/10+1);
}
//输入区域数字与哈希值匹配函数，存储在一个全局map_hash[66]里。

static string map_hash[66];
void map_hash_pipei(string str)
{
	ifstream in_map(str);

	
	int map_num[66];
	for (int map_i = 0; !in_map.eof(); map_i++)
	{
		in_map >> map_hash[map_i] >> map_num[map_i];
		

	}
	in_map.close();
	
}

void hash_time_transmit(string in_address , string out_address)
{


	
	string order[8];
	ifstream in_order(in_address);
	ofstream out_map(out_address);
	while (!in_order.eof())
	{
		in_order >> order[0] >> order[1] >> order[2] >> order[3] >> order[4] >> order[5] >> order[6] >> order[7];
		int time_pian = splittime(order[7]);
		for (int map_i = 0; map_i<66; map_i++)
		{
			if (order[3] == map_hash[map_i])
			{
				out_map << in_address << " " << map_i + 1 << " " << time_pian << " " << order[1] << endl;
			}
		}

	}
	in_order.close();
	out_map.close();

	
}
void de_su_gap_Statistics(string in_num,string out_num)
{
	int demand[67][145] = {0};
	int supply[67][145] = {0};
	int gap[67][145] = {0};
	ifstream in(in_num);
	ofstream out(out_num);
	string day;
	int area,time;
	string driver_id;
	while (!in.eof())
	{
		in >> day >> area >>time >> driver_id;
		++demand[area][time];
		if (driver_id != "NULL")
		{
			++supply[area][time];
		}
		else
		{
			++gap[area][time];
		}
	}
	for (int area = 1; area < 67; ++area)

	{
		for (int time = 1; time < 145; ++time)
		{
			if (demand[area][time] && supply[area][time] && gap[area][time])
			out << area << " " << time << " " << demand[area][time] << " " << supply[area][time] << " " << gap[area][time] << endl;
		}
	}

	in.close();
	out.close();
}

void weather(string in_address, string out_address)
{
	ifstream in(in_address);
	ofstream out(out_address);
	string day;
	string read_time;
	int read_wea;
	double read_tem;
	double read_pm;
	int wea[145] = { 0 };
	double tem[145] = { 0 };
	double pm[145] = { 0 };
	while (!in.eof())
	{
		in >> day >> read_time >> read_wea >> read_tem >> read_pm;
		int time_pian = splittime(read_time);
		wea[time_pian] = read_wea;
		tem[time_pian] = read_tem;
		pm[time_pian] = read_pm;
		
	}
	
	for (int time_pian = 1; time_pian < 145; time_pian++)
	{
		if (wea[time_pian] && tem[time_pian] && pm[time_pian])
		out << time_pian << " " << wea[time_pian] << " " << tem[time_pian] << " " << pm[time_pian] << endl;
	}

	in.close();
	out.close();
}
void traffic_turn(string in_address, string out_address)
{
	ifstream in(in_address);
	ofstream out(out_address);
	string traffic[7];
	int area_time_traffic[67][145][5] = { 0 };
	while (!in.eof())
	{
		in >> traffic[0] >> traffic[1] >> traffic[2] >> traffic[3] >> traffic[4] >> traffic[5] >> traffic[6];
		int area;
		for (int map_i = 0; map_i < 66; map_i++)
		{
			if (traffic[0] == map_hash[map_i])
			{
				area = map_i + 1;
			}
		}
		int time = splittime(traffic[6]);
		int yongdu1 = splittraffic(traffic[1]);
		int yongdu2 = splittraffic(traffic[2]);
		int yongdu3 = splittraffic(traffic[3]);
		int yongdu4 = splittraffic(traffic[4]);
		area_time_traffic[area][time][0] = yongdu1;
		area_time_traffic[area][time][1] = yongdu2;
		area_time_traffic[area][time][2] = yongdu3;
		area_time_traffic[area][time][3] = yongdu4;

	}
		for (int area = 1; area < 67; ++area)

		{
			for (int time = 1; time < 145; ++time)
			{
				if (area_time_traffic[area][time][0] && area_time_traffic[area][time][1] && area_time_traffic[area][time][2] && area_time_traffic[area][time][3])
				out << area << " " << time << " " << area_time_traffic[area][time][0] << " " << area_time_traffic[area][time][1]<< " " << area_time_traffic[area][time][2] << " " << area_time_traffic[area][time][3]<<endl;
			}
		}

	in.close();
	out.close();
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	map_hash_pipei("G:/cluster_map.txt");
	/*hash_time_transmit("G:/order_data_2016-01-01", "G:/write_1");
	hash_time_transmit("G:/order_data_2016-01-02", "G:/write_2");
	hash_time_transmit("G:/order_data_2016-01-03", "G:/write_3");
	hash_time_transmit("G:/order_data_2016-01-04", "G:/write_4");
	hash_time_transmit("G:/order_data_2016-01-05", "G:/write_5");
	hash_time_transmit("G:/order_data_2016-01-06", "G:/write_6");
	hash_time_transmit("G:/order_data_2016-01-07", "G:/write_7");
	hash_time_transmit("G:/order_data_2016-01-08", "G:/write_8");
	hash_time_transmit("G:/order_data_2016-01-09", "G:/write_9");
	hash_time_transmit("G:/order_data_2016-01-10", "G:/write_10");
	hash_time_transmit("G:/order_data_2016-01-11", "G:/write_11");
	hash_time_transmit("G:/order_data_2016-01-12", "G:/write_12");
	hash_time_transmit("G:/order_data_2016-01-13", "G:/write_13");
	hash_time_transmit("G:/order_data_2016-01-14", "G:/write_14");
	hash_time_transmit("G:/order_data_2016-01-15", "G:/write_15");
	hash_time_transmit("G:/order_data_2016-01-16", "G:/write_16");
	hash_time_transmit("G:/order_data_2016-01-17", "G:/write_17");
	hash_time_transmit("G:/order_data_2016-01-18", "G:/write_18");
	hash_time_transmit("G:/order_data_2016-01-19", "G:/write_19");
	hash_time_transmit("G:/order_data_2016-01-20", "G:/write_20");
	hash_time_transmit("G:/order_data_2016-01-21", "G:/write_21");*/

	/*de_su_gap_Statistics("G:/write_1","G:/ij_num/ij_num_01");
	de_su_gap_Statistics("G:/write_2", "G:/ij_num/ij_num_02");
	de_su_gap_Statistics("G:/write_3", "G:/ij_num/ij_num_03");
	de_su_gap_Statistics("G:/write_4", "G:/ij_num/ij_num_04");
	de_su_gap_Statistics("G:/write_5", "G:/ij_num/ij_num_05");
	de_su_gap_Statistics("G:/write_6", "G:/ij_num/ij_num_06");
	de_su_gap_Statistics("G:/write_7", "G:/ij_num/ij_num_07");
	de_su_gap_Statistics("G:/write_8", "G:/ij_num/ij_num_08");
	de_su_gap_Statistics("G:/write_9", "G:/ij_num/ij_num_09");
	de_su_gap_Statistics("G:/write_10", "G:/ij_num/ij_num_10");
	de_su_gap_Statistics("G:/write_11", "G:/ij_num/ij_num_11");
	de_su_gap_Statistics("G:/write_12", "G:/ij_num/ij_num_12");
	de_su_gap_Statistics("G:/write_13", "G:/ij_num/ij_num_13");
	de_su_gap_Statistics("G:/write_14", "G:/ij_num/ij_num_14");
	de_su_gap_Statistics("G:/write_15", "G:/ij_num/ij_num_15");
	de_su_gap_Statistics("G:/write_16", "G:/ij_num/ij_num_16");
	de_su_gap_Statistics("G:/write_17", "G:/ij_num/ij_num_17");
	de_su_gap_Statistics("G:/write_18", "G:/ij_num/ij_num_18");
	de_su_gap_Statistics("G:/write_19", "G:/ij_num/ij_num_19");
	de_su_gap_Statistics("G:/write_20", "G:/ij_num/ij_num_20");
	de_su_gap_Statistics("G:/write_21", "G:/ij_num/ij_num_21");*/

	/*weather("G:/weather/weather_data_2016-01-01", "G:/weather_time/weather_01");
	weather("G:/weather/weather_data_2016-01-02", "G:/weather_time/weather_02");
	weather("G:/weather/weather_data_2016-01-03", "G:/weather_time/weather_03");
	weather("G:/weather/weather_data_2016-01-04", "G:/weather_time/weather_04");
	weather("G:/weather/weather_data_2016-01-05", "G:/weather_time/weather_05");
	weather("G:/weather/weather_data_2016-01-06", "G:/weather_time/weather_06");
	weather("G:/weather/weather_data_2016-01-07", "G:/weather_time/weather_07");
	weather("G:/weather/weather_data_2016-01-08", "G:/weather_time/weather_08");
	weather("G:/weather/weather_data_2016-01-09", "G:/weather_time/weather_09");
	weather("G:/weather/weather_data_2016-01-10", "G:/weather_time/weather_10");
	weather("G:/weather/weather_data_2016-01-11", "G:/weather_time/weather_11");
	weather("G:/weather/weather_data_2016-01-12", "G:/weather_time/weather_12");
	weather("G:/weather/weather_data_2016-01-13", "G:/weather_time/weather_13");
	weather("G:/weather/weather_data_2016-01-14", "G:/weather_time/weather_14");
	weather("G:/weather/weather_data_2016-01-15", "G:/weather_time/weather_15");
	weather("G:/weather/weather_data_2016-01-16", "G:/weather_time/weather_16");
	weather("G:/weather/weather_data_2016-01-17", "G:/weather_time/weather_17");
	weather("G:/weather/weather_data_2016-01-18", "G:/weather_time/weather_18");
	weather("G:/weather/weather_data_2016-01-19", "G:/weather_time/weather_19");
	weather("G:/weather/weather_data_2016-01-20", "G:/weather_time/weather_20");
	weather("G:/weather/weather_data_2016-01-21", "G:/weather_time/weather_21");*/
	
	
	/*traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-01", "G:/yongdu/yongdu_01");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-02", "G:/yongdu/yongdu_02");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-03", "G:/yongdu/yongdu_03");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-04", "G:/yongdu/yongdu_04");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-05", "G:/yongdu/yongdu_05");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-06", "G:/yongdu/yongdu_06");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-07", "G:/yongdu/yongdu_07");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-08", "G:/yongdu/yongdu_08");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-09", "G:/yongdu/yongdu_09");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-10", "G:/yongdu/yongdu_10");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-11", "G:/yongdu/yongdu_11");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-12", "G:/yongdu/yongdu_12");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-13", "G:/yongdu/yongdu_13");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-14", "G:/yongdu/yongdu_14");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-15", "G:/yongdu/yongdu_15");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-16", "G:/yongdu/yongdu_16");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-17", "G:/yongdu/yongdu_17");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-18", "G:/yongdu/yongdu_18");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-19", "G:/yongdu/yongdu_19");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-20", "G:/yongdu/yongdu_20");
	traffic_turn("G:/yongdu_yuanshi/traffic_data_2016-01-21", "G:/yongdu/yongdu_21");*/


	/*traffic_turn("G:/test_set_1/traffic_data/traffic_data_2016-01-22_test", "G:/test_set_1/traffic_data/testtraffic22");
	traffic_turn("G:/test_set_1/traffic_data/traffic_data_2016-01-24_test", "G:/test_set_1/traffic_data/testtraffic24");
	traffic_turn("G:/test_set_1/traffic_data/traffic_data_2016-01-26_test", "G:/test_set_1/traffic_data/testtraffic26");
	traffic_turn("G:/test_set_1/traffic_data/traffic_data_2016-01-28_test", "G:/test_set_1/traffic_data/testtraffic38");
	traffic_turn("G:/test_set_1/traffic_data/traffic_data_2016-01-30_test", "G:/test_set_1/traffic_data/testtraffic30");*/
	

	/*hash_time_transmit("G:/test_set_1/order_data/order_data_2016-01-22_test", "G:/testwrite01");
	hash_time_transmit("G:/test_set_1/order_data/order_data_2016-01-24_test", "G:/testwrite02");
	hash_time_transmit("G:/test_set_1/order_data/order_data_2016-01-26_test", "G:/testwrite03");
	hash_time_transmit("G:/test_set_1/order_data/order_data_2016-01-28_test", "G:/testwrite04");
	hash_time_transmit("G:/test_set_1/order_data/order_data_2016-01-30_test", "G:/testwrite05");*/

	/*de_su_gap_Statistics("G:/testwrite01", "G:/test_write01");
	de_su_gap_Statistics("G:/testwrite02", "G:/test_write02");
	de_su_gap_Statistics("G:/testwrite03", "G:/test_write03");
	de_su_gap_Statistics("G:/testwrite04", "G:/test_write04");
	de_su_gap_Statistics("G:/testwrite05", "G:/test_write05");*/

    /* weather("G:/test_set_1/weather_data/weather_data_2016-01-22_test","G:/test_set_1/weather_data/testweather22");
	 weather("G:/test_set_1/weather_data/weather_data_2016-01-24_test", "G:/test_set_1/weather_data/testweather24");
	 weather("G:/test_set_1/weather_data/weather_data_2016-01-26_test", "G:/test_set_1/weather_data/testweather26");
	 weather("G:/test_set_1/weather_data/weather_data_2016-01-28_test", "G:/test_set_1/weather_data/testweather28");
	 weather("G:/test_set_1/weather_data/weather_data_2016-01-30_test", "G:/test_set_1/weather_data/testweather30");*/


/*hash_time_transmit("G:/test2/23_test", "G:/test2/23_chulue");
hash_time_transmit("G:/test2/25_test", "G:/test2/25_chulue");
hash_time_transmit("G:/test2/27_test", "G:/test2/27_chulue");
hash_time_transmit("G:/test2/29_test", "G:/test2/29_chulue");
hash_time_transmit("G:/test2/31_test", "G:/test2/31_chulue"); */

de_su_gap_Statistics("G:/test2/23_chulue", "G:/test2/ijnum23");
de_su_gap_Statistics("G:/test2/25_chulue", "G:/test2/ijnum25");
de_su_gap_Statistics("G:/test2/27_chulue", "G:/test2/ijnum27");
de_su_gap_Statistics("G:/test2/29_chulue", "G:/test2/ijnum29");
de_su_gap_Statistics("G:/test2/31_chulue", "G:/test2/ijnum31");
	return 0;
}

