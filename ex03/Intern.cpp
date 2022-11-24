/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:31 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:55:51 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

typedef AForm *(Intern::*ptr)(std::string);

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(Intern const &other)
{
	(void)other;
	std::cout << "Intern Copy Constructor" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "Intern Assignment Operator" << std::endl;
	return *this;
}

AForm *Intern::creatPPF(const std::string &target_name)
{
	return (new PresidentialPardonForm(target_name));
}

AForm *Intern::creatSCF(const std::string &target_name)
{
	return (new ShrubberyCreationForm(target_name));
}

AForm *Intern::creatRRF(const std::string &target_name)
{
	return (new RobotomyRequestForm(target_name));
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target_name)
{
	AForm *(Intern::*compl_fun[])(const std::string&) = 
		{&Intern::creatPPF, &Intern::creatSCF, &Intern::creatRRF};
	std::string comp_index[3] = 
		{"PresidentialPardonForm" , "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; ++i)
		if (form_name == comp_index[i]){
			std::cout << "Intern creates" << comp_index[i] << std::endl;
			return ((this->*(compl_fun[i]))(target_name));
		}
	std::cout << "The AForm Requested does not exist *Bloody Paperwork*\n";
	throw std::exception();
	return (NULL);
}