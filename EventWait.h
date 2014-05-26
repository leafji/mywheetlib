#ifndef _EVENT_WAIT_HEADER_
#define _EVENT_WAIT_HEADER_

#include <sys/epoll.h>
#include <vector>
#include "Event.h"

class EventWait
{
public:
    EventWait();
    ~EventWait();

    std::vector<Event> waitEvent();

    int appendReadEvent(int fd);

private:
    static const int MAXEVENT = 1024;

    int efd_;

    std::vector<struct epoll_event> events_;
};

#endif //_EVENT_WAIT_HEADER_
