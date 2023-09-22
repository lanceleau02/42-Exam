/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:09:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 09:28:59 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock {
	private:
		std::string	_name;
		std::string	_title;
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
};

#endif