#pragma once
#include "LoginUI.h"
#include "LoginControl.h"
#include "Member.h"
#include "MemberCollection.h"

LoginControl::LoginControl()
{
	//Function: LoginControl()
	//Description: Login�� �õ��ϸ� successLogin ������ False�� �ʱ�ȭ �ϴ� �Լ�
	//Created: 2019/05/31
	//Author: �̰��

	this->successLogin = false;
}

void LoginControl::requestLogin(string id, string password, MemberCollection* memberCollection)
{
	//Function: requestLogin(string id, string password, MemberCollection* memberCollection)
	//Description: �Է¹��� id �� password�� MemberCollection�� �ִ��� Ȯ���Ͽ� Login�� �õ��Ѵ�
	//Created: 2019/05/31
	//Author: �̰��

	int memberCount = memberCollection->getMemberNumber(); // memberCollection���� ������� �޴´�.
	
	for (int i = 0; i < memberCount; i++) // �������ŭ �ݺ����� ������.
	{
		if ((memberCollection->getMember(i)->getId().compare(id) == 0) && // ���̵� ���Ѵ�. ������ 0 
		    (memberCollection->getMember(i)->getPassword().compare(password) == 0)) // ��й�ȣ�� ���Ѵ�. ������ 0
		{
			this->successLogin = true; // �� �� �´� ���� �ִٸ� true�� ���ش�.
			memberCollection->getMember(i)->setSessionOn(true);
			break;
		}
	}
	if (this->successLogin != true)
	{
		cout << "> ��ġ�ϴ� ������ �����ϴ�." << endl << endl;
		exit(0);
	}
}

bool LoginControl::getSuccessLogin()
{
	//Function: LoginControl()
	//Description: Login ���� ���θ� ��ȯ�ϴ� �Լ�
	//Created: 2019/05/31
	//Author: �̰��

	return this->successLogin;
}