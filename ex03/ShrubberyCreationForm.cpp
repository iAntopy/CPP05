/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 04:40:42 by marvin            #+#    #+#             */
/*   Updated: 2023/07/23 04:40:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation Form", 145, 137),
	_target("General_purpose")
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("Shrubbery Creation Form", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm constructor. exec grade : " << getGradeToExecute() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

void	ShrubberyCreationForm::get_ascii_tree(std::string& tree) const
{
	std::random_device	rd;
	int					type = rd() % 3;

	if (type == 0)
	{
		tree += "             v .   ._, |_  .,			\n";
		tree += "           `-._\\/  .  \\ /    |/_		\n";
		tree += "               \\  _\\, y | \\//		\n";
		tree += "         _\\_.___\\, \\/ -.\\||			\n";
		tree += "           `7-,--.`._||  / / ,			\n";
		tree += "           /'     `-. `./ / |/_.'		\n";
		tree += "                     |    |//			\n";
		tree += "                     |_    /			\n";
		tree += "                     |-   |				\n";
		tree += "                     |   =|				\n";
		tree += "                     |    |				\n";
		tree += "--------------------/ ,  . \\--------._	\n\n\n";
	}
	else if (type == 1)
	{
		tree += "            .        +          .      .          .	\n";
		tree += "     .            _        .                    .		\n";
		tree += "  ,              /;-._,-.____        ,-----.__			\n";
		tree += " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,		\n";
		tree += "  `                 \\   _|`'=:_::.`.);  \\ __/ /		\n";
		tree += "                      ,    `./  \\:. `.   )==-'  .		\n";
		tree += "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .	\n";
		tree += ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o			\n";
		tree += "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .	\n";
		tree += "  .      ,=':  \\    ` `/` ' , , ,:' `'--'.--'---._/`7	\n";
		tree += "   `.   (    \\: \\,-._` ` + '\\, ,'   _,--._,---':.__/	\n";
		tree += "              \\:  `  X` _| _,\\/'   .-'				\n";
		tree += ".               ':._:`\\____  /:'  /      .           .	\n";
		tree += "                    \\::.  :\\/:'  /              +		\n";
		tree += "   .                 `.:.  /:'  }      .				\n";
		tree += "           .           ):_(:;   \\           .			\n";
		tree += "                      /:. _/ ,  |						\n";
		tree += "                   . (|::.     ,`                  .	\n";
		tree += "     .                |::.    {\\						\n";
		tree += "                      |::.\\  \\ `.						\n";
		tree += "                      |:::(\\    |						\n";
		tree += "              O       |:::/{ }  |                  (o	\n";
		tree += "               )  ___/#\\::`/ (O '==._____   O, (O  /`	\n";
		tree += "          ~~~w/w~'~~,\\` `:/,-(~`'~~~~~~~~'~o~\\~/~w|/~	\n\n\n";
	}
	else
	{
		tree += "                   ; ; ;									\n";
		tree += "                   ;        ;  ;     ;;    ;				\n";
		tree += "                ;                 ;         ;  ;			\n";
		tree += "                                ;							\n";
		tree += "                               ;                ;;			\n";
		tree += "               ;          ;            ;              ;		\n";
		tree += "               ;            ';,        ;               ;	\n";
		tree += "               ;              'b      *						\n";
		tree += "                ;              '$    ;;                ;;	\n";
		tree += "               ;    ;           $:   ;:               ;		\n";
		tree += "             ;;      ;  ;;      *;  @):        ;   ; ;		\n";
		tree += "                          ;     :@,@):   ,;**:'   ;			\n";
		tree += "              ;      ;,         :@@*: ;;**'      ;   ;		\n";
		tree += "                       ';o;    ;:(@';@*''  ;				\n";
		tree += "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;		\n";
		tree += "                          ,p$q8,:@)'  ;p*'      ;			\n";
		tree += "                   ;     '  ; '@@Pp@@*'    ;  ;				\n";
		tree += "                    ;  ; ;;    Y7'.'     ;  ;				\n";
		tree += "                              :@):.							\n";
		tree += "                             .:@:'.							\n";
		tree += "                           .::(@:.\n\n\n";
	}
}

bool    ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::fstream	file;
	std::string		filename;
	std::string		tree;

	_check_exec_requirements(executor);
//		throw GradeTooLowException("Grade insufficient to execute this form");

	get_ascii_tree(tree);
//	std::cout << tree << std::endl;

	filename = _target + "_shrubbery";
	file.open(filename, std::fstream::out | std::fstream::app);
	if (file.is_open())
	{
		file << tree;
		if (file.fail())
			std::cerr << "OOPS ! Tried to write to file but something failed" << std::endl;
	}
	else
		std::cerr << "OOPS ! Failed to open file" << std::endl;
	file.close();
	return (true);
}
