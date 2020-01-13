//#include <stdio.h>
#include <iostream>
#include "Combat.h"
#include "main.h"

void main()
{
	ModuleCombat* combat_system = new ModuleCombat();

	while (combat_system->in_game)
	{
		system("cls");

		int option = 0;
		printf("Options:\n    1. Combat.\n    2. Actions.\n\n Selecte the option: ");
		scanf_s("%i", &option);

		if (option == 1)
		{
			Combat(combat_system);
		}
		else if (option == 2)
		{
			printf("Something");
			system("pause");
		}
	}

	system("pause");
	return;
}

void Combat(ModuleCombat * combat_system)
{
	combat_system->StartCombat();

	while (combat_system->in_combat)
	{
		combat_system->InCombat();

		system("cls");
	}
	combat_system->PrintStats();
	combat_system->EndCombat();
}