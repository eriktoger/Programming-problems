#include "580B-Kefa-&-Company.h"

void kefa(std::istream &is, std::ostream &os) {

    int nrOfFriends;
    int diff;
    cin >> nrOfFriends;
    cin >> diff;
    diff--;
    vector<Friend> friends;
    friends.reserve(nrOfFriends);
    int money;
    int friendship;
    while (nrOfFriends--) {
        cin >> money;
        cin >> friendship;
        friends.emplace_back(Friend(money, friendship));
    }
    sort(friends.begin(), friends.end());


    auto firstIt = friends.begin();
    auto secondIt = friends.begin();
    long long currentValue = 0;
    long long maxValue = 0;

    while (firstIt != friends.end()) {
        currentValue += firstIt->getFriendship();
        while ( firstIt->getMoney() - secondIt->getMoney() > diff) {
            currentValue -= secondIt->getFriendship();
            secondIt++;
        }
        maxValue = max(maxValue, currentValue);
        firstIt++;
    }

    cout << maxValue;

}