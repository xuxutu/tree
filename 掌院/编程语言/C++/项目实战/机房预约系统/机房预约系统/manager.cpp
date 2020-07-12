#include"manager.h"

//构造
Manager::Manager()
{


}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器,获取文件中老师学生的信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	ComputerRoom cr;

	while (ifs >> cr.m_ComId && ifs >> cr.m_Max)
	{
		vCom.push_back(cr);
	}
	ifs.close();
	cout <<"机房的数量为：" <<vCom.size()<<endl;
}
//析构
Manager::~Manager()
{



}

//菜单
void Manager::openMenu()
{
	
	cout << "欢迎管理员" << m_Name << "登录！" << endl;
		cout << endl << "----------------------------------------------------------------\n" << endl;
		cout << "\t\t|------------------------------|\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         1.添加账号           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         2.查看账号           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         3.查看机房           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         4.清空预约           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         0.注销登录           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|------------------------------|\n" << endl;
		cout << "请选择您的操作：" << endl;



}

//添加账号
void Manager::addPerson()
{
	cout <<"请输入添加账号类型" << endl;
	cout <<"1、添加学生" << endl;
	cout <<"2、添加老师" << endl;

	string errorTip;//重复错误提示；
	string fileName;
	string tip;
	ofstream ofs;

	int sel = 0;
	cin >> sel;
	if (sel == 1)
	{
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		//添加的是老师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入！";
	}

    //追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id;//学号/职工号
	string name;
	string pwd;
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id,sel);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout <<"添加成功！" << endl;
	
	this->initVector();//刷新容器

	ofs.close();
	system("pause");
	system("cls");

}

void printStu(Student& s)
{
	cout << "学号："<<s.m_id << "  姓名： " << s.m_Name << endl;

}
void printTea(Teacher& t)
{
	cout << "学号："<<t.m_EmpId<< "  姓名： " << t.m_Name << endl;

}

//查看账号
void Manager::showPerson()
{
	cout <<"请选择要显示的内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int sel = 0;
	cin >> sel;

	if (sel == 1)
	{
		cout <<"所有的学生信息如下：" << endl;
		for_each(vStu.begin(),vStu.end(),printStu);
	}
	else
	{
		cout << "所有的老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(),printTea);
	}

	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout <<"机房的信息如下"<< endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout <<"机房id: " <<it->m_ComId <<" 最大容量："<< it->m_Max << endl;
	}

	system("pause");
	system("cls");
}

//清空预约记录
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout <<"预约清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//读取信息 学生、老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout <<" 文件打开失败 !"<< endl;
		return;
	}
	//确保清空容器
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	//测试
	cout <<"当前的学生数量为：" <<vStu.size()<< endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << " 文件打开失败 !" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	//测试
	cout << "当前的老师数量为：" << vTea.size() << endl;
	ifs.close();
}

//检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (auto it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
		return false;

	}

}