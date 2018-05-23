#include "CommandObserver.h"
#include "CommandParser.h"

void CommandObserver::attachSubject(CommandParser *parser) {
    parser->registerObserver(this);
}