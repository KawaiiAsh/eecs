#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function for deciding whether to use the singular or plural form of a word
string pluralize(string singularForm, string pluralForm, int quantity);

int main() {
    // Defining constants related to the recipe and its costs
    const double LOAVES_PER_PERSON = 0.25;  // Equivalent to 4 people per loaf
    const double CUPS_FLOUR_IN_LOAF = 5;
    const double CUPS_FLOUR_IN_BAG = 20;
    const double TEASPOONS_YEAST_IN_LOAF = 1.75;
    const double TEASPOONS_YEAST_IN_PACKAGE = 2.25;
    const double TEASPOONS_SALT_IN_LOAF = 1.875;
    const double TEASPOONS_SALT_IN_CANISTER = 6;
    const double TABLESPOONS_OIL_IN_LOAF = 2;
    const double TABLESPOONS_OIL_IN_BOTTLE = 500 / 14.8;
    const double COST_PER_FLOUR_BAG = 2.69;
    const double COST_PER_YEAST_PACKAGE = 0.4;
    const double COST_PER_SALT_CANISTER = 0.49;
    const double COST_PER_OIL_BOTTLE = 6.39;

    // Variables for storing user input and calculated results
    int attendeeCount = 0;
    int loavesRequired = 0;
    int bagsOfFlour = 0;
    int packagesOfYeast = 0;
    int canistersOfSalt = 0;
    int bottlesOfOil = 0;
    double estimatedTotalCost = 0.0;

    // Taking user input for the number of attendees
    cout << "How many people do you need to serve? ";
    cin >> attendeeCount;
    cout << endl;

    // Calculating the required quantity of each ingredient
    loavesRequired = ceil(attendeeCount * LOAVES_PER_PERSON);
    bagsOfFlour = ceil(loavesRequired * CUPS_FLOUR_IN_LOAF / CUPS_FLOUR_IN_BAG);
    packagesOfYeast = ceil(loavesRequired * TEASPOONS_YEAST_IN_LOAF / TEASPOONS_YEAST_IN_PACKAGE);
    canistersOfSalt = ceil(loavesRequired * TEASPOONS_SALT_IN_LOAF / TEASPOONS_SALT_IN_CANISTER);
    bottlesOfOil = ceil(loavesRequired * TABLESPOONS_OIL_IN_LOAF / TABLESPOONS_OIL_IN_BOTTLE);

    // Calculating the total cost for the ingredients
    estimatedTotalCost = (bagsOfFlour * COST_PER_FLOUR_BAG) +
                         (packagesOfYeast * COST_PER_YEAST_PACKAGE) +
                         (canistersOfSalt * COST_PER_SALT_CANISTER) +
                         (bottlesOfOil * COST_PER_OIL_BOTTLE);

    // Outputting the results
    cout << "You need to make: " << loavesRequired << " ";
    cout << pluralize("loaf", "loaves", loavesRequired) << " of focaccia" << endl << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    cout << bagsOfFlour << " " << pluralize("bag", "bags", bagsOfFlour) << " of flour" << endl;
    cout << packagesOfYeast << " " << pluralize("package", "packages", packagesOfYeast) << " of yeast" << endl;
    cout << canistersOfSalt << " " << pluralize("canister", "canisters", canistersOfSalt) << " of salt" << endl;
    cout << bottlesOfOil << " " << pluralize("bottle", "bottles", bottlesOfOil) << " of olive oil" << endl << endl;
    cout << "Total expected cost of ingredients: $" << estimatedTotalCost << endl << endl;
    cout << "Have a great party!" << endl;

    return 0;
}

// Function to determine the singular or plural form of a word based on the quantity
string pluralize(string singularForm, string pluralForm, int quantity) {
    return (quantity == 1) ? singularForm : pluralForm;
}