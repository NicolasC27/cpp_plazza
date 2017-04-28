//
// PlazzaCore.cpp for cpp_plazza in /home/ikirame/CLionProjects/cpp_plazza/srcs
//
// Made by Valentin Gérard
// Login   <valentin.gerard@epitech.eu>
//
// Started on  Mon Apr 17 13:38:07 2017 Valentin Gérard
// Last update Thu Apr 27 23:19:09 2017 Valentin Gérard
//

#include "SemaphoreRessources.hpp"
#include "PlazzaCore.hpp"

bool alive = true;

Plazza::PlazzaCore::PlazzaCore(int nbThreads) : _nbThreads(nbThreads), _nbCommands(0)
{}

Plazza::PlazzaCore::~PlazzaCore()
{}

void	sig_handler(int signo)
{
  (void)signo;
  alive = false;
}

void					Plazza::PlazzaCore::run()
{
  std::vector<Plazza::PlazzaProcess *>	slaves;
  SemaphoreRessources			semaphoreRessources;
  std::string				currentCommand;
  std::string				currentFeedBack;
  NamedPipe				commandPipe(PIPECOMMAND);
  NamedPipe				feedBackPipe(PIPEFEEDBACK);
  Common::IOfd				feedBackIofd(PIPEFEEDBACK, O_RDONLY);
  fd_set				readSet;
  parser::Parser			parser;

  FD_ZERO(&readSet);
  FD_SET(0, &readSet);
  FD_SET(feedBackIofd.getFd(), &readSet);
  signal(SIGINT, sig_handler);
  while (alive)
    {
      if (select(feedBackIofd.getFd() + 1, &readSet, NULL, NULL, NULL) != -1)
	{
	  if (FD_ISSET(0, &readSet))
	    {
	      try
		{
		  std::getline(std::cin, currentCommand);
		  if (!std::cin.eof())
		    {
		      parser.ManageCommand(currentCommand);
		      this->_nbCommands += parser.getFiles().size();
		      deleteProcess();
		      if (this->_slaves.size() < nbProcessNeeded(this->_nbCommands, this->_slaves))
			for (unsigned int i = 0; i < this->_slaves.size() - nbProcessNeeded(this->_nbCommands, this->_slaves); ++i)
			  createNewProcess();
		      writeCommands(parser.getFiles(), commandPipe);
		    }
		  else
		    sig_handler(1);
		}
	      catch (std::exception &exception)
		{
		  std::cerr << exception.what() << std::endl;
		}
	    }
	  if (FD_ISSET(feedBackIofd.getFd(), &readSet))
	    {
	      currentFeedBack = feedBackPipe.reader();
	      std::cout << currentFeedBack << std::endl;
	      this->_nbCommands -= currentFeedBack.size();
	      deleteProcess();
	    }
	}
    }
  slaves.clear();
}

unsigned int	Plazza::PlazzaCore::nbProcessNeeded(int nbCurrentCommands, std::vector<Plazza::PlazzaProcess *>slaves)
{
  if (slaves.size() == 0)
    return (1);
  if (nbCurrentCommands > this->_nbThreads * JOBSPENDING)
    return (unsigned int) ((nbCurrentCommands / (this->_nbThreads * JOBSPENDING)) + 1);
  else
    return (unsigned int) ((nbCurrentCommands / (this->_nbThreads * JOBSPENDING)));
}

void	Plazza::PlazzaCore::createNewProcess()
{
  try
    {
    	  this->_slaves.push_back(new Plazza::PlazzaProcess(this->_nbThreads));
    }
  catch (std::exception &exception)
    {
      // delete
    }
}

void	Plazza::PlazzaCore::writeCommands(const std::vector<parser::Data *> files, Plazza::NamedPipe &commandPipe)
{
  for (std::vector<parser::Data *>::const_iterator file = files.begin(); file < files.end(); file++)
    commandPipe.writer((*file)->getName() + "-" + (*file)->getInformation()[0]);
}

void Plazza::PlazzaCore::deleteProcess()
{
  std::vector<Plazza::PlazzaProcess *>::iterator iterator = this->_slaves.begin();
  for (unsigned long i = 0; i < this->_slaves.size(); i++)
    {
      std::cout << this->_slaves[i]->getStatus() << std::endl;
      if (!this->_slaves[i]->getStatus())
	{
	  delete(*iterator);
	  iterator = this->_slaves.erase(iterator);
	}
      i++;
      iterator++;
    }
}

