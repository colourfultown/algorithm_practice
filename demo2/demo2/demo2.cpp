#include <stdio.h>
#include<string>
#include <vector>
#include <iostream>

using namespace std;



int main()
{
	//char ch = 65;
	///*printf("%d", ch);
	//char ch1[] = "n\"hello\"m";*/

	//char a[] = "abcd";
	//int a1=sizeof(a);

	//a[2] = 0;
	//int a2 = sizeof(a);


	vector <int> v{1,2,3,4};
	for (auto &a : v)
		a *= a;
	for (auto a : v)
		cout << a << endl;
	return(0);
}

