/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:44:45 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 13:00:17 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	public:
		AForm(void);
		AForm(const std::string& name, const int s_grade, const int e_grade);
		AForm(const std::string& name, const int s_grade, const int e_grade, 
			const std::string& target);
		AForm(AForm const &other);
		virtual ~AForm(void) = 0;

		AForm &operator=(AForm const &other);

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

std::ostream& operator<<(std::ostream& os, const AForm &other);


#endif