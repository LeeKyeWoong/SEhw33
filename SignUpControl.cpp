#pragma once
#include "SignUpUI.h"
#include "SignUpControl.h"
#include "Member.h"
#include "MemberCollection.h"

SignUpControl::SignUpControl()
{
	// Function : SignUpControl()
	// Description: 객체의 checkID값을 true로 초기화 하는 생성자 ( true 는 중복이 없다는 것을 의미한다.)
	// Created: 2019/5/30
	// Author: 이계웅

	this->checkId = true;
}

void SignUpControl::createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection)
{
	// Function : createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection)
	// Description: 새 Account를 생성하며, 입력된 ID의 중복 여부를 확인하는 함수
	// Created: 2019/5/30
	// Author: 이계웅

	int memberCount = memberCollection->getMemberNumber(); // 갯수를 받아온다.

	for (int i = 0; i < memberCount; i++)
	{
		if (id.compare(memberCollection->getMember(i)->getId()) == 0) // 문자열이 같으면 0이다.
		{
			this->checkId = false; // 문자열이 같으면 False이다.
		}
	}
	
	if(this->checkId) // 문자열이 동일한 것이 없다. 즉, true이다.
	{
		memberCollection->addMember(id, password, name, idNum, memType, sessionOn);
	}
	else // 문자열이 동일한것이 있다.
	{
		// 아무일도 하지 않는다.
	}
	
}

bool SignUpControl::getCheckId()
{
	// Function : getCheckId()
	// Description: 회원 가입을 시도하는 ID의 중복 여부를 반환하는 함수
	// Created: 2019/5/30
	// Author: 이계웅

	return this->checkId;
}