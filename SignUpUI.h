#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignUpControl;
class MemberCollection;

class SignUpUI
{
	// Class: SignUpUI
	// Description: SignUp�� boundary class
	// Created: 2019/5/30
	// Author: �̰��
private:

public:
	void inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection);  
	//Member�� ���� �Ѵ�. �ش� ��ü�� MemberCollection�� �����ϰ�, �޼����� ����Ѵ�. 
};

