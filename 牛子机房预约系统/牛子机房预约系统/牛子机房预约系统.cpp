#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"Globalfile.h"
#include"student.h"
#include"Teacher.h"
#include"manager.h"
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->Show_Menu();

		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1)
		{
			tea->Show_AllOrder();
		}
		else if (select == 2)
		{
			tea->Check_Order();
		}
		else
		{
			delete teacher;
			cout << "注销登录成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}

void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->Show_Menu();

		Student* stu = (Student*)student;
		int select;
		cin >> select;
		if (select == 1)
		{
			stu->Apply_Order();
		}
		else if (select == 2)
		{
			stu->Show_MyOrder();
		}
		else if (select == 3)
		{
			stu->Show_AllOrder();
		}
		else if (select == 4)
		{
			stu->Cancel_Order();
		}
		else
		{
			delete student;
			cout << "注销登录成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}


}


void ManagerMenu(Identity* &manager)
{
	while (true)
	{
		manager->Show_Menu();

		Manager* man = (Manager*)manager;
		int select;
		cin >> select;
		if (select == 1)
		{
			man->Add_Person();
		}
		else if (select == 2)
		{
			man->Show_Person();
		}
		else if (select == 3)
		{
			man->Show_Computer();
		}
		else if (select == 4)
		{
			man->Clean_File();
		}
		else
		{
			delete manager;
			cout << "注销登录成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	

}


void LoginIn(string filename, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件为空或文件不存在!" << endl;
		ifs.close();
		return;
	}
	int id;
	int tt_id;
	string name;
	string pwd;
	if (type==1)
	{
		cout << "请输入您的学号: " << endl;
		cin >> id;
	}
	else if (type==2)
	{
		cout << "请输入您的职工号: " << endl;
		cin >> tt_id;
	}
	cout << "请输入您的用户名: " << endl;
	cin >> name;
	cout << "请输入您的密码: " << endl;
	cin >> pwd;

	if (type==1)
	{
		int m_id;
		string m_name;
		string m_pwd;
		while (ifs>>m_id&&ifs>>m_name&&ifs>>m_pwd)
		{
			if (m_id == id&&m_name == name && m_pwd == pwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		int t_id;
		string t_name;
		string t_pwd;
		while (ifs >> t_id && ifs >> t_name && ifs >> t_pwd)
		{
			if (t_id == tt_id && t_name == name && t_pwd == pwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(tt_id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if(type==3)
	{
		string adminname;
		string adminpwd;
		while (ifs>>adminname&&ifs>>adminpwd)
		{
			if (adminname==name&&adminpwd==pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);

				return;
			}
		}
	}
	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");

}



int main()
{



	int select = 0;

	while (true)
	{
		cout << "=================== 欢迎来到牛子机房预约系统 ====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t  ------------------------------\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         1、学生代表           |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         2、老   师            |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         3、管 理 员           |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t |         0、退   出            |\n";
		cout << "\t\t |                               |\n";
		cout << "\t\t  ------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1:                                 //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:                                 //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:                                 //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:                                  //退出系统
			cout << "欢迎下次使用!" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误,请重新选择!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");




	return 0;
}