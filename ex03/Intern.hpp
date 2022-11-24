/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:51:33 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:56:29 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern(void);
		Intern(Intern const &other);
		virtual ~Intern(void);

		Intern &operator=(Intern const &other);
		Form *makeForm(const std::string& form_name, const std::string& targetname);
	private:
		Form *creatPPF(const std::string &target_name);
		Form *creatSCF(const std::string &target_name);
		Form *creatRRF(const std::string &target_name);

};
#endif