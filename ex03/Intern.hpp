/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:53:24 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/31 22:04:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:

		typedef AForm* (*__factory_method_t)(const std::string& target);

		typedef	struct	s_form_index
		{
			const std::string	form_name;
			__factory_method_t	factory_method;
			//AForm* (*factory_method)(const std::string& target);
		}	t_form_index;

		static t_form_index	factory_index[3];

		static AForm*	get_shrubbery_creation_form(const std::string& target);
		static AForm*	get_robotomy_request_form(const std::string& target);
		static AForm*	get_presidential_pardon_form(const std::string& target);

	public:

		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);		
		~Intern(void);

		AForm*	makeForm(const std::string& form_name, const std::string& target) const;
};

#endif