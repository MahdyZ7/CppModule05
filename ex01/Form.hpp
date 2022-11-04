#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureacrate.hpp"

class Form{
	public:
		Form(void);
		Form(const std::string name, const int s_grade, const int e_grade);
		Form(const Form &other);
		virtual ~Form(void);

		Form &operator=(const Form &other);

		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		const int			getSGrade(void) const;
		const int			getEGrade(void) const;
		void				beSigned(const Bureacrate &low);
		class GradeTooHighException : public std::exception{};
		class GradeTooLowException : public std::exception{};

	private:
		const std::string name;
		bool is_signed;
		const int s_grade;
		const int e_grade;
};

std::ostream& operator<<(std::ostream& os, const Form &other);


#endif