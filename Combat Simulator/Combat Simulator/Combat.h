#ifndef __MODULECOMBAT_H__
#define __MODULECOMBAT_H__


class Character;
class ModuleCombat
{
public:
	ModuleCombat() {};
	void StartCombat();
	void EnemyStatsByLvl(int lvl);
	void PlayerStatsByLvl(int lvl);
	void PrintStats();
	void InCombat();
	void EnemyTurn();
	void PlayerTurn();
	void RewriteInCombat();
	void EndCombat();

public:
	bool in_game = true;
	bool in_combat = true;
	Character* character1 = nullptr;
	Character* character2 = nullptr;

	int attack_modifier = 0;
	int defense_modifier = 0;
};
#endif //__MODULECOMBAT_H__

