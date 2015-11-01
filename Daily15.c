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


#define BIG_G_GCS  6.673*pow(10, -8) // Universal Gravitational Constant.
#define BIG_G_KMS	6.673*pow(10,-11) //

// Precondition: None
// Postcondition: Inputs are taken in proper units.
double input();

// Precondition: Proper inputs have been made
// Postcondition: Outputs the attractive force between units
double calculate_attractive_force();

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

	do{

		grav_constant = unit_choice();
		printf("%g \n", grav_constant );


		do{
			
			printf("A distance, in CENTIMETER(S): ");
			distance = input();
			printf("You entered: %g CENTIMETER(S).\nWhich: is %g KILOMETER(S).\n",
				distance, distance * pow(10, -5));
			} while (u_correct() != 1);

		do{
			printf("A mass for body 1, in GRAM(S) : ");
			mass1 = input();
			printf("You entered: %g GRAM(S)\nWhich is: %g KILOGRAMS\n", mass1, mass1 * pow(10,-3));
		}while (u_correct() != 1);

		do{
			printf("A mass for body 2, in KILOGRAM(S): ");
			mass2 = input();
			printf("You entered: %g GRAM(S)\nWhich is %g KILOGRAMS\n", mass2, mass2* pow(10,-3));
		} while (u_correct() != 1);

		

		force_of_bodies = ((grav_constant * mass1 * mass2) / pow(distance, 2));  // Attempts to calculate force of bodies this works. units are in units.
																		// Works (originally set up program to input Newtons, may be off by one exponent if I missed changing one thing.)


		//force_of_bodies = calculate_attractive_force(distance, mass1, mass2); // Attempts to calculate force of bodies using a function, this doesnt work.

		printf("Attractive force: %g UNITS \n", force_of_bodies); 

	} while (u_continue());

		
	return(0);
		}


double input()
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

/* float calculate_attractive_force(distance, mass1, mass2) // this function has yet to work, I may be entering my inputs incorrectly, trying to take inputs from main to here.
{
	float m1, dist, m2;
		double force;
	dist = distance;
	m1 = mass1;
	m2 = mass2;
	

	printf("****M1: %g **** \n", m1); //test

	printf("****M2: %g****\n", m2);

	printf("****DISTANCE: %g **** \n", dist);



	//force = ((BIG_G * (m1 * m2)) / dist);

	force = m1;

	return force;

	} */ 
	

void clear_key(void)
{
	char c;

	scanf("%c", &c);
	while (c != '\n')
	{
	scanf("%c", &c);
}
}

Boolean u_continue(void)
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

Boolean u_correct(void)
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

float unit_choice(void)
{
	char answer;
	do
	{
		printf("Do you wish to use GCS(1) or KMS(2) units?: ");
		scanf(" %c", &answer);
		clear_key();

		if (answer != '1' && answer != '2' )
		{
			printf("You can only enter '1' or '2' \n");
		}
	} while (answer != '1' && answer != '2' );

	if (answer == '1')
	{
		return BIG_G_GCS;

	}
	return BIG_G_KMS;
}
