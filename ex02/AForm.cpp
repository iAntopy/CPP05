/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:56:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 02:56:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

BaseFormException::BaseFormException(const char *msg): message(msg) {}
const char	*BaseFormException::BaseFormException::what(void) const _NOEXCEPT {return (message);}

AForm::GradeTooHighException::GradeTooHighException(void): BaseGradeException("Grade too high exception") {}
AForm::GradeTooHighException::GradeTooHighException(const char *msg): BaseGradeException(msg) {}

AForm::GradeTooLowException::GradeTooLowException(void): BaseGradeException("Grade too low exception") {}
AForm::GradeTooLowException::GradeTooLowException(const char *msg): BaseGradeException(msg) {}

AForm::FormUnsignedException::FormUnsignedException(void): BaseFormException("Form Error : unsigned") {}
AForm::FormUnsignedException::FormUnsignedException(const char *msg): BaseFormException(msg) {}

AForm::AForm(void) : _name("Generic AForm"), _grade_to_sign(1), _grade_to_exec(1), _is_signed(false)
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string& name, int sign_grade, int exec_grade): _name(name),
	_is_signed(false), _grade_to_sign(sign_grade), _grade_to_exec(exec_grade)
{
	std::cout << "AForm constructor" << std::endl;
	if (_grade_to_sign > 150)
		throw GradeTooLowException("Cannot create Form with grade required to sign lower than 150");
	else if (_grade_to_sign < 1)
		throw GradeTooHighException("Cannot create Form with grade required to sign higher than 1");

	if (_grade_to_exec > 150)
		throw GradeTooLowException("Cannot create Form with grade required to exec lower than 150");
	else if (_grade_to_exec < 1)
		throw GradeTooHighException("Cannot create Form with grade required to exec higher than 1");
}

AForm::AForm(AForm const& other): _name(other._name), _grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec), _is_signed(other._is_signed)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm&	AForm::operator=(const AForm& obj)
{
	std::cout << "AForm copy assignment operator" << std::endl;
	return (*this);
}

AForm::~AForm(void) {
	std::cout << "AForm destructor" << std::endl;
}

AForm&	AForm::beSigned(const Bureaucrat& bur)
{
	const int	bgrade = bur.getGrade();

	if (bgrade > _grade_to_sign)
		throw GradeTooLowException("Grade insufficient to sign this form");
	_is_signed = true;
	return (*this);
}

void	AForm::_check_exec_requirements(const Bureaucrat& bur) const
{
	if (!_is_signed)
		throw FormUnsignedException("Cannot execute an unsigned form ! That's against the code don't you know !?");
	else if (bur.getGrade() > _grade_to_exec)
		throw GradeTooLowException("Grade insufficient to execute this form");
}

const std::string&	AForm::getName(void) const {return (_name);}
bool				AForm::getIsSigned(void) const {return (_is_signed);}
int					AForm::getGradeToSign(void) const {return (_grade_to_sign);}
int					AForm::getGradeToExecute(void) const {return (_grade_to_exec);}

std::ostream&   operator<<(std::ostream& o, const AForm& obj)
{
	std::cout << std::endl;
	std::cout << "*******************************************" << std::endl;
	std::cout << "* ---------- * START OF FORM * ---------- *" << std::endl;
	std::cout << "* + AForm [ " << obj.getName() << " ]" << std::endl;
	std::cout << "*" << std::endl;
	std::cout << "* - Is signed :			[ " << (obj.getIsSigned() ? "True" : "False") << " ]" << std::endl;
	std::cout << "* - Grade required to sign :	[ " << obj.getGradeToSign() << " ]" << std::endl;
	std::cout << "* - Grade required to execute :	[ " << obj.getGradeToExecute() << " ]" << std::endl;
	std::cout << "* ----------- * END OF FORM * ----------- *" << std::endl;
	std::cout << "*******************************************" << std::endl;
	return (o);
}
