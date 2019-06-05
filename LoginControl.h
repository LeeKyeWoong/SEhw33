#pragma once

#include <iostream>
#include <string>

using namespace std;

class LoginUI;
class MemberCollection;

class LoginControl
{
	//Class: LoginControl
	//Description: Login�� control class
	//Created: 2019/05/31
	//Author: �̰��

private:
	bool successLogin;// Login ���� ���θ� �����ϴ� ����
public:
	LoginControl();  // Login�� �õ��ϸ� successLogin ������ False�� �ʱ�ȭ �ϴ� �Լ�
	void requestLogin(string id, string password, MemberCollection* memberCollection);  // ID, password�� MemberCollection�� �ִ��� Ȯ���Ͽ� Login�� �õ��ϴ� �Լ�
	bool getSuccessLogin();  // Login ���� ���θ� ��ȯ�ϴ� �Լ�

};