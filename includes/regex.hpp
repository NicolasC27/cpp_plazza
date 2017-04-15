//
// regex.cpp for plazza in /home/codeine/Projects/B4/CPP/cpp_plazza/includes
// 
// Made by Lucas Debouté
// Login   <lucas.deboute@epitech.eu>
// 
// Started on  Thu Apr 13 19:34:42 2017 Lucas Debouté
// Last update Sat Apr 15 11:53:08 2017 Lucas Debouté
//

#ifndef REGEX_HPP_
# define REGEX_HPP_

# include <vector>
# include <string>
# include <regex>
# include <iostream>

class regex
{
public:
  regex(){}
  ~regex(){}
  std::vector<std::string> ip_tracker(const std::string &toFind);
  std::vector<std::string> email_tracker(const std::string &toFind);
};

#endif /* REGEX_HPP_ */
