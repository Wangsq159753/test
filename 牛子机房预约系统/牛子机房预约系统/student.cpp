#include"student.h"


Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_UserName = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在或者文件为空!" << endl;
		ifs.close();
		return;
	}
	ComputerRoom com;
	while (ifs >> com.Com_Id && ifs >> com.ComputerMax_Capacity)
	{
		v_Com1.push_back(com);
	}
	
	ifs.close();
}

void Student::Apply_Order()
{
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间: " << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int week = 0;        //日期
	int interval = 0;    //时间段
	int room = 0;        //机房编号

	while (true)
	{
		cin >> week;
		if (week>=1&&week<=5)
		{
			break;
		}
		else
		{
			cout << "机房开放时间为周一至周五,其他时间段并无开放,请重新输入: " << endl;
		}
	}
	cout << "请输入申请预约的时间段: " << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误,请重新输入" << endl;
	}
	cout << "请选择机房: " << endl;
	for (int i = 0; i < v_Com1.size(); i++)
	{
		cout << "机房ID: " << v_Com1[i].Com_Id << " 机房容量: " << v_Com1[i].ComputerMax_Capacity << endl;

	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误,请重新输入" << endl;
	}
	cout << "预约成功,审核中..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "week:" << week << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_UserName << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " " << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::Show_MyOrder()
{
	OrderFile of;
	if (of.m_Size==0)
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
			if (this->m_id==atoi(of.m1[i]["stuId"].c_str()))
			{
				cout << "预约日期: 周 " << of.m1[i]["week"];
				cout<< " 时间段: " << (of.m1[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号: " << of.m1[i]["roomId"];
				string status = " 状态: ";
				if (of.m1[i]["status"]=="1")
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
					status +="取消预约";
				}
				cout << status << endl;
			}

		}
		
	}
	system("pause");
	system("cls");
}

void Student::Show_AllOrder()
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
					status +="取消预约";
				}
				cout << status << endl;
			}


	}
	system("pause");
	system("cls");
}

void Student::Cancel_Order()
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
		cout << "预约状态为审核中或者审核成功的记录可以取消预约!" << endl;
		vector<int>v;
		int index = 1;

		for (int i = 0; i <of.m_Size ; i++)
		{
			if (this->m_id == atoi(of.m1[i]["stuId"].c_str()))
			{
				if (of.m1[i]["status"]=="1"||of.m1[i]["status"]=="2")
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
					else if (of.m1[i]["status"] == "2")
					{
						status += "预约成功";
					}
					cout << status << endl;
				}
			}
		}
		cout << "请选择要删除的记录,返回请按0:" << endl;
		int select;
		while (true)
		{
			cin >> select;
			if (select==0)
			{
				break;
			}
			else if (select > 0 && select <= v.size())
			{
				of.m1[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "预约已经取消!" << endl;

				break;
			}
			else
			{
				cout << "输入有误,请重新输入!" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void Student::Show_Menu()
{
	cout << "欢迎学生代表: " << this->m_UserName << " 登录! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1、申请预约           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2、查看我的预约       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         3、查看所有预约       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         4、取消预约           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0、注销登录           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "请选择您的操作: ";
}