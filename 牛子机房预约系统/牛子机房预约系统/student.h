#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include"ComputerRoom.h"
#include<fstream>
#include"Globalfile.h"
#include<vector>
#include"OrderFile.h"
#include<string>

class Student:public Identity
{
public:
	Student();

	Student(int id, string name, string pwd);

	void Apply_Order();

	void Show_MyOrder();

	void Show_AllOrder();

	void Cancel_Order();

	virtual void Show_Menu();

	vector<ComputerRoom>v_Com1;

	int m_id;
};