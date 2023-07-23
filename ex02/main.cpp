/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 05:54:17 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 05:54:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    ShrubberyCreationForm   sf1("Cousin Bob's");
    Bureaucrat              b1("Definitly not Bob (Bob with moustache)", 2);
    RobotomyRequestForm     rf1("Fry");
    Bureaucrat              b2("Aunt Janine", 70);
    PresidentialPardonForm  pf1("Guiguidi Plimbo");
    Bureaucrat              b3("Lord Emperor scribe", 20);
    Bureaucrat              b4("Lord Emperor assistant", 5);

    b1.signForm(sf1);
    b1.executeForm(sf1);

    b2.signForm(rf1);
    b1.executeForm(rf1);

    b3.signForm(pf1);
    b4.executeForm(pf1);

    return (0);
}