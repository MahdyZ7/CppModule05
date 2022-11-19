#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void): name("Sam Lowry"), grade(150)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): name(name)
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
		std::cout << "Bureaucrat Grade too high exception, grade set to 1" << std::endl;
	}
	catch(GradeTooLowException& e){
		std::cout << "Bureaucrat Grade too low exception, grade set to 150" << std::endl;
	}
	std::cout << "Bureaucrat parameteric constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this->grade != other.grade && this->name != other.name)
    {
    	Bureaucrat	tmp(other);
		std::swap(*this, tmp);
	}
	std::cout << "Bureaucrat copy assinment operator" << std::endl;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Bureaucrat grade to high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Bureaucrat grade to low exception";
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

std::string Bureaucrat::getName(void) const
{
	return (name);
}

void Bureaucrat::incrementGrade(void) try
{
	if (grade > 1)
		--grade;
	else
		throw GradeTooHighException();
}
catch(GradeTooHighException& e){
	std::cout << this->name << ": grade to high exception" << std::endl;
}

void Bureaucrat::decrementGrade(void) try
{
	if (grade < 150)
		++grade;
	else
		throw GradeTooLowException();
} 
catch (GradeTooLowException& e){
	std::cout << this->name << ": grade to low exception" << std::endl;
}

bool Bureaucrat::signForm(Form &paper) const
{
	if (paper.beSigned(*this))
		return (true);
	return (false);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other)
{
	os << other.getName() << ", bureacrate grade " << other.getGrade();
	return os;
}