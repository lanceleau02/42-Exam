/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:45:18 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/26 12:48:21 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const std::string& name, const std::string& effects) : name(name), effects(effects) {}

ASpell::ASpell(const ASpell& source) {
	*this = source;
}

ASpell& ASpell::operator=(const ASpell& source) {
	name = source.name;
	effects = source.effects;
	return *this;
}

ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {
	return name;
}

const std::string&	ASpell::getEffects() const {
	return effects;
}

void				ASpell::launch(const ATarget& param) {
	param.getHitBySpell(*this);
}