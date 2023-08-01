/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 06:28:20 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 06:28:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request Form", 72, 45), _target("General_purpose")
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor. sign grade : " << getGradeToSign() << ", exec grade : " << getGradeToExecute() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

bool    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	std::random_device	rd;
	int                 pick = rd() % 2;

	_check_exec_requirements(executor);

	std::cout << std::endl << " * ROBOTOMY PROCEDURE ENGAGED * " << std::endl;
	std::cout << "BZZZZZZZZZZZZZGHRGHRGHRHGRHGHRGHRKKKKKJJJJZZZZZZZZZ BLIP BLOOP" << std::endl;
	if (pick)
		std::cout << " * PROCEDURE OVER * LEAVE ALL YOUR POSSESSIONS AT THE FRONT DESK * AND WE WELCOME YOU " << _target << " TO OUR GREAT FAMILY :: HAIL MOM !! * GOOD BYE * bzt *" << std::endl;
	else
	{
		std::cout << " * PROCEDURE OVER * WE APPRECIATE YOU TRUSTING US FOR YOUR ROBOTOMY NEEDS * blip boop OUYYYUOOUYYUOOUYYUOO !!! " << std::endl;
		std::cout << " * Diagnostic : Low resistance to holes drilling. * " << std::endl;
		std::cout << " * " << _target << " * PRESENT YOURSELF TO YOUR LOCAL RECYCLING FACILITY FOR DISPOSAL * GOOD BYE * " << std::endl;
	}
	return (true);
}
