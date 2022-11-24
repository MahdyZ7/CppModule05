# include "Intern.hpp"

typedef Form *(Intern::*ptr)(std::string);

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

Form *Intern::creatPPF(const std::string &target_name)
{
	return (new PresidentialPardonForm(target_name));
}

Form *Intern::creatSCF(const std::string &target_name)
{
	return (new ShrubberyCreationForm(target_name));
}

Form *Intern::creatRRF(const std::string &target_name)
{
	return (new RobotomyRequestForm(target_name));
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target_name)
{
	// ptr = {
	// 	&ShrubberyCreationForm(target_name), &RobotomyRequestForm(target_name), &PresidentialPardonForm(target_name)};
	Form *(Intern::*compl_fun[])(const std::string&) = 
		{&Intern::creatPPF, &Intern::creatSCF, &Intern::creatRRF};
	std::string comp_index[3] = 
		{"PresidentialPardonForm" , "ShrubberyCreationForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; ++i)
		if (form_name == comp_index[i])
			return ((this->*(compl_fun[i]))(target_name));
	std::cout << "The Form Requested does not exist *Bloody Paperwork*\n";
	throw std::exception();
	return (NULL);
}