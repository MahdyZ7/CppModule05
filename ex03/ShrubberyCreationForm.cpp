/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:53 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:51:54 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	Form("Chrubbery Creation Form", 145, 137)
{
	std::cout << "Chrubbery Creation Form defaut constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	Form("Chrubbery Creation Form", 145, 137, target)
{
	std::cout << "Chrubbery Creation Form Target constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	Form(other)
{
	std::cout << "Chrubbery Creation Form copy constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Chrubbery Creation Form destructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Chrubbery Creation Form Assignment Operator" << std::endl;
	Form::operator=(other);
	return *this;
}

bool ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{	
	if (this->getIsSigned() == false || this->getEGrade() < executor.getGrade())
		return(Form::execute(executor));
	std::ofstream 	fout;
	std::string		outfile = this->getTarget() + "_shrubbery";
	fout.open(outfile.c_str());
	if (fout.is_open() == false)
	{
		std::cout << "Error: Unable to open file " << outfile << std::endl;
		return(false);
	}
	fout << SHRUBTREE;
	fout.close();
	return(Form::execute(executor));
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm &other)
{
	os << "The form " << other.getName();

	if (other.getIsSigned())
		os << " is signed, it can be excuted by a level " << other.getEGrade() << " bureaucrat";
	else
	{
		os << " is not signed, it requires a level " << other.getSGrade() << " bureaucrat to sign it";
		os << " and a level " << other.getEGrade() << " bureaucrat to excute it";
	}
	return os;
}
