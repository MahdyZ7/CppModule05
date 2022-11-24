#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm: public Form{
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