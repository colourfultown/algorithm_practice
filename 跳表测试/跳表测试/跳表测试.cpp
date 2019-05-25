// �������.cpp : �������̨Ӧ�ó������ڵ㡣
//






//���ļ����ڲ���skiplist
//
//@���ߣ��ź���
//@ʱ�䣺2013-12-17
//@��Ȩ����������
#include "stdafx.h"
#include "skiplist.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "test is starting ....." << endl;

	SkipList list;

	//���Բ���
	for (int i = 0; i < 100; ++i){
		list.Insert(i, i + 10);
		//cout << list.GetCurrentLevel() << endl;
	}
	cout << "The number of elements in SkipList is :"
		<< list.size()
		<< endl;
	if (list.size() != 100){
		cout << "Insert failure." << endl;
	}
	else{
		cout << "Insert success." << endl;
	}

	//���Բ���
	bool is_search_success = true;
	for (int i = 0; i < 100; ++i){
		int value;
		if (!(list.Search(i, value) && (value == i + 10))){
			is_search_success = false;
			break;
		}
	}
	if (is_search_success){
		cout << "Search success." << endl;
	}
	else{
		cout << "Search failure." << endl;
	}

	//����ɾ��
	bool is_delete_success = true;
	for (int i = 0; i < 100; ++i){
		int value;
		if (!(list.Delete(i, value) && (value == i + 10))){
			is_delete_success = false;
			break;
		}
	}
	if (is_delete_success){
		cout << "Delete success." << endl;
	}
	else{
		cout << "Delete failure." << endl;
	}

	cout << "test is finished ...." << endl;
	return 0;
}


