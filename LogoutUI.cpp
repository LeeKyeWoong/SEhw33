#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LogoutUI::callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection)
{
	//Function: callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection)
	//Description: Control에 Logout을 요청하는 함수
	//Created: 2019/05/31
	//Author: 이계웅

	logoutControl->requestLogout(memberCollection);

	cout << "2.2. 로그아웃" << endl;
	cout << "> " << logoutControl->getLogoutId() << endl << endl;

}
