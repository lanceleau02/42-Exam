/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:09:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/10/06 16:21:04 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
	private:
		std::string				_name;
		std::string				_title;
		SpellBook				_spellBook;
		
		Warlock();
		Warlock(const Warlock& source);
		Warlock& operator=(const Warlock& source);

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();
		
		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(const std::string& title);
		void				introduce() const;
		void				learnSpell(ASpell* spell);
		void				forgetSpell(std::string spellName);
		void				launchSpell(std::string spellName, const ATarget& target);
};

#endif