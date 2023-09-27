/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:44:03 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 09:59:46 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

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
		void		forgetTargetType(std::string const &type);
		ATarget*	createTarget(std::string const &type);
};

#endif