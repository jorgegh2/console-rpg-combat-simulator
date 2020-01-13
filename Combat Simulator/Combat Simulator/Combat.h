#ifndef __MODULECOMBAT_H__
#define __MODULECOMBAT_H__


class Character;
class ModuleCombat
{
public:
	ModuleCombat() {};
	void StartCombat();
	void PrintStats();
	void InCombat();
	void CleanAndPrintStats();
	void EndCombat();

public:
	bool in_game = true;
	bool in_combat = true;
	Character* character1 = nullptr;
	Character* character2 = nullptr;
};
#endif //__MODULECOMBAT_H__

