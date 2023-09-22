/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:15:47 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 11:38:16 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	for (size_t i = 0; i < _spells.size(); i++)
		if (_spells[i] != NULL)
			delete _spells[i];
}

const std::string&	Warlock::getName() const {
	return _name;
}

const std::string&	Warlock::getTitle() const {
	return _title;
}

void				Warlock::setTitle(const std::string& title) {
	_title = title;
}

void				Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void				Warlock::learnSpell(ASpell* spell) {
	_spells.push_back(spell);
}

void				Warlock::forgetSpell(std::string spellName) {
	for (size_t i = 0; i < _spells.size(); i++) {
		if (_spells[i] != NULL && _spells[i]->getName() == spellName) {
			delete _spells[i];
			_spells[i] = NULL;
		}
	}
}

void				Warlock::launchSpell(std::string spellName, ATarget& target) {
	for (size_t i = 0; i < _spells.size(); i++)
		if (_spells[i] != NULL && _spells[i]->getName() == spellName)
			target.getHitBySpell(*_spells[i]);
}