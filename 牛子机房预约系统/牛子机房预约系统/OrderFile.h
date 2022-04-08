#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"Globalfile.h"
#include<fstream>
class OrderFile
{
public:

	OrderFile();

	void updateOrder();
	
	int m_Size;

	map<int, map<string, string>>m1;
};

