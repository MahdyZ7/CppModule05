/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:21:30 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/27 10:48:08 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureaucrat;

class Bureaucrat{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		virtual ~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &other);
		
		int getGrade(void) const;
		std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		bool signForm(Form &paper) const;
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
			int grade;
} ;

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other);

#endif