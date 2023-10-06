/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:58:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 15:58:05 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {
	for (size_t i = 0; i < _spells.size(); i++)
		_spells[i] = NULL;
}

SpellBook::~SpellBook() {
	for (size_t i = 0; i < _spells.size(); i++) {
		if (_spells[i] != NULL) {
			delete _spells[i];
			_spells[i] = NULL;
		}
	}
}

void	SpellBook::learnSpell(ASpell* spell) {
	if (spell != NULL)
		_spells.push_back(spell->clone());
}

void	SpellBook::forgetSpell(const std::string& spellName) {
	for (size_t i = 0; i < _spells.size(); i++) {
		if (_spells[i] != NULL && _spells[i]->getName() == spellName) {
			delete _spells[i];
			_spells[i] = NULL;
		}
	}
}

ASpell*	SpellBook::createSpell(const std::string& spellName) {
	for (size_t i = 0; i < _spells.size(); i++)
		if (_spells[i] != NULL && _spells[i]->getName() == spellName)
			return _spells[i];
	return NULL;
}