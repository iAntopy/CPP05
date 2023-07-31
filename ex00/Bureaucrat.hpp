/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:53:35 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/31 19:03:41 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <ostream>
# include <exception>

class BaseGradeException: std::exception
{
	protected:
		const char*	message;
		BaseGradeException(void);
		BaseGradeException(const char *msg);
	public:
		virtual const char*	what(void) const _NOEXCEPT;;
};

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

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
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(Bureaucrat const& other);
		Bureaucrat& operator=(Bureaucrat const& other);
		~Bureaucrat(void);

		std::string const&	getName(void) const;
		uint32_t			getGrade(void) const;

		Bureaucrat& operator++(void);
		Bureaucrat& operator--(void);
		Bureaucrat& operator+=(int n);
		Bureaucrat& operator-=(int n);
};

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& obj);

#endif