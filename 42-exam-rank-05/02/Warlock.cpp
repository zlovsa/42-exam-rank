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
	spells.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spellName)
{
	spells.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target)
{
	ASpell *spell = spells.createSpell(spellName);
	if (spell)
		spell->launch(target);
}
