/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 03:37:42 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 03:37:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form		f1;
	Form		f2("Construction permit", 100, 80);
	Form		f99("Permit for Presidency aquisition", 2, 1);
	Form		f3(f2);
	Form		f4 = f2;

	std::cout << f2 << std::endl;
	std::cout << "f2 is signed ? : " << f2.getIsSigned() << std::endl;
	std::cout << "f2 name ? : " << f2.getName() << std::endl;
	std::cout << "f2 grade to sign : " << f2.getGradeToSign() << std::endl;
	std::cout << "f2 grade to execute : " << f2.getGradeToExecute() << std::endl;

	std::cout << std::endl << "Form constructor test : GOOD" << std::endl;
	try {
		Form	f5("Good Form", 50, 50);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "Form constructor test : Grade to sign too low" << std::endl;
	try {
		Form	f6("Bad Form signed grade", 1000, 50);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "Form constructor test : Grade to sign too high" << std::endl;
	try {
		Form	f6("Bad Form signed grade", -100, 50);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "Form constructor test : Grade to execute too low" << std::endl;
	try {
		Form	f6("Bad Form exec grade", 50, 1000);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	std::cout << std::endl << "Form constructor test : Grade to execute too high" << std::endl;
	try {
		Form	f6("Bad Form exec grade", 50, -100);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	Bureaucrat	b1("Billy Mayes", 10);
	Bureaucrat	b2("Jimbo Jones", 110);
	Bureaucrat	b0("JFC", 2);

	std::cout << std::endl << "Form Signing Test : GOOD" << std::endl;
	b1.signForm(f2);
	b2.signForm(f2);
	b2.signForm(f99);
	b0.signForm(f99);

	return (0);
}
