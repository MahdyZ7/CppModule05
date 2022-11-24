/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:47:06 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:47:07 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon Form", 25, 5, "NULL_HELL")
{
	std::cout << "Presidential Pardon Form defaut constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm("Presidential Pardon Form", 25, 5, target)
{
	std::cout << "Presidential Pardon Form Target constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other)
{
	std::cout << "Presidential Pardon Form copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon Form destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Presidential Pardon Form Assignment Operator" << std::endl;
	AForm::operator=(other);
	return *this;
}

bool PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (AForm::execute(executor) == false)
		return false;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return true;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &other)
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