/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:54:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/28 15:59:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("ANONYMOUS"), grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : name(other.getName()), grade(other.getGrade()) {}
Bureaucrat::~Bureaucrat(void) {}

std::string const&	Bureaucrat::getName(void) const {return (this->name);}
uint32_t			Bureaucrat::getGrade(void) const {return (this->grade);}
