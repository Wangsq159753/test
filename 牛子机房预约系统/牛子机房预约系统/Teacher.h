#pragma once
#include"Identity.h"
#include"OrderFile.h"
#include<vector>

class Teacher:public Identity
{
public:
	Teacher();

	Teacher(int id, string name, string pwd);

	void Show_AllOrder();

	void Check_Order();

	virtual void Show_Menu();

	int t_id;
};