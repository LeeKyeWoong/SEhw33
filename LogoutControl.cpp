#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LogoutControl::requestLogout(MemberCollection* memberCollection)
{
	//Function: requestLogout(MemberCollection* memberCollection)
	//Description: ȸ���� ���ǻ��¸� ������ �α׾ƿ� ��.
	//Created: 2019/05/31
	//Author: �̰��

	if (memberCollection->currentSession() == NULL) // ���� �α��� ���� ���̵� ���ٸ�
	{
		cout << "> ���� �α��� ���� id�� �����ϴ�."; // ������ ����Ѵ�.
	}
	else // �α��� ���� id�� �ִٸ� 
	{
		this->logoutId = memberCollection->currentSession()->getId(); // �α����� id�� ��´�.
		memberCollection->currentSession()->setSessionOn(false);
	}
}

string LogoutControl::getLogoutId()
{
	//Function: getLogoutId()
	//Description: LogoutID�� ����ϴ� �Լ�
	//Created: 2019/05/31
	//Author: �̰��

	return this->logoutId;
}