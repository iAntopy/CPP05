/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:54:17 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 05:54:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		jim;
	AForm*		form;
	Bureaucrat	b3("gibly", 80);
	Bureaucrat	b2("Big boy pants", 30);
	Bureaucrat	b1("El Presidente", 1);


	form = jim.makeForm("shrubbery creation", "Bob Ross");
	if (form)
	{
		std::cout << *form << std::endl;
		b1.signForm(*form);
		b3.executeForm(*form);
		delete form;
	}
	form = jim.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << std::endl;
		b1.signForm(*form);
		b3.executeForm(*form);
		b2.executeForm(*form);
		delete form;
	}

	form = jim.makeForm("presidential pardon", "Steve Bannon");
	if (form)
	{
		std::cout << *form << std::endl;
		b1.signForm(*form);
		b3.executeForm(*form);
		b1.executeForm(*form);
		delete form;
	}

	std::cout << std::endl;
	form = jim.makeForm("X TOP SECRET X", "NowheresVille");
	if (form)
	{
		std::cout << *form << std::endl;
		b1.signForm(*form);
		b3.executeForm(*form);
		b1.executeForm(*form);
		delete form;
	}

	return (0);
}