/**
 * @file history_command.cpp
 * @author Dominic Ewing
 */

#include <utility>	// std::move

#include "history_command.hpp"

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
}
