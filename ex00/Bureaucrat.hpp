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
		private:
			class GradeTooHighException : public std::exception{
				public:
					char *what ();
			};
			class GradeTooLowException : public std::exception{
				public:
					char *what ();
			};
			
			const std::string name;
			int grade;
} ;

// class MyCustomException : public std::exception {
//     public:
// char * what () {
//         return "Custom C++ Exception";
//     }
// };

std::ostream& operator<<(std::ostream& os, const Bureaucrat &other);

#endif