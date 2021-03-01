/**
 * @file history_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "history_command.h"

/**
 * Construct a history command object.
 *
 * @param cid The customer id of the customer whose history should be reported.
 */
HistoryCommand::HistoryCommand(CustomerID cid): customer_id{std::move(cid)}
{
}

/**
 * Ask the rental system to report a customer's transaction history.
 *
 * @param rentalSystem The rental system with which to process the report.
 */
void HistoryCommand::runWith(RentalSystem& rentalSystem) override
{
	rentalSystem.history(customer_id);
}
