#include "Bureacrate.hpp"

Bureacrate::Bureacrate(void): name("Sam Lowry"), grade(150)
{
	std::cout << "Bureacrate default constructor" << std::endl;
}

Bureacrate::Bureacrate(const std::string& name, const int grade) try : name(name)
{
	this->grade = grade;
	std::cout << "Bureacrate paramter constructor" << std::endl;
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

void Bureacrate::incrementGrade(void)
{
	--grade;
}

void Bureacrate::decrementGrade(void)
{
	++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureacrate &other)
{
	os << other.getName() << ", bureacrate grade " << other.getGrade() << std::endl;
	return os;
}