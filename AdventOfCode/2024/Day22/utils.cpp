unsigned long long mixing(unsigned long long secret, unsigned long long result)
{
    return secret ^ result;
}

unsigned long long pruning(unsigned long long secret)
{
    return secret % 16777216;
}

unsigned long long getNextSecret(unsigned long long secret)
{

    auto multResult = secret * 64;
    secret = mixing(secret, multResult);
    secret = pruning(secret);

    auto divResult = secret / 32;
    secret = mixing(secret, divResult);
    secret = pruning(secret);

    auto multResult2 = secret * 2048;
    secret = mixing(secret, multResult2);
    secret = pruning(secret);
    return secret;
}