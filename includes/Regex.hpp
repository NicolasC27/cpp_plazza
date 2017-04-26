//
// Regex.cpp for plazza in /home/codeine/Projects/B4/CPP/cpp_plazza/includes
// 
// Made by Lucas Debouté
// Login   <lucas.deboute@epitech.eu>
// 
// Started on  Thu Apr 13 19:34:42 2017 Lucas Debouté
// Last update Thu Apr 27 00:14:38 2017 Valentin Gérard
//

#ifndef REGEX_HPP_
# define REGEX_HPP_

# include <vector>
# include <string>
# include <regex>
# include <iostream>

namespace Plazza
{

  class Regex
  {
  public:
    Regex(){}
    ~Regex(){}
    std::vector<std::string> ipTracker(const std::string &toFind);
    std::vector<std::string> phoneTracker(const std::string &toFind);
    std::vector<std::string> emailTracker(const std::string &toFind);
  };
  
}

#endif /* !REGEX_HPP_ */
