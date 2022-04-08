#include"Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
	this->t_id = id;
	this->m_UserName = name;
	this->m_Pwd = pwd;
}

void Teacher::Show_AllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < of.m_Size; i++)
		{

			cout << "预约日期: 周 " << of.m1[i]["week"];
			cout << " 时间段: " << (of.m1[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学号: " << of.m1[i]["stuId"];
			cout << " 姓名: " << of.m1[i]["stuName"];
			cout << " 机房号: " << of.m1[i]["roomId"];
			string status = " 状态: ";
			if (of.m1[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m1[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m1[i]["status"] == "-1")
			{
				status += "预约失败,审核未通过";
			}
			else
			{
				status += "取消预约";
			}
			cout << status << endl;
		}


	}
	system("pause");
	system("cls");
}

void Teacher::Check_Order()
{

	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录!" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "待审核的记录如下: " << endl;
		vector<int>v;
		int index = 1;

		for (int i = 0; i < of.m_Size; i++)
		{
			
				if (of.m1[i]["status"] == "1" )
				{
					v.push_back(i);
					cout << index++ << "、";
					cout << "预约日期: 周 " << of.m1[i]["week"];
					cout << " 时间段: " << (of.m1[i]["interval"] == "1" ? "上午" : "下午");
					cout << " 机房号: " << of.m1[i]["roomId"];
					string status = " 状态: ";
					if (of.m1[i]["status"] == "1")
					{
						status += "审核中";
					}
					
					cout << status << endl;
				}
			
		}
		cout << "请选择要审核的记录(返回请按0):" << endl;
		cout << "请输入您的选择: ";
		int select;
		while (true)
		{
			cin >> select;
			if (select == 0)
			{
				break;
			}
			else if (select==1)
			{
				of.m1[v[select - 1]]["status"] = "2";
				of.updateOrder();
				cout << "审核通过！" << endl;
				break;
			}
			else if (select==2)
			{
				of.m1[v[select - 1]]["status"] = "-1";
				of.updateOrder();
				cout << "审核未通过！" << endl;
				break;
			}
			else
			{
				cout << "输入有误,请重新输入:" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void Teacher::Show_Menu()
{
	cout << "欢迎教师: " << this->m_UserName << " 登录! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1、查看所有预约       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2、审核预约           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0、注销登录           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "请选择您的操作: ";

 }