#pragma once

#include <iostream>
#include <string>

using namespace std;

class LogoutControl;
class MemberCollection;

class LogoutUI
{
	// Class: LogoutUI
	// Description: Logout의 boundary class
	// Created: 2019/05/31
	// Author: 이계웅

public:
	void callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection); //LogoutControl 객체에 User의 Logout 요청을 전달하는 함수
};

