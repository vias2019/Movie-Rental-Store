/**
 * @file history_command.hpp
 * @author Dominic Ewing
 */

#ifndef RENTAL_SYSTEM_COMMAND_HISTORY_HPP
#define RENTAL_SYSTEM_COMMAND_HISTORY_HPP

#include "customer_id.hpp"
#include "command.hpp"

/**
 * Concrete command for reporting a customer's transaction history.
 */
class HistoryCommand : public Command
{
public:
	explicit HistoryCommand(CustomerID cid);

	// Command interface.
	void runWith(RentalSystem& rentalSystem) override;

private:
	CustomerID customer_id;
};

#endif
