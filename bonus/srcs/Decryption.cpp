//
// Decryption.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/bonus/srcs
// 
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
// 
// Started on  Sun Apr 30 15:19:46 2017 Valentin Gérard
// Last update Sun Apr 30 15:19:47 2017 Valentin Gérard
//

#include "../includes/Decryption.hpp"

std::vector<std::string> Plazza::Decryption::ceasarDecryption(const std::string &stringToDecrypt, const std::string &information)
{
  std::string uncryptedStr(stringToDecrypt);
  Plazza::Regex regex;
  std::vector<std::string> results;

  for (int key = 1; key < CEASAR_KEY; key++)
    {
      for (unsigned int i = 0; i < stringToDecrypt.length(); i++)
	uncryptedStr[i] = (char) ((char) (stringToDecrypt[i] - key) % CEASAR_KEY);
      if (strcmp(information.c_str(), "IP_ADDRESS") == 0)
	results = regex.ipTracker(uncryptedStr);
      else if (strcmp(information.c_str(), "EMAIL_ADDRESS") == 0)
	  results = regex.emailTracker(uncryptedStr);
      else
	  results = regex.phoneTracker(uncryptedStr);
      if (results.size() > 0)
	return results;
      uncryptedStr = stringToDecrypt;
    }
  return results;
}

std::vector<std::string> Plazza::Decryption::xorDecryption(const std::string &stringToDecrypt, const std::string &information)
{
  std::string uncryptedStr(stringToDecrypt);
  Plazza::Regex regex;
  std::vector<std::string> results;

  for (int key = 1; key < XOR_KEY ; key++)
    {
      std::cout << key << std::endl;
      for (unsigned int i = 0; i < stringToDecrypt.length(); i++)
	uncryptedStr[i] = (char) (stringToDecrypt[i] ^ key);
      if (strcmp(information.c_str(), "IP_ADDRESS") == 0)
	results = regex.ipTracker(uncryptedStr);
      else if (strcmp(information.c_str(), "EMAIL_ADDRESS") == 0)
	  results = regex.emailTracker(uncryptedStr);
	else
	  results = regex.phoneTracker(uncryptedStr);
      if (results.size() > 0)
	return results;
      uncryptedStr = stringToDecrypt;
    }
  std::cout << "aie" << std::endl;
  return results;
}

