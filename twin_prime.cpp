//Name: 			Tony Ranieri
//Created:			April 2015
//Modified:			July 2015

// uses "NTL: A Library for doing Number Theory", packages and readmes can be located at http://www.shoup.net/ntl/
// the code presented here is written with NTL 6.2.1 in mind

#include <ctime>
#include <iostream>
#include <NTL/ZZ.h>

NTL_CLIENT

int main()
{
	//initialize value for timing
	std::clock_t    s_time;
	s_time = std::clock();
	
	//initialize the primes to be used
	ZZ p_prime, q_prime;
	
	cout << "Please enter the first prime of your twin prime system: \n";
	cin >> p_prime;
	cout << "\n";
	
	q_prime = p_prime + 2;
	
	cout << "We will now generate the difference set for Z" << p_prime <<"xZ"<< q_prime;
	cout << "\n";
	
	// create vectors to hold the values of the quadratic residues and non-quadratic residues mod p and q
	Vec<ZZ> p_prime_quad, p_prime_non, q_prime_quad, q_prime_non;
	
	long p_len = conv<long>(p_prime-1)/2;
	long q_len = conv<long>(q_prime-1)/2;
	
	//set vectors to be of the appropriate lengths to hold quadratic residues and non-quadratic residues
	p_prime_quad.SetLength(p_len);
	p_prime_non.SetLength(p_len);
	q_prime_quad.SetLength(q_len);
	q_prime_non.SetLength(q_len);
	
	int p_ind_quad=0;
	int q_ind_quad=0;
	int p_ind_non=0;
	int q_ind_non=0;
		
	ZZ holder;
		
	// fill both p_prime_quad and p_prime_non
	for (int i=1;i<p_prime;i++)
	{
		holder = i;
		if (Jacobi(holder,p_prime)==1)
		{
			p_prime_quad[p_ind_quad]=i;
			p_ind_quad++;
		}
		else
		{
			p_prime_non[p_ind_non]=i;
			p_ind_non++;
		}
	}
	
	// fill both q_prime_quad and q_prime_non
	for (int j=1;j<q_prime;j++)
	{
		holder = j;
		if (Jacobi(holder,q_prime)==1)
		{
			q_prime_quad[q_ind_quad]=j;
			q_ind_quad++;
		}
		else
		{
			q_prime_non[q_ind_non]=j;
			q_ind_non++;
		}
	}
	
		
	// From theorem, if group is AxB, then we fill (a,0), where a is in A
	cout << "{ ";
	for (int k=0;k<p_prime;k++)
	{
		cout << "(" << k << ",0) ";
	}
	
	
	// From theorem, if group is AxB, then we fill (a,b), where a is a quadratic residue and b is a quadratic residue
	for (int k=0;k<p_len;k++)
	{
		for (int l=0;l<q_len;l++)
		{
			cout << "(" << p_prime_quad[k] << "," << q_prime_quad[l] << ") ";
		}
	}
	
	
	// From theorem, if group is AxB, then we fill (a,b), where a is a non-quadratic residue and b is a non-quadratic residue
	for (int k=0;k<p_len;k++)
	{
		for (int l=0;l<q_len;l++)
		{
			cout << "(" << p_prime_non[k] << "," << q_prime_non[l] << ") ";
		}
	}
	cout << "}\n" << "\n";
	std::cout << "Time: " << (std::clock() - s_time) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
}
