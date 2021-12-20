#include <iostream>
#include <iomanip>

using namespace std;

int main()                               // Declare variables to store input
{
	float initInv, monDep, AnuInt, months, years;     // To store year end total amount
	float totalAm, intAmt, yearTotInt;                // To store interest and year end interest

	cout << "**********************************\n";   // Display form to user
	cout << "********** Data Input ************\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";
	
	system("PAUSE");     // To get press any key to continue line
	
	cout << "**********************************\n";  // Get data from user
	cout << "********** Data Input ************\n";
	cout << "Initial Investment Amount: $";
	cin >> initInv;
	cout << "Monthly Deposit: $";
	cin >> monDep;
	cout << "Annual Interest: %";
	cin >> AnuInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;
	
	system("PAUSE");
	
	totalAm = initInv;   // Set totalAm = initInv

	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";  // Display year data without monthly deposits
	cout << "====================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------------\n";
	
	for (int i = 0; i < years; i++)
	{
		intAmt = (totalAm) * ((AnuInt / 100));   // Calculate yearly interest
		totalAm = totalAm + intAmt;              // Calculate year end total
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t$" << intAmt << "\n";  // Set fixed and Set precision to show only two decimal points
	}
	
	totalAm = initInv;  // For monthly
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";   // Display year data with monthly deposits
	cout << "====================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------------\n";
	
	for (int i = 0; i < years; i++)
	{
		yearTotInt = 0;    // Set yearly interest to zero at the start of year
		for (int j = 0; j < 12; j++)
		{
			intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);   // Calculate monthly interest
			yearTotInt = yearTotInt + intAmt;                      // Calculate month end interest
			totalAm = totalAm + monDep + intAmt;                   // Calculate month end total
			
		}
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAm << "   \t\t\t$" << yearTotInt << "\n";
	}
	return 0;
}