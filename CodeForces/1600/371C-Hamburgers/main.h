#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#ifndef COMPETITIVE_PROGRAMMING_MAIN_H
#define COMPETITIVE_PROGRAMMING_MAIN_H

struct Ingredient
{
    int price;
    int inStock;
    int nrInRecipe = 0;

    int calcCostPerBurger() const
    {
        return price * nrInRecipe;
    }
    int calcCostToFinishBurger() const
    {
        int deficit = inStock - nrInRecipe;
        if (deficit < 0)
        {
            return abs(deficit) * price;
        }
        else
        {
            return 0;
        }
    }
    void useIngridientToFinishBurger()
    {
        int deficit = inStock - nrInRecipe;
        if (deficit < 0)
        {
            inStock = 0;
        }
        else
        {
            inStock -= nrInRecipe;
        }
    }
    bool inStockLeft()
    {

        return inStock != 0 && nrInRecipe != 0;
    }
    Ingredient() = default;
};

void func(std::istream &is = cin, std::ostream &os = cout);
void readData(vector<Ingredient> &ingredients, unsigned long long &money);
int burgersInStock(vector<Ingredient> &ingredients);
int burgersPartlyInStock(vector<Ingredient> &ingredients, unsigned long long &money);
unsigned long long int burgersFromStore(vector<Ingredient> &ingredients, unsigned long long &money);

#endif // COMPETITIVE_PROGRAMMING_MAIN_H
