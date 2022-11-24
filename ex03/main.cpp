/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:36 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:51:37 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include "Intern.hpp"

int main()
{
	std::cout << "------Intern with an attitude--------\n";
	AForm *ppf = NULL, *bonkers = NULL;
	try{
		Intern heba;
		Bureaucrat Khan("Khan", 25);
		Bureaucrat amina("amina", 1);
		std::cout << "\033[0;35m";
		ppf = heba.makeForm("presidential pardon", "wasiq");
		bonkers = heba.makeForm("Dinner out", "wasiq");
		amina.executeForm(*bonkers);
		amina.executeForm(*ppf);
		std::cout << "\033[0m";
	}catch (const std::exception& e){
		std::cout << "\033[0m";
		std::cout << e.what() << ": You messed up"<< std::endl;
	}
	delete ppf;
	delete bonkers;
	ppf = NULL;
	std::cout << "\n------Intern check--------\n";
	try{
		Intern heba;
		Bureaucrat Khan("Khan", 25);
		Bureaucrat amina("amina", 1);
		std::cout << "\033[0;35m";
		ppf = heba.makeForm("presidential pardon", "wasiq");
		amina.executeForm(*ppf);
		amina.signForm(*ppf);
		amina.executeForm(*ppf);
		delete ppf;
		std::cout << "\033[0m";
	}catch (const std::exception& e){
		std::cout << "\033[0m";
		delete ppf;
		std::cout << e.what() << ": You messed up"<< std::endl;
	}
	return 0;
}