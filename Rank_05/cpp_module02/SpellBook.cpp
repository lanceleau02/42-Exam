/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:58:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 10:01:44 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (size_t i = 0; i < _spells.size(); i++)
		delete _spells[i];
}

void	SpellBook::learnSpell(ASpell* spell) {
	_spells.push_back(spell->clone());
}

void	SpellBook::forgetSpell(std::string const &spell) {
	for (size_t i = 0; i < _spells.size(); i++)
		if (_spells[i] != NULL && _spells[i]->getName() == spell)
			delete _spells[i];
}

ASpell*	SpellBook::createSpell(std::string const &spell) {
	for (size_t i = 0; i < _spells.size(); i++)
		if (_spells[i] != NULL && _spells[i]->getName() == spell)
			return _spells[i];
	return NULL;
}