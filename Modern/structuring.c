#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmptime(struct timespec* a, struct timespec* b);

int main()
{
    /*-------------------------------------
    Omitted struct initializers force the corresponding member to 0.
    It can even have all but one of the members are initialized
    A struct initializer must initialize at least one member.
    ---------------------------------------*/
    typedef struct {
        unsigned int strength;
        unsigned int health;
        unsigned int intelligence;
    } warrior;

    // struct parameters are passed by value.
    warrior hellr0x = {75, 35, 75};
    printf("Hellrox's has strength = %d\n", hellr0x.strength);

    struct timespec tm1 = {394853, 234923423234};
    struct timespec tm2 = {394853, 234923423224};
    printf("After %ld seconds..\n", tm1.tv_sec);
    hellr0x.strength += 5;
    printf("After leveling up Hellrox's has strength = %d\n", hellr0x.strength);

    printf("%d", cmptime(&tm1, &tm2));

    return 0;
}

int cmptime(struct timespec* a, struct timespec* b)
{
    if (a->tv_sec == b->tv_sec)
        return a->tv_nsec - b->tv_nsec;
    else
        return a->tv_sec - b->tv_sec;
}

