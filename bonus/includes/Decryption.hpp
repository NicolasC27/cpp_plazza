//
// Decryption.hpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/bonus/includes
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 30 15:19:02 2017 Valentin Gérard
// Last update Sun Apr 30 15:19:31 2017 Valentin Gérard
//

#ifndef DECRYPTION_HPP_
# define DECRYPTION_HPP_

# define CEASAR_KEY 256
# define XOR_KEY CEASAR_KEY * CEASAR_KEY

# include <string>

# include "Regex.hpp"

namespace Plazza
{

  class Decryption
  {
   public:
    static std::vector<std::string> ceasarDecryption(const std::string &stringToDecrypt, const std::string &information);
    static std::vector<std::string> xorDecryption(const std::string &stringToDecrypt, const std::string &information);
  };

};

#endif /* !DECRYPTION_HPP_ */
