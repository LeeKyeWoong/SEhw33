#pragma once

#include <iostream>
#include <string>

using namespace std;

class SignUpUI;
class MemberCollection;

class SignUpControl
{
	//Class: SignUpControl
	//Description: SignUp의 control class
	//Created: 2019/05/30
	//Author: 이계웅
private:
	bool checkId;  //해당 ID의 중복 여부를 저장하는 변수, 중복이 없으면 True이고, 중복이면 False이다. 
public:
	SignUpControl();  // SignInControl의 control 객체의 checkID값을 true값으로 초기화 하는 생성자
	void createAccount(string id, string password, string name, string idNum, string memType, bool sessionOn, MemberCollection* memberCollection); // 새 Account를 생성하며, 입력된 ID의 중복 여부를 확인하는 함수
	bool getCheckId(); //회원 가입을 시도하는 ID의 중복 여부를 반환하는 함수

};