#include <iostream>
#include <string>
using	namespace std;
#define MAX 1000

void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//��ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];
	int m_Size;
};

//1. �����ϵ��
void addPerson(Addressbooks * abs){
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		while (true) {
			cout << "�������Ա�" << endl;
			cout << "1-----��" << endl;
			cout << "2-----Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "�Ա���������" << endl;
			}
		}

		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "������绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "������סַ" << endl;
		string addr;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "��ϵ����ӳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void show(Addressbooks abs) {
	if (abs.m_Size == 0) {
		cout << "��¼Ϊ��" << endl;
	}
	else {
		//int num;
		for (int i = 0; i < abs.m_Size; i++) {
			cout << i+1 << "\t";
			cout << "����:" << abs.personArray[i].m_Name << "\t";
			cout << "�Ա�:" << (abs.personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "����:" << abs.personArray[i].m_Age << "\t";
			cout << "�绰��" << abs.personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs.personArray[i].m_Addr << endl;
		}
		//cout << "��ϵ������" << endl;
		//cin >> num;
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExit(Addressbooks abs,string name) {
	for (int i = 0; i < abs.m_Size; i++) {
		if (abs.personArray[i].m_Name == name) {
			return i;
		}
		}
	return -1;
	}

//ɾ��ָ����ϵ��
void deletePerson(Addressbooks * abs,string name) {
	//cout << "������Ҫɾ������ϵ��" << endl;
	//string name;
	//cin >> name;
	int ret = isExit(*abs, name);
	if (ret != -1) {
		//�ҵ�����
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//����ָ����ϵ��
void findPerson(Addressbooks abs,string name) {
	int ret = isExit(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "����:" << abs.personArray[ret].m_Name << "\t";
		cout << "�Ա�:" << (abs.personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����:" << abs.personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs.personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs.personArray[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks * abs,string name) {
	int ret = isExit(* abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "��������������" << endl;
		cin >> abs->personArray[ret].m_Name;
		cout << "��������������" << endl;
		cin >> abs->personArray[ret].m_Age;
		//cout << "�����������Ա�" << endl;
		int sex = 0;
		while (true) {
			cout << "�����������Ա�" << endl;
			cout << "1-----��" << endl;
			cout << "2-----Ů" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else {
				cout << "�Ա���������" << endl;
			}
		}
		//cin >> abs->personArray[ret].m_Sex;
		cout << "����������绰" << endl;
		cin >> abs->personArray[ret].m_Phone;
		cout << "�����������ַ" << endl;
		cin >> abs->personArray[ret].m_Addr;
		cout << "�޸����" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks * abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


int main() {
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	abs.m_Size = 0;


	while (true) {
		showMenu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1: //1. �����ϵ��
			addPerson(&abs); //���õ�ַ���� ��������ʵ��
			break;
		case 2: //2. ��ʾ��ϵ��
			show(abs);
			break;
		case 3: //3. ɾ����ϵ��
		{	cout << "������Ҫɾ����ϵ������" << endl;
			string name;
			cin >> name;
		//	if (isExit(abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
			deletePerson(&abs, name);
		}
			break;
		case 4: //4. ������ϵ��
		{
			cout << "������Ҫ���ҵ���ϵ������" << endl;
			string name;
			cin >> name;
			findPerson(abs,name);
		}

			break;
		case 5: //5. �޸���ϵ��
		{
			cout << "������Ҫ�޸ĵ���ϵ������" << endl;
			string name;
			cin >> name;
			modifyPerson(&abs, name);
		}
			break;
		case 6: //6. �����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //0. �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

}