/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:30:37 by red               #+#    #+#             */
/*   Updated: 2023/09/02 11:59:56 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>

int        easyfind(T &container, int n)
{
    typename T::iterator head = container.begin();
    typename T::iterator tail = container.end();

    while (head != tail)
    {
        if (*head == n)
            return (*head);
        head++;
    }
    return (-1);
}