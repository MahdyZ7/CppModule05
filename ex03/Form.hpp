/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:22 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:55:42 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form{
	public:
		Form(void);
		Form(const std::string& name, const int s_grade, const int e_grade);
		Form(const std::string& name, const int s_grade, const int e_grade, 
			const std::string& target);
		Form(Form const &other);
		virtual ~Form(void) = 0;

		Form &operator=(Form const &other);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getSGrade(void) const;
		int			getEGrade(void) const;
		bool		beSigned(const Bureaucrat &lam);
		virtual bool		execute(Bureaucrat const &executor) const;
	protected:
		std::string getTarget(void) const;

	private:
		class GradeTooHighException : public std::exception{
				public:
					const char * what () const throw ();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char * what () const throw ();
		};
		const std::string name;
		bool is_signed;
		const int s_grade;
		const int e_grade;
		const std::string target;
};

std::ostream& operator<<(std::ostream& os, const Form &other);


#endif