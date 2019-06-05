#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignUpControl;
class MemberCollection;

class SignUpUI
{
	// Class: SignUpUI
	// Description: SignUp의 boundary class
	// Created: 2019/5/30
	// Author: 이계웅
private:

public:
	void inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection);  
	//Member를 생성 한다. 해당 객체를 MemberCollection에 저장하고, 메세지를 출력한다. 
};

