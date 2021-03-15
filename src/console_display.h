/**
 * @file console_display.h
 * @author Dominic Ewing
 */

#ifndef CONSOLE_DISPLAY_H
#define CONSOLE_DISPLAY_H

#include "display.h"

class ConsoleDisplay : public Display
{
public:
	void displayInventory(const std::vector<std::shared_ptr<Item>>& items) const override;
	void displayHistory(int customerID, std::vector<Customer::History> transactions) const override;
	void displayError(const std::runtime_error& error) const override;
};

#endif
