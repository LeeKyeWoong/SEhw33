#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignUpUI;
class MemberCollection;

class SignUpControl
{
	//Class: SignUpControl
	//Description: SignUp�� control class
	//Created: 2019/05/30
	//Author: �̰��
private:
	bool checkId;  //�ش� ID�� �ߺ� ���θ� �����ϴ� ����, �ߺ��� ������ True�̰�, �ߺ��̸� False�̴�. 
public:
	SignUpControl();  // SignInControl�� control ��ü�� checkID���� true������ �ʱ�ȭ �ϴ� ������
	void createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection); // �� Account�� �����ϸ�, �Էµ� ID�� �ߺ� ���θ� Ȯ���ϴ� �Լ�
	bool getCheckId(); //ȸ�� ������ �õ��ϴ� ID�� �ߺ� ���θ� ��ȯ�ϴ� �Լ�

};