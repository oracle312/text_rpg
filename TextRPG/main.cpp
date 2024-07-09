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

struct StatInfo
{
	string className;
	int level;
	int exp;
	int maxhp;
	int hp;
	int attack;
	int defence;
};

PlayerClass playerClass;
StatInfo playerStat;

MonsterClass monsterClass;
StatInfo monsterStat;

void EnterLobby();
void SelectPlayer();
void EnterDungeon();
void SpawnMonster();
void EnterBattle();
void WaitKey();
void EnterUpgrade();

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
		if (playerClass == NULL)
			SelectPlayer();
		cout << "����� PLAYER STAT �����" << endl;
		cout << "        CLASS : " << playerStat.className << "" << endl;
		cout << "          LEVEL : " << playerStat.level << "" << endl;
		cout << "           HP : " << playerStat.hp << "" << endl;
		cout << "           ATK : " << playerStat.attack << "" << endl;
		cout << "           DEF : " << playerStat.defence << "" << endl;
		cout << "           EXP : " << playerStat.exp << "" << endl;
		cout << "����������������" << endl;
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
			if (playerStat.level >= 5)
			{
				EnterUpgrade();
			}
			else
			{
				cout << "2�� ������ ���� 5 �̻���� �����մϴ�." << endl;
				WaitKey();
			}
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
			playerStat.className = "����";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 200;
			playerStat.hp = 200;
			playerStat.defence = 20;
			playerStat.attack = 10;
			playerClass = PC_Warrior;
			break;
		}
		else if (classNum == PC_Mage)
		{
			cout << "������� �����մϴ�.." << endl;
			playerStat.className = "������";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 100;
			playerStat.hp = 100;
			playerStat.defence = 1;
			playerStat.attack = 50;
			playerClass = PC_Mage;
			break;
		}
		else if (classNum == PC_Archer)
		{
			cout << "�ü��� �����մϴ�.." << endl;
			playerStat.className = "�ü�";
			playerStat.level = 1;
			playerStat.exp = 0;
			playerStat.maxhp = 150;
			playerStat.hp = 150;
			playerStat.defence = 5;
			playerStat.attack = 20;
			playerClass = PC_Archer;
			break;
		}
	}
}

void EnterDungeon()
{
	system("cls");
	while (true)
	{
		cout << "------------------------------" << endl;
		cout << "������ �����߽��ϴ� !" << endl;
		cout << "------------------------------" << endl;
		cout << "����� PLAYER STAT �����" << endl;
		cout << "        CLASS : " << playerStat.className << "" << endl;
		cout << "          LEVEL : " << playerStat.level << "" << endl;
		cout << "           HP : " << playerStat.hp << "" << endl;
		cout << "           ATK : " << playerStat.attack << "" << endl;
		cout << "           DEF : " << playerStat.defence << "" << endl;
		cout << "           EXP : " << playerStat.exp << "" << endl;
		cout << "����������������" << endl;
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

			if (playerStat.hp == 0)
				return;
		}
		else
		{
			system("cls");
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
		monsterStat.hp = 100;
		monsterStat.attack = 2;
		monsterStat.defence = 0;
		monsterStat.exp = 2;
		break;
	case MC_Goblin:
		cout << "����� �����߽��ϴ� ! (HP:30 / ATK:5 / DEF:3)" << endl;
		monsterStat.hp = 50;
		monsterStat.attack = 15;
		monsterStat.defence = 3;
		monsterStat.exp = 15;
		break;
	case MC_Orc:
		cout << "��ũ�� �����߽��ϴ� ! (HP:50/ ATK:12 / DEF:10)" << endl;
		monsterStat.hp = 150;
		monsterStat.attack = 30;
		monsterStat.defence = 15;
		monsterStat.exp = 30;
		break;
	}
}

void EnterBattle()
{
	int temp = 15;
	while (true)
	{
		int damage = playerStat.attack - monsterStat.defence;
		if (damage < 0)
			damage = 0;

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
			monsterStat.hp = 0;

		cout << "���� ���� ü�� : " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "���͸� óġ�߽��ϴ� !" << endl;
			playerStat.exp += monsterStat.exp;
			if (playerStat.exp >= (playerStat.level * temp))
			{
				cout << "������ �߽��ϴ� !!" << endl;
				playerStat.level++;
				playerStat.maxhp += 30;
				playerStat.hp = playerStat.maxhp;
				playerStat.attack += 10;
				playerStat.defence += 2;
			}
			WaitKey();
			return;
		}

		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;

		cout << "�÷��̾� ���� ü�� : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
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

void EnterUpgrade()
{
	cout << "------------------------------" << endl;
	cout << "2�� ������ �������ּ���." << endl;
	cout << "------------------------------" << endl;
	if (playerClass == PC_Warrior)
	{
		cout << "[1] �ȶ�� [2] ����" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			break;
		case 2:
			
			break;
		default:
			return;
		}
	}
	else if (playerClass == PC_Mage)
	{
		cout << "[1] �Ҽ����� [2] ������Ʈ" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			cout << "�Ҽ������� �����߽��ϴ�" << endl;
			playerStat.className = "�Ҽ�����";
			playerStat.maxhp += playerStat.maxhp / 10;
			playerStat.hp = playerStat.maxhp;
			playerStat.defence += playerStat.defence / 10;
			playerStat.attack += playerStat.attack / 10;
			break;
		case 2:
			cout << "������Ʈ�� �����߽��ϴ�" << endl;
			playerStat.className = "������Ʈ";
			playerStat.maxhp += playerStat.maxhp / 10;
			playerStat.hp = playerStat.maxhp;
			playerStat.defence += playerStat.defence / 10;
			playerStat.attack += playerStat.attack / 10;
			break;
		default:
			return;
		}
	}
	else if (playerClass == PC_Archer)
	{
		cout << "[1] ���� [2] ���ݼ�" << endl;
		cout << ">> ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			return;
		}
	}
}
