#include "CommandExecutor.h"
#include "CommandFactory.h"


int main() 
{	
	CommandExecutor ex;

	while (1)
	{
		ex.addCommand(CommandFactory::getInstance().getCommand());
	}
	
	return 0;
}