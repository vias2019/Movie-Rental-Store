/**
 * @file history_command.cpp
 * @author Dominic Ewing
 */

#include <utility>  // move

#include "history_command.h"
#include "rental_system.h"

/**
 * Constructor - Construct a history command object.
 *
 * @param cid The customer id of the customer whose history should be reported.
 */
HistoryCommand::HistoryCommand(int cid): customer_id{cid}
{
}

/**
 * runWith - Ask the rental system to report a customer's transaction history.
 *
 * @param rentalSystem The rental system with which to process the report.
 */
void HistoryCommand::runWith(RentalSystem& rentalSystem)
{
    rentalSystem.history(customer_id);
}
