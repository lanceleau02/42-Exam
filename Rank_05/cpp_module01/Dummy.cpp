/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <laprieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:20:10 by laprieur          #+#    #+#             */
/*   Updated: 2023/09/22 11:07:02 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() {
	_type = "Target Practice Dummy";
}
		
ATarget*	Dummy::clone() const {
	ATarget*	clone = new Dummy();
	return clone;
}