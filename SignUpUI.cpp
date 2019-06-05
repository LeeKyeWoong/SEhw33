#pragma once
#include "SignUpUI.h"
#include "SignUpControl.h"
#include "Member.h"
#include "MemberCollection.h"

void SignUpUI::inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection)
{
	// Function :inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection)
	// Description: 입력된 정보를 바탕으로 새 계정을 만드는 함수
	// Created: 2019/5/30
	// Author: 이계웅

	string id, password, name, idNum, memType;
	bool session = false;

	cin >> id >> password >> name >> idNum >> memType; // 정보를 입력받는다. 

	signupControl->createAccount(id, password, name, idNum, memType, session, memberCollection);

	if(signupControl->getCheckId()) // 중복이 없다면 즉, true라면
	{
		cout << "1.1 회원가입" << endl;
		cout << "> " << id << " " << password << " " << name << " " << idNum << " " << memType << " " << endl << endl;
	}
	else
	{
		cout << "> ID 중복입니다" << endl << endl;
	}
	
}
