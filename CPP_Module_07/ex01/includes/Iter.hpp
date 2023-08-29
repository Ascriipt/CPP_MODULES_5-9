/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:44:36 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/26 21:49:19 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< typename T >

void	Iter( T *tab, size_t tabLength, void (*func)(T&) ) {
	for (size_t i = 0; i < tabLength; i++) {
		func(tab[i]);
	}
}

template< typename T >

void	printValue( T &data )
{
	std::cout << data << std::endl;
}