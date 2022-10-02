#include "SpellBook.hpp"
#include <iostream>

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end())
	{
		delete *it;
		++it;
	}
	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if(!spell)
		return;
	std::vector<ASpell *>::iterator it = spells.begin();
	while(it!=spells.end() && (*it)->getName()!=spell->getName())
		++it;
	if(it==spells.end())
		spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end() && (*it)->getName() != spellName)
		++it;
	if (it != spells.end()){
		delete *it;
		spells.erase(it);
	}
}

ASpell* SpellBook::createSpell(const std::string &spellName)
{
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end() && (*it)->getName() != spellName)
		++it;
	if (it != spells.end())
		return (*it);
	return 0;
}
