#include "Warlock.hpp"
#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title) :
	name(name),
	title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end())
	{
		delete *it;
		++it;
	}
	spells.clear();
}

const std::string &Warlock::getName() const
{
	return name;
}

const std::string &Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void Warlock::learnSpell(ASpell *spell)
{
	if(!spell)
		return;
	std::vector<ASpell *>::iterator it = spells.begin();
	while(it!=spells.end() && (*it)->getName()!=spell->getName())
		++it;
	if(it==spells.end())
		spells.push_back(spell);
}

void Warlock::forgetSpell(const std::string &spellName)
{
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end() && (*it)->getName() != spellName)
		++it;
	if (it != spells.end()){
		delete *it;
		spells.erase(it);
	}
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target)
{
	std::vector<ASpell *>::iterator it = spells.begin();
	while (it != spells.end() && (*it)->getName() != spellName)
		++it;
	if (it != spells.end())
		(*it)->launch(target);
}
