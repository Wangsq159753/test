#include"OrderFile.h"


OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string week;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	this->m_Size = 0;
	while (ifs>>week&&ifs>>interval&&ifs>>stuId&&ifs>>stuName&&ifs>>roomId&&ifs>>status)
	{
		//date:1
		string key;
		string value;
		map<string, string>m;
		int pos = week.find(":");
		if (pos!=-1)
		{
			key = week.substr(0, pos);
			value = week.substr(pos + 1, week.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		 pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m1.insert(make_pair(m_Size, m));
		this->m_Size++;
	}
	ifs.close();
	/*for (map<int,map<string,string>>::iterator it=m1.begin();it!=m1.end();it++)
	{
		cout << "ÌõÊý = " << it->first << " value = " << endl;
		for (map<string,string>::iterator mit=it->second.begin();mit!=it->second.end();mit++ )
		{
			cout << "key = " << mit->first << " value = " << mit->second << " ";
		}
		cout << endl;
	}*/
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "week:" << this->m1[i]["week"] << " ";
		ofs << "interval:" << this->m1[i]["interval"] << " ";
		ofs << "stuId:" << this->m1[i]["stuId"] << " ";
		ofs << "stuName:" << this->m1[i]["stuName"] << " ";
		ofs << "roomId:" << this->m1[i]["roomId"] << " ";
		ofs << "status:" << this->m1[i]["status"] << " " << endl;

	}
	ofs.close();

}

