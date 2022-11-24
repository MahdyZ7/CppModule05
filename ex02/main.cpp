/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:45:10 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:45:11 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

int main()
{
	std::cout << "------Presidential Pardon Form operation------" << std::endl;
	try
	{
		PresidentialPardonForm form("Assange");
		PresidentialPardonForm form2;
		Bureaucrat man("Zoma", 5);
		Bureaucrat sam("Ford", 124);
		std::cout << "\033[0;35m";
		std::cout << form2 << std::endl;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form.beSigned(man);
		form2 = form;
		form2.execute(sam);
		form2.execute(man);
		std::cout << "\033[0m";
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "------Robotomy tests-------" << std::endl;
	try
	{
		RobotomyRequestForm form("Assange");
		RobotomyRequestForm form2;
		Bureaucrat man("Zoma", 42);
		Bureaucrat sam("Ford", 42);
		std::cout << "\033[0;35m";
		std::cout << form2 << std::endl;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form.beSigned(man);
		form2 = form;
		int count = 0;
		for (int i = 0; i < 200; i++){
			if(form2.execute(sam))
				++count;
		}
		std::cout << count << std::endl;
		form2.execute(man);
		std::cout << "\033[0m";
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "------Shrubbery Creation Form operation------" << std::endl;
	try
	{
		ShrubberyCreationForm form("Garden");
		ShrubberyCreationForm form2;
		Bureaucrat man("Zoma", 5);
		Bureaucrat sam("Ford", 124);
		std::cout << "\033[0;35m";
		std::cout << form2 << std::endl;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form2.beSigned(man);
		// form2 = form;
		form2.execute(sam);
		form2.execute(man);
		std::cout << "\033[0m";
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}