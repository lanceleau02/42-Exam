/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:38:31 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:04:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	_name;
		std::string	_effects;
	
	public:
		ASpell();
		ASpell(const std::string& name, const std::string& effects);
		ASpell(const ASpell& source);
		ASpell& operator=(const ASpell& source);
		virtual ~ASpell();
		
		const std::string&	getName() const;
		const std::string&	getEffects() const;
		virtual ASpell*		clone() const = 0;
		void				launch(const ATarget& target);
};

#endif