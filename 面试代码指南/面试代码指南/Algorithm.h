#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Algorithm
{
public:
	Algorithm();
	~Algorithm();
	void MP(string T, string P){
		int lenT = T.length();//��
		int lenP = P.length();//��
		vector<int> v(lenP + 1, 0);
		MP_bulid_v(v, P);
		int i = 0, j = 0;//i�Ƕ̴���ָ�� j�ǳ�����ָ��
		//�������̾�������ָ����ƶ�
		while (j < lenT){
			while (i>-1 && P[i] != T[j])
				i = v[i];
			i++;
			j++;
			if (i >= lenP){
				//�ɹ��ҵ�һ��
				cout << j - i;
				i = v[i];//����������һ��
			}
		}


	}
	void MP_bulid_v(vector<int> &v, string &P){
		int m = P.length();
		int i = 0;
		int j = v[0] = -1;
		while (i < m){
			while (j>-1 && P[i] != P[j])
				j = v[j];//�����ʵ�ַǳ����� �����뵽
			i++;
			j++;
			v[i] = j;
		}
	}
	void KMP(string T, string P){
		int chang = T.length();
		int duan = P.length();
		//�����ж�PΪ�� ��chang<duan
		
		vector<int> v(duan + 1, 0);
		int i=0, j = 0;//i �Ƕ̵� j�ǳ���
		while ( j<chang){
			while (i>-1 && T[j] != P[i])
				i = v[i];
			i++;
			j++;
			if (i >= duan){
				cout << j - i;
				i = v[i];
			}
		}
	}
	void KMPbuileVec(vector<int> &v, string &P){
		int m = P.length();
		int i = 0;
		int j = -1;
		v[0] = -1;
		while (i < m ){
			while (j>-1 && P[i] != P[j])
				j = v[j];
			i++; j++;
			if (P[i] != P[j]) v[i] = j;
			else v[i] = v[j];
		}
	}
};

