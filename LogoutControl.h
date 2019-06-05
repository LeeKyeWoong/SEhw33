#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutUI;
class MemberCollection;

class LogoutControl
{
	//Class: LogoutControl
	//Description: Logout�� control class
	//Created: 2019/05/31
	//Author: �̰��

private:
	string logoutId;  //Logout�� �õ��ϴ� Memeber�� ID�� �����ϴ� ����
public:
	void requestLogout(MemberCollection* memberCollection); // ���� sessionOn������ ȸ���� ���� �����ϴ� �Լ�
	string getLogoutId();  // logoutID�� ��ȯ�ϴ� �Լ�
};