#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureacrate.hpp"

class Form;
class Bureacrate;

class Form{
	public:
		Form(void);
		Form(const std::string& name, const int s_grade, const int e_grade);
		Form(Form const &other);
		virtual ~Form(void);

		Form &operator=(Form const &other);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSGrade(void) const;
		int			getEGrade(void) const;
		bool		beSigned(Bureacrate &lam);
		class GradeTooHighException : public std::exception{
				public:
					const char * what () const throw (){
						return "Form grade to high";
					}
		};
		class GradeTooLowException : public std::exception{
			public:
				const char * what () const throw (){
						return "Form grade to low";
					}
		};

	private:
		const std::string name;
		bool is_signed;
		const int s_grade;
		const int e_grade;
};

std::ostream& operator<<(std::ostream& os, const Form &other);


#endif