/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:44:42 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/26 21:44:43 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< typename T >

void	swap( T &s1, T &s2 ) {
	T	swop;
	swop = s1;
	s1 = s2;
	s2 = swop;
}

template< typename T >

T	min( T v1, T v2 ) {
	return	v1 < v2 ? v1 : v2;
}

template< typename T >

T	max( T v1, T v2 ) {
	return	v1 > v2 ? v1 : v2;
}