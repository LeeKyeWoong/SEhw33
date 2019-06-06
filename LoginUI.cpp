#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LoginUI::inputLogin(LoginControl* loginControl, MemberCollection* memberCollection)
{
	//Functnion: inputLogin(LoginControl* loginControl, MemberCollection* memberCollection)
	//Description: Login 정보를 입력받는다
	//Created: 2019/05/31
	//Author: 이계웅
	
	string id, password;
	cin >> id >> password;
	loginControl->requestLogin(id, password, memberCollection);

	if (loginControl->getSuccessLogin()) // 로그인이 성공한다면 
	{
		cout << "2.1 로그인" << endl;
		cout << "> " << id << " " << password << endl << endl;
	}
	else // 로그인이 실패한다면
	{
		cout << "> 로그인 실패" << endl << endl;
		exit(0);
	}
}
