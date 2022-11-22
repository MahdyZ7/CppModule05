# include "Form.hpp"

Form::Form(void): name("form 27B/6"), is_signed(false), s_grade(150), e_grade(150)
{
	std::cout << "Form Default Constructor" << std::endl;
}

Form::Form(const std::string& name, const int s_grade, const int e_grade): name(name), is_signed(false), s_grade(s_grade), e_grade(e_grade){
	std::cout << "Form parametric Constructor" << std::endl;
	if (this->s_grade < 1 || this->e_grade < 1)
		throw GradeTooHighException();
	else if (this->s_grade > 150 || this->e_grade > 150)
		throw GradeTooLowException(); 
} 

Form::Form(const Form& other): name(other.name), is_signed(other.is_signed),
								s_grade(other.s_grade), e_grade(other.e_grade)
{
	std::cout << "Form Copy Constructor " << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form Destructor" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form Assignment Operator" << std::endl;
	if (this != &other)
	{
		const_cast<std::string&> (this->name) = other.name;
		const_cast<int&> (this->s_grade) = other.s_grade;
		const_cast<int&> (this->e_grade) = other.e_grade;
		this->is_signed = other.is_signed;
	}
	return (*this);
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high exception";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low exception";
}

std::string Form::getName(void) const
{
	return name;
}

int Form::getSGrade(void) const
{
	return s_grade;
}

int Form::getEGrade(void) const
{
	return e_grade;
}

bool Form::getIsSigned(void) const
{
	return is_signed;
}

bool Form::beSigned(const Bureaucrat &lam) try
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
	std::cout << "form grade too high for bureaucrat\n";
	return false;
}

std::ostream& operator<<(std::ostream& os, const Form &other)
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