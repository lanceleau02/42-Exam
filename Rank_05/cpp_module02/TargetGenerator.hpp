/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:44:03 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:06:00 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator {
	private:
		std::vector<ATarget*>	_targets;
		
		TargetGenerator(const TargetGenerator& source);
		TargetGenerator& operator=(const TargetGenerator& source);

	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget* type);
		void		forgetTargetType(const std::string& targetType);
		ATarget*	createTarget(const std::string& targetType);
};

#endif