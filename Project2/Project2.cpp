//Project2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double calccost(int, double);
double acctotal(double, double);
void printLine(string, string, int, double, double);
void printInvoiceHeader(string);
void printReportHeader();
void printTotal(double);

ofstream fout; //Open output file
int main()
{
	int i, items;
	int quantity;
	double unitCost;
	double totalCost;
	string itemno;
	string name;
	string date;
	double newTotalCost;

	fout.open("invoice.txt");  // open the file
	ifstream fin("input.txt");
	if (fin.fail())
		cout << "Unable to open file!\n";
	else
	{
		fout << fixed << setprecision(2);
		printReportHeader(); // call the header function
		while (fin >> items >> date)
		{
			totalCost = 0;
			newTotalCost = 0;
			printInvoiceHeader(date);
			for (i = 1; i <= items; i++)
			{
				fin >> itemno >> name >> quantity >> unitCost;
				totalCost = calccost(quantity, unitCost);
				newTotalCost = acctotal(totalCost, newTotalCost);
				printLine(itemno, name, quantity, unitCost, totalCost);
			}
			printTotal(newTotalCost);
		}		
	}
	fin.close();
	fout.close();
	return 0;
}

double calccost(int quantity, double unitCost)
{
	return quantity * unitCost;
}
double acctotal(double totalCost, double newTotalCost)
{
	return totalCost + newTotalCost;
}
void printLine(string itemno, string name, int quantity, double unitCost, double totalCost)
{
	fout << right << setw(8) << itemno << "      " 
		<< left << setw(10) << name << right << setw(3) 
		<< quantity << right << setw(8) << unitCost 
		<< right << setw(9) << totalCost << endl;
}
void printInvoiceHeader(string date)
{
	fout << "Invoice date: " << date << endl;
	fout << endl;
}
void printReportHeader()
{
	fout << "    Erie Industrial Supply Corporation\n";
}
void printTotal(double newTotalCost)
{
	fout << "Total ..................." << newTotalCost << endl;
	fout << endl;
	fout << endl;
}

/* invoice.txt
Erie Industrial Supply Corporation
Invoice date: 2/12/2017

134276      Framis-R    8    7.35    58.80
125790      Framis-L   12   15.76   189.12
100086      Aglet     395    0.11    43.45
Total ...................291.37


Invoice date: 1/23/2017

135876      Wrench     12   22.50   270.00
543287      Henway      4   19.25    77.00
Total ...................347.00


Invoice date: 1/15/2017

161432      Widget      5    6.50    32.50
543289      Wodget     10    2.25    22.50
876234      Gadget      2   10.75    21.50
Total ...................76.50


Invoice date: 2/16/2017

198765      Corkle      2   12.18    24.36
107654      Swale       3    8.75    26.25
987987      Sinter      5    6.43    32.15
654821      Zangle      6   18.45   110.70
432165      Lunule      7    9.60    67.20
333221      Fangle     10   58.49   584.90
654098      Fwetstock   3   12.65    37.95
543210      Furnal      3    9.98    29.94
543287      Bobble     12   19.25   231.00
Total ...................1144.45


Invoice date: 2/26/2017

654821      Muntin      2   18.45    36.90
766443      Finwiddie   9    2.22    19.98
120980      Ferkle    100    0.12    12.00
123222      Sneedooper700    1.19   833.00
876543      Ferrule     2  345.77   691.54
877721      Uberfrock  14   88.93  1245.02
Total ...................2838.44

*/