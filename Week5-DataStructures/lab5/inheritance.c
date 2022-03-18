// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

const int GENERATIONS = 3; // represents the number of generations to simulate
const int INDENT_LENGTH = 4; // 

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0)); // generates pseudo random numbers

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0); // prints out family as hierarchical tree

    // Free memory
    free_family(p); // free all of the memory creates in process of create_family
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    person *p = malloc(sizeof(person));

    // Generation with parent data
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents. recursively call create family function for each parent
        generations = generations - 1;
        p->parents[0] = create_family(generations);
        p->parents[1] = create_family(generations);
        // TODO: Randomly assign child alleles based on parents. Look at one parents two alleles and randomly chose 1 to set as child allelle 0
        int random_1 = rand() % 2;
        int random_2 = rand() % 2;
        if (random_1 == 0)
        {
            p->alleles[0] = p->parents[0]->alleles[0];
        }
        else
        {
            p->alleles[0] = p->parents[0]->alleles[1];
        }
        if (random_2 == 0)
        {
            p->alleles[1] = p->parents[1]->alleles[0];
        }
        else
        {
            p->alleles[1] = p->parents[1]->alleles[1];
        }
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        // TODO: Randomly assign alleles
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return p;
}

// Free `p` and all ancestors of `p`.
void free_family(person *p)
{
    if (p != NULL) // base case: handle an input of NULL
    {
        // TODO: Free parents: call free_family function on each of the child's two parents
        free_family(p->parents[0]);
        free_family(p->parents[1]);
        // TODO: Free child
        free(p);
    }
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}