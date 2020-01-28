#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates 2
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string asma)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(asma, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
void print_winner(void)
{
    /*int t = 0;
    string T = "";

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (candidates[j].votes < candidates[i].votes)
            {
                t = candidates[j].votes;
                T = candidates[j].name;
                candidates[j].votes = candidates[i].votes;
                candidates[i].votes = t;
                candidates[j].name = candidates[i].name;
                candidates[i].name = T;
            }
        }
    }
    if (candidates[candidate_count - 1].votes)*/
    int t = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (candidates[i].votes >= candidates[j].votes)
            {
                t++;
            }
        }
        if (t == candidate_count - 1)
        {
            printf("%s\n", candidates[i].name);
        }
        t = 0;
    }
}
