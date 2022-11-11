/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureacrate.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:21:30 by ayassin           #+#    #+#             */
/*   Updated: 2022/10/27 10:48:08 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREACRATE_HPP
#define BUREACRATE_HPP
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;
class Bureacrate;

class Bureacrate{
	public:
		Bureacrate(void);
		Bureacrate(const std::string &name, const int grade);
		Bureacrate(const Bureacrate &other);
		virtual ~Bureacrate(void);

		Bureacrate &operator=(const Bureacrate &other);
		
		int getGrade(void) const;
		std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		bool signForm(Form &paper);
		private:
			class GradeTooHighException : public std::exception{
				public:
					const char * what () const throw (){
						return "Bureacrate grade to high";
					}
			};
			class GradeTooLowException : public std::exception{
				public:
					const char * what () const throw (){
						return "Bureacrate grade to low";
					}
			};
			
			const std::string name;
			int grade;
} ;

std::ostream& operator<<(std::ostream& os, const Bureacrate &other);

#endif