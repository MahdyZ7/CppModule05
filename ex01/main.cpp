# include "Form.hpp"
# include "Bureacrate.hpp"

int main()
{
	// {
	// 	Bureacrate bowman;
	// 	Bureacrate green(bowman);
	// 	Bureacrate kola;
	// 	std::cout<< kola << std::endl;
	// 	kola.decrementGrade();
	// 	std::cout<< kola << std::endl;
	// 	kola.incrementGrade();
	// 	std::cout<< kola << std::endl;
	// }
	// std::cout<< std::endl;
	// {
	// 	Bureacrate bowman("kissinger", 0);
	// 	bowman.incrementGrade();
	// 	std::cout<< bowman << std::endl;
	// 	bowman.decrementGrade();
	// 	std::cout<< bowman << std::endl;
	// }
	try
	{		
		Form form("leab", 10, 55);
		Form form2;
		Form form3(form2);
		std::cout << form2;
		form2 = form;
		std::cout << form2;
		Bureacrate sam;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form.beSigned(sam);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}