#include "main.h"

const int nrOfPrimes = 2564;
const int primeLimit = 23000;

constexpr array<int, nrOfPrimes> generatePrimes()
{

    array<int, primeLimit> primeNumbers = {};
    primeNumbers[0] = -1;
    primeNumbers[1] = -1;
    for (int prime = 0; prime < primeLimit; prime++)
    {
        if (primeNumbers[prime] == -1)
        {
            continue;
        }
        primeNumbers[prime] = prime;
        for (long int i = prime * prime; i < primeLimit; i += prime)
        {
            if (i % prime == 0)
            {
                primeNumbers[i] = -1;
            }
        }
    }

    int counter = 0;
    array<int, nrOfPrimes> arr = {};
    for (auto prime : primeNumbers)
    {
        if (prime != -1)
        {
            arr[counter] = prime;
            counter++;
        }
    }

    return arr;
}

constexpr auto primes = generatePrimes();

void secondUseOfPrime(int &number, int currentPrime, int primeCounter, int nrOfPrimes, vector<int> &numbers)
{
    int thirdNumber = number / currentPrime;
    int secondPrimeCounter = primeCounter;
    auto secondCurrentPrime = primes[secondPrimeCounter];
    while (secondPrimeCounter < nrOfPrimes)
    {

        if (secondPrimeCounter > thirdNumber)
        {
            break;
        }

        bool restCanBeSpliIntoTwoDistinctNumbers = thirdNumber % secondCurrentPrime == 0 &&
                                                   (thirdNumber / secondCurrentPrime) != currentPrime * secondCurrentPrime &&
                                                   (thirdNumber / secondCurrentPrime) != 1;
        if (restCanBeSpliIntoTwoDistinctNumbers)
        {
            numbers.emplace_back(currentPrime * secondCurrentPrime);
            number = thirdNumber / secondCurrentPrime;
            break;
        }

        secondPrimeCounter++;
    }
}

void solution(std::istream &is, std::ostream &os)
{
    int testcases;

    is >> testcases;

    while (testcases--)
    {
        int number;
        is >> number;
        vector<int> numbers;

        int primeCounter = 0;
        const int nrOfPrimes = primes.size();
        while (primeCounter < nrOfPrimes)
        {
            auto currentPrime = primes[primeCounter];

            if (currentPrime > number)
            {
                break;
            }

            if (number % currentPrime == 0)
            {
                numbers.emplace_back(currentPrime);
                number /= currentPrime;
                if (numbers.size() == 2)
                {
                    break;
                }

                if (number % currentPrime == 0)
                {
                    secondUseOfPrime(number, currentPrime, primeCounter, nrOfPrimes, numbers);
                }
            }

            primeCounter++;

            if (numbers.size() == 2)
            {
                break;
            }
        }

        bool distinctNumbers = numbers.size() == 2 &&
                               numbers[0] != numbers[1] &&
                               numbers[0] != number &&
                               numbers[1] != number;

        if (numbers.size() == 2 && number > 1 && distinctNumbers)
        {
            os << "YES\n";
            os << numbers[0];
            os << " ";
            os << numbers[1];
            os << " ";
            os << number;
            os << "\n";
        }
        else
        {
            os << "NO\n";
        }
    }
}
