/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:45:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 11:18:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() : _name(""), _effects("") {}

ASpell::ASpell(const std::string& name, const std::string& effects) : _name(name), _effects(effects) {}

ASpell::ASpell(const ASpell& source) {
	*this = source;
}

ASpell& ASpell::operator=(const ASpell& source) {
	_name = source._name;
	_effects = source._effects;
	return *this;
}

ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {
	return _name;
}

const std::string&	ASpell::getEffects() const {
	return _effects;
}

void				ASpell::launch(const ATarget& param) {
	param.getHitBySpell(*this);
}