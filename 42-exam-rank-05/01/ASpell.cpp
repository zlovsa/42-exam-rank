#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(){}

ASpell::~ASpell(){}

ASpell::ASpell(const std::string &name, const std::string &effects) :
	name(name),
	effects(effects)
{}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}

ASpell &ASpell::operator=(const ASpell &other)
{
	name = other.name;
	effects = other.effects;
	return (*this);
}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

const std::string &ASpell::getName() const
{
	return name;
}

const std::string &ASpell::getEffects() const
{
	return effects;
}
