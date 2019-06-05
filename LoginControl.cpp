#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "Member.h"
#include "MemberCollection.h"

LoginControl::LoginControl()
{
	//Function: LoginControl()
	//Description: Login을 시도하며 successLogin 변수를 False로 초기화 하는 함수
	//Created: 2019/05/31
	//Author: 이계웅

	this->successLogin = false;
}

void LoginControl::requestLogin(string id, string password, MemberCollection* memberCollection)
{
	//Function: requestLogin(string id, string password, MemberCollection* memberCollection)
	//Description: 입력받은 id 및 password가 MemberCollection에 있는지 확인하여 Login을 시도한다
	//Created: 2019/05/31
	//Author: 이계웅

	int memberCount = memberCollection->getMemberNumber(); // memberCollection에서 멤버수를 받는다.
	
	for (int i = 0; i < memberCount; i++) // 멤버수만큼 반복문을 돌린다.
	{
		if ((memberCollection->getMember(i)->getId().compare(id) == 0) && // 아이디를 비교한다. 같으면 0 
		    (memberCollection->getMember(i)->getPassword().compare(password) == 0)) // 비밀번호를 비교한다. 같으면 0
		{
			this->successLogin = true; // 둘 다 맞는 것이 있다면 true로 해준다.
			memberCollection->getMember(i)->setSessionOn(true);
		}
		else
		{
			memberCollection->getMember(i)->setSessionOn(false);
		}
	}
}

bool LoginControl::getSuccessLogin()
{
	//Function: LoginControl()
	//Description: Login 성공 여부를 반환하는 함수
	//Created: 2019/05/31
	//Author: 이계웅

	return this->successLogin;
}