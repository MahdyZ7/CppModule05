# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

int main()
{
	// std::cout << "------ Bureacrate operation------" << std::endl;
	// try {
	// 	Bureacrate bowman;
	// 	Bureacrate green(bowman);
	// 	Bureacrate kola;
	// 	std::cout<< kola << std::endl;
	// 	kola.decrementGrade();
	// 	std::cout<< kola << std::endl;
	// 	kola.incrementGrade();
	// 	std::cout<< kola << std::endl;
	// } catch (const std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout<< std::endl;
	// std::cout << "------Bureacrate operation 1------" << std::endl;
	// try {
	// 	Bureacrate bowman("kissinger", 0);
	// 	bowman.incrementGrade();
	// 	std::cout<< bowman << std::endl;
	// 	bowman.decrementGrade();
	// 	std::cout<< bowman << std::endl;
	// } catch (const std::exception& e){
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout<< std::endl;
	std::cout << "------Normal operation------" << std::endl;
	try
	{
		PresidentialPardonForm form;
		PresidentialPardonForm form2;
		std::cout << form2 << std::endl;
		// form2 = form;
		std::cout << form2 << std::endl;
		Bureaucrat sam;
		std::cout << sam << std::endl;
		std::cout << form << std::endl;
		form.beSigned(sam);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "------low grade tests-------" << std::endl;
	return 0;
}