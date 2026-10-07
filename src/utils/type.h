#ifndef TYPE_H
# define TYPE_H

//------------------------------------------------------------------

#include <stdlib.h>
#include <stdbool.h>

/**
 * This struct is used for define the category, for example
 * Woman = 0, and Man = 1,
 * Hydrogen = 0, Oxygen = 1, and Carbon = 2
 * etc.
 */
typedef struct t_category_dict
{
	size_t	category_id;
	char	*category_label;
}	t_category_dict;

/**
 * This struct define the overall preference of the agents.
 * - category_id_arr (This is array)
 * 		The preferred category. For example both straight/bisexual woman and gay/bisexual man like man,
 * 		both lesbian/bisexual woman and straight/bisexual man like woman,
 * 		Carbon like hydrogen because it can become Methane or Ethane etc.
 * - max_connected_arr (This array can be NULL.)
 * 		The default value is 1.
 * 		e.g. Most people, including gays, straight, and bisexual people,
 * 		prefer to have one romantic partners (some people also prefer
 * 		ethical non monogamy but we want to simulate
 * 		only people who have 1 crushes at a time), so max_connected = 1.
 * 		on the other hands, many atoms have multiple connection e.g. max_connected of oxygen and carbon
 * 		is 2 and 4 respectively.
 * - is_reciprocal_arr (This array can be NULL.)
 * 		The default value is false.
 * 		e.g. some gay guy like some straight guy and he OK if his crush don't like him back,
 * 		(is_reciprocal is false). However some gay guy want to make connection
 * 		with only gay or bisexual guy because he want reciprocal from his crush (is_reciprocal is true),
 * 		every covalent bond have is_reciprocal equal to true etc.
 * - length (both length and max_total_connected should either greater than 0 or equal to 0)
 * 		The length of preference_arr array.
 * 		some agents might have multiple preference towards multiple categories of agents
 * 		e.g. bisexual people like both man and woman, Carbon like Oxygen, Carbon, and hydrogen etc.
 * - max_total_connected (this value might or might not equal to length)
 * 		the maximum relationship that the agents can make,
 * 		for examples most people (guys, gays, bisexual etc.) have a girl/boy friend,
 * 		but the max_total_connected of carbon is 4,
 * 		Note that this is differ from max_connected_arr[i],
 * 		because carbon can have connection with 1 carbon and 3 hydrogen to become Ethane, but it cannot connect 2 carbons and 4 hydrogens.
 * 		Note that this have limitation, for example carbon that have connection with 2 oxygen and 2 hydrogen is invalid,
 * 		we could impose the additional blueprint, such that we have a few types of carbon based on its preference preference as multiple blueprint
 * 		e.g. carbon that never prefer hydrogen but prefer carbon and oxygen, carbon that never prefer oxygen etc.
 */
typedef struct t_preference_arr
{
	size_t			*category_id_arr;
	size_t			*max_connected_arr;
	bool			*is_reciprocal_arr;
	size_t			length;
	size_t			max_total_connected;
}	t_preference_arr;

/**
 * This struct make other agents with the specific category_id cannot connect to the given agent.
 * - category_id_arr (This array can be NULL if and only if length == 0)
 * 		The target category, for examples some straight man OK if the gay man like him,
 * 		but some straight man don't OK with that etc.
 * 		Note that some straight man might block woman such that she cannot make
 * 		connection with him, but he can make connection with her.
 * 		This allow us to define more complicated unusual situation e.g.
 * 		bad guys block police but he call police for negotiating with police by using his hostage. etc.
 * - length
 * 		The length of category_id_arr array.
 */
typedef struct t_block_arr
{
	size_t	*category_id_arr;
	size_t	length;
}	t_block_arr;

/**
 * This struct is used for defining the blue print of the agents,
 * for example some people are straight guy, some people are lesbian, some are bisexual guy, some particles
 * are Carbon that only make bond with hydrogen and oxygen, but some Carbon making bond with only oxygen instead etc.
 * - blueprint_id
 * 		The id of the blue print.
 * - population
 * 		The total number of the population of agents with the given blue prints.
 * - category_id
 * 		The category of the agents e.g. Male, Female, Oxygen, Hydrogen, Carbon etc.
 * - preference_arr
 * 		The list of the prefer categories e.g. every straight guys like girls,
 * 		some Carbon making bond with Carbon, Oxygen, Hydrogen etc.
 * - block_arr
 * 		The list of blocked categories.
 * - next_state (This array can be NULL.)
 * 		user can set the next state of the agent, such that the instance of the agents change its blue print,
 * 		for example human agents have Covid infection after someone with Covid contact them etc.
 */
