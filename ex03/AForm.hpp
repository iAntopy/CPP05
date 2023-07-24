/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 04:34:49 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 04:34:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <ostream>
# include <string>

class Bureaucrat;

# include "Bureaucrat.hpp"

class BaseFormException: public std::exception{
	protected:
		const char	*message;
	public:
		BaseFormException(const char *msg);
		virtual const char*	what(void) const _NOEXCEPT;// noexcept;
};

class AForm
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;

	protected:
		class GradeTooHighException: public BaseGradeException {
			public:
				GradeTooHighException(void);
				GradeTooHighException(const char *msg);
		};
		class GradeTooLowException: public BaseGradeException {
			public:
				GradeTooLowException(void);
				GradeTooLowException(const char *msg);
		};
		class FormUnsignedException: public BaseFormException {
			public:
				FormUnsignedException(void);
				FormUnsignedException(const char *msg);
		};
		
		void	_check_exec_requirements(const Bureaucrat& bur) const;

	public:
		AForm(void);
		AForm(const std::string& name, int sign_grade, int exec_grade);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm(void);

		const std::string&  getName(void) const;
		bool getIsSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;

		AForm&	beSigned(const Bureaucrat&);
        virtual bool    execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& o, const AForm& obj);

#endif
