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
    Bureaucrat              b0("Mr. Nobody", 150);
    ShrubberyCreationForm   sf1("Cousin Bob's");
    Bureaucrat              b1("Definitly not Bob (Bob with moustache)", 140);
    RobotomyRequestForm     rf1("Bender");
    Bureaucrat              b2("Aunt Janine", 70);
    PresidentialPardonForm  pf1("Jebediah Plimbo");
    Bureaucrat              b3("Lord Emperor scribe", 20);
    Bureaucrat              b4("Lord Emperor assistant", 5);

    std::cout << std::endl << "Schrubbery creation procedure tests: " << std::endl;
    std::cout << "Try execute before signing : " << std::endl;
    try {b4.executeForm(sf1);}
    catch (std::exception &e) {}
    try {b0.signForm(sf1);}
    catch (std::exception &e) {}
    try {b1.signForm(sf1);}
    catch (std::exception &e) {}
    try {b1.executeForm(sf1);}
    catch (std::exception &e) {}
    try {b2.executeForm(sf1);}
    catch (std::exception &e) {}


    std::cout << std::endl << "Robotomy procedure tests: " << std::endl;
    std::cout << "Try execute before signing : " << std::endl;
    try {b4.executeForm(rf1);}
    catch (std::exception &e) {}
    try {b1.signForm(rf1);}
    catch (std::exception &e) {}
    try {b2.signForm(rf1);}
    catch (std::exception &e) {}
    try {b2.executeForm(rf1);}
    catch (std::exception &e) {}
    try {b3.executeForm(rf1);}
    catch (std::exception &e) {}

    std::cout << std::endl << "Presidential pardon procedure tests: " << std::endl;
    std::cout << "Try execute before signing : " << std::endl;
    try {b4.executeForm(pf1);}
    catch (std::exception &e) {}
    try {b2.signForm(pf1);}
    catch (std::exception &e) {}
    try {b3.signForm(pf1);}
    catch (std::exception &e) {}
    try {b3.executeForm(pf1);}
    catch (std::exception &e) {}
    try {b4.executeForm(pf1);}
    catch (std::exception &e) {}

    std::cout << std::endl;
    return (0);
}