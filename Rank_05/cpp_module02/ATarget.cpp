/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:55:04 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/25 15:02:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string& type) : type(type) {}

ATarget::ATarget(const ATarget& source) {
	*this = source;
}

ATarget& ATarget::operator=(const ATarget& source) {
	type = source.type;
	return *this;
}

ATarget::~ATarget() {}

const std::string&	ATarget::getType() const {
	return type;
}

void			ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}