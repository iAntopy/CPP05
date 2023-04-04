/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:53:35 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/28 15:59:29 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <string>

class Bureaucrat
{
	private:
		std::string const   name;
		uint32_t           grade;
	public:
		Bureaucrat( void );
		Bureaucrat(Bureaucrat const& other);
		Bureaucrat&    operator=(Bureaucrat const& other);
		~Bureaucrat( void );

		std::string const&	getName(void) const;
		uint32_t			getGrade(void) const;
};

#endif