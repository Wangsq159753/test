#pragma once
#include"Identity.h"
#include"Globalfile.h"
#include<fstream>
#include<string>
#include"student.h"
#include"Teacher.h"
#include<vector>
#include<algorithm>
#include"ComputerRoom.h"
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	void Add_Person();
	
	void Show_Person();

	void Show_Computer();

	void Clean_File();
	
	void Init_Vector();

	bool Check_Repeat(int id,int type);

	vector<Student>v_Stu;

	vector<Teacher>v_Tea;

	vector<ComputerRoom>v_Com;

	virtual void Show_Menu();

	
};