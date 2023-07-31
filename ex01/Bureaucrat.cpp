/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:54:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/31 19:19:54 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

BaseGradeException::BaseGradeException(void): message("Grade Exception") {};
BaseGradeException::BaseGradeException(const char *msg): message(msg) {};
const char*	BaseGradeException::what(void) const _NOEXCEPT {return (this->message);}

Bureaucrat::GradeTooHighException::GradeTooHighException(void): BaseGradeException("Grade too high exception") {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg): BaseGradeException(msg) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void): BaseGradeException("Grade too low exception") {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg): BaseGradeException(msg) {}

Bureaucrat::Bureaucrat(void) : _name("ANONYMOUS"), _grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor" << std::endl;
	if (grade > 150)
		throw GradeTooLowException("Cannot create Bureaucrat with grade lower than 150");
	else if (grade < 1)
		throw GradeTooHighException("Cannot create Bureaucrat with grade higher than 1");
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& other): _name(other._name), _grade(other._grade)//: name(other.getName()), grade(other.getGrade()) {}
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	this->_grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string const&	Bureaucrat::getName(void) const {return (this->_name);}
uint32_t			Bureaucrat::getGrade(void) const {return (this->_grade);}

bool	Bureaucrat::signForm(Form& f) const
{
	bool	success;

	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
		success = true;
	}
	catch(const BaseGradeException& e)
	{
		std::cerr << _name << " couldn't sign " << f.getName() << " because : " << e.what() << std::endl;
		success = false;
	}
	return (success);
}

Bureaucrat& Bureaucrat::operator++(void)
{
	if (_grade <= 1)
		throw GradeTooHighException("Cannot promote bureaucrat to grade higher than 1");
	this->_grade--;
	return (*this);
}

Bureaucrat& Bureaucrat::operator--(void)
{
	if (_grade >= 150)
		throw GradeTooLowException("Cannot demote bureaucrat to grade lower than 150");
	this->_grade++;
	return (*this);
}

Bureaucrat& Bureaucrat::operator+=(int n)
{
	if ((_grade - n) < 1)
		throw GradeTooHighException("Cannot promote bureaucrat to grade higher than 1");
	this->_grade -= n;
	return (*this);
}

Bureaucrat& Bureaucrat::operator-=(int n)
{
	if ((_grade + n) > 150)
		throw GradeTooLowException("Cannot demote bureaucrat to grade lower than 150");
	this->_grade += n;
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& obj)
{
	o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return (o);
}
