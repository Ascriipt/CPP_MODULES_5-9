/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: red <red@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:30:37 by red               #+#    #+#             */
/*   Updated: 2023/09/03 20:49:07 by red              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class span {
    private:
        int *_integers;
    public:
        class tooManyStoredIntegers : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return  ("The Integer stocking capacity of the specified container is full");
                };
        };
};