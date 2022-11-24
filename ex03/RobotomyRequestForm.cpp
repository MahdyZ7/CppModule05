#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("Robotomy Request Form", 72, 45)
{
	std::cout << "Robotomy Request Form Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	Form("Robotomy Request Form", 72, 45, target)
{
	std::cout << "Robotomy Request Form Target Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	Form(other)
{
	std::cout << "Robotomy Request Form Copy Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy Request Form Destructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Robotomy Request Form Assignment Operator" << std::endl;
	Form::operator=(other);
	return *this;
}

bool RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	
	if (this->getIsSigned() == false || this->getEGrade() < executor.getGrade())
		return(Form::execute(executor));

	Form::execute(executor);
	std::cout << "\a\a WERRR... \a\a WERR..\n";
	if (std::rand()&1)
	{
		std::cout << "Robotomy has failed sucessfully" << std::endl;
		return false;
	}
	std::cout << this->getTarget() << " has been robotomized" << std::endl;
	return true;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &other)
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