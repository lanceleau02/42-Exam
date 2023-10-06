/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:15:47 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:21:13 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
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
	if (spell != NULL)
		_spellBook.learnSpell(spell);
}

void				Warlock::forgetSpell(std::string spellName) {
	_spellBook.forgetSpell(spellName);
}

void				Warlock::launchSpell(std::string spellName, const ATarget& target) {
	ASpell*	tmp = _spellBook.createSpell(spellName);
	if (tmp != NULL)
		tmp->launch(target);
}