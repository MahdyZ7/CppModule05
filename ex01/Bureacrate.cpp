#include "Bureacrate.hpp"

Bureacrate::Bureacrate(void): name("Sam Lowry"), grade(150)
{
	std::cout << "Bureacrate default constructor" << std::endl;
}

Bureacrate::Bureacrate(const std::string& name, const int grade): name(name)
{
	try
	{
		if (grade < 1){
			this->grade = 1;
			throw GradeTooHighException();
		}
		else if (grade > 150){
			this->grade = 150;
			throw GradeTooLowException();
		}
		else
			this->grade = grade;
	}
	catch(GradeTooHighException& e){
		std::cout << "Bureacrate Grade too high exception, grade set to 1" << std::endl;
	}
	catch(GradeTooLowException& e){
		std::cout << "Bureacrate Grade too low exception, grade set to 150" << std::endl;
	}
	std::cout << "Bureacrate parameteric constructor" << std::endl;
}

Bureacrate::Bureacrate(const Bureacrate &other): name(other.name), grade(other.grade)
{
	std::cout << "Bureacrate copy constructor" << std::endl;
}

Bureacrate::~Bureacrate(void)
{
	std::cout << "Bureacrate destructor" << std::endl;
}

Bureacrate &Bureacrate::operator=(const Bureacrate &other)
{
	if (this->grade != other.grade && this->name != other.name)
    {
    	Bureacrate	tmp(other);
		std::swap(*this, tmp);
	}
	std::cout << "Bureacrate copy assinment operator" << std::endl;
	return (*this);
}

int Bureacrate::getGrade(void) const
{
	return (grade);
}

std::string Bureacrate::getName(void) const
{
	return (name);
}

void Bureacrate::incrementGrade(void) try
{
	if (grade > 1)
		--grade;
	else
		throw GradeTooHighException();
}
catch(GradeTooHighException& e){
	std::cout << this->name << ": grade to high exception" << std::endl;
}

void Bureacrate::decrementGrade(void) try
{
	if (grade < 150)
		++grade;
	else
		throw GradeTooLowException();
} 
catch (GradeTooLowException& e){
	std::cout << this->name << ": grade to low exception" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureacrate &other)
{
	os << other.getName() << ", bureacrate grade " << other.getGrade();
	return os;
}