# Daily-15
Daily 15 -> want to tweak

Assignment: 


COMP 91.101 Day 15– Due Wednesday, October 14 at class time F15 - Dr. Adams
Create a project called Daily15. Add a C source file to the project named daily15.c.
The gravitational attractive force between two bodies with masses m1 and m2 separated by a
distance d is given by:
𝐹 = G𝑚1𝑚2
𝑑2
where G is the universal gravitational constant:
𝐺 = 6.673 × 10−8 � 𝑐𝑚3
𝑔 × sec2�
write a function definition that takes arguments for the masses of two bodies and
the distance between them and that returns the gravitational force. Since you will
use the preceding formula, the gravitational force will be in dynes. One dyne
equals
�
𝑔 × 𝑐𝑐
sec2 �
you should use a globally defined constant for the universal gravitational constant
named UNIVERSAL_GRAVITATIONAL_CONSTANT (don’t be afraid to use
descriptive names; G is not a good name). Embed your function definition in a
complete program that computes the gravitational force between two objects
given suitable inputs. Your program should allow the user to repeat this
calculation as often as the user wishes.
Please note that the user will have to enter the masses in grams and the distance in
centimeters unless you provide some conversion for the input. If you do decide to
allow the user to enter the information in some other units then please include at
least one option to enter mass as grams and distance in centimeters as that is
likely what the graders will use to grade. When outputting the resulting force you
may want to consider using %g instead of %f since the range of numbers is so
great it is hard to find settings on %f that look good for all input values.
Also note: The mass of the earth is approximately 5.972 × 1024 kilograms and the
mass of the moon is 7.34767309 × 1022 kilograms. The moon is about 384,400
kilometers from the earth. In your comments section list the gravitational
attractive force in dynes of the moon on the earth given by your program
using the notation for exponents that C uses for constants (like 6.02e23).
COMP 91.101 Day 15– Due Wednesday, October 14 at class time F15 - Dr. Adams
Your program output should look something like the following though you are not required to give the
user an option between kilograms and grams:
At the top of your program you should have a comment section that follows the below format:
/***********************************************
Author: <insert your name>
Date: <insert today’s date>
Purpose: <Insert a short description of what
your program does here.>
Sources of Help: <Please list any sources that you used
 for help: tutors, web sites, lab assistants etc.>
 Gravitational force in dynes of the moon on the earth: <insert
 force your program computed here>
Time Spent: <Insert how much time you spent
on the assignment here>
***********************************************/
