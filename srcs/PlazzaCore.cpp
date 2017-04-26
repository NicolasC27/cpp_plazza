//
// PlazzaCore.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
//
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
//
// Started on  Mon Apr 17 13:38:07 2017 Valentin Gérard
// Last update Wed Apr 26 00:26:47 2017 Valentin Gérard
//

#include "SemaphoreRessources.hpp"
#include "PlazzaCore.hpp"

Plazza::PlazzaCore::PlazzaCore(int nbThreads) : _nbThreads(nbThreads), _nbCommands(0)
{}

Plazza::PlazzaCore::~PlazzaCore()
{}

void					Plazza::PlazzaCore::run()
{
  std::vector<Plazza::PlazzaProcess *>	slaves;
  SemaphoreRessources			semaphoreRessources;
  std::string				currentCommand;
  std::string				currentFeedBack;
  NamedPipe				commandPipe(PIPECOMMAND);
  NamedPipe				feedBackPipe(PIPEFEEDBACK);
  parser::Parser			parser;

  while (std::getline(std::cin, currentCommand))
    {
      try
	{
	  parser.ManageCommand(currentCommand);

	  this->_nbCommands += parser.getFiles().size();
	  if (this->_slaves.size() < nbProcessNeeded(this->_nbCommands))
	    createNewProcess();
	  writeCommands(parser.getFiles(), commandPipe);
	  currentFeedBack = feedBackPipe.reader();
	  this->_nbCommands -= currentFeedBack.size();
	}
      catch (std::exception &exception)
	{
	  std::cerr << exception.what() << std::endl;
	}
      std::cout << "nb command : " << this->_nbCommands << std::endl;
    }
}

unsigned int	Plazza::PlazzaCore::nbProcessNeeded(int nbCurrentCommands)
{
  return (unsigned int) ((nbCurrentCommands / (this->_nbThreads * JOBSPENDING)) + 1);
}

void	Plazza::PlazzaCore::createNewProcess()
{
  this->_slaves.push_back(new Plazza::PlazzaProcess(this->_nbThreads));
}

void	Plazza::PlazzaCore::writeCommands(const std::vector<parser::Data *> files, Plazza::NamedPipe &commandPipe)
{
  for (std::vector<parser::Data *>::const_iterator file = files.begin(); file < files.end(); file++)
    commandPipe.writer((*file)->getName() + "-" + (*file)->getInformation()[0]);
}
