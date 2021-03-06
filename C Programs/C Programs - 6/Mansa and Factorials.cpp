#include <cstdio>

long long no_of_zeroes(long long n)
{
    long long zero_count = 0, five_power = 5;

    while(five_power <= n)
    {
        zero_count += n/five_power;
        five_power *= 5;
    }

    return zero_count;
}

void solve()
{
    long long minimum_zeroes, ans;
    scanf("%lld", &minimum_zeroes);

    long long low = 1, high = 5e16;

    while(low <= high)
    {
        long long mid = (low + high) >> 1;

        if(no_of_zeroes(mid) == minimum_zeroes)
        {
            while(no_of_zeroes(mid) == minimum_zeroes)
                mid--;

            ans = mid + 1;
            break;
        }
        else if(no_of_zeroes(mid) < minimum_zeroes)
        {
            low = mid + 1;
        }
        else if(no_of_zeroes(mid) > minimum_zeroes)
        {
            if(no_of_zeroes(mid - 1) < minimum_zeroes)
            {
                ans = mid;
                break;
            }

            high = mid - 1;
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}

