#include "Vector.h"

int main()
{
	Vector v,v1;
	v.push_back(10);
	v.push_back(2.5);
	v.push_back(4.3);
	
	for (int i = 0;i < v.size();i++)
		cout << v.at(i) << endl;

	cout << endl;

	v[0] = 1.8;
	v.at(1) = 5.4;

	for (int i = 0;i < v.size();i++)
		cout << v.at(i) << endl;

	Vector v2(v);
	cout << endl;
	for (int i = 0;i < v.size();i++)
		cout << v2[i] << endl;

	v1 = v;
	cout << endl;
	for (int i = 0;i < v.size();i++)
		cout << v1[i] << endl;
	cout << endl;
	if (v == v1)cout << "true\n";
	cout << endl;
	v1.push_back(15);
	v.push_back(15);
	if (v != v1)cout << "true\n";
	else 
		cout << "false\n";
	cout << endl;
	cout << v << endl;
	v + v2;
	cout << endl;
	cout << v << endl;
	v - v2;
	cout << endl;
	cout << v << endl;
	Vector v3;
	v3.push_back(10);
	v3.push_back(11);
	v3.push_back(12);
	cout << v3 << endl;
	double a = v3 << 1;
	cout << a << endl;			
	cout << v3 << endl;
	v3 >> 5;
	cout << v3 << endl;
	system("pause");
	return 0;
}