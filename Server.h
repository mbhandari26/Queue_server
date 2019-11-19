#ifndef SERVER_H
#define SERVER_H

struct Server
{
	int custId;
	int endTime;
	bool busy;

	Server();

};

Server::Server()
{
	custId = 0;
	endTime = 0;
	busy = false;
}

#endif
