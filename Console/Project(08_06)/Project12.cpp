#include "Warrior_86.h"
#include "Archer_86.h"
#include "Wizard_86.h"

int main()
{
	UnitProject_86* Warrior = new Warrior_86("레오나드", 150, 30, 40);

	Warrior->PrintInfo();
	Warrior->GetWeapon();
	Warrior->Attack();
	Warrior->Move();
	Warrior->TakeAttack(30);
	Warrior->PrintInfo();


	UnitProject_86* Archer = new Archer_86("레골라스", 100, 20, 10);

	Archer->PrintInfo();
	Archer->GetWeapon();
	Archer->Attack();
	Archer->Move();
	Archer->TakeAttack(10);
	Archer->PrintInfo();

	UnitProject_86* Wizard = new Wizard_86("아일라", 80, 40, 10);

	Wizard->PrintInfo();
	Wizard->GetWeapon();
	Wizard->Attack();
	Wizard->Move();
	Wizard->TakeAttack(20);
	Wizard->PrintInfo();


	delete Warrior;
	Warrior = nullptr;

	delete Archer;
	Archer = nullptr;

	delete Wizard;
	Wizard = nullptr;


	return 0;
}