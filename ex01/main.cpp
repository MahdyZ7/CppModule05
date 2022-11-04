# include "Bureacrate.hpp"

int main()
{
	{
		Bureacrate bowman;
		Bureacrate green(bowman);
		Bureacrate kola;
		std::cout<< kola << std::endl;
		kola.decrementGrade();
		std::cout<< kola << std::endl;
		kola.incrementGrade();
		std::cout<< kola << std::endl;
	}
	std::cout<< std::endl;
	{
		Bureacrate bowman("kissinger", 0);
		bowman.incrementGrade();
		std::cout<< bowman << std::endl;
		bowman.decrementGrade();
		std::cout<< bowman << std::endl;
	}
}