typedef struct t_blueprint
{
	size_t				blueprint_id;
	size_t				population;
	size_t				category_id;
	t_preference_arr	preference_arr;
	t_block_arr			block_arr;
	void				(*next_state)(void*);
}	t_blueprint;

/**
 * record which connection that the agents make with another agents
 * and how many connection it make as dynamic array.
 * - agent_id (This array can be NULL if and only if length equal to 0)
 * 		The id of the given agent, for examples this gay guys have the connection with another gay guy,
 * 		so he have the agent_id of that dude. Another examples is one straight dude might be popular among
 * 		many woman and some gay man, so he own their multiple agent_id, even if he has only one crush toward a girl.
 * - frequency (This array can be NULL.)
 * 		The frequency would likely represent the sum of each time step of the graph
 * 		i.e. gay like a guy once at a time but he might have multiple ex boy friend,
 * 		so this is the sum count divide by n steps.
 * 		This is useful for getting the Eigan vector of the matrix graph within
 * 		a particular interval time. We can compare how change the Eigan vector
 * 		is for 0 to 100 and 100 to 200 time.
 * 		In addition, we can operate multiple algorithms e.g. path finding,
 * 		more generalized betweenness centrality (beyond just the integer value) etc.
 * - length (length <= capacity)
 * 		The length of agent_id and frequency array.
 * - capacity
 * 		The total capacity of the agent_id and frequency dynamic array.
 */
typedef struct t_connect_agents
{
	size_t	*agent_id;
	float	*frequency;
	size_t	length;
	size_t	capacity;
}	t_connect_agents;

/*
 * Properties of each instance of agent. Note that the simulation can have a few blueprint, but a lots of agents instances.
 * - agent_id
 * 		The ID of each agents instance.
 * - blueprint
 * 		e.g. some people are straight guy, some people are lesbian, some are bisexual guy, some particles
 * 		are Carbon that only make bond with hydrogen but some Carbon making bond with only oxygen instead etc.
 * - prefer_agents
 * 		e.g. female (if the agent is straight man), Oxygen (if the agent is Carbon or Hydrogen) etc.
 * - fan_agents
 * 		e.g. some agents that contact them like gay man or bisexual man/woman,
 * 		or straight woman (if this agent is straight man) etc.
 */
typedef struct t_agent
{
	size_t				agent_id;
	t_blueprint			blueprint;
	t_connect_agents	prefer_agents;
	t_connect_agents	fan_agents;
}	t_agent;

/*
Examples of Blue Print

Hydrogen
-	category_id: 0
-	preference: Oxygen (1), Carbon (1), Hydrogen (1)
-	max_length: 1

Oxygen
-	category_id: 1
-	preference: Oxygen (2), Carbon (2), Hydrogen (2)
-	max_length: 2

Carbon
-	category_id: 2
-	preference: Oxygen (2), Carbon (1), Hydrogen (4)
-	max_length: 4

Carbon (that connect to only hydrogen)
-	category_id: 2
-	preference: Oxygen (0), Carbon (1), Hydrogen (4)
-	max_length: 4

gay guys
-	category_id: 1
-	preference: Man (1), Woman (0)
-	max_length: 1

bisexual guys
-	category_id: 1
-	preference: Man (1), Woman (1)
-	max_length: 1

aroace guys
-	category_id: 1
-	preference: Man (0), Woman (0)
-	max_length: 0

aroace girls
-	category_id: 0
-	preference: Man (0), Woman (0)
-	max_length: 0

straight guys
-	category_id: 1
-	preference: Man (0), Woman (1)
-	max_length: 1

straight guys who like ethical non monogamy
-	category_id: 1
-	preference: Man (0), Woman (2)
-	max_length: 2

straight girls
-	category_id: 0
-	preference: Man (1), Woman (0)
-	max_length: 1
*/

//------------------------------------------------------------------

/**
 * The aggregation sum of repeat link between agents between
 * start_time and end_time.
 * - agent_id
 * 		The given agent within a node. The agent might or might not
 * 		change its category or its blueprint.
 * - prefer_agents
 * 		All of the current and past connection that this agent initialize.
 * - fan_agents
 * 		All of the current and past connection that this agent is initialized by others.
 * - start_time
 * 		The start time interval.
 * - end_time
 * 		The end time interval.
 */
