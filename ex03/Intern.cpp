/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:38:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/23 21:29:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*  Intern::get_shrubbery_creation_form(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}
AForm*  Intern::get_robotomy_request_form(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
AForm*  Intern::get_presidential_pardon_form(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

Intern::t_form_index	Intern::factory_index[] = {
	{"shrubbery creation", Intern::get_shrubbery_creation_form},
	{"robotomy request", Intern::get_robotomy_request_form},
	{"presidential pardon", Intern::get_presidential_pardon_form}
};

Intern::Intern(void) {
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor" << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	std::cout << "Intern copy constructor" << std::endl;
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "Intern destructor" << std::endl;
}

AForm*	Intern::makeForm(const std::string& form_name, const std::string& target) const
{
	AForm*	form = NULL;

	for (int i=0; i < 3; i++)
	{
		if (this->factory_index[i].form_name == form_name)
			form = this->factory_index[i].factory_method(target);
	}
	if (form)
		std::cout << "Intern creates [ " << form_name << " ] form." << std::endl;
	else
		std::cerr << "[ " << form_name << " ] is not a valid form name." << std::endl;
	return (form);
}