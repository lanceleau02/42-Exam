/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:47:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/26 17:38:34 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (size_t i = 0; i < _targets.size(); i++)
		delete _targets[i];
}

void		TargetGenerator::learnTargetType(ATarget* type) {
	_targets.push_back(type->clone());
}

void		TargetGenerator::forgetTargetType(std::string const &type) {
	for (size_t i = 0; i < _targets.size(); i++) {
		if (_targets[i] != NULL && _targets[i]->getType() == type)
			delete _targets[i];
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &type) {
	for (size_t i = 0; i < _targets.size(); i++) {
		if (_targets[i] != NULL && _targets[i]->getType() == type)
			return _targets[i];
	}
	return NULL;
}