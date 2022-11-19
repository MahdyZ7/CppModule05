# include "Bureaucrat.hpp"

int main()
{
	{
		Bureaucrat bowman;
		Bureaucrat green(bowman);
		Bureaucrat kola;
		std::cout<< kola << std::endl;
		kola.decrementGrade();
		std::cout<< kola << std::endl;
		kola.incrementGrade();
		std::cout<< kola << std::endl;
	}
	std::cout<< std::endl;
	{
		Bureaucrat bowman("kissinger", 0);
		bowman.incrementGrade();
		std::cout<< bowman << std::endl;
		bowman.decrementGrade();
		std::cout<< bowman << std::endl;
	}
}