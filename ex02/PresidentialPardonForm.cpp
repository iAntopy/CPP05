/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 07:58:07 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 07:58:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", 25, 5),
	_target("General_purpose")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("Presidential Pardon Form", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other),
	_target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

bool    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    _check_exec_requirements(executor);

    std::cout << "Congratulations " << _target << ", you have formally been pardoned by President Zaphod Beeblebrox for your filthy, filthy crimes. Now go. He doesn't appreciate your kind loitering around here." << std::endl;
    return (true);
}
