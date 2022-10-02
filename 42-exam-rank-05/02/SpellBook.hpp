#pragma once

#include <iostream>
#include <vector>
#include "ASpell.hpp"

class SpellBook{
public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	ASpell* createSpell(const std::string &spellName);

private:
	SpellBook(const SpellBook &other);
	SpellBook operator=(const SpellBook &other);
	std::vector<ASpell *> spells;
};