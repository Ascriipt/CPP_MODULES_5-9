/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uniix <uniix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:51:21 by uniix             #+#    #+#             */
/*   Updated: 2023/10/06 15:09:44 by uniix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

span::span() {};

span::span( unsigned int N ) : _size(0), _msize(N) {};

span::span( const span & old ) {
    if ( this != &old ) {
        _integers = old._integers;
        _msize = old._msize;
        _size = old._size;
    }
};

span & span::operator=( const span & old ) {
    if ( this != &old ) {
        if ( _msize != old._msize )
            throw std::length_error( "different size spans" );
        _integers = old._integers;
        _msize = old._msize;
        _size = old._size;
    }
    return (*this);
};

span::~span() {};

void    span::addNumber( int N ) {
    if ( _size <= _msize ) {
        _integers.push_back( N );
    }
    else
        throw span::tooManyStoredIntegers();
};

int span::longestSpan() {
    int max = _integers[0];
    int min = _integers[0];

	if (_integers.size() < 2)
		throw tooFewStoredIntegers();

    std::vector<int>::const_iterator it = _integers.begin();

    for (; it != _integers.end(); ++it) {
        int num = *it;
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }

    return max - min;
}

int     span::shortestSpan() {
    int sspan;

    if (_integers.size() < 2)
        throw   tooFewStoredIntegers();
    sspan = _integers[0];
    for ( size_t i = 0; i < _integers.size(); i++ ) {
        int span = std::abs( _integers[i] - _integers[i - 1] );
        if ( span < sspan) {
            sspan = span;
        }
    }
    return (sspan);
};