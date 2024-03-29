/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:45:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 15:43:42 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string& name, const std::string& effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell& source) {
	*this = source;
}

ASpell& ASpell::operator=(const ASpell& source) {
	if (this != &source) {
		_name = source._name;
		_effects = source._effects;
	}
	return *this;
}

ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {
	return _name;
}

const std::string&	ASpell::getEffects() const {
	return _effects;
}

void				ASpell::launch(const ATarget& target) {
	target.getHitBySpell(*this);
}