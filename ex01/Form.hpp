/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:40:27 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:40:28 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

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
		bool		beSigned(const Bureaucrat &lam);

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
};

std::ostream& operator<<(std::ostream& os, const Form &other);


#endif