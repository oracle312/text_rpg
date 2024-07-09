#include <iostream>

using namespace std;

enum PlayerClass
{
	PC_None = 0,
	PC_Warrior = 1,
	PC_Mage = 2,
	PC_Archer = 3,
};

enum MonsterClass
{
	MC_None = 0,
	MC_Slime = 1,
	MC_Goblin = 2,
	MC_Orc = 3,
};

PlayerClass playerClass;

int level;
int pexp;
int hp;
int attack;
int defence;

MonsterClass monsterClass;
int mHp;
int mAttack;
int mDefence;

void EnterLobby();
void SelectPlayer();
void EnterDungeon();
void SpawnMonster();
void EnterBattle();
void WaitKey();

int main()
{
	srand(time(0));
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "로비에 입장했습니다 !" << endl;
		cout << "------------------------------" << endl;
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "[1] 던전 입장 [2] 2차 전직 [3] 게임 종료" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int num;
		cin >> num;

		if (num == 1)
		{
			EnterDungeon();
		}
		else if (num == 2)
		{
		
		}
		else
		{

		}
	}
}

void SelectPlayer()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "직업을 골라주세요 !" << endl;
		cout << "[1] 전사 [2] 마법사 [3] 궁수" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int classNum;
		cin >> classNum;

		if (classNum == PC_Warrior)
		{
			cout << "전사로 시작합니다.." << endl;
		}
		else if (classNum == PC_Mage)
		{
			cout << "마법사로 시작합니다.." << endl;
		}
		else if (classNum == PC_Archer)
		{
			cout << "궁수로 시작합니다.." << endl;
		}
	}
}

void EnterDungeon()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "던전에 입장했습니다 !" << endl;
		cout << "------------------------------" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■ LEVEL : " << level << " ■" << endl;
		cout << "■    HP : " << hp << " ■" << endl;
		cout << "■   ATT : " << attack << " ■" << endl;
		cout << "■   DEF : " << defence << " ■" << endl;
		cout << "■   EXP : " << pexp << " ■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■" << endl;
		cout << ">> ";

		SpawnMonster();

		cout << "------------------------------" << endl;
		cout << "[1] 싸우기 [2] 도망가기" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int num;
		cin >> num;

		if (num == 1)
		{
			EnterBattle();

			if (hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void SpawnMonster()
{
	int random = 1 + (rand() % 3);

	switch (random)
	{
	case MC_Slime:
		cout << "슬라임이 등장했습니다 ! (HP:30 / ATK:2 / DEF:0)" << endl;
		break;
	case MC_Goblin:
		cout << "고블린이 등장했습니다 ! (HP:30 / ATK:5 / DEF:3)" << endl;
		break;
	case MC_Orc:
		cout << "오크가 등장했습니다 ! (HP:50/ ATK:12 / DEF:10)" << endl;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = attack - mDefence;
		if (damage < 0)
			damage = 0;

		mHp -= damage;
		if (mHp < 0)
			mHp = 0;

		cout << "몬스터 남은 체력 : " << mHp << endl;

		if (mHp == 0)
		{
			cout << "몬스터를 처치했습니다 !" << endl;
			WaitKey();
			return;
		}

		damage = mAttack - defence;
		if (damage < 0)
			damage = 0;

		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "플레이어 남은 체력 : " << hp << endl;

		if (hp == 0)
		{
			cout << "[GAME OVER] 플레이어가 사망했습니다 [GAME OVER]" << endl;
			WaitKey();
			return;
		}
	}
}

void WaitKey()
{
	cout << "계속하시려면 아무키나 눌러주세요" << endl;
	cout << ">> ";
	int num;
	cin >> num;
	system("cls");
}
