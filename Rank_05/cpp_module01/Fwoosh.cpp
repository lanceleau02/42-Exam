/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:12:43 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 11:07:27 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {
	_name = "Fwoosh";
	_effects = "fwooshed"; 
}
		
ASpell*	Fwoosh::clone() const {
	ASpell*	clone = new Fwoosh();
	return clone;
}