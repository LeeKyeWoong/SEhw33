#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutControl;
class MemberCollection;

class LogoutUI
{
	// Class: LogoutUI
	// Description: Logout�� boundary class
	// Created: 2019/05/31
	// Author: �̰��

public:
	void callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection); //LogoutControl ��ü�� User�� Logout ��û�� �����ϴ� �Լ�
};

