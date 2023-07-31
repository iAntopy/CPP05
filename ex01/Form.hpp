/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 02:42:24 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 02:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <string>

class Bureaucrat;

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;

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

	public:
		Form(void);
		Form(const std::string& name, int sign_grade, int exec_grade);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form(void);

		const std::string&  getName(void) const;
		bool	getIsSigned(void) const;
		int		getGradeToSign(void) const;
		int		getGradeToExecute(void) const;

		Form&	beSigned(const Bureaucrat&);
};

std::ostream&	operator<<(std::ostream& o, const Form& obj);

#endif
