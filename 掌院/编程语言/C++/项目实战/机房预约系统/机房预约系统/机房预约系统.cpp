#define _CRT_SECURE_NO_WARNING
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//进入管理员的子菜单界面
void managerMenu(Identity* manager)
{
	while (true)
	{
		//调用子菜单
		manager->openMenu();

		//将父类指针转为子类指针，调用其他的特有接口
		Manager* man = (Manager*)manager;

		int sel = 0;
		//接收用户的选择
		cin >> sel;

		if (sel == 1)//添加账号
		{
			//cout <<"添加账号" << endl;
			man->addPerson();
		}
		else if (sel == 2)//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (sel == 3)//查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if(sel == 4)//清空预约
		{
			//cout << "清空预约" << endl;
			man->clearFile();
		}
		else
		{
			//cout << "注销登录" << endl;
			//销毁掉堆区管理员对象
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入学生的子菜单
void studentMenu(Identity* student)
{
	while (true)
	{
		//调用学生子菜单
		student->openMenu();
		Student* stu = (Student*)student;

		int sel = 0;
		cin >> sel;//接收用户的选择

		switch (sel)
		{
		case 1://申请预约
			stu->applyOrder();
			break;
		case 2://查看自身预约
			stu->showMyOrder();
			break;
		case 3://查看所有人预约
			stu->showAllOrder();
			break;
		case 4://取消预约
			stu->cancelOrder();
			break;
		default://注销登录
			delete student;
			cout <<"注销成功！"<< endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//进入教师的子菜单
void TeacherMenu(Identity* teacher)
{
	while (true)
	{
		//调用学生子菜单
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;

		int sel = 0;
		cin >> sel;//接收用户的选择

		switch (sel)
		{
		case 1://查看所有预约
			tea->showAllOrder();
			break;
		case 2://审核预约
			tea->validOrder();
			break;
		default://注销登录
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}
//参数：
//fileName:操作的文件名
//    type:登陆的身份（1.代表学生，2.教师，3.代表管理员）
void LoginIn(string fileName, int type)
{
	//创建父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout <<"文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备缓冲区
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生身份
	{
		cout <<"请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入用户密码：" << endl;
	cin >> pwd;

	//身份验证
	if (type == 1)
	{
		//学生身份验证
		//1 张三 123
	    //2 李四 12345
		
		//存储从文件中获取的信息
		int fId;
		string fName;
		string fPwd;

		//获取信息
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//测试是否读到
			//cout << fId << fName << fPwd << endl;

			//对比
			if ( fId == id && fName == name && fPwd == pwd)
			{
				cout <<"学生的验证登录成功！" << endl;

				
				system("pause");
				system("cls");
				//显示学生菜单
				person = new Student(id, name, pwd);
        		studentMenu(person);
				system("pause");
				return;
			}
		}
		
	}
	else if (type==2)
	{
		//教师身份验证
		//1 老王 123

		//存储从文件中获取的信息
		int fId;
		string fName;
		string fPwd;

		//获取信息
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//测试是否读到
			//cout << fId << fName << fPwd << endl;

			//对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师的验证登录成功！" << endl;


				system("pause");
				system("cls");
				//显示教师菜单
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				
				system("pause");
				return;
			}
		}
    }
	else if (type == 3)
	{
		//管理员身份验证
		//admin 123

		//存储从文件中获取的信息
		string fName;
		string fPwd;

		//获取信息
		while (ifs >> fName && ifs >> fPwd)
		{
			//测试是否读到
			//cout  << fName << fPwd << endl;

			//对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员的验证登录成功！" << endl;


				system("pause");
				system("cls");
				//显示管理员菜单
				person = new Manager(name, pwd);
				managerMenu(person);
				system("pause");
				return;
			}
		}
	}

	cout<< "验证登录失败！" << endl;
	/*system("pause");
	system("cls");*/

	return;
}

int main(void)
{
	int sel;
	while (true)
	{
		cout << "=============欢迎来到机房预约系统==============================" << endl;
		cout << "请输入您的身份:" << endl;
		cout << endl << "----------------------------------------------------------------\n" << endl;
		cout << "\t\t|------------------------------|\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         1.学生代表           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         2.老师               |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         3.管理员             |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         0.退出               |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|------------------------------|\n" << endl;
		cout << "请输入您的选择：" << endl;

		cin >> sel;
		switch (sel)
		{
		case 1://学生
			LoginIn(STUDENT_FILE,1);
			break;

		case 2://老师
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout <<"欢迎下次使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout <<"您的输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	

	system("pause");
	return 0;
}