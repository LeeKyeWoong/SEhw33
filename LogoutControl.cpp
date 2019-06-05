#pragma once
#include "LogoutUI.h"
#include "LogoutControl.h"
#include "Member.h"
#include "MemberCollection.h"

void LogoutControl::requestLogout(MemberCollection* memberCollection)
{
	//Function: requestLogout(MemberCollection* memberCollection)
	//Description: 회원의 세션상태를 변경해 로그아웃 함.
	//Created: 2019/05/31
	//Author: 이계웅

	if (memberCollection->currentSession() == NULL) // 만약 로그인 중인 아이디가 없다면
	{
		cout << "> 현재 로그인 중인 id가 없습니다."; // 문구를 출력한다.
	}
	else // 로그인 중인 id가 있다면 
	{
		this->logoutId = memberCollection->currentSession()->getId(); // 로그인한 id를 얻는다.
		memberCollection->currentSession()->setSessionOn(false);
	}
}

string LogoutControl::getLogoutId()
{
	//Function: getLogoutId()
	//Description: LogoutID를 출력하는 함수
	//Created: 2019/05/31
	//Author: 이계웅

	return this->logoutId;
}