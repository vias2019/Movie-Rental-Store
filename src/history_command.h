/**
 * @file history_command.h
 * @author Dominic Ewing
 */

#ifndef HISTORY_COMMAND_H
#define HISTORY_COMMAND_H

#include "customer_id.h"
#include "command.h"

/**
 * Concrete command for reporting a customer's transaction history.
 */
class HistoryCommand : public Command
{
public:
	explicit HistoryCommand(int cid);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

private:
	int customer_id;
};

#endif
