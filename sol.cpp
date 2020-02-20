#include "sol.h"

void print_solution(solution *sol)
{
  std::cout << sol->libraries.size() << std::endl;
  for(auto &i: sol->libraries )
    {
      std::cout << i << " " << sol->books_per_library[i].size() << std::endl;
      for( auto &j: sol->books_per_library[i])
	{
	  std::cout << j << " ";
	}
    }
}
