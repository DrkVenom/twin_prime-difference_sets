c++ twin_prime-difference_sets
produces the difference set formed by a pair of twin primes

== TO DO ==

1) presently there is no test to ensure that the user's input is indeed a prime number. If an arbitrary non-prime is entered the result is a segmentation fault. If an arbitrary prime is entered such that it is not the first half of a twin prime system (ie 7, 13, etc), the result is also a segmentation fault. The only working input are primes such that they are the FIRST half of a twin prime system (ie 5, 11, 71, etc)

2) the output does not yet include the total number of elements in the difference set. This is easy enough to solve though, I currently use a very small matlab file to solve for the size. Need to translate that to c++.

3) possibly store the results, unsure if this is truly needed.

== THEORY ==

Let G=Z_{p}*Z_{p+2}, where p and p+2 are primes. Let D be the subset of G consisting of elements (a,b) such that one of the following statements is true:

i) b=0

ii) a and b are both non-zero squares in their respective fields

iii) a and b are both non-squares in their respective fields

Then D is a difference set

== EXAMPLE ==

Consider the group Z_15 which is isomorphic to Z_3*Z_5. We can construct a difference set is three parts (described above) and take the union (assuming it satisfies correct dimensional sizes).

i) D_1 = {(0,0),(1,0),(2,0)}

ii) D_2 = {(1,1),(1,4)}

iii) D_3 = {(2,2),(2,3)}

So D = {(0,0),(1,0),(2,0),(1,1),(1,4),(2,2),(2,3)} is a (15,7,3)-difference set.

== NOTES ==

1) The code takes the user's input (a number of type ZZ) and automatically calculates its twin.

2) Output is not stored but merely printed to the screen as a difference set.

== COMPILING ==

1) This code uses the Number Theory Library (NTL from http://www.shoup.net/ntl/). I wrote it with 6.2.1 in mind, but presumably it should work with most (any) version. It relies on the calculation of the Jacobi number to check for the presence of quadratic residues (ie squares)

2) I use Linux to compile via the terminal using  ---> g++ twin_prime.cpp -o twin_prime -lntl -lm
