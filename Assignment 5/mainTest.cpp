#include  <cstdlib>
#include  "array.h"
#include <string>
#include  <math.h>


using namespace std;

//
// Test valid limits for an Array object with a
// lower index of zero.
//
static void  zeroBasedArrayTest()
{
	Array<float>  data(5);

	data[0] = 10.5;
	data[3] = 20.4;
	data[5] = 30.3;

	cout << std::endl
		<< "Test1 - "
		<< data[0] << ' '
		<< data[3] << ' '
		<< data[5] << ' '
		<< std::endl;
}


//
// Test valid limits for an Array object with a
// non-zero, positve lower index.
//

static void  positiveBasedArrayTest()
{
	Array<float>  data(10, 5);

	data[5] = -10;
	data[8] = 22;
	data[10] = 9;

	cout << std::endl
		<< "Test2 - "
		<< data[5] << ' '
		<< data[8] << ' '
		<< data[10] << ' '
		<< std::endl;
}


//
// Test valid limits for an Array object with a
// non-zero, negative lower index.
//
static void  negativeBasedArrayTest()
{
	Array<float>  data(3, -2);

	data[-2] = 78;
	data[0] = -30;
	data[3] = -8;

	cout << std::endl
		<< "Test3 - "
		<< data[-2] << ' '
		<< data[0] << ' '
		<< data[3] << ' '
		<< std::endl;
}


//
// Display array settings and contents.
//
static void  displayArray(const Array<float>  &a, const char  *prompt)
{
	cout << prompt << ":"
		<< "  L: " << a.lowerBound()
		<< "  U: " << a.upperBound()
		<< "  N: " << a.numElements()
		<< "  S: " << a.size()
		<< endl << "    Contents: ";

	for (int idx = a.lowerBound(); idx <= a.upperBound(); ++idx)
		cout << a[idx] << ' ';

	cout << endl;
}


//
// Test the copy constructor for the Array class.
//
static void  cctorTest()
{
	cout << std::endl << "Test 4" << std::endl;

	const int  lower = 7;
	const int  upper = 16;

	Array<float>  data(upper, lower);

	int  idx;

	for (idx = lower; idx <= upper; ++idx)
		data[idx] = (idx * 2);

	displayArray(data, "  Original");

	Array<float>  copy1(data);
	Array<float>  copy2(data);

	cout << endl;
	displayArray(copy1, "  Copy 1");

	cout << endl;
	displayArray(copy2, "  Copy 2");

	cout << std::endl;
}


//
// Test valid limits for a SafeArray object with a
// non-zero, positive lower index.
//
static void  positiveBasedSafeArrayTest()
{
	SafeArray<float>  data(10, 5);

	data[5] = -10.3;
	data[8] = 22.4;
	data[10] = 9.5;

	cout << "Test5 - "
		<< data[5] << ' '
		<< data[8] << ' '
		<< data[10] << ' '
		<< std::endl;
}


//
// Test for an index limits violation for a
// SafeArray object.
//
static void  safeArrayViolationTest()
{
	try
	{
		SafeArray<float>  data(10, 5);

		data[5] = -10.3;
		data[8] = 22.4;
		data[10] = 9.5;

		cout << std::endl
			<< "Test6 - "
			<< data[5] << ' '
			<< data[8] << ' '
			<< std::endl;
	}
	catch (int e)
	{
		if (e == 1)
			cout << "Bad bound" << endl;
		if (e == 2)
			cout << "Memory Allocation" << endl;
		if (e == 3)
			cout << "Out of bounds" << endl;
	}
}
void checkAt()
{
	Array<float> values(10);
	Array<string> s(6);
	s[1] = "Hello ";
	s[2] = " world ";
	s[3] = "hi";
	s[4] = " kendra ";
	s[5] = "!!";

	for (int i = 0; i <= 10; i++)
	{
		values[i] = i*3.14;
		cout << "Value in position " << i << " of array Values: " << values[i] << endl;
	}
	for (int i = 0; i <= 6; i++)
	{
		cout << s[i];
		Array<string> copyS(s);

		cout << " " << copyS[i] << endl;
	}
}

//
// main() program
//
int  main()
{
	Array<int>  data(5);
	data[0] = 10;
	data[3] = 20;

	Array<int> bdata(5);
	bdata = data;
	
	cout << data[0] << " Copy 1: " << bdata[0];
	cout << data[3] << " Copy 2: " << bdata[3];
	

	// Testing at function 
	checkAt();

	/*class point{};
	SafeArray<point> data(38, 31);

	data.at(38) = point(8);*/

	// Zero-based Array
	zeroBasedArrayTest();


	// Non-zero positive based array
	positiveBasedArrayTest();

	// Non-zero negative based array
	negativeBasedArrayTest();

	// CCTOR
	cctorTest();

	// Non-zero positive safe array
	positiveBasedSafeArrayTest();

	// Safe-Array Violations test
	safeArrayViolationTest();



	return 0;

}