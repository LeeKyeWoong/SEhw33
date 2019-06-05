#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LogoutUI::callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection)
{
	//Function: callLogout(LogoutControl* logoutControl, MemberCollection* memberCollection)
	//Description: Control�� Logout�� ��û�ϴ� �Լ�
	//Created: 2019/05/31
	//Author: �̰��

	logoutControl->requestLogout(memberCollection);

	cout << "2.2. �α׾ƿ�" << endl;
	cout << "> " << logoutControl->getLogoutId() << endl << endl;

}
