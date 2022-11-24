/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:47:15 by ayassin           #+#    #+#             */
/*   Updated: 2022/11/24 12:47:22 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		virtual bool	execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm &other);


#endif