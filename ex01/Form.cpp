/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:56:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 02:56:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(void): BaseGradeException("Grade too high exception") {}
Form::GradeTooHighException::GradeTooHighException(const char *msg): BaseGradeException(msg) {}

Form::GradeTooLowException::GradeTooLowException(void): BaseGradeException("Grade too low exception") {}
Form::GradeTooLowException::GradeTooLowException(const char *msg): BaseGradeException(msg) {}


Form::Form(void) : _name("Generic Form"), _grade_to_sign(1), _grade_to_exec(1), _is_signed(false)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string& name, int sign_grade, int exec_grade): _name(name),
	_is_signed(false), _grade_to_sign(sign_grade), _grade_to_exec(exec_grade)
{
	std::cout << "Form constructor" << std::endl;
	if (_grade_to_sign > 150)
		throw GradeTooLowException("Cannot create Form with grade required to sign lower than 150");
	else if (_grade_to_sign < 1)
		throw GradeTooHighException("Cannot create Form with grade required to sign higher than 1");

	if (_grade_to_exec > 150)
		throw GradeTooLowException("Cannot create Form with grade required to exec lower than 150");
	else if (_grade_to_exec < 1)
		throw GradeTooHighException("Cannot create Form with grade required to exec higher than 1");
}

Form::Form(Form const& other): _name(other._name), _grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec), _is_signed(other._is_signed)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form&	Form::operator=(const Form& obj)
{
	std::cout << "Form copy assignment operator" << std::endl;

//	this->_is_signed = obj.getIsSigned();
//	this->_grade_to_sign = obj.getGradeToSign();
//	this->_grade_to_exec = obj.getGradeToExecute();
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form destructor" << std::endl;
}

Form&	Form::beSigned(const Bureaucrat& bur)
{
	const int	bgrade = bur.getGrade();

	if (bgrade > _grade_to_sign)
		throw GradeTooLowException("Grade insufficient to sign this form");
	_is_signed = true;
	return (*this);
}

const std::string&	Form::getName(void) const {return (_name);}
bool				Form::getIsSigned(void) const {return (_is_signed);}
int					Form::getGradeToSign(void) const {return (_grade_to_sign);}
int					Form::getGradeToExecute(void) const {return (_grade_to_exec);}

std::ostream&   operator<<(std::ostream& o, const Form& obj)
{
	std::cout << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "* ---------- * START OF FORM * ---------- *" << std::endl;
	std::cout << "* + Form [ " << obj.getName() << " ]" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "* - Is signed :			[ " << (obj.getIsSigned() ? "True" : "False") << " ]" << std::endl;
	std::cout << "* - Grade required to sign :	[ " << obj.getGradeToSign() << " ]" << std::endl;
	std::cout << "* - Grade required to execute :	[ " << obj.getGradeToExecute() << " ]" << std::endl;
	std::cout << "* ----------- * END OF FORM * ----------- *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	return (o);
}
