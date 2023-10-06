/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:53:38 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:05:38 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include <string>
#include <vector>

#include "ASpell.hpp"

class SpellBook {
	private:
		std::vector<ASpell*>	_spells;
		
		SpellBook(const SpellBook& source);
		SpellBook& operator=(const SpellBook& source);
	
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell* spell);
		void	forgetSpell(const std::string& spellName);
		ASpell*	createSpell(const std::string& spellName);
};

#endif