#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginControl;
class MemberCollection;

class LoginUI
{
	//Class: LoginUI
	//Description: Login의 boundary class
	//Created: 2019/05/31
	//Author: 이계웅

private:
	
public:
	void inputLogin(LoginControl* loginControl, MemberCollection* memberCollection);//Login 정보를 입력받는 함수
};

