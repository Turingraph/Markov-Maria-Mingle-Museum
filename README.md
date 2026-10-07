# Markov-Mingle

https://mathshistory.st-andrews.ac.uk/Biographies/Markov/

# Attribute

1.	There are m agents.
2.	Each agent have one of n genders
3.	Each agents have one of 2^n orientations (including the wish for one of every combination of all gender actively and no orientation a.k.a. inactive). It will only start the connection 
4.	Each agents will seek k friends that align with its orientation or won't seek friends if it inactive.
5.	After the agent belong to its group (or be inactive) within the current discrete turn, it might or might not change its gender, orientation, and/or k friends/partners network, based on its friend's genders composition and its if else condition and its current state.

(5. is all about if your friend is bisexual woman, you will be a gay man, if your friend is straight woman, you won't change your gender and your orientation etc. If your n friends is m-th genders, you will be l-th gender/orientation etc. The 5.'s input is always depending on your network's gender/orientation, and output is changing your gender/orientation according to your internal if else condition, without consider your history e.g. how many ex you have that is gay etc.)

Such that this align with typical Markov chain, simplified romance simulation of gay/guy/girl/straight/bisexual/aroace dating with each other, simplified hydrogen and oxygen simulation, drug vs cancer (some drug 'dating' with cancer and after that the cancer become inactive forever), Covid Pandemic, groups of people playing rock paper scissors or loss etc.

Future attributes
1.	How the agents select its network e.g. do straight woman prefer to date guys with fewest ex, do bisexual people with low kinsey scale prefer straight over gay when there are straight and gay, do atom prefer to create a bond with near atom over far atom, how entanglement effect how molecule bond form, can 2 atoms that very far away within 2d world form a molecule etc. This shouldn't be implement in the first version due to the risk of scope creep and premature abstraction.
2.	diverse types of statistics might or might not be include in the first version e.g. how many percent of the graph over romance networks are tree given that all allo people have only exactly 1 crush (some allo people can have aroace as their crush) but every aroace have 0 crush, the distribution of graph centrality value of every agents within the given time interval, how much entropy the simulation is according to information theory etc.
3.	using ML model to predict the state of the simulation in the future, such that the ML model use fewer time/space than the direct computed simulation.
4.	research more on practical application of this simulation for research in medical science, ecology, logistics, etc.

# Statistics report

Value
1.	centrality range counts (how many people with centrality less than 2 ? etc.)
2.	composition counts (How many Methan are there? How many satisfy Yuri (2 lesbians that date with each other) are there ? How many straight love triangles (between a guy and 2 girls) are there ?)
3.	edge counts (how many lesbian woman like straight woman, lesbian woman, or bisexual woman, how many Oxygen connect to Hydrogen vs Carbon etc.)
4.	category and blueprint counts (How many gay/guy/straight/bi/girls? How many Oxygen/Hydrogen/Carbon ? How many Covid19 patients vs uninfected people etc.)
5.	graph counts or community detection counts

graph type
1.	current time
2.	graph sum between time t1 and t2.

Statistics
1.	Value-Frequency (Distribution)
2.	Value-Time (Trend)

<!-- 
# Input format (no code)

## 1st example

```
/*
This means there are 430 guys and 550 girls. Everyone have only one crush, excepts 30 straight mans.
50 guys and 150 girls are homosexual. 100 guys wouldn't OK if the gay date them.
280 guys want to trying date woman, but 100 guys want to have 100% monogamy relationship with woman.
300 womans are straight. 100 woman are bisexual. Lastly every lesbian feel uncomfortable when guys like her.
*/

// TARGET_FILE = 1 // means write(1, ...);
TARGET_FILE = (output dir path)
ITERATION = 100

CATEGORY: MALE FEMALE

BLUEPRINT_TABLE
: ID	, AGENTS	, CATEGORY	, PREFERENCE
: 0		, 100		, MALE		, SEARCH 1 FEMALE; BLOCK MALE;
: 1		, 150		, MALE		, SEARCH 1 FEMALE;
: 2		, 50		, MALE		, SEARCH 1 MALE;
: 3		, 30		, MALE		, SEARCH 2 FEMALE;
: 4		, 100		, MALE		, REPLY 1 FEMALE;
: 5		, 300		, FEMALE	, SEARCH 1 MALE;
: 6		, 100		, FEMALE	, SEARCH 1 MALE; SEARCH 1 FEMALE;
: 7		, 150		, FEMALE	, SEARCH 1 FEMALE; BLOCK MALE;

// Allow only few allow formula instead of all possible combination of graph. This would make the simulation more useful for simple chemistry simulation.
// ALLOW_FORMULA: FORMULA(4, 1, HYDROGEN, CARBON), FORMULA(<4&>1, OXYGEN), FORMULA(2, 1, HYDROGEN, OXYGEN), FORMULA(<3&>0, 1, OXYGEN, CARBON)

// The output is compatible with Numpy, Pandas, and CSV.
// time, counts male like male, counts female like male, counts male like female, counts female like female, counts the directed graph with exactly 1 male and 1 female, counts the directed graph with 5 or fewer male and 4 or fewer female, counts the directed graph with 1 male and 11 or many more females.

OUTPUT_TABLE:
: TIME, RELATION(MALE, MALE), RELATION(FEMALE, MALE), RELATION(MALE, FEMALE), RELATION(FEMALE, FEMALE), FORMULA(1, 1, MALE, FEMALE), FORMULA(<6, <5, MALE, FEMALE), FORMULA(1, > 10, MALE, FEMALE)
```

Common command
1.	RELATION(CATEGORY_1, CATEGORY_2)
*	the directed edge between 2 agents from the specific 2 categories.
*	output table means total count
2.	FORMULA(number, ..., CATEGORY, ...)
*	All graph with the specific combination of things. It use variadic functions.
*	output table means total count
3.	CENTRALITY(CATEGORY, MODE)
*	output table means average centrality and its standard deviation.
4.	CATEGORY
*	output table means counts

Feature to avoid to do
1.	FORBIDDEN_FORMULA (because it risks scope creep)

## 2st example
 -->
