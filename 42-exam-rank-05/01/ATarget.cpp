#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(){}

ATarget::~ATarget(){}

ATarget::ATarget(const std::string &type) :
	type(type)
{}

ATarget &ATarget::operator=(const ATarget &other)
{
	type = other.type;
	return (*this);
}

ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

const std::string &ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
