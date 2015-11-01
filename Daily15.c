/*
Author: Joshua Butler
Date: 10/28/2015
Purpose: To calculate the force of gravity exerted between two bodies
using Newtons Law of Universal Gravitation. Takes input in gcs.
Gravitational force in dynes of moon on earth: 1.98 x 10^ 25
<Time Spent>: 5 hours.
*/

#include <stdio.h>
#include <math.h>


enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

static const double BIG_G = 6.673;

// Precondition: None
// Postcondition: Inputs are taken in proper units.
double input();

// Precondition: Proper inputs have been made
// Postcondition: Outputs the attractive force between units
double calculate_attractive_force(double distance, double mass1, double mass2, double grav_constant);

void clear_key();
Boolean u_continue();
Boolean u_correct();
double unit_choice();

int main(int argc, char* argv[])
{
	double output, distance, mass1, mass2, force_of_bodies, grav_constant;

	printf("The number is scientific notation \n");
	printf("The format is input1 * 10 ^ input2.\n");
	printf("For example, for 5.73 * 10 ^-3, input1 is 5.73, input2 is -3.\n\n");


	//************** fix so printf gives correct units**************
	// MASS_UNIT, DISTANCE_UNIT, AND FORCE_UNIT have been used as place holders.

	do{

		grav_constant = unit_choice();
		printf("%g \n", grav_constant);


		do{

			printf("A distance, in DISTANCE_UNIT(S): ");
			distance = input();
			printf("You entered: %g DISTANCE_UNIT(S).\nWhich: is %g DISTANCE_UNIT(S).\n",
				distance, distance * pow(10, -5));
		} while (u_correct() != 1);

		do{
			printf("A mass for body 1, in MASS_UNIT(S) : ");
			mass1 = input();
			printf("You entered: %g MASS_UNIT(S)\nWhich is: %g MASS_UNIT(S)\n", mass1, mass1 * pow(10, -3));
		} while (u_correct() != 1);

		do{
			printf("A mass for body 2, in MASS_UNIT(S): ");
			mass2 = input();
			printf("You entered: %g MASS_UNIT(S))\nWhich is %g MASS_UNIT(S)\n", mass2, mass2* pow(10, -3));
		} while (u_correct() != 1);

		force_of_bodies = calculate_attractive_force( distance, mass1, mass2, grav_constant); //calculate force of bodies using a function
		printf("Attractive force: %g FORCE_UNIT(S) \n", force_of_bodies);

	} while (u_continue());


	return(0);
}


double 
input()
{
	double first, second, last, input2;

	printf("Please enter the first number: ");
	scanf("%lf", &first);
	clear_key();

	printf("And what number is 10 raised to?: ");
	scanf("%lf", &second);
	clear_key();
	input2 = second;

	last = first * pow(10.0, input2);


	return last;




}

double
calculate_attractive_force(double distance, double mass1,double mass2,double grav_constant)
{
double m1, dist, m2, force, grav;

dist = distance;
m1 = mass1;
m2 = mass2;
grav = grav_constant;

printf("****M1: %g **** \n", m1);  // test***
printf("****M2: %g****\n", m2);
printf("****DISTANCE: %g **** \n", dist);
force = ((grav * (m1 * m2)) / 1*pow(dist,2));

return force;
} 


void
clear_key(void)
{
	char c;

	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}

Boolean 
u_continue(void)
{
	char answer;
	do
	{

		printf("Do you wish to continue? (y/n): ");
		scanf(" %c", &answer);
		clear_key();

		if (answer != 'y' && answer != 'Y' && answer != 'n'
			&& answer != 'N')
		{
			printf("You can only enter 'y' or 'n' \n");
		}
	} while (answer != 'y' && answer != 'Y' && answer != 'n'
		&& answer != 'N');

	if (answer == 'y' || answer == 'Y')
	{
		return TRUE;

	}
	return FALSE;
}

Boolean 
u_correct(void)
{
	char answer;
	do
	{
		printf("Is this input correct? (y/n): ");
		scanf(" %c", &answer);
		printf("\n");
		clear_key();

		if (answer != 'y' && answer != 'Y' && answer != 'n'
			&& answer != 'N')
		{
			printf("You can only enter 'y' or 'n' \n");
		}
	} while (answer != 'y' && answer != 'Y' && answer != 'n'
		&& answer != 'N');

	if (answer == 'y' || answer == 'Y')
	{
		return TRUE;

	}
	return FALSE;
}

double 
unit_choice()
{		
	
	char answer;
	do
	{
		printf("Do you wish to use GCS(1) or KMS(2) units?: ");
		scanf(" %c", &answer);
		clear_key();

		if (answer != '1' && answer != '2')
		{
			printf("You can only enter '1' or '2' \n");
		}
	} while (answer != '1' && answer != '2');

	if (answer == '1')
	{
		return  BIG_G*pow(10,-8);

	}
	return  BIG_G*pow(10,-11);
}
