#include "Combat.h"
#include "Character.h"
#include <stdio.h>
#include <iostream>
void ModuleCombat::StartCombat()
{
	system("cls");
	character1 = new Character(10, 5, 3, 6, this);
	character2 = new Character(20, 2, 1, 4, this);

	in_combat = true;
}

void ModuleCombat::EndCombat()
{
	delete character1;
	character1 = nullptr;

	delete character2;
	character2 = nullptr;
}

void ModuleCombat::PrintStats()
{
	printf("Player:\n    HP: %i\n    Attack: %i\n    Defense: %i\n    Speed: %i\n", character1->hp, character1->attack, character1->defense, character1->speed);
	printf("\n\nEnemy:\n    HP: %i\n    Attack: %i\n    Defense: %i\n    Speed: %i\n", character2->hp, character2->attack, character2->defense, character2->speed);
}

void ModuleCombat::InCombat()
{
	int action = 0;
	PrintStats();

	printf("\n\n\nActions:");
	printf("\n    1. Attack.\n    2. Heal.\n\nSelect your action: ");
	scanf_s("%i", &action);

	CleanAndPrintStats();
	if (action == 1)
	{
		character1->Attack(character2);
	}
	else if (action == 2)
	{
		character1->Heal();
	}

	system("pause");
}

void ModuleCombat::CleanAndPrintStats()
{
	system("cls");
	PrintStats();
}
