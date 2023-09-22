/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:55:04 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 11:05:47 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() : _type("") {}

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::ATarget(const ATarget& source) {
	*this = source;
}

ATarget& ATarget::operator=(const ATarget& source) {
	_type = source._type;
	return *this;
}

ATarget::~ATarget() {}

const std::string&	ATarget::getType() const {
	return _type;
}

void			ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}