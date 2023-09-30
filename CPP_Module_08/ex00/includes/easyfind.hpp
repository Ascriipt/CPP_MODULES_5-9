/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:30:37 by red               #+#    #+#             */
/*   Updated: 2023/09/30 19:32:54 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& t, int toFind)
{
	if (std::find(t.begin(), t.end(), toFind) == t.end())
		throw std::length_error("the list does not contain your object");
	return (std::find(t.begin(), t.end(), toFind));
}