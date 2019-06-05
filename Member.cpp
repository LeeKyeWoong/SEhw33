#pragma once

#include "Member.h"

Member::Member()
{
	// Function: Member()
	// Description: �ƹ� �Է� ���� ������ Member�� SessionOn ���� False�� �ʱ�ȭ �ϴ� ������
	// Created: 2019/05/29
	// Author: �̰��
	
	this->sessionOn = false;
}

Member::Member(string id, string password, string name, string idNum, string memType, bool sessionOn)
{
	// Function: Member(string id, string password, string name, string idNum, string memType, bool sessionOn)
	// Description: �Է¹��� ���� �޾Ƽ� ��ü�� �����ϴ� ������
	// Created: 2019/05/29
	// Author: �̰��

	this->id = id;
	this->password = password;
	this->name = name;
	this->idNum = idNum;
	this->memType = memType;
	this->sessionOn = sessionOn;
}

Member::~Member()
{
	// Function: ~Member()
	// Description: �Ҹ���
	// Created: 2019/05/29
	// Author: �̰��
}

void Member::createMember(string id, string password, string name, string idNum, string memType, bool sessionOn)
{
	// Function: createMember(string id, string password, string name, string idNum, string memType, bool sessionOn)
	// Description: �Է¹��� ���� �޾Ƽ� ��ü�� �����ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	this->id = id;
	this->password = password;
	this->name = name;
	this->idNum = idNum;
	this->memType = memType;
	this->sessionOn = sessionOn;
	
}

void Member::deleteMember()
{
	// Function: deleteMember()
	// Description: Member�� �����ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	this->id = "";
	this->password = "";
	this->name = "";
	this->idNum = "";
	this->memType = "";
	this->sessionOn = false;

}

string Member::getId()
{
	// Function: getId()
	// Description: id�� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->id;
}

string Member::getPassword() 
{
	// Function: getPassword() 
	// Description: ��й�ȣ�� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->password;
}

string Member::getName()
{
	// Function: getName()
	// Description: �̸��� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->name;
}

string Member::getIdNum()
{
	// Function: getIdNum()
	// Description: �ֹι�ȣ�� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->idNum;
}

string Member::getMemType()
{
	// Function: getMemType()
	// Description: ȸ�� Ÿ���� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->memType;
}

bool Member::getSessionOn()
{
	// Function: getSessionOn()
	// Description: session ��� ���θ� ��ȯ�ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	return this->sessionOn;
}

void Member::setMemType(string memType)
{
	// Function: setMemType(string memType)
	// Description: ȸ�� Ÿ���� �����ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��

	this->memType = memType;
}

void Member::setSessionOn(bool sessionOn)
{
	// Function: setSessionOn(bool sessionOn)
	// Description: ���� ��� ���θ� �����ϴ� �Լ�
	// Created: 2019/05/29
	// Author: �̰��
	
	this->sessionOn = sessionOn;
}
