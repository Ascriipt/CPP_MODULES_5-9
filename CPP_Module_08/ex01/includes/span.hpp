/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:30:37 by red               #+#    #+#             */
/*   Updated: 2023/09/30 22:08:02 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <stdexcept>

class span {
    private:
        span();
        span( const span & old );
        unsigned int _size;
        unsigned int _msize;
        std::vector<int> _integers;
    public:
        span( unsigned int N );
        ~span( );
        span & operator=( const span & old );

        int     longestSpan();
        int     shortestSpan();

        void    addNumber( int N );

        class tooManyStoredIntegers : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return  ("The Integer stocking capacity of the specified container is full");
                };
        };
        class tooFewStoredIntegers : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return  ("There are too few integers to interact with this container");
                }  
        };
};