#include "TargetGenerator.hpp"
#include <iostream>

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::vector<ATarget *>::iterator it = targets.begin();
	while (it != targets.end())
	{
		delete *it;
		++it;
	}
	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if(!target)
		return;
	std::vector<ATarget *>::iterator it = targets.begin();
	while(it!=targets.end() && (*it)->getType()!=target->getType())
		++it;
	if(it==targets.end())
		targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const std::string &targetType)
{
	std::vector<ATarget *>::iterator it = targets.begin();
	while (it != targets.end() && (*it)->getType() != targetType)
		++it;
	if (it != targets.end()){
		delete *it;
		targets.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &targetType)
{
	std::vector<ATarget *>::iterator it = targets.begin();
	while (it != targets.end() && (*it)->getType() != targetType)
		++it;
	if (it != targets.end())
		return (*it);
	return 0;
}
