#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LoginUI::inputLogin(LoginControl* loginControl, MemberCollection* memberCollection)
{
	//Functnion: inputLogin(LoginControl* loginControl, MemberCollection* memberCollection)
	//Description: Login ������ �Է¹޴´�
	//Created: 2019/05/31
	//Author: �̰��
	
	string id, password;
	cin >> id >> password;
	loginControl->requestLogin(id, password, memberCollection);

	if (loginControl->getSuccessLogin()) // �α����� �����Ѵٸ� 
	{
		cout << "2.1 �α���" << endl;
		cout << "> " << id << " " << password << endl << endl;
	}
	else // �α����� �����Ѵٸ�
	{
		cout << "> �α��� ����" << endl << endl;
	}
}
