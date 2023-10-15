/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:33:37 by maparigi          #+#    #+#             */
/*   Updated: 2023/10/15 18:55:50 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>

class PmergeMe {
	private:
		PmergeMe(PmergeMe const & old);
		PmergeMe & operator=(PmergeMe const & old);

    public:
		PmergeMe();
        ~PmergeMe(void);

        void sortVec(int argc, char **argv);
        void sortList(int argc, char **argv);

        class InvalidElementException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};