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
		cout << "�κ� �����߽��ϴ� !" << endl;
		cout << "------------------------------" << endl;
		SelectPlayer();

		cout << "------------------------------" << endl;
		cout << "[1] ���� ���� [2] 2�� ���� [3] ���� ����" << endl;
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
		cout << "������ ����ּ��� !" << endl;
		cout << "[1] ���� [2] ������ [3] �ü�" << endl;
		cout << "------------------------------" << endl;
		cout << ">> ";

		int classNum;
		cin >> classNum;

		if (classNum == PC_Warrior)
		{
			cout << "����� �����մϴ�.." << endl;
		}
		else if (classNum == PC_Mage)
		{
			cout << "������� �����մϴ�.." << endl;
		}
		else if (classNum == PC_Archer)
		{
			cout << "�ü��� �����մϴ�.." << endl;
		}
	}
}

void EnterDungeon()
{
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "������ �����߽��ϴ� !" << endl;
		cout << "------------------------------" << endl;
		cout << "��������������������" << endl;
		cout << "�� LEVEL : " << level << " ��" << endl;
		cout << "��    HP : " << hp << " ��" << endl;
		cout << "��   ATT : " << attack << " ��" << endl;
		cout << "��   DEF : " << defence << " ��" << endl;
		cout << "��   EXP : " << pexp << " ��" << endl;
		cout << "��������������������" << endl;
		cout << ">> ";

		SpawnMonster();

		cout << "------------------------------" << endl;
		cout << "[1] �ο�� [2] ��������" << endl;
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
		cout << "�������� �����߽��ϴ� ! (HP:30 / ATK:2 / DEF:0)" << endl;
		break;
	case MC_Goblin:
		cout << "����� �����߽��ϴ� ! (HP:30 / ATK:5 / DEF:3)" << endl;
		break;
	case MC_Orc:
		cout << "��ũ�� �����߽��ϴ� ! (HP:50/ ATK:12 / DEF:10)" << endl;
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

		cout << "���� ���� ü�� : " << mHp << endl;

		if (mHp == 0)
		{
			cout << "���͸� óġ�߽��ϴ� !" << endl;
			WaitKey();
			return;
		}

		damage = mAttack - defence;
		if (damage < 0)
			damage = 0;

		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "�÷��̾� ���� ü�� : " << hp << endl;

		if (hp == 0)
		{
			cout << "[GAME OVER] �÷��̾ ����߽��ϴ� [GAME OVER]" << endl;
			WaitKey();
			return;
		}
	}
}

void WaitKey()
{
	cout << "����Ͻ÷��� �ƹ�Ű�� �����ּ���" << endl;
	cout << ">> ";
	int num;
	cin >> num;
	system("cls");
}
