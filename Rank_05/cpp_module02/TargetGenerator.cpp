/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:47:27 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:00:40 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {
	for (size_t i = 0; i < _targets.size(); i++)
		_targets[i] = NULL;
}

TargetGenerator::~TargetGenerator() {
	for (size_t i = 0; i < _targets.size(); i++) {
		if (_targets[i] != NULL) {
			delete _targets[i];
			_targets[i] = NULL;
		}
	}
}

void		TargetGenerator::learnTargetType(ATarget* type) {
	if (type != NULL)
		_targets.push_back(type->clone());
}

void		TargetGenerator::forgetTargetType(const std::string& targetType) {
	for (size_t i = 0; i < _targets.size(); i++) {
		if (_targets[i] != NULL && _targets[i]->getType() == targetType) {
			delete _targets[i];
			_targets[i] = NULL;
		}
	}
}

ATarget*	TargetGenerator::createTarget(const std::string& targetType) {
	for (size_t i = 0; i < _targets.size(); i++)
		if (_targets[i] != NULL && _targets[i]->getType() == targetType)
			return _targets[i];
	return NULL;
}