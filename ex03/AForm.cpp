/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:44:42 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:44:43 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm(void): name("form 27B/6"), is_signed(false), s_grade(150), e_grade(150), target("NULLMAN")
{
	std::cout << "AForm Default Constructor" << std::endl;
}

AForm::AForm(const std::string& name, const int s_grade, const int e_grade)
	: name(name), is_signed(false), s_grade(s_grade), e_grade(e_grade), target("Null"){
	std::cout << "AForm parametric Constructor" << std::endl;
	if (this->s_grade < 1 || this->e_grade < 1)
		throw GradeTooHighException();
	else if (this->s_grade > 150 || this->e_grade > 150)
		throw GradeTooLowException(); 
} 

AForm::AForm(const std::string& name, const int s_grade, const int e_grade, const std::string& target)
	: name(name), is_signed(false), s_grade(s_grade), e_grade(e_grade), target(target){
	std::cout << "AForm parametric Constructor" << std::endl;
	if (this->s_grade < 1 || this->e_grade < 1)
		throw GradeTooHighException();
	else if (this->s_grade > 150 || this->e_grade > 150)
		throw GradeTooLowException(); 
} 

AForm::AForm(const AForm& other): name(other.name), is_signed(other.is_signed),
								s_grade(other.s_grade), e_grade(other.e_grade), target(other.target)
{
	std::cout << "AForm Copy Constructor " << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm Assignment Operator" << std::endl;
	if (this != &other)
	{
		const_cast<std::string&> (this->target) = other.target;
		const_cast<std::string&> (this->name) = other.name;
		const_cast<int&> (this->s_grade) = other.s_grade;
		const_cast<int&> (this->e_grade) = other.e_grade;
		this->is_signed = other.is_signed;
	}
	return (*this);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade too high exception";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade too low exception";
}

std::string AForm::getTarget(void) const
{
	return target;
}

std::string AForm::getName(void) const
{
	return name;
}

int AForm::getSGrade(void) const
{
	return s_grade;
}

int AForm::getEGrade(void) const
{
	return e_grade;
}

bool AForm::getIsSigned(void) const
{
	return is_signed;
}

bool AForm::beSigned(const Bureaucrat &lam) try
{
	if (is_signed)
	{
		std::cout << lam.getName() << " couldn’t sign " << this->name << " becuase ";
		std::cout << "the form is already signed\n";
		return false;
	}
	if (lam.getGrade() > s_grade)
		throw GradeTooLowException();
	is_signed = true;
	std::cout << lam.getName() << " signed " << this->name << std::endl;
	return true;
} catch (GradeTooLowException& e)
{
	std::cout << lam.getName() << " couldn’t sign " << this->name << " becuase ";
	std::cout << "form grade too high for bureacrate\n";
	return false;
}

bool AForm::execute(Bureaucrat const &executor) const try
{
	if (is_signed == false)
	{
		std::cout << executor.getName() << " couldn’t excute " << this->name << " becuase ";
		std::cout << "the form is not signed\n";
		return false;
	}
	if (executor.getGrade() > e_grade)
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->name << std::endl;
	return true;
} catch (GradeTooLowException& e)
{
	std::cout << executor.getName() << " couldn’t execute " << this->name << " becuase ";
	std::cout << "form grade too high for bureacrate\n";
	return false;
}

std::ostream& operator<<(std::ostream& os, const AForm &other)
{
	os << "The form " << other.getName();

	if (other.getIsSigned())
		os << " is signed, it can be excuted by a level " << other.getEGrade() << " bureacrate";
	else
	{
		os << " is not signed, it requires a level " << other.getSGrade() << " bureacrate to sign it";
		os << " and a level " << other.getEGrade() << " bureacrate to excute it";
	}
	return os;
}