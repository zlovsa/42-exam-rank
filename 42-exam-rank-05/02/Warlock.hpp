#pragma once

#include <iostream>
#include <vector>
#include "SpellBook.hpp"
#include "ATarget.hpp"

class Warlock{
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	void launchSpell(const std::string &spellName, const ATarget &target);

private:
	Warlock();
	Warlock(const Warlock &other);
	Warlock operator=(const Warlock &other);
	std::string name;
	std::string title;
	SpellBook spells;
};