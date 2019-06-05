#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginUI;
class MemberCollection;

class LoginControl
{
	//Class: LoginControl
	//Description: Login의 control class
	//Created: 2019/05/31
	//Author: 이계웅

private:
	bool successLogin;// Login 성공 여부를 저장하는 변수
public:
	LoginControl();  // Login을 시도하며 successLogin 변수를 False로 초기화 하는 함수
	void requestLogin(string id, string password, MemberCollection* memberCollection);  // ID, password가 MemberCollection에 있는지 확인하여 Login을 시도하는 함수
	bool getSuccessLogin();  // Login 성공 여부를 반환하는 함수

};