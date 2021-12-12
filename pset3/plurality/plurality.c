#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // MAX is a constant that can be used throughout the program representing max number of candidates an election can have

// Candidates have name and vote count
typedef struct
{
    string name; // representing the candidate’s name
    int votes; // representing the number of votes the candidate has
}
candidate;

// Array of candidates
candidate candidates[MAX]; //candidates[9] global array of candidates, where each element is itself a candidate

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

    // Populate array of candidates
    candidate_count = argc - 1; // number of candidates in the election
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

    int voter_count = get_int("Number of voters: "); // asks the user to type in the number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // Type name for vote

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
bool vote(string name)
{
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (strcmp(candidates[i].name, name) == 0) // strcmp returns 0 if s1 is the same as s2
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int winner_votes = 0;
    string winner_name;
    for (int i = 0, n = candidate_count; i < n; i++)
    {
        if (candidates[i].votes == winner_votes && candidates[i].votes != 0)
        {
            printf("%s\n", winner_name);
        }
        if (candidates[i].votes >= winner_votes && candidates[i].votes != 0)
        {
            winner_votes = candidates[i].votes;
            winner_name = candidates[i].name;
        }
    }
    printf("%s\n", winner_name);
    return;
}