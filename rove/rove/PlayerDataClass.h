#pragma once

//Scene
//0 : Splash
//1 : title
//2 : GamestartScene

typedef struct _PlayerState
{
	int HP;

	// main 4 stat
	int passion;			// -�̿��� / +������
	int endurence;			// -����� / +������ ����
	int intelligent;		// -������ / +������
	int extroverted;		// -������ / +������

	// hidden 4 stat
	int independent;		// -������ / +������
	int naive;				// -Ÿ���� / +������
	int optimism;			// -����� / +������
	int resistance;			// -������ / +������
}PlayerState;

class PlayerDataClass
{
private:
	
public:
	int NowScene;
	PlayerState stat;
	int town[12];

	PlayerDataClass();
	~PlayerDataClass();

	void PlayerLoadFromFile();
	void DiaryLoadFromFile();
};

