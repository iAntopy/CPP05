/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:01:25 by iamongeo          #+#    #+#             */
/*   Updated: 2023/07/31 19:01:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1;
	Bureaucrat	b2("Bobby", 42);
	Bureaucrat	b3;
	Bureaucrat	b4(b2);
	//Bureaucrat	b5("Jimmy", 1000);/* Throws Grade too low exception */

	b3 = b2;

	std::cout << std::endl << "b1 vs b2 vs b3 vs b4 ? : "<< std::endl << b1 << b2 << b3 << b4 << std::endl;

	try {
		Bureaucrat	b5("GoodBoy", 10);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	try {
		Bureaucrat	b6("BadBoy", 1000);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}

	try {
		Bureaucrat	b7("BadBoy", 0);}
	catch (const BaseGradeException& e){
		std::cerr << e.what() << std::endl;}


	std::cout << std::endl;
	std::cout << "Bureaucrat info :" << std::endl;
	std::cout << b2 << std::endl;
	std::cout << "Bureaucrat info after promotion:" << std::endl;
	std::cout << ++b2 << std::endl;
	std::cout << "Bureaucrat info after demotion:" << std::endl;
	std::cout << --b2 << std::endl;
	std::cout << "Bureaucrat info after 2x promotion:" << std::endl;
	std::cout << (b2 += 2) << std::endl;
	std::cout << "Bureaucrat info after 10x demotion:" << std::endl;
	std::cout << (b2 -= 10) << std::endl;

	std::cout << "Bureaucrat when they try to play god:" << std::endl;
	try {
		std::cout << (b2 += 9000) << std::endl;}
	catch (BaseGradeException& e) {
		std::cerr << e.what() << std::endl;}

	return (0);
}