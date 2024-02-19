#include <iostream>

int main() {
    double investment_amount, apy_hysa, fdic_max_hysa, apy_ibonds, apy_index_fund;

    // Prompt user for investment amount
    cout << "Enter total amount of money to invest in USD: ";
    cin >> investment_amount;
  
    // Only accepting possitive values
    if (investment_amount < 0) {
        cout << "Error: Negative value entered. Please enter a positive value." << endl;
        return 1;
    }

    // Ask for APY of High Yield Savings Account
    cout << "Enter the Annual Percentage Yield (APY) of High Yield Savings Account: ";
    cin >> apy_hysa;

    if (apy_hysa < 0) {
        cout << "Error: Negative APY entered. Overriding with 0.01 (1%)." << endl;
        apy_hysa = 0.01; // Default APY of 1%
    }

    // Prompt user for FDIC insurance maximum of HYSA
    cout << "Enter FDIC insurance maximum of High Yield Savings Account: ";
    cin >> fdic_max_hysa;

    if (fdic_max_hysa < 0) {
        cout << "Error: Negative value entered. We will just go withe the 250k USD default." << endl;
        fdic_max_hysa = 250000; // Default FDIC insurance maximum of $250,000
    }

    // Ask for APY of I bonds
    cout << "Enter the APY of I Bonds: ";
    cin >> apy_ibonds;

    if (apy_ibonds < 0) {
        cout << "Error: Negative APY entered. We will just go with the 6% deffault." << endl;
        apy_ibonds = 0.06; // Default APY of I Bonds as 6%
    }

    // Prompt user for APY of index fund
    cout << "Enter the APY of Index Fund: ";
    cin >> apy_index_fund;

    if (apy_index_fund < 0) {
        cout << "Error: Negative APY entered. We will just go with the 10% deffault." << endl;
        apy_index_fund = 0.10; // Default APY of Index Fund as 10%
    }

    // Check which option has the highest APY
    double max_apy = max(apy_hysa, max(apy_ibonds, apy_index_fund));
    double expected_return = 0;

    if (max_apy == apy_hysa) {
        cout << "Invest as much money as possible into the High Yield Savings Account." << endl;
        cout << "How much money do you want to invest into High Yield Savings Account? $";
        double investment_into_hysa;
        cin >> investment_into_hysa;
        expected_return = investment_into_hysa * (1 + apy_hysa);
    } else if (max_apy == apy_ibonds) {
        cout << "Invest as much money as possible into I Bonds." << endl;
        cout << "How much money do you want to invest into I Bonds? $";
        double investment_into_ibonds;
        cin >> investment_into_ibonds;
        expected_return = investment_into_ibonds * (1 + apy_ibonds);
    } else {
        cout << "Invest as much money as possible into the Index Fund." << endl;
        cout << "How much money do you want to invest into Index Fund? $";
        double investment_into_index_fund;
        cin >> investment_into_index_fund;
        expected_return = investment_into_index_fund * (1 + apy_index_fund);
    }
    // Tell the user how much money they will be expected to make in a year with the highest option
    cout << "Expected return after 1 year: $" << expected_return << endl;

    return 0;
}

