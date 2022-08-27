
#include "main.h"

void func(std::istream &is, std::ostream &os)
{
    vector<Ingredient> ingredients(3);
    unsigned long long money;
    readData(ingredients, money);

    unsigned long long int burgers = 0;

    burgers += burgersInStock(ingredients);
    burgers += burgersPartlyInStock(ingredients, money);
    burgers += burgersFromStore(ingredients, money);

    cout << burgers;
}

void readData(vector<Ingredient> &ingredients, unsigned long long &money)
{
    string recipe;
    cin >> recipe;

    for (auto &ingredient : ingredients)
    {
        cin >> ingredient.inStock;
    }

    for (auto &ingredient : ingredients)
    {
        cin >> ingredient.price;
    }

    cin >> money;

    for (auto &c : recipe)
    {
        switch (c)
        {
        case 'B':
            ingredients[0].nrInRecipe++;
            break;
        case 'S':
            ingredients[1].nrInRecipe++;
            break;
        case 'C':
            ingredients[2].nrInRecipe++;
            break;
        default:
            break;
        }
    }
}

int burgersInStock(vector<Ingredient> &ingredients)
{
    int burgersMade = INT_MAX;
    for (const auto &ingredient : ingredients)
    {
        if (ingredient.nrInRecipe != 0)
        {
            burgersMade = min(burgersMade, ingredient.inStock / ingredient.nrInRecipe);
        }
    }
    for (auto &ingredient : ingredients)
    {
        ingredient.inStock -= ingredient.nrInRecipe * burgersMade;
    }

    return burgersMade;
}

int burgersPartlyInStock(vector<Ingredient> &ingredients, unsigned long long &money)
{
    int burgersMade = 0;
    bool inStockLeft = true;
    while (inStockLeft)
    {

        unsigned costForNextBurger = 0;
        for (auto &ingredient : ingredients)
        {
            costForNextBurger += ingredient.calcCostToFinishBurger();
        }

        if (costForNextBurger > money)
        {
            break;
        }
        for (auto &ingredient : ingredients)
        {
            ingredient.useIngridientToFinishBurger();
        }

        money -= costForNextBurger;
        burgersMade++;

        inStockLeft = false;
        for (auto &ingredient : ingredients)
        {
            inStockLeft |= ingredient.inStockLeft();
        }
    }
    return burgersMade;
}

unsigned long long int burgersFromStore(vector<Ingredient> &ingredients, unsigned long long &money)
{
    unsigned long long int burgersMade = 0;
    if (money > 0)
    {
        unsigned long long int costOfOneBurger = 0;
        for (const auto &ingredient : ingredients)
        {
            costOfOneBurger += ingredient.calcCostPerBurger();
        }
        burgersMade = money / costOfOneBurger;
    }
    return burgersMade;
}