typedef struct t_history_graph
{
	size_t				agent_id;
	t_connect_agents	*prefer_agents;
	t_connect_agents	*fan_agents;
	size_t				start_time;
	size_t				end_time;
}	t_history_graph;

/**
 * The aggregation history of the agents start_time and end_time.
 * - agent_id
 * 		The given agent within a node. The agent might or might not
 * 		change its category or its blueprint.
 * - blueprint_id
 * 		The blueprint that this agents was become.
 * - start_time
 * 		The start time interval.
 * - end_time
 * 		The end time interval.
 * - length
 * 		The length of blueprint_id records array.
 */
typedef struct t_history_agent
{
	size_t	*blueprint_id;
	size_t	agent_id;
	size_t	start_time;
	size_t	end_time;
	size_t	length;
}	t_history_agent;

/*
louvain community detection for NETWORK_MODULARITY .
*/

/**
 * @see the video about the power of friendship
 * https://youtu.be/j2T4gvQAiaE?si=UPTYcad_CgR0Hggc
 * more for study how connected the network is.
 */
typedef enum t_connectedness
{
	NETWORK_CUTOFF,
	NETWORK_MODULARITY,
	NETWORK_DIAMETER,
	NETWORK_CLUSTER
}	t_connectedness;

/**
 * - CENTRAL_DEGREE How many connection the node have.
 * - CENTRAL_BETWEENNESS The betweenness centrality of the node.
 * - CENTRAL_EIGANVECTOR The Eiganvector centrality of the node.
 * @see the video about Wikipedia URL network
 * https://youtu.be/-llumS2rA8I?si=dmOK43cArk97ZWDw
 * more for study how to measure the centrality
 */
typedef enum t_centrality
{
	CENTRAL_DEGREE,
	CENTRAL_BETWEENNESS,
	CENTRAL_EIGANVECTOR
}	t_centrality;

/**
 * Define the data about the centrality of each agents at time interval t1 and t2.
 * - agent_id
 * 		The given agent.
 * - centrality
 * 		The centrality value of each agent.
 * - length
 * 		How many agent are there/
 */
typedef struct t_data_centrality
{
	size_t	*agent_id;
	float	*centrality;
	size_t	length;
}	t_data_centrality;

/**
 * Define the data about how common the specific network/graph formula is
 * for examples 2 mans and 1 woman, 2 Hydrogen and 1 Oxygen etc. at time t.
 * - profile_id
 * 		The ingredient of the formula as category_id or blueprint_id.
 * - profile_amount
 * 		The amount of each i-th ingredient for example love triangle with 2 man
 * 		or water with 2 hydrogen etc.
 * - frequency
 * 		How common he specific ingredient in the current time of the graph simulation.
 * - length
 * 		How many types of ingredient are there in this formula.
 */
typedef struct t_data_formula
{
	size_t	*profile_id;
	size_t	*profile_amount;
	size_t	frequency;
	size_t	length;
}	t_data_formula;

/**
 * Define the data about how common the specific connection between 2 agents is
 * e.g. how common is lesbian like straight woman, how common is man like woman,
 * how common is hydrogen connect to carbon etc. at time t or at time interval t1 and t2.
 * - profile_id_1
 * 		The blueprint or category_id of the agent that make the connection e.g. 
 * 		this agents is woman, lesbian, or Hydrogen etc.
 * - profile_id_2
 * 		The blueprint or category_id of the target agent e.g. the target agent is
 * 		the another woman who might not might not be straight, or the target agent
 * 		might be carbon, oxygen, or hydrogen, but not helium etc.
 * - is_reciprocal
 * 		Is the relationship 100% satisfy e.g. the target agents might ignore
 * 		the request of this agent regardless of its gender orientation
 * 		or it might reciprocate this agents as lesbian or as Oxygen
 * 		(because it need covariance bond or for other reason).
 * - frequency
 * 		How strong the link is.
 */
typedef struct t_data_relation
{
	size_t	profile_id_1;
	size_t	profile_id_2;
	bool	is_reciprocal;
	float	frequency;
}	t_data_relation;

/**
 * Counts how common the given profile (e.g. category or blueprint)
 * are there at time t or at time interval t1 and t2.
 */
typedef struct t_data_category
{
	size_t	profile_id;
	size_t	frequency;
}	t_data_category;

//------------------------------------------------------------------

#endif
