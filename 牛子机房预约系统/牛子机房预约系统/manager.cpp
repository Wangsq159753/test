#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_UserName = name;
	this->m_Pwd = pwd;
	this->Init_Vector();

	ifstream ifs;
	ifs.open(COMPUTERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在或者文件为空!" << endl;
		ifs.close();
		return;
	}
	ComputerRoom com;
	while (ifs>>com.Com_Id&&ifs>>com.ComputerMax_Capacity)
	{
		v_Com.push_back(com);
	}
	cout << "当前机房数量: " << v_Com.size() << endl;
	ifs.close();
}
bool  Manager::Check_Repeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it =v_Stu.begin(); it !=v_Stu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			if (id == it->t_id)
			{
				return true;
			}
		}
	}
	return false;
}

void  Manager::Init_Vector()
{
	v_Stu.clear();
	v_Tea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件为空或者文件不存在!" << endl;
		ifs.close();
		return;
	}
	Student s;
	while (ifs>>s.m_id&&ifs>>s.m_UserName&&ifs>>s.m_Pwd)
	{
		v_Stu.push_back(s);
	}
	cout << "当前学生数量: " << v_Stu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件为空或者文件不存在!" << endl;
		ifs.close();
		return;
	}
	Teacher t;
	while (ifs >> t.t_id&& ifs >> t.m_UserName && ifs >> t.m_Pwd)
	{
		v_Tea.push_back(t);
	}
	cout << "当前老师数量: " << v_Tea.size() << endl;
	ifs.close();


}
void Manager::Add_Person()
{
	cout << "请输入要添加的账号类型: " << endl;
	cout << "1、添加学生账号" << endl;
	cout << "2、添加老师账号" << endl;
	int select;
	string filename;
	string tip;
	string errortip;
	ofstream ofs;
	while (true)
	{
		cin >> select;
		if (select == 1)
		{
			filename = STUDENT_FILE;
			tip = "请输入学生学号: ";
			errortip = "学号重复,请重新输入: ";
			break;
		}
		else if(select==2)
		{
			filename = TEACHER_FILE;
			tip = "请输入教师职工号: ";
			errortip = "职工号重复,请重新输入: ";
			break;
		}
		else
		{
			cout << "输入有误,请重新输入: " << endl;
		}
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string username;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->Check_Repeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入用户名: " << endl;
	cin >> username;
	cout << "请输入密码: " << endl;
	cin >> pwd;
	ofs << id << " " << username << " " << pwd<<" "<<endl;
	cout << "添加成功!" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->Init_Vector();
}
void StudentPrintf(Student& s)
{
	cout << "学号: " << s.m_id << " 账号: " << s.m_UserName << " 密码: " << s.m_Pwd << endl;
}
void TeacherPrintf(Teacher& t)
{
	cout << "学号: " << t.t_id << " 账号: " << t.m_UserName << " 密码: " << t.m_Pwd << endl;
}
void Manager::Show_Person()
{
	cout << "请输入要查看的账号类型: " << endl;
	cout << "1、学生账号" << endl;
	cout << "2、老师账号" << endl;
	int select;
	cin >> select;
	if (select==1)
	{
		cout << "所有学生的信息如下: " << endl;
		for_each(v_Stu.begin(), v_Stu.end(), StudentPrintf);
	}
	else
	{
		cout << "所有老师的信息如下: " << endl;
		for_each(v_Tea.begin(), v_Tea.end(), TeacherPrintf);
	}
	system("pause");
	system("cls");
}
void ComputerRoomPrintf(ComputerRoom& com)
{
	cout << "机房ID: " << com.Com_Id << " 机房容量: " << com.ComputerMax_Capacity << endl;
}
void Manager::Show_Computer()
{
	cout << "机房信息如下: " << endl;
	for_each(v_Com.begin(), v_Com.end(), ComputerRoomPrintf);
	system("pause");
	system("cls");
}

void Manager::Clean_File()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

void Manager::Show_Menu()
{
	cout << "欢迎管理员: " << this->m_UserName << " 登录! " << endl;
	cout << "\t\t  ------------------------------\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         1、添加账号           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         2、查看账号           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         3、查看机房           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         4、清空预约记录       |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t |         0、注销登录           |\n";
	cout << "\t\t |                               |\n";
	cout << "\t\t  ------------------------------\n";
	cout << "请选择您的操作: ";
}