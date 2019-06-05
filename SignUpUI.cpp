#pragma once
#include "SignUpUI.h"
#include "SignUpControl.h"
#include "Member.h"
#include "MemberCollection.h"

void SignUpUI::inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection)
{
	// Function :inputInfo(SignUpControl* signupControl, MemberCollection* memberCollection)
	// Description: �Էµ� ������ �������� �� ������ ����� �Լ�
	// Created: 2019/5/30
	// Author: �̰��

	string id, password, name, idNum, memType;
	bool session = false;

	cin >> id >> password >> name >> idNum >> memType; // ������ �Է¹޴´�. 

	signupControl->createAccount(id, password, name, idNum, memType, session, memberCollection);

	if(signupControl->getCheckId()) // �ߺ��� ���ٸ� ��, true���
	{
		cout << "1.1 ȸ������" << endl;
		cout << "> " << id << " " << password << " " << name << " " << idNum << " " << memType << " " << endl << endl;
	}
	else
	{
		cout << "> ID �ߺ��Դϴ�" << endl << endl;
	}
	
}
