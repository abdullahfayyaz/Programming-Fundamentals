#include <iostream>
using namespace std;
main()
{
	float volume;
	float pipe1;
	float pipe2;
	float hours;
	float litres;
	float over;
	cout<<"Enter Volume of the pool (1 - 10000): ";
	cin>>volume;
	cout<<"Enter Rate flow of Pipe 1 (1 - 5000): ";
	cin>>pipe1;
	cout<<"Enter Rate flow of Pipe 2 (1 - 5000): ";
	cin>>pipe2;
	cout<<"Enter Number of absent hours (1.0 - 24.00): ";
	cin>>hours;
	pipe1 = pipe1 * hours;
	pipe2 = pipe2 * hours;
	litres = (pipe1) + (pipe2);
	if(litres < volume)
	{
	litres = (litres / volume) * 100;
	cout << "The Pool is " << litres << " % full. ";
	pipe1 = (pipe1 / volume) * 100;
	pipe2 = (pipe2 / volume) * 100;
	cout << " Pipe 1 : " << pipe1 <<"%";
	cout << " Pipe 2 : " << pipe2 <<"%";
	}
	if(litres > volume)
	{
	litres = litres - volume;
	over = ((pipe1 + pipe2) - volume) / ((pipe1 + pipe2) / hours);
	cout << "For " << over << " Hours, The pool overflows with " <<litres << " Litres";
	}
}