#include <Core/Engine.hpp>

#include <Utils/Logger.hpp>

void Engine::launch() {
	Log log = logStartBlock("Hello", DEBUG);

	logAddLine(&log, "Hello, world");
	logEndBlock(&log);
	logPrint(log);

	log = logStartBlock("Hello", INFO);

	logAddMultilineString(&log, "Hello, world\nFrom Core");
	logEndBlock(&log);
	logPrint(log);

	log = logStartBlock("Hello", WARN);

	logAddLine(&log, "Hello, world");
	logAddLine(&log, "From CORE");
	logEndBlock(&log);
	logPrint(log);

	log = logStartBlock("Hello", ERROR);

	logAddLine(&log, "Hello, world");
	logAddLine(&log, "From CORE");
	logEndBlock(&log);
	logPrint(log);

	log = logStartBlock("Hello", CRIT);

	logAddLine(&log, "Hello, world");
	logAddLine(&log, "From CORE");
	logEndBlock(&log);
	logPrint(log);

}