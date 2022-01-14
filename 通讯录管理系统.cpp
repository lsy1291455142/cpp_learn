#include <iostream>
#include <string>
using	namespace std;
#define MAX 1000

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//联系人结构体
struct Person {
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//通讯录结构体
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};

//1. 添加联系人
void addPerson(Addressbooks * abs){
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		while (true) {
			cout << "请输入性别" << endl;
			cout << "1-----男" << endl;
			cout << "2-----女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "性别输入有误" << endl;
			}
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入住址" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "联系人添加成功！" << endl;
	}
	system("pause");
	system("cls");
}

void show(Addressbooks abs) {
	if (abs.m_Size == 0) {
		cout << "记录为空" << endl;
	}
	else {
		//int num;
		for (int i = 0; i < abs.m_Size; i++) {
			cout << i+1 << "\t";
			cout << "姓名:" << abs.personArray[i].m_Name << "\t";
			cout << "性别:" << (abs.personArray[i].m_Sex == 1 ? "男":"女" )<< "\t";
			cout << "年龄:" << abs.personArray[i].m_Age << "\t";
			cout << "电话：" << abs.personArray[i].m_Phone << "\t";
			cout << "住址：" << abs.personArray[i].m_Addr << endl;
		}
		//cout << "联系人姓名" << endl;
		//cin >> num;
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int isExit(Addressbooks abs,string name) {
	for (int i = 0; i < abs.m_Size; i++) {
		if (abs.personArray[i].m_Name == name) {
			return i;
		}
		}
	return -1;
	}

//删除指定联系人
void deletePerson(Addressbooks * abs,string name) {
	//cout << "请输入要删除的联系人" << endl;
	//string name;
	//cin >> name;
	int ret = isExit(*abs, name);
	if (ret != -1) {
		//找到此人
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找指定联系人
void findPerson(Addressbooks abs,string name) {
	int ret = isExit(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名:" << abs.personArray[ret].m_Name << "\t";
		cout << "性别:" << (abs.personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄:" << abs.personArray[ret].m_Age << "\t";
		cout << "电话：" << abs.personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs.personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks * abs,string name) {
	int ret = isExit(* abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "请重新输入姓名" << endl;
		cin >> abs->personArray[ret].m_Name;
		cout << "请重新输入年龄" << endl;
		cin >> abs->personArray[ret].m_Age;
		//cout << "请重新输入性别" << endl;
		int sex = 0;
		while (true) {
			cout << "请重新输入性别" << endl;
			cout << "1-----男" << endl;
			cout << "2-----女" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "性别输入有误" << endl;
			}
		}
		//cin >> abs->personArray[ret].m_Sex;
		cout << "请重新输入电话" << endl;
		cin >> abs->personArray[ret].m_Phone;
		cout << "请重新输入地址" << endl;
		cin >> abs->personArray[ret].m_Addr;
		cout << "修改完成" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks * abs) {
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}


int main() {
	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_Size = 0;


	while (true) {
		showMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1: //1. 添加联系人
			addPerson(&abs); //利用地址传递 可以修饰实参
			break;
		case 2: //2. 显示联系人
			show(abs);
			break;
		case 3: //3. 删除联系人
		{	cout << "请输入要删除联系人姓名" << endl;
			string name;
			cin >> name;
		//	if (isExit(abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
			deletePerson(&abs, name);
		}
			break;
		case 4: //4. 查找联系人
		{
			cout << "请输入要查找的联系人姓名" << endl;
			string name;
			cin >> name;
			findPerson(abs,name);
		}

			break;
		case 5: //5. 修改联系人
		{
			cout << "请输入要修改的联系人姓名" << endl;
			string name;
			cin >> name;
			modifyPerson(&abs, name);
		}
			break;
		case 6: //6. 清空联系人
			cleanPerson(&abs);
			break;
		case 0: //0. 退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

}