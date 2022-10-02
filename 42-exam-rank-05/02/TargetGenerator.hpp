#pragma once

#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator{
public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *target);
	void forgetTargetType(const std::string &targetName);
	ATarget *createTarget(const std::string &targetName);

private:
	TargetGenerator(const TargetGenerator &other);
	TargetGenerator operator=(const TargetGenerator &other);
	std::vector<ATarget *> targets;
};