#pragma once
#include "Net/CommonTCP.h"

namespace ThicknessProtocol
{
	enum Status { eOk, eNew, eNext, eLast, eErr };
	struct Receive
	{
		int from, count;
		Status status;
	};
	struct Response
	{
		int from, count;
		Status status;
		int Next;
	};
	class Server: public CommonServer<Server>
	{
	public:
		static bool Do(Frame *);
	};
	struct Client
	{
		static void Do(wchar_t *addr, int port, int from, int count);
	};
}