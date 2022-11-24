/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:42:44 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:42:45 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"

int main()
{
	std::cout << "------ Bureaucrat operation------" << std::endl;
	try {
		Bureaucrat bowman;
		Bureaucrat green(bowman);
		Bureaucrat kola;
		std::cout<< kola << std::endl;
		kola.decrementGrade();
		std::cout<< kola << std::endl;
		kola.incrementGrade();
		std::cout<< kola << std::endl;
	} catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout<< std::endl;
	std::cout << "------Bureaucrat operation 1------" << std::endl;
	try {
		Bureaucrat bowman("kissinger", 0);
		bowman.incrementGrade();
		std::cout<< bowman << std::endl;
		bowman.decrementGrade();
		std::cout<< bowman << std::endl;
	} catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout<< std::endl;
	std::cout << "------Normal operation------" << std::endl;
	try
	{
		Form form("D4C", 10, 55);
		Form form2;
		Form form3(form2);
		std::cout << form2 << std::endl;
		form2 = form;
		std::cout << form2 << std::endl;
		Bureaucrat sam;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form.beSigned(sam);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "------low grade tests-------" << std::endl;
	try{
		Form form("C34", 160, 11);
		Bureaucrat fsg;
		form.beSigned(fsg);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}