#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
// #include "Bureacrate.hpp"
#include "Form.hpp"

// class Form; 

class PresidentialPardonForm: public Form{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		// std::string	getName(void) const;
		// bool		getIsSigned(void) const;
		// int			getSGrade(void) const;
		// int			getEGrade(void) const;
		// bool 		beSigned(const Bureacrate &lam);
		// bool 		beSigned(const Bureacrate &lam);
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm &other);


#endif