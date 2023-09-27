/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:50:31 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/27 09:49:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string	_type;

	public:
		ATarget();
		ATarget(const std::string& type);
		ATarget(const ATarget& source);
		ATarget& operator=(const ATarget& source);
		virtual ~ATarget();
		
		const std::string&	getType() const;
		virtual ATarget*	clone() const = 0;
		void				getHitBySpell(const ASpell& spell) const;
};

#endif