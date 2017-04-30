//
// Regex.cpp for plazza in /home/codeine/Projects/B4/CPP/cpp_plazza/srcs
// 
// Made by Lucas Debouté
// Login   <lucas.deboute@epitech.eu>
// 
// Started on  Thu Apr 13 19:37:37 2017 Lucas Debouté
// Last update Thu Apr 27 00:14:09 2017 Valentin Gérard
//

#include "Regex.hpp"

std::vector<std::string>	Plazza::Regex::ipTracker(const std::string &toFind)
{
  std::smatch matches;
  std::regex ip_combinaison("(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)");
  std::vector<std::string>	tmp;

  for (std::sregex_iterator it = std::sregex_iterator(toFind.begin(), toFind.end(), ip_combinaison);
       it != std::sregex_iterator(); it++)
    {
      std::smatch m = *it;
      tmp.push_back(m[0]);
    }
  return tmp;
}

std::vector<std::string>	Plazza::Regex::phoneTracker(const std::string &toFind)
{
  std::smatch matches;
  std::regex mail_combinaison("(([0-9]{2}))((.[0-9]{2}){4})");
  std::vector<std::string>	tmp;

  for (std::sregex_iterator it = std::sregex_iterator(toFind.begin(), toFind.end(), mail_combinaison);
       it != std::sregex_iterator(); it++)
    {
      std::smatch m = *it;
      tmp.push_back(m[0]);
    }
  return tmp;
}

std::vector<std::string>	Plazza::Regex::emailTracker(const std::string &toFind)
{
  std::smatch matches;
  std::regex mail_combinaison("(\\\\w+)(\\\\.|_)?(\\\\w*)@(\\\\w+)(\\\\.(\\\\w+))+");
  std::vector<std::string>	tmp;

  for (std::sregex_iterator it = std::sregex_iterator(toFind.begin(), toFind.end(), mail_combinaison);
       it != std::sregex_iterator(); it++)
    {
      std::smatch m = *it;
      tmp.push_back(m[0]);
    }
  return tmp;
}
