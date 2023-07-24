/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 06:26:41 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 06:26:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <random>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm&  operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm(void);

		bool    execute(const Bureaucrat& executor) const;        
};

#endif