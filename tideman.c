#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = 0;
            locked[i][j] = false;
        }
    }

    pair_count = (candidate_count * candidate_count - 1) / 2;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        /*for (int ik = 0; ik < candidate_count; ik++)
        {
            printf("%i\n", ranks[ik]);
            for (int iy = 0; iy < candidate_count; iy ++)
            {
                printf("%i   ", preferences[ik][iy]);
            }
        }*/
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    /*for (int ir = 0; ir < pair_count; ir++)
        {
            printf("winner %i\n", pairs[ir].winner);
            printf("loser%i\n", pairs[ir].loser);
        }
        printf("\n");*/


    return 0;

}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k]) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i < j)
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0, k = 0; i < candidate_count; i++, k++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[k].winner = i;
                pairs[k].loser = j;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[k].winner = j;
                pairs[k].loser = i;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair t;
    for (int k = 1; k < pair_count; k++)
    {
        if (pairs[k].winner - pairs[k].loser > pairs[k - 1].winner - pairs[k - 1].loser)
        {
            t = pairs[k];
            pairs[k] = pairs[k - 1];
            pairs[k - 1] = t;
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0, k = 0; i < candidate_count - 1; i++, k++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == pairs[k].winner && j == pairs[k].loser)
            {
                locked[i][j] = true;
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    bool flag;
    for (int i = 0; i < candidate_count; i++)
    {
        flag = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                flag = false;
                continue;
            }
        }
        if (flag == true)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}

