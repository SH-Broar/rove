#include "stdafx.h"
#include "PlayerDataClass.h"

PlayerDataClass::PlayerDataClass()
{
	NowScene		= SN_splash;

	this->stat.passion			= 0;
	this->stat.endurence		= 0;
	this->stat.intelligent		= 0;
	this->stat.extroverted		= 0;

	this->stat.independent		= 0;
	this->stat.naive			= 0;
	this->stat.optimism		    = 0;
	this->stat.resistance		= 0;
}


PlayerDataClass::~PlayerDataClass()
{

}

void PlayerDataClass::PlayerLoadFromFile()
{
	//SAVE ���Ͽ��� �÷��̾� ������ �ҷ���.
}

void PlayerDataClass::DiaryLoadFromFile()
{
	//SAVE ���Ͽ��� ��� ������ �ҷ���.
}

