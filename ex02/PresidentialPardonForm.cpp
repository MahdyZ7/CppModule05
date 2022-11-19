# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("Presidential Pardon Form", 25, 5)
{
	std::cout << "Presidential Pardon Form defaut constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	Form(other)
{
	std::cout << "Presidential Pardon Form copy constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon Form destructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	this->setIsSigned(other.getIsSigned());
	std::cout << "Presidential Pardon Form operator copy constructor" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &other)